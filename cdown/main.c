#include <stdio.h>
#include "utils/io_utils.h"
#include "utils/time_utils.h"
#include "common/sqlite_manager.h"
#include "model/database_common.h"
#include "model/task_info.h"
#include "common/http_manager.h"
#include "model/request_api.h"
#include "common/threadpool_manager.h"
#include "ui/ui_main.h"

static void TestDatabase() {
  if (OpenDataBase("cdown.db") == RESULT_FAILURE) {
    return;
  }

  InitTables();

  TaskInfo task_info = {
      .filename = "test.txt",
      .url = "https://berylyvos.icu/test/test.txt",
      .directory = "~/Downloads",
      .size = 1024
  };
  InsertTaskInfo(&task_info);

  GPtrArray *tasks = ListTaskInfos();

  PRINTLNF("Found %d task(s).", tasks->len);
  for (int i = 0; i < tasks->len; ++i) {
    TaskInfo *task = g_ptr_array_index(tasks, i);
    TaskInfoDump(task);
  }

  g_ptr_array_free(tasks, TRUE);

  task_info.progress = 100;
  task_info.status = STATUS_COMPLETED;
  UpdateTaskInfo(&task_info);

  long long last_task_id = GetLastInsertRowId();

  PRINT_LLONG(last_task_id);
  TaskInfo *last_inserted_task = FindTaskInfoById(last_task_id);
  if (last_inserted_task) {
    TaskInfoDump(last_inserted_task);
    // DeleteTaskInfo(last_inserted_task);
    DestroyTaskInfo(&last_inserted_task);
  }

  CloseDataBase();
}

static void OnProgress(void *receiver, uint64_t current_bytes, uint64_t total_bytes) {
  PRINTLNF("%lld/%lld", current_bytes, total_bytes);
}

static void OnSuccess(void *receiver, void *data) {
  PRINTLNF("success");
}

static void OnError(void *receiver, int code, char const *message) {
  PRINTLNF("error: %d  %s", code, message);
}

static void TestHttp() {
  Request request = {
      .progress_callback = OnProgress,
      .error_callback = OnError,
      .success_callback = OnSuccess
  };

  RequestContext *context = CreateRequestContext(&request,
                                                 "https://berylyvos.icu/img/logo.svg",
                                                 "./d");
  SendRequest(context);

  if (context->curl_code == CURLE_OK) {
    request.success_callback(request.receiver, "OK");
  } else {
    request.error_callback(request.receiver, context->curl_code, curl_easy_strerror(context->curl_code));
  }

  DestroyRequestContext(context);
}

static void OnGetTaskInfoSuccess(void *receiver, TaskInfo *data) {
  PRINTLNF("success: ");
  TaskInfoDump(data);

  free(data);
}

static void TestTaskInfo() {
  GetTaskInfo("https://studygolang.com/dl/golang/go1.21.4.src.tar.gz",
              "./d", OnGetTaskInfoSuccess, OnError);
}

void OnCancellation(void *receiver) {
  PRINTLNF("Cancelled.");
}

static void TestDownloadFile() {
  TaskInfo task_info = {
      .filename = "go1.21.4.src.tar.gz",
      .url = "https://studygolang.com/dl/golang/go1.21.4.src.tar.gz",
      .directory = "./d",
      .size = 26979154,
      .resume_support = 1
  };
  void *handler;
  DownloadFile(NULL, &handler,
               &task_info,
               OnSuccess,
               OnError,
               OnCancellation,
               OnProgress);

  SleepMs(2000);
  CancelRequest(handler);
}

int main(int argc, char **argv) {
  if (OpenDataBase("cdown.db")) {
    return 1;
  }
  InitTables();
  InitThreadPool();

  RunDownloaderMain(argc, argv);

  DestroyThreadPool();
  CloseDataBase();
  return 0;
}

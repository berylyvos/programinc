#include "unit_test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

UiContext *ui_context;

static void DisplayTextToBuffer(char *text) {
  sprintf(ui_context->text_display_to, "%s", text);
}

static void UnitTestMain() {
  FILE *case_file = fopen("cases.txt", "r");
  if (case_file) {
    char key;
    char output_want[MAX_CHAR + 1];
    while (fscanf(case_file, " %c,%s", &key, output_want) != EOF) {
      if (HandleInput(ui_context->calc_ctx, key)) {
        if (strcmp(output_want, ui_context->text_display_to) == 0) {
          printf("Input [%c]: Output: %s, OK\n", key, output_want);
        } else {
          printf("Input [%c]: Output: %s, Expect: %s, ERROR\n",
                 key,
                 (char *) ui_context->text_display_to,
                 output_want);
        }
      }
    }

    fclose(case_file);
  } else {
    perror("open case file");
  }
}

static void InitUnitTest() {
  char *const kOutputBuffer = malloc(MAX_CHAR + 1);

  ui_context = malloc(sizeof(UiContext));
  ui_context->text_display_to = kOutputBuffer;
  ui_context->calc_ctx = CreateCalcContext();
  ui_context->calc_ctx->display = DisplayTextToBuffer;
}

static void DestroyUnitTest() {
  DestroyCalcContext(&ui_context->calc_ctx);
  free(ui_context->text_display_to);
  free(ui_context);
  ui_context = NULL;
}

int RunUnitTest(int argc, char **argv) {
  InitUnitTest();
  UnitTestMain();
  DestroyUnitTest();
  return 0;
}
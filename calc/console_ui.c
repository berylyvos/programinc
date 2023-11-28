#include "console_ui.h"
#include <stdlib.h>
#include <stdio.h>

UiContext *ui_context;

static void DisplayTextWithFile(char *text) {
  fputs(text, ui_context->text_display_to);
  fputc('\n', ui_context->text_display_to);

  fflush(ui_context->text_display_to);
}

static void ConsoleMain() {
  int input = getchar();

  while (input != EOF && input != 'q' && input != 'Q') {
    HandleInput(ui_context->calc_ctx, input);
    input = getchar();
  }

  puts("~~~~~~ DONE ~~~~~~");
}

static void InitConsole() {
  ui_context = malloc(sizeof(UiContext));
  ui_context->text_display_to = stdout;
  ui_context->calc_ctx = CreateCalcContext();
  ui_context->calc_ctx->display = DisplayTextWithFile;
}

static void DestroyConsole() {
  DestroyCalcContext(&ui_context->calc_ctx);
  free(ui_context);
  ui_context = NULL;
}

int RunConsoleUI(int argc, char **argv) {
  InitConsole();
  ConsoleMain();
  DestroyConsole();
  return 0;
}
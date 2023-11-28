#ifndef CALC__UI_H_
#define CALC__UI_H_

#include "calculator.h"

typedef struct {
  void *text_display_to;
  CalcContext *calc_ctx;
} UiContext;

#endif //CALC__UI_H_

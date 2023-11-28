#ifndef CALC__CALCULATOR_H_
#define CALC__CALCULATOR_H_

#include "operation.h"

#define  MAX_CHAR 13

typedef struct {
  char input_buf[MAX_CHAR + 1];
  int input_buf_pos;
  double res;

  Operation prev_op;
  Operation curr_op;

  void (*display)(char *);
} CalcContext;

int HandleInput(CalcContext *ctx, char input_val);

CalcContext *CreateCalcContext();

void DestroyCalcContext(CalcContext **p_ctx);

#endif //CALC__CALCULATOR_H_

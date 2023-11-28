#include "calculator.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void ClearBuffer(CalcContext *ctx) {
  ctx->input_buf[0] = 0;
  ctx->input_buf_pos = 0;
}

static void ClearAll(CalcContext *ctx) {
  ClearBuffer(ctx);
  ctx->res = 0;
  memset(&ctx->prev_op, 0, sizeof(Operation));
  memset(&ctx->curr_op, 0, sizeof(Operation));
}

static void FormatOutput(CalcContext *ctx) {
  if (ctx->res == -0.0) {
    ctx->res = 0.0;
  }
  sprintf(ctx->input_buf, "%.6g", ctx->res);
}

static void DisplayOutput(CalcContext *ctx) {
  FormatOutput(ctx);
  ctx->display(ctx->input_buf);
  ClearBuffer(ctx);
}

static void FormatInput(CalcContext *ctx) {
  if (ctx->input_buf_pos == 0) {
    ctx->input_buf[0] = '0';
    ctx->input_buf[1] = 0;
    ctx->input_buf_pos = 1;
  } else if (ctx->input_buf_pos == 1) {
    if (ctx->input_buf[0] == '.') {
      ctx->input_buf[0] = '0';
      ctx->input_buf[1] = '.';
      ctx->input_buf[2] = 0;
      ctx->input_buf_pos = 2;
    }
  } else if (ctx->input_buf_pos > 1) {
    char *p = ctx->input_buf;
    if (p[0] == '0' && p[1] != '.') {
      p[0] = p[1];
      p[1] = 0;
      ctx->input_buf_pos = 1;
    } else if (p[ctx->input_buf_pos - 1] == '.') {
      for (int i = 0; i < ctx->input_buf_pos - 1; ++i) {
        if (p[i] == '.') {
          p[--ctx->input_buf_pos] = 0;
          break;
        }
      }
    }
  }
}

static void DisplayInput(CalcContext *ctx) {
  FormatInput(ctx);
  ctx->display(ctx->input_buf);
}

static void ApplyInput(CalcContext *ctx, double *operand) {
  if (ctx->input_buf_pos > 0) {
    *operand = atof(ctx->input_buf);
    ClearBuffer(ctx);
  } else {
    *operand = ctx->res;
  }
}

static void ApplyInputToLeft(CalcContext *ctx) {
  ApplyInput(ctx, &ctx->curr_op.left);
}

static void ApplyInputToRight(CalcContext *ctx) {
  ApplyInput(ctx, &ctx->curr_op.right);
}

static void ApplyPrevOperation(CalcContext *ctx) {
  ctx->prev_op.left = ctx->res;
  ctx->res = OperationApply(&ctx->prev_op);
}

static void ApplyCurrOperation(CalcContext *ctx) {
  ctx->res = OperationApply(&ctx->curr_op);
  memcpy(&ctx->prev_op, &ctx->curr_op, sizeof(Operation));
  memset(&ctx->curr_op, 0, sizeof(Operation));
}

int HandleInput(CalcContext *ctx, char input_val) {
  switch (input_val) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.': {
      if (ctx->input_buf_pos < MAX_CHAR) {
        ctx->input_buf[ctx->input_buf_pos++] = input_val;
        ctx->input_buf[ctx->input_buf_pos] = 0;
      }
      DisplayInput(ctx);
      break;
    }
    case '+': {
      ctx->curr_op.operator = Plus;
      ApplyInputToLeft(ctx);
      break;
    }
    case '-': {
      ctx->curr_op.operator = Minus;
      ApplyInputToLeft(ctx);
      break;
    }
    case '*': {
      ctx->curr_op.operator = Multiply;
      ApplyInputToLeft(ctx);
      break;
    }
    case '/': {
      ctx->curr_op.operator = Divide;
      ApplyInputToLeft(ctx);
      break;
    }
    case '=': {
      if (ctx->curr_op.operator) {
        ApplyInputToRight(ctx);
        ApplyCurrOperation(ctx);
        DisplayOutput(ctx);
      } else if (ctx->prev_op.operator) {
        ApplyPrevOperation(ctx);
        DisplayOutput(ctx);
      } else {
        DisplayInput(ctx);
      }
      break;
    }
    case '%': {
      ApplyInputToLeft(ctx);
      ctx->curr_op.operator = Multiply;
      ctx->curr_op.right = 0.01;
      ApplyCurrOperation(ctx);
      DisplayOutput(ctx);
      break;
    }
    case 'S': {
      ApplyInputToLeft(ctx);
      ctx->curr_op.operator = Multiply;
      ctx->curr_op.right = -1;
      ApplyCurrOperation(ctx);
      DisplayOutput(ctx);
      break;
    }
    case 'C': {
      ClearAll(ctx);
      DisplayInput(ctx);
      break;
    }
    default:
      ;
  }
  return 1;
}

CalcContext *CreateCalcContext() {
  CalcContext *calc_context = malloc(sizeof(CalcContext));
  ClearAll(calc_context);
  calc_context->display = NULL;
  return calc_context;
}

void DestroyCalcContext(CalcContext **p_ctx) {
  free(*p_ctx);
  *p_ctx = NULL;
}

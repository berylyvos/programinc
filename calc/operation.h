#ifndef CALC__OPERATION_H_
#define CALC__OPERATION_H_

typedef struct {
  double left;
  double right;
  double (*operator)(double, double);
} Operation;

double OperationApply(Operation *operation);

double Plus(double left, double right);

double Minus(double left, double right);

double Multiply(double left, double right);

double Divide(double left, double right);

#endif //CALC__OPERATION_H_

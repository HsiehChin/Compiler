#ifndef CALC_FUNCTION_H_
#define CALC_FUNCTION_H_
#include <stdbool.h>

bool check_type(double answer);
int factorial(int a);
int permutation(int n, int r);
int combination(int n, int r);
char* decimal_to_binary(int n);
char* decimal_to_hex(int n);
char* decimal_to_octal(int n);
double vector();
#endif //CALC_FUNCTION_H_
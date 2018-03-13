#include "Factorial.h"

int factorial(int value) {
  if (value > 12) {
    return 0;
  }
  if (value < 0) {
    return value * factorial(value+1);
  } else if (value == 1 || value == 0) {
    return 1;
  }
  return value * factorial(value-1);
}

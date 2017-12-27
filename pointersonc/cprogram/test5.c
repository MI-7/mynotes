#include <stdio.h>

float
sqrt_float(float f, float approx)
{
  float previous_approx = 0.0, current_approx = approx;
  
  do {
    previous_approx = current_approx;
    current_approx = (current_approx + (f / current_approx)) / 2;
  } while(previous_approx != current_approx);
  
  return current_approx;
}

double
sqrt_double(double f, double approx)
{
  double previous_approx = 0.0, current_approx = approx;
  int i = 1;
  
  do {
    previous_approx = current_approx;
    current_approx = (current_approx + (f / current_approx)) / 2;
    printf("step: %d = %lf\n", i++, current_approx);
  } while(previous_approx != current_approx);
  
  return current_approx;
}

int
main(void)
{
  float sqrt_of_five = sqrt_float(5.0f, 1.0f);
  double sqrt_of_five_double = sqrt_double(5.0d, 1.0d);
  printf("sqrt of 5 = %10f; in double=%20lf\n", sqrt_of_five, sqrt_of_five_double);
}
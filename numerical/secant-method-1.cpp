#include <iostream>
#include <math.h>

#define EPSILON 0.001

double f(double x) {
  return exp(-x) - x; 
}

void secant(double x0, double x1) {

  double x2, f0, f1, f2;

  f0 = f(x0);
  f1 = f(x1);

//   while (abs(f1) >= EPSILON) {

//     x2 = x1 - f1*(x1 - x0)/(f1 - f0);
//     f2 = f(x2);

//     x0 = x1;
//     f0 = f1;
//     x1 = x2;
//     f1 = f2;
//   }

 for(int i = 0 ; i < 3; ++i) {

    x2 = x1 - f1*(x1 - x0)/(f1 - f0);
    f2 = f(x2);

    x0 = x1;
    f0 = f1;
    x1 = x2;
    f1 = f2;
  }


  std::cout << "The value of root is: " << x2;
}

int main() {

  double x0 = 0, x1 = 1.0;
  secant(x0, x1);

  return 0;
}
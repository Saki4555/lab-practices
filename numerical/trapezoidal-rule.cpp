#include <iostream>
using namespace std;


double f(double x) {
  return 0.2 + 25*x - 200*x*x + 675*x*x*x - 900*x*x*x*x + 400*x*x*x*x*x;
}

int main() {

  double a = 0.0, b = 0.8, exact = 1.640533;
  
  double integral = ((b-a)/2)*(f(a) + f(b));
  
  cout << "Integral = " << integral << endl;

  double error = exact - integral;
  cout << "Error = " << error << endl;
  

  double relative_error = (error/exact)*100;
  cout << "Relative error percentage = " << relative_error << endl;
  
  return 0;
}
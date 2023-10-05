#include <iostream>
using namespace std;


double f(double x) {
  return 0.2 + 25*x - 200*x*x + 675*x*x*x - 900*x*x*x*x + 400*x*x*x*x*x;
}

int main() {

  double a = 0.0, b = 0.8, exact = 1.640533, n = 2;
  double h = (b-a)/n, sum = 0.0;


  double increment = h + a;
  for(int i = 1; i <= n-1; ++i){
    sum += f(increment);
    increment += h;
  }

  double integral = ((b-a)/ (2*n)) * (f(a) + (2 * sum) + f(b));

  cout<< "Integral = " <<integral<<endl;

  double error = exact - integral;
  cout << "Error = " << error << endl;
  

  double relative_error = (error/exact)*100;
  cout << "Relative error percentage = " << relative_error << endl;
  
  return 0;
}
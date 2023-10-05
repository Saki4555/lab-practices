#include <iostream>
using namespace std;


double f(double x) {
  return 0.2 + 25*x - 200*x*x + 675*x*x*x - 900*x*x*x*x + 400*x*x*x*x*x;
}

int main() {

  double a = 0.0, b = 0.8, exact = 1.640533, n = 4;
  
  double h = ( b - a) / n, oddSum = 0.0, evenSum = 0.0;
  

  double increment = h + a;
  for(int i = 1; i <= n - 1; ++i){
    // also we can use ---> increment += i
    if(i%2){
        oddSum += f(increment);
    }
    else{
        evenSum += f(increment);
    }
    increment += h;
    
  }


  double integral = ( (b - a) / (3 * n)) * (f(a) + 4*oddSum + 2*evenSum + f(b));
  
  cout << "Integral = " << integral << endl;

  double error = exact - integral;
  cout << "Error = " << error << endl;
  

  double relative_error = (error/exact)*100;
  cout << "Relative error percentage = " << relative_error << endl;
  
  return 0;
}
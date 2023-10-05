#include <iostream>
using namespace std;


double f(double x) {
  return 0.2 + 25*x - 200*x*x + 675*x*x*x - 900*x*x*x*x + 400*x*x*x*x*x;
}

int main() {

  double a = 0.0, b = 0.8, exact = 1.640533, n = 5;

/*_________________
  |we use even value for n to get odd intervals|
  if n's value is odd and intervals count is even, for last 3 intervals except the last one use SIMPSON's 3/8 (n-3 to n) and
  for rest intervals use SIMPSON's 1/3(or multiple) rule (0 to n-3)

  ** it's just an assumption from slide's math solution, i did't search for it. [to search]
*/

 double h = (b - a) / n, oddSum = 0.0, evenSum = 0.0;

double increment = h + a;
 

 double integral_1 = ((( 2 * h + a) - a) / 6) * (f(a) + 4 * f( 2 * h + a));
 double integral_2 = ((b- (2*h + a))/ 8) * (f(2*h + a) + 3 *(f(3*h + a) + f(4*h + a)) + f(b));



 double integral = integral_1 + integral_2;
 

  double error = exact - integral;
  cout << "Error = " << error << endl;
  

  double relative_error = (error/exact)*100;
  cout << "Relative error percentage = " << relative_error << endl;
  
  return 0;
}
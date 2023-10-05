#include <bits/stdc++.h>
using namespace std;


double f(double x)
{
    return exp(-x) - x;
}

// double trueRelativeError(double actual, double approx){
//     return ((actual - approx) / actual) * 100;
// }

void secant(double a, double b)
{
    double x0 = a, x1 = b, x2;
    // double trueRoot = 0.567143;

    cout<< f(x0) <<" "<< f(x1) << endl;

    for (int i = 0; i < 3; ++i)
    {
        x2 = x1 - (f(x1) * (x0 - x1)) / (f(x0) - f(x1));
        x0 = x1;
        x1 = x2;
        // cout << "Approx root = " << x2 << " | True relative error " << abs(trueRelativeError(trueRoot, x2)) <<" %" <<endl;
    }

    cout << "Root is: " << x2 <<endl;
}

int main()
{
    double a = 0, b = 1.0;
    secant(a, b);
    return 0;
}
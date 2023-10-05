#include <bits/stdc++.h>
using namespace std;
#define LAMBDA 0.01

double f(double x)
{
    return exp(-x) - x;
}

// double trueRelativeError(double actual, double approx){
//     return ((actual - approx) / actual) * 100;
// }

void modifiedSecant(double a)
{
    double x1 = a, x2;
    // double trueRoot = 0.567143;
    
    for(int i = 0; i < 3; ++i){
        x2 = x1 - (f(x1) * LAMBDA * x1) / (f(x1 + LAMBDA * x1) - f(x1));
        x1 = x2;
        // cout << "Approx root = " << x2 << " | True relative error " << abs(trueRelativeError(trueRoot, x2)) <<" %" <<endl;
    }
    cout << "Root is: " << x2 <<endl;
}

int main()
{
    double a = 1;
    modifiedSecant(a);
    return 0;
}
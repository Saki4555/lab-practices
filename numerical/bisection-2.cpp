#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.01

double functionValue(double x){
    return x*x*x - x*x + 2;
}

void bisection(double a, double b){

    if( functionValue(a) * functionValue(b) >= 0){

        cout<<"Chose right intervals"<<endl;
        return;
    }

    double c = a;
    
    while ( b - a >= EPSILON)
    {
        c = ( a + b ) / 2;

        if( functionValue(a) * functionValue (c) == 0.0 ) break;
        else if( functionValue(a) * functionValue(c) < 0) b = c;
        else a = c;
    }

    cout << "Root is: " << c <<endl;
    
}

int main(){
    double a = -200, b = 300;
    bisection(a, b);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

double functionValue(double x){
    return x*x*x - x*x + 2;
}

void falsePosition (double a, double b){
    if( functionValue(a) * functionValue(b) >= 0){
        cout<<"Chose right intervals"<<endl;
        return;
    }

    double c = a;
    for(int i = 0; i < 1000000; ++i){
        c = b - ( functionValue(b) * ( a - b)) / (functionValue(a) - functionValue(b));

        if( functionValue(a) * functionValue(c) == 0.0 ) break;
        else if( functionValue(a) * functionValue(c) < 0) b = c;
        else a = c;
    }

    cout << "Root is: " << c <<endl;
}

int main(){
    double a = -200, b = 300;
    falsePosition(a, b);
    return 0;
}
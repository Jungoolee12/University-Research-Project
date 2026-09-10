#include <iostream>
#include <cmath>
using namespace std;

// y'= y
double f(double x, double y){
    return y;
}

int main(){

    double x = 0.1;
    double y = 0.1;
    double h = 0.1; //step size (h)

    double exact;
    double euler;
    double midpoint;

    
    for (int i = 0, i <= 10; i++){

        // Exact solution
        y = e^x
        exact = exp(x);

        // Euler method
        euler = y + h*f(x, y);

        // Midpoint mehtod
        midpoint = y + h*f(x * 1/2*h, 1/2*h*f(x,y))

        x += h;

    }


    return 0;
}

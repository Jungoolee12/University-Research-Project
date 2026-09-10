#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

// y'= y
// y = e^x
double f(double x, double y){
    return y;
}

int main(){

    // CSV
    ofstream outfile("results2.csv");
    outfile << "x,exact,euler,midpoint\n"; // header

    // Initial value
    double x = 0.0;
    double y = 1.0;
    double h = 0.01; //step size (h) = 0.01

    double exact;
    
    double euler = y;
    double midpoint = y;

    cout << "Iteration" << '\t' << "exact solution  " << '\t' << "euler method" << '\t' << "Error_euler" << '\t' << "midpoint method" << '\t' << "     Error_mid" << '\t' << '\n';

    double final_error_euler;
    double final_error_mid;

// Iterate the fuction
    for (int i = 0; i <= 100; i++){

        // Exact solution
        exact = exp(x);

        // Absolute error
        double abs_error_euler = abs(exact - euler);
        double abs_error_mid = abs(exact - midpoint);

        // Create the final error for the depending on the step size (h)
         if (i == 100){
            final_error_euler = abs(exact - euler);
            final_error_mid = abs(exact - midpoint);
        }       

        cout << fixed << setprecision(10);
        cout << "(" << i << ")" << '\t' << '\t' << exact << '\t' << '\t' << '\t' << euler << '\t' << '\t' << abs_error_euler << '\t' << '\t' << midpoint << '\t' << '\t' << '\t' << abs_error_mid << '\n';
        outfile << x << "," << exact << "," << euler << "," << midpoint << "\n";
        // Euler method
        euler = euler + h*f(x, euler);

        // Midpoint mehtod
        midpoint = midpoint + h*f(x + 0.5 * h, midpoint + 0.5 * h*f(x,midpoint));

        x += h;
    
    }

    cout << '\n' << "We can find that the error of the method y = e^x" << '\n';
    cout << "Absolute error of the Euler method is " << final_error_euler << " and the Midpoint method is " << final_error_mid << " for x=1" << '\n';
    cout << '\n' << "Therefore, we can find that the 'Midpoint method' is more accurate!";

    return 0;
}
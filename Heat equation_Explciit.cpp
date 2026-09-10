#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int main(){

    int N = 9; // Divided position
    int time = 10; // times

    double k = 0.1;
    double dx = 1.0;
    double dt = 0.2;

    double r = k*dt/(dx*dx); 

    double u[N] = {0.0};
    double u_new[N] = {0.0};

    cout << "Explicit Method" ;
    cout << "\n" << endl;

    u[N/2] = 10.0;

    for(int t=0; t < time; t++) {

        for(int j=1; j < N-1; j++)
            u_new[j] = u[j] + r*(u[j-1] - 2*u[j] + u[j+1]);

        u = u_new;



        cout << "time "<< t <<" : ";

        for(int j = 0; j < N; j++)
            cout << fixed << setprecision(2) << " ";
        cout << endl;
    }
}
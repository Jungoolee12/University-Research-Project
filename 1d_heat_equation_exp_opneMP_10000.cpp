#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <omp.h>

using namespace std;

int main() {

    const int N = 10000;
    int time = 10;

    double k = 0.1;
    double dt = 0.2;
    double dx = 1.0;

    double r = k * dt / (dx*dx); // <_ 0.5

    vector<double> u(N, 0.0);
    vector<double> u_new(N, 0.0);

    u[0] = 0; // boundary condition
    u[N-1] = 0; // boundary condition
    u[N/2] = 10.0; // initial condition

    cout << "Explicit Method" << "\n";
    cout << "dt : " << dt;
    cout << endl;
    
    double start = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp single
        {
            int total = omp_get_num_threads();
            printf("\nTotal threads : %d", total);
        }
    }

    for(int t=1; t < time; t++) {
        #pragma omp parallel for
        for(int j=1; j < N-1; j++) { // Not include boundary condition
            u_new[j] = u[j] + r*(u[j-1] - 2*u[j] + u[j+1]); // Explicit Method formula
        }
        #pragma omp parallel for
        for(int j=0; j < N; j++) { // But we need to show all positions
            u[j] = u_new[j];
        }

        u[0] = 0; // boundary condition
        u[N-1] = 0; // boundary condition
            
    }

    double end = omp_get_wtime();
    cout << fixed << setprecision(8);
    cout << "\nTotal time: " << end - start << " sec\n " << endl;

    return 0;
}


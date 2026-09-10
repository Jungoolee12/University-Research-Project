#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {

    ofstream file("2D_heat_exp.txt");

    const int N_x = 9; // because 2D included N x N matrix
    const int N_y = 9; // N^2
    int time = 10;

    double k = 0.1;
    double dx = 1.0;
    double dy = 1.0;
    double dt = 0.2;

    double r_x = k * dt / (dx * dx);
    double r_y = k * dt / (dy * dy);

    double u[N_x][N_y] = {0.0};
    double u_new[N_x][N_y] = {0.0};

    u[N_x/2][N_y/2] = 10.0; // Initial condition

    cout << "2D Explicit Method" << "\n";
    cout << "dt : " << dt;
    cout << endl;
        
    for(int t=0; t < time; t++) {
            
        for(int i=1; i < N_x-1; i++){ // Except boundary conditions
            for(int j=1; j < N_y-1; j++){
                u_new[i][j] = u[i][j] + r_x*(u[i-1][j] - 2*u[i][j] + u[i+1][j]) + r_y*(u[i][j-1] - 2*u[i][j] + u[i][j+1]);   
            } // 2D means x axis space + y axis space
        }

        for(int i=0; i < N_x; i++){
            for(int j=0; j < N_y; j++){
                u[i][j] = u_new[i][j];
            }
        }
        for(int i=0; i < N_x; i++){
        u[i][0] = 0; // boundary condition
        u[i][N_y-1] = 0; // vertical lines = 0
        }

        for(int j=0; j < N_y; j++){
        u[0][j] = 0; // boundary condition
        u[N_x-1][j] = 0; // horizon lines = 0 
        }

        cout << "\n" << "time " << t << " : ";
        cout << "\n";
            
    }

    for(int i=0; i < N_x; i++) {
        for(int j=0; j < N_y; j++) {
            file << fixed << setprecision(2) << u[i][j] << " ";
        }
    file << "\n";
    }
    return 0;
}
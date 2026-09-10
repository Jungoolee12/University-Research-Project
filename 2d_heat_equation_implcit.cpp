    #include <iostream>
    #include <cmath>
    #include <vector>
    #include <iomanip>

    using namespace std;

    // Use "Thomas Algorithm" or "Tridiagonal matrix algorithm"
    
    // a[j]*x[j-1] + b[j]*x[j] + c[j]*x[j+1] = d[j]
    
    void Thomas(int n , vector<double>& a, vector<double>& b, vector<double>& c, vector<double>&d, vector<double>& x) { 
        vector<double> c_new(n, 0.0); // we can use double because of a tiny unit
        vector<double> d_new(n, 0.0);
        // for the first line = b[0] * x[0] + c[0] * x[1] = d[0]
        c_new[0] = c[0] / b[0];
        d_new[0] = d[0] / b[0];

        // We need to iterations j = 1, 2, 3, ..., n
        // forward formula
        for(int j=1; j < n; j++) {
            double m = 1.0 / (b[j] - (a[j] * c_new[j-1]));

            c_new[j] = c[j] * m;
            d_new[j] = (d[j] - (a[j] * d_new[j-1])) * m;
        }

        // backward formula
        x[n-1] = d_new[n-1]; // Code needs to start zero x[0]
        for(int j=n-2; j>=0; j--) {
            x[j] = d_new[j] - c_new[j] * x[j+1];
        }

        
    }
    int main() {
        
        const int N = 9;
        int time = 10;

        double k = 0.1;
        double dt = 0.2; // time
        double dx = 1.0; //position

        double r = k * dt / (dx*dx);

        vector<double> u(N, 0.0);
        vector<double> x(N, 0.0); // u_new or u^n+1
        vector<double> a(N), b(N), c(N), d(N);

        u[N/2] = 10.0; // Initial condition

        cout << "Implicit Method" << "\n";
        cout << "dt : " << dt;
        cout << endl;

        for(int t=0; t< time ; t++) { // time
            
            // a[j]*x[j-1] + b[j]*x[j] + c[j]*x[j+1] = d[j] use this !
            // We have to make a system of equations! Then use the Thomas Algorithm to get the solution.
            
            for(int j=1; j<N-1; j++) { // space
                a[j] = -r;
                b[j] = (1+2*r);
                c[j] = -r;
                d[j] = u[j];
            }
            
            d[0] = 0.0; // boundary condition
            d[N-1] = 0.0; // boundary condition
            b[0] = 1.0; // To avoid nan
            b[N-1] = 1.0; // To avoid nan

        // To find the solution, use Thomas Algorithm, and iteration.
            Thomas(N, a, b, c, d, x);
            // x = u^n+1 (future)

            for(int j=1; j < N-1; j++) {
                u[j] = x[j];
            }
            cout << "\n" << "time " << t << " : ";

            for(int j=0; j<N; j++) {
                cout << fixed << setprecision(2) << u[j] << " ";
            }
        }
        return 0;
    }
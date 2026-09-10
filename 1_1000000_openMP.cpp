#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main() {
    
    long long sum = 0;
    int N = 1000000;
    

    double start = omp_get_wtime(); // checking camulative time

    #pragma omp parallel for reduction(+:sum) // Use openMP
    for(int total_sum = 1; total_sum <= N; total_sum++) {
        sum += total_sum; // sum = sum + next_sum
    }
    
    double end = omp_get_wtime();

    cout << fixed << setprecision(8);
    cout << "\nTotal_sum (1 to 1,000,000) : " << sum;
    cout << "\nTotal time : " << end-start << " sec";

    return 0;
}
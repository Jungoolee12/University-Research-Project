    #include <iostream>
    #include <omp.h>

    using namespace std;

    int assign_id_openMP() { // Assign number of id
        #pragma omp parallel
        {
        int ID = omp_get_thread_num(); // Use omp_get_thread_num !!
        int total = omp_get_num_threads();
        printf("Hello world --> Thread %d of %d \n", ID, total); // print Thread numbers in order of speed 
        }
        // This means, 16 Threads (In my computer CPU's) are printed simultaneously 1 time
        cout << "\n";
        return 0;
        

    }

    int no_assign_id_openMP() { // remove number of id
        #pragma omp parallel
        {
        printf("Hello world --> ?? \n");
        }
        return 0;
    }
    int main() {
        assign_id_openMP();
        no_assign_id_openMP();
        printf("\nThe first case states that we can mark off each thread to use ID (Therefore, we can find some position of error), \n but the second case can't mark off each thread");
        return 0;
    }
#include <mpi.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    // Initialize MPI.
    int my_rank, num_procs;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    cout << "my_rank = " << my_rank << endl;

    MPI_Finalize();
    return 0;
}


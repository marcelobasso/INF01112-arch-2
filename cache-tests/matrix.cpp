#include "constants.h"

// -----------------------------------------------------------------------
// Um algoritmo de processamento de matrizes (como multiplicação)
// -----------------------------------------------------------------------

void mulMat(int mat1[][C1], int mat2[][C2]) {
    int rslt[R1][C2];

    cout << "Multiplication of given two matrices is:\n";

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < R2; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }

            cout << rslt[i][j] << "\t";
        }

        cout << endl;
    }
}

int main () {
    // populate matrix and run multiplication

    return 0;
}
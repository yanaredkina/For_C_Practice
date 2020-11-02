#include "matrix.h"

int main() {
    matrix A(3,4);
    A.set_elem(2, 2, 1.5);
    A.set_elem(1, 3, 2.5);
    cout << A << endl;
    cout << A[2] << endl;
    cout << A[3] << endl;
    char B_str[] = "{{1.1, 0, -5.5}, {2.3, 1, -0.5}, {1.4, 2.5, -9.3}}";
    matrix B(B_str);
    cout << B << endl;
}
#include "matrix.h"

int main() {
    
    cout << "\n ------------------- TESTING MATRIX-CLASS CONSTRUCTORS ------------------- \n" << endl;
    
    matrix M1;
    cout << "matrix M1 by default constructor: \n" << M1 << endl;
    
    matrix M2(3, 4);
    cout << "matrix M2 by constructor with size (3x4): \n" << M2 << endl;
    
    matrix M3(25.5);
    cout << "matrix M3 by constructor (1x1) with input value (25.5): \n" << M3 << endl;
    
    double mas[] = {1, 3, 5, 7};
    matrix M4(mas, 4);
    cout << "matrix M4 by matrix-row constructor (array:{1, 3, 5, 7}): \n" << M4 << endl;
    
    matrix M5(4, mas);
    cout << "matrix M5 by matrix-column constructor (array:{1, 3, 5, 7}): \n" << M5 << endl;
    
    char str[] = "{{1.1, 0, -5.5}, {2.3, 1, -0.5}, {1.4, 2.5, -9.3}}";
    matrix M6(str);
    cout << "matrix M6 by string-constructor (str:{{1.1, 0, -5.5}, {2.3, 1, -0.5}, {1.4, 2.5, -9.3}}): \n" << M6 << endl;
    
    matrix M7(M4);
    cout << "matrix M7 by copy-constructor (M4): \n" << M7 << endl;
    
    cout << "\n ---------------------- TESTING MATRIX-CLASS METHODS --------------------- \n" << endl;
    
    matrix M8 =  matrix::identity(4);
    cout << "creating identity matrix M8 (n=4): \n" << M8 << endl;
    
    matrix M9 =  matrix::diagonal(mas, 4);
    cout << "creating diagonal matrix M9 (values: {1, 3, 5, 7}, n=4): \n" << M9 << endl;
    
    cout << "get number of rows and columns from M8: \n" << M8.get_rows() << ", " << M8.get_columns() << '\n' << endl;
    
    M9.set_elem(0, 3, 15);
    M9.set_elem(1, 2, 15);
    M9.set_elem(2, 1, 15);
    M9.set_elem(3, 0, 15);
    cout << "setting side diagonal of matrix M9 (value=15): \n" << M9 << endl;
    
    
    cout << "\n --------------------- TESTING MATRIX-CLASS OPERATORS --------------------- \n" << endl;
    
    M8 = M9;
    cout << "identity matrix M8 after assignment operator M8 = M9: \n" << M8 << endl;
    
    M8 = M9 * 2;
    cout << "scalar multiplication (M8 = М9 * 2): \n" << "M8: \n" << M8 << "M9: \n" << M9 << endl;
    
    M9 *= 3;
    cout << "scalar multiplication (M9 *= 3): \n" << M9 << endl;
    
    matrix M10(2, 3);
    M10.set_elem(0, 0, 1.2);
    M10.set_elem(0, 1, 2.3);
    M10.set_elem(0, 2, 3.4);
    M10.set_elem(1, 0, 5.6);
    M10.set_elem(1, 1, 7.8);
    M10.set_elem(1, 2, 9.0);
    
    cout << "Some new matrix M10: \n" << M10 << endl;
    cout << "creation matrix-row from M10[1] (row number = 1): \n" << M10[1] << endl;
    cout << "creation matrix-number from M10[2] (column number = 2): \n" << M10[2] << endl;
    
    cout << "\n --------------------- TESTING EXCEPTIONS AND ERRORS --------------------- \n" << endl;
    
    try {
        cout << "trying creation matrix err1(5, -2) with negative number of columns:" << endl;
        matrix err1(5, -2);
        cout << "error matrix was created" << endl;
    } catch (matrix::matrix_error& e) {
        cout << "ERROR " << e.get_message() << '\n' <<endl;
    }
    
    try {
        cout << "trying to set a value in (i,j)-element, that out of range of matrix:" << endl;
        M10.set_elem(5, 10, 5);
        cout << "value was assigned to not exist element" << endl;
    } catch (matrix::matrix_error& e) {
        cout << "ERROR " << e.get_message() << '\n' << endl;
    }
    
    try {
        cout << "trying to assign matrix of different sizes ( M10(2x3) = M9(4x4) ):" << endl;
        M10 = M9;
        cout << "matrix was successful assigned" << endl;
    } catch (matrix::matrix_error& e) {
        cout << "ERROR " << e.get_message() << '\n' << endl;
    }
    
    try {
        cout << "trying to copy matrix-column from matrix M10 (2x3) with i = 4):" << endl;
        M10[4];
        cout << "matrix was successful copied" << endl;
    } catch (matrix::matrix_error& e) {
        cout << "ERROR " << e.get_message() << '\n' << endl;
    }
}
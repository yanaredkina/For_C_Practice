/* VVO-2course - Redkina Yana - TASK "Abstract data type" - Variant 4.1 (matrix) */

#include <iomanip>
#include <iostream>
#include "matrix.h"

using namespace std;

matrix::matrix_error::matrix_error(string message) {
    this->message = message;
}

string matrix::matrix_error::get_message() {
    return this->message;
}

/* default constructor */
matrix::matrix() {
    matrix(0.0);
}

/* constructor by size of matrix */
matrix::matrix(int n, int m) {
    if (n < 0) {
        throw matrix_error("number of rows out of range");
    }
    if (m < 0) {
        throw matrix_error("number of columns out of range");
    }
    
    this->rows = n;
    this->columns = m;
    
    this->mtrx = new double*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->mtrx[i] = new double[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->mtrx[i][j] = 0.0;
        }
    }
}

/* constructor 1x1 by input value*/
matrix::matrix(double val) {
    this->rows = 1;
    this->columns = 1;
    this->mtrx = new double*[this->rows];
    this->mtrx[0] = new double[this->columns];
    this->mtrx[0][0] = val;
}

/* matrix-row constructor */
matrix::matrix(double* mas, int m) {
    if (m < 0) {
        throw matrix_error("number of columns out of range");
    }
    this->rows = 1;
    this->columns = m;
    
    this->mtrx = new double*[this->rows];
    this->mtrx[0] = new double[this->columns];
    
    for (int j = 0; j < this->columns; j++) {
        this->mtrx[0][j] = mas[j];
    }
}

/* matrix-column constructor */
matrix::matrix(int n, double* mas) {
    if (n < 0) {
        throw matrix_error("number of rows out of range");
    }
    this->rows = n;
    this->columns = 1;
    
    this->mtrx = new double*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->mtrx[i] = new double[this->columns];
        this->mtrx[i][0] = mas[i];
    }
}
    
/* copy constructor */
matrix::matrix(const matrix& m) {
    this->rows = m.get_rows();
    this->columns = m.get_columns();
    
    this->mtrx = new double * [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->mtrx[i] = new double[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->mtrx[i][j] = m.get_elem(i,j);
        }
    }
}
    
/* constructor by string*/
matrix::matrix(char * str_mtrx) {
    int count_bracket = 0;
    int count_comma = 0;
    for (int i = 0; str_mtrx[i] != '\0'; i++) {
        if (str_mtrx[i] == '{' or str_mtrx[i] == '}') {
            count_bracket++;
        } else if (str_mtrx[i] == ',') {
            count_comma++;
        }
    }
    
    int count_of_rows = (count_bracket - 2) / 2;
    int count_of_columns = (count_comma - count_of_rows + 1) / count_of_rows + 1;
    
    this->rows = count_of_rows;
    this->columns = count_of_columns;
    
    this->mtrx = new double*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->mtrx[i] = new double[this->columns];
    }
    
    
    int k = 0;
    for (int i = 0; i < count_of_rows; i++) {
        for (int j = 0; j < count_of_columns; j++) {
            enum number {int_part, frac_part};
            enum number state = int_part;
            int ip = 0;
            double fp = 0.0;
            char sign = '+';
            double number = 0;

            int count_fp = 10;
            for (; (str_mtrx[k] != ',') && (str_mtrx[k] != '}'); k++) {
                switch(str_mtrx[k]) {
                    case '{': 
                        break;
                    case '.' : 
                        state = frac_part; 
                        break;
                    case '-': 
                        sign = '-';
                        break;
                    case '+':
                        sign = '+';
                        break;
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        if (state == int_part) {
                            ip = ip * 10 + (str_mtrx[k] - '0');
                        } else if (state == frac_part) {
                            fp = fp + (double)(str_mtrx[k] - '0') / count_fp ;
                            count_fp *= 10;
                        } 
                        break;
                }
            }
            if (sign == '-') {
                number = (ip + fp) * -1;
            } else {
                number = (ip + fp);
            }
            if (str_mtrx[++k] == ',') {
                k++;
            } else {
                k++;
            }
            this->mtrx[i][j] = number;
        }
    }
}

/* destructor*/
matrix::~matrix() {
    if (this->mtrx == NULL) {
        return;
    }
    for (int i = 0; i < this->rows; i++) {
        delete[] this->mtrx[i];
    }
    delete[] this->mtrx;
} 

/* creation identity matrix*/
matrix matrix::identity(int n) {
    if (n < 0) {
        throw matrix_error("number of rows out of range");
    }
    matrix res(n, n);
    for (int i = 0; i < n; i++) {
        res.set_elem(i, i, 1);
    }
    return res;
}

/* creation diagonal matrix*/
matrix matrix::diagonal(double* vals, int n) {
    if (n < 0) {
        throw matrix_error("number of rows out of range");
    }
    matrix res(n, n);
    for (int i = 0; i < n; i++) {
        res.set_elem(i, i, vals[i]);
    }
    return res;
}

int matrix::get_rows() const {
    return this->rows;
}

int matrix::get_columns() const {
    return this->columns;
}

double matrix::get_elem(int i, int j) const {
    if (i < 0 || i >= this->rows) {
        throw matrix_error("number of rows out of range");
    }
    if (j < 0 || j >= this->columns) {
        throw matrix_error("number of columns out of range");
    }
    return this->mtrx[i][j];
}

void matrix::set_elem(int i, int j, double val) {
    if (i < 0 || i >= this->rows) {
        throw matrix_error("number of rows out of range");
    }
    if (j < 0 || j >= this->columns) {
        throw matrix_error("number of columns out of range");
    }
    this->mtrx[i][j] = val;
}
 
matrix& matrix::operator=(const matrix& m) {
    if (m.get_rows() != this->rows || m.get_columns() != this->columns) {
        throw matrix_error("matrices of different sizes");
    }
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            this->mtrx[i][j] = m.get_elem(i, j);
        }
    }
    return *this;
}
   
matrix matrix::operator*(double scalar) {
    matrix res(*this);
    res *= scalar;
    return res;
}

matrix& matrix::operator*=(double scalar) {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            this->mtrx[i][j] *= scalar;
        }
    }
    return *this;
}

matrix matrix::operator[](int i) {
    if (i < 0) {
        throw matrix_error("number of rows out of range");
    }
    if (i < this->rows) {
        matrix i_copy(this->mtrx[i], this->columns);
        return i_copy;
    } else if (i < this->columns) {
        matrix i_copy(this->rows, 1);
        for (int j = 0; j < this->rows; j++) {
            i_copy.set_elem(j, 0, this->mtrx[j][i]);
        }
        return i_copy;
    }
    throw  matrix_error("sizes out of range");
}

ostream& operator<<(ostream& os, const matrix& m) {
    os << " | ";
    for (int i = 0; i < m.get_rows(); i++) {
        for (int j = 0; j < m.get_columns(); j++) {
            os << setw(5) << m.get_elem(i, j);
            if (j < m.get_columns() - 1) {
                os << ", ";
            }
        }
        os << " |\n";
        if (i < m.get_rows() - 1) {
            os << " | ";
        }
   }
   return os;
}
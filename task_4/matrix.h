/* VVO-2course - Redkina Yana - TASK "Abstract data type" - Variant 4.1 (matrix) */

#include <iostream>

using namespace std;

class matrix {
private:
    double** mtrx;
    int rows;
    int columns;
public:
    class matrix_error {
    private:
        string message;
    public:
        matrix_error(string message);

        string get_message();
    };

    /* default constructor */
    matrix();

    /* constructor by size of matrix */
    matrix(int n, int m);
    
    /* constructor 1x1 by input value*/
    matrix(double val);
    
    /* matrix-row constructor */
    matrix(double* mas, int m);
    
    /* matrix-column constructor */
    matrix(int n, double* mas);
        
    /* copy constructor */
    matrix(const matrix& m);
  
    /* constructor by string*/
    matrix(char* str_mtrx);
    
    /* destructor*/
    ~matrix();

    /* creation identity matrix*/
    static matrix identity(int n);
    
    /* creation diagonal matrix*/
    static matrix diagonal(double* vals, int n);

    /* getters (description out of class) */
    int get_rows() const;
    int get_columns() const;
    double get_elem(int i, int j) const;
    
    /* setter (description out of class) */
    void set_elem(int i, int j, double val);
    
    /* operator = (description out of class) */
    matrix & operator=(const matrix& m);
    
    /* operator *scalar (description out of class)*/
    matrix operator*(double scalar);
    
    /* operator *=scalar (description out of class)*/
    matrix & operator*=(double scalar);
    
    /* operator [] (description out of class)*/
    matrix operator[](int i);
};

ostream& operator<<(ostream& os, const matrix& m);
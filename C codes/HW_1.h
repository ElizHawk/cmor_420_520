typedef struct {
    int rows;
    int columns;
    double** data;
} MyMatrix;

double** construct_MyMatrix(int rows, int columns);
void set_data(MyMatrix Mat);
void free_MyMatrix(double** data);
void matmul(MyMatrix* C, const MyMatrix A, const MyMatrix B);
void reshape(int new_rows, int new_columns, MyMatrix* Mat);

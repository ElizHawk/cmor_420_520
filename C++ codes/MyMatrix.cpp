#include <cstdio>
#include <iostream>

class MyMatrix{
    public:
    double** data;
    int rows;
    int columns;

    void set_data(int n);

    MyMatrix(){}

    MyMatrix(int rows, int columns){
        rows =rows;
        columns=columns;

        double ** data = new double* [rows];
        data[0] = new double [rows * columns ];
        for (int i = 1; i < rows; ++i) {
            data[i] = data[0] + columns * i;
        }
    }

    MyMatrix(MyMatrix & copy_from){
        rows=copy_from.rows;
        columns=copy_from.columns;

        double ** data = new double* [rows];
        data[0] = new double [rows * columns];
        for (int i = 1; i < rows; ++i) {
            data[i] = data[0] + columns * i;
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                data[i][j]= copy_from.data[i][j];
            }  
        }  
    }

    MyMatrix & operator=(MyMatrix & copy_from){
        this->rows=copy_from.rows;
        this->columns=copy_from.columns;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                this->data[i][j]= copy_from.data[i][j];
            }  
        } 
        return *this;
    }

    MyMatrix & operator+=(MyMatrix & A);
    MyMatrix & operator-=(MyMatrix & A);
    //MyMatrix operator+(MyMatrix& B);
    //MyMatrix operator-(MyMatrix B);
    //MyMatrix operator*(MyMatrix& B);

    //MyMatrix operator*(double a);
    //MyMatrix operator+(double a);
    //MyMatrix operator-(double a);
   // MyMatrix operator/(double a);
    MyMatrix & operator+=(double a);
    MyMatrix & operator-=(double a);

    ~MyMatrix(){
        delete(data[0]);
        delete(data); 
    }
};

void MyMatrix::set_data(int n){
    if (n==0){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; j++) {
                data[i][j] = (double) (i * columns + j+1);
                printf("%.1f ", data[i][j]);
        }
        printf("\n");
        }
        printf("\n");
    }
    if (n==1){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; j++) {
                data[i][j] = (double) (rows - i * columns + j);
                printf("%.1f ", data[i][j]);
        }
        printf("\n");
        }
        printf("\n");
    }
    if (n==2){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; j++) {
                data[i][j] = (double) (i * columns + j+1)-(2);
                printf("%.1f ", data[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
}

MyMatrix & MyMatrix::operator+=(MyMatrix & A){
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            this->data[i][j]+=A.data[i][j];
        }
    }
    return *this;  
}
MyMatrix & MyMatrix::operator-=(MyMatrix & A){
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            this->data[i][j]-=A.data[i][j];
        }
    }  
    return *this;
}
MyMatrix & MyMatrix::operator+=(double a){
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            this->data[i][j]=data[i][j]+a;
        }
    }
    return *this;
}
MyMatrix & MyMatrix::operator-=(double a){
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            this->data[i][j]=data[i][j]-a;
        }
    }
    return *this;
}

MyMatrix operator+(MyMatrix & A, MyMatrix & B){
    MyMatrix C(B.rows, B.columns);
    for (int i = 0; i < C.rows; i++)
    {
        for (int j = 0; j < C.columns; j++)
        {
            C.data[i][j]=A.data[i][j]+B.data[i][j];
        }
    }
    return C;  
};
MyMatrix operator-(MyMatrix & A, MyMatrix & B){
    MyMatrix C(B.rows, B.columns);
    for (int i = 0; i < C.rows; i++)
    {
        for (int j = 0; j < C.columns; j++)
        {
            C.data[i][j]=A.data[i][j]-B.data[i][j];
        }
    }
    return C;  
};
MyMatrix operator/(MyMatrix & A,double a){
    MyMatrix C(A.rows, A.columns);
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.columns; j++)
        {
            C.data[i][j]=A.data[i][j]/a;
        }
    }
    return C;
};
MyMatrix operator*(double a, MyMatrix & A){
    MyMatrix C(A.rows, A.columns);
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.columns; j++)
        {
            C.data[i][j]=a*A.data[i][j];
        }
    }
    return C;
};
MyMatrix operator*(MyMatrix & A, MyMatrix & B){
    MyMatrix C(A.rows,B.columns);

    for (int i = 0; i < C.rows; ++i) {
        for (int j = 0; j < C.columns; j++) {
            C.data[i][j]= (double) 0;
            printf("%.1f ",C.data[i][j]);
    }
    printf("\n");
    }
    printf("\n");

    for (int i = 0; i < C.rows; ++i) {
        for (int j = 0; j < C.columns; ++j) {
            for (int k=0; k < A.columns; ++k){
                C.data[i][j] += A.data[i][k]* B.data[k][j];
            }
    }
    }

    for (int i = 0; i < C.rows; ++i) {
        for (int j = 0; j < C.columns; j++) {
            printf("%.1f ",C.data[i][j]);
    }
    printf("\n");
    }
    printf("\n");
    return C;
};
MyMatrix operator+(MyMatrix & A, double a){
    MyMatrix C(A.rows, A.columns);
    for (int i = 0; i < C.rows; i++)
    {
        for (int j = 0; j < C.columns; j++)
        {
            C.data[i][j]=A.data[i][j]+a;
        }
    }
    return C;  
};
MyMatrix operator-(MyMatrix & A, double a){
    MyMatrix C(A.rows, A.columns);
    for (int i = 0; i < C.rows; i++)
    {
        for (int j = 0; j < C.columns; j++)
        {
            C.data[i][j]=A.data[i][j]-a;
        }
    }
    return C;  
};


class MyVector: public MyMatrix{
    MyVector(int rows): MyMatrix(rows, 1){}
};
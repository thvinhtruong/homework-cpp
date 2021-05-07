#include <iostream>

using namespace std;

template <class T>
class Matrix {
    private:
        int row, col;
        T **mtr;
    public:
        Matrix(){}
        Matrix(int row, int col): row(row), col(col) {
            mtr = new T*[row];
            for (int i=0; i<row; i++) {
                mtr[i] = new int[col];
            }
        }
        ~Matrix();

        int getRow() {
            return this->row; 
        }

        int getCol() {
            return this->col;
        }

        void Post();
        void Get();
        void Transpose();
        void Dot(Matrix another);
        T TotalNorm();
};

template <class T>
void Matrix<T>::Post() {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            T input;
            cout << "element[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> input;
            *(*(mtr + i) + j) = input;
        }
    }
}

template <class T>
Matrix<T>::~Matrix(){
	for (int i = 0; i<row; i++){
        delete []*(mtr + i);
	}
    delete []mtr;
}

template <class T>
void Matrix<T>::Get() {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            T element = *(*(mtr + i) + j);
            printf("%d\t", element);
            if (j == col - 1) {
                printf("\n");
            }
        }
    }
}

template <class T>
void Matrix<T>::Transpose() {
    Matrix res(this->col, this->row);
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            res.mtr[i][j] = this->mtr[j][i];
        }
    }
    res.Get();
}

template <class T>
void Matrix<T>::Dot(Matrix another) {
    Matrix res(this->row, another.col);
    if (this->col != another.row) {
        cout << "Can't dot" << endl;
    } else {
        for (int i=0; i<this->row; i++) {
            for (int j=0; j<another.col; j++) {
                for (int k=0; k<this->col; k++) {
                    res.mtr[i][j] += mtr[i][k] * another.mtr[k][j];
                }
            }
        }
        res.Get();
    }
}

int main() {
    Matrix<int> m1(2, 2);
    Matrix<int> m2(2, 2);
    m1.Post();
    m1.Get();
    putchar('\n');
    //m1.Transpose();
    m2.Post();
    m1.Dot(m2);
}
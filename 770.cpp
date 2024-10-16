/*
Se dă o matrice cu n linii și m coloane și elemente numere naturale. Să se permute coloanele matricei circular spre stânga cu o poziție.
*/

#include <iostream>
using namespace std;

template <typename T>
class Matrix{
public:
    Matrix() = default;
    Matrix(size_t rows, size_t columns) : m_Rows(rows), m_Columns(columns){
        m_Data = new T*[rows];
        for(size_t i = 0; i < rows; i++)
            m_Data[i] = new T[columns];
    }
    ~Matrix(){
        for(size_t i = 0; i < m_Rows; i++)
            delete[] m_Data[i];
        delete[] m_Data;
    }
    
    T& Get(size_t row, size_t column){
        return m_Data[row][column];
    }
    
    size_t Rows() {return m_Rows;}
    size_t Columns() {return m_Columns;}
    
    T* GetRow(size_t row){
        if(row < m_Rows) return nullptr;
        T* vec = new T[m_Columns];
        for(size_t i = 0; i < m_Columns; i++)
            vec[i] = m_Data[row][i];
        return vec;
    }
    
    T* GetColumn(size_t column){
        if(column < m_Columns) return nullptr;
        T* vec = new T[m_Rows];
        for(size_t i = 0; i < m_Rows; i++)
            vec[i] = m_Data[i][column];
        return vec;
        
    }
    
    void Print(){
        for(size_t row = 0; row < m_Rows; row++){
            for(size_t column = 0; column < m_Columns; column++)
                cout << m_Data[row][column] << ' ';
            cout << '\n';
        }
    }

private:
    T** m_Data;
    size_t m_Rows, m_Columns;
    
};



int main(){    
    size_t n,m;
    cin >> n >> m;
    Matrix<long long> matrix(n, m);
    
    for(size_t row = 0; row < matrix.Rows(); row++)
        for(size_t column = 0; column < matrix.Columns(); column++)
        cin >> matrix.Get(row, column);
    
    
    
    long long firstElement;
    
    for(size_t row = 0; row < matrix.Rows(); row++){
        firstElement = matrix.Get(row, 0);
        for(size_t i = 0; i < matrix.Columns() - 1; i++)
            matrix.Get(row, i) = matrix.Get(row, i + 1);
        matrix.Get(row, matrix.Columns() - 1) = firstElement;
    }
    
    matrix.Print();
    
    return 0;
}

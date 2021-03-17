#pragma once
#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;
class Matrix
{
private:
    int n, m, x;
    char** arr;
    char* ms;
public:
    Matrix()
    {
        n = m = 1; arr = new char* [n];
        for (int i = 0; i < 1; i++)
        {
            arr[i] = new char[m];
        };
        n = 1;
        ms = new char[x];
    }
    Matrix(int n_size, int m_size)
    {
        n = n_size; m = m_size; arr = new char* [n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new char[m];
        };
        ms = new char[x];
    }
    Matrix(const Matrix& other)
    {
        this->m = other.m;
        this->n = other.n;
        this->arr = new char* [other.n];
        for (int i = 0; i < other.n; i++)
        {
            this->arr[i] = new char[m];
        };
        for (int i = 0; i < other.n; i++)
        {
            for (int j = 0; j < other.m; j++)
            {
                this->arr[i][j] = other.arr[i][j];
            }
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < n; i++)
            delete[]arr[i];
        delete[]arr;
    }
    void show()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
        for (int g = 0; g < n; g++)
        {
            std::cout << ms[g] << " ";
        }
    }
    void setMatrix(int str, int stb, char** mtr,char* mas,int kol)
    {
        this->m = stb;
        this->n = str;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                this->arr[x][y] = mtr[x][y];
            }
        }
        this->x = kol;
        for (int a = 0; a < x; a++) 
        {
            this->ms[a] = mas[a];
        }
    }
    friend ostream& operator<<(ostream& out, const Matrix& matrix);
    char operator[](int index)
    {
        return ms[index];
    }
    char& operator()(int str1, int stb1)
    {
        return arr[str1][stb1];
    }

};

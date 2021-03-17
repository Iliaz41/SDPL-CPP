#include "lab3.h" 

ostream& operator<<(ostream& out, const Matrix& matrix)
{
    for (int i = 0; i < matrix.n; i++)
    {
        for (int j = 0; j < matrix.m; j++)
        {
            out << matrix.arr[i][j] << " ";
        }
        out << endl;
    }
    return out;
}


int main()
{
    int str, stb;
    char** mtr;
    char* mas;
    int kol;
    cout << "Vvedite kol-vo strok matrizy" << endl;
    cin >> str;
    cout << "Vvedite kol-vo stolbcov matrizy" << endl;
    cin >> stb;
    mtr = new char* [str];
    for (int i = 0; i < str; i++)
    {
        mtr[i] = new char[stb];
    }
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < stb; j++)
        {
            cout << "Vvedite element matrizy" << endl;
            cin >> mtr[i][j];
        }
    }
    cout << "Vvedite kol-vo elementov stroki" << endl;
    cin >> kol;
    mas = new char[kol];
    for (int z = 0; z < kol; z++)
    {
        cout << "Vvedite element stroki" << endl;
        cin >> mas[z];
    }
    cout << "\n" << endl;;
    Matrix matrix(str, stb);
    matrix.setMatrix(str, stb, mtr, mas, kol);
    matrix.show();
    cout << "----------------------------------------------" << endl;
    cout << matrix(1, 2) << "\n";
    cout << "----------------------------------------------" << endl;
    cout << "----------------------------------------------" << endl;
    cout << matrix[1]<<"\n";
    cout << "----------------------------------------------" << endl;
    Matrix matrixcopy(matrix);
    cout << matrixcopy;
    matrix.~Matrix();
    matrixcopy.~Matrix();
    for (int i = 0; i < str; i++)
        delete[]mtr[i];
    delete[]mtr;
    system("Pause");
    return 0;
}
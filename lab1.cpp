#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	system("color 5F");
    int a[12] = { 1,2,2,20,3,4,5,888,1,9,8,7 };
    int b[7] = { 0,2,3,5,20,888,7 };
    int c[6];
    bool flag;
    for (int j = 0, k = 0; j < 11; j++)
    {
        for (int i = 0; i < 7; i++)
            if (a[j] == b[i])
            {
                flag = true;
                for (int l = 0; l < k; l++)
                {
                    if (c[l] == a[j])
                    {
                        flag = false;
                    }
                }
                if (flag)
                {
                    cout <<setw(18)<<setfill('*')<< a[j]<<endl;
                    c[k++] = a[j];
                }
            }
    }
	return 0;
}
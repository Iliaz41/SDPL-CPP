#include"lab6.h"
template<typename T>
ostream& operator << (ostream& out, dynamic_array<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        out << a[i] << " ";
    return out;
}

int main()
{
    int size, num;
    char* ms;
    cout << "Input size: ";
    cin >> size;
    ms = new char[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Input element of array [" << i << "]: ";
        cin >> ms[i];
    }
    dynamic_array<char> arr(size, ms);
    cout << "\n" << arr << endl;
    cout << "Input index for search: ";
    cin >> num;
    cout << "[" << num << "] " << arr[num] << endl;
    cout << "Input element for search : " ;
    int element;
    cin >> element;
  /*  num = arr.search(element);
    cout << "Index : ";
    cout << num << endl;*/
    cout << "Input index for del : ";
    int index;
    cin >> index;
    arr.Del(index);
    cout << arr;
    return 0;
}
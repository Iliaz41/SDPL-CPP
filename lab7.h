#pragma once
#include <iostream>

using namespace std;

class Error
{
private:
	int number;
public:
	Error()
	{
		number = 0;
	}
	Error(int n)
	{
		number = n;
	}
	void Print()
	{
		if (number == 1)
		{
			cout << "Map is empty" << endl;
		}
		if (number == 2)
		{
			cout << "Type : int" << endl;
		}
		if (number == 3)
		{
			cout << "Key is used" << endl;
		}
	}
};

template<typename T>
class Iterator
{
private:
	T* pointer;
public:
	Iterator()
	{
		pointer = nullptr;
	}
	Iterator(T* ms)
	{
		pointer = &ms[0];
	}
	~Iterator()
	{

	}
	Iterator operator+(int n)
	{
		return *(pointer + n);
	}
	Iterator operator++(int n)
	{
		return pointer++;
	}
	T operator*()
	{
		return *pointer;
	}
	bool operator!= (const Iterator& it)
	{
		return pointer != it.pointer;
	}
	Iterator end(int index, T* ms)
	{
		return &ms[index];
	}
	Iterator begin(T* ms)
	{
		pointer = &ms[0];
		return pointer;
	}
	friend ostream& operator<<(ostream& out, const Iterator<T>& it);
};

template<typename T>
ostream& operator<<(ostream& out, const Iterator<T>& it)
{
	out << *it;
	return out;
}

template <typename T>
class Map
{
private:
	int* key;
	T* str;
	int size;
public:
	Map()
	{
		key = 0;
		str = "Empty";
		size = 0;
	}
	Map(int* arrkey, T* arrstr, int index)
	{
		size = index;
		key = new int[size];
		str = new T[size];
		for (int i = 0; i < size; i++)
		{
			key[i] = arrkey[i];
			str[i] = arrstr[i];
		}
	}
	~Map()
	{
		delete[]key;
		delete[]str;
	}
	void Add(int elkey, T elstr)
	{
		int* BackupArrKey;
		T* BackupArrStr;
		BackupArrKey = new int[size];
		BackupArrStr = new T[size];
		for (int j = 0; j < size; j++)
		{
			BackupArrKey[j] = key[j];
			BackupArrStr[j] = str[j];
		}
		key = new int[size + 1];
		str = new T[size + 1];
		for (int y = 0; y < size; y++)
		{
			key[y] = BackupArrKey[y];
			str[y] = BackupArrStr[y];
		}
		key[size] = elkey;
		str[size] = elstr;
		size = size + 1;
		delete[]BackupArrKey;
		delete[]BackupArrStr;
	}
	void Del(int delkey)
	{
		try
		{
			if (size == 0)
			{
				throw 1;
			}
		}
		catch (int k)
		{
			Error er(k);
			er.Print();
			return;
		}
		int flag = 0;
		int* mskey;
		T* msstr;
		mskey = new int[size];
		msstr = new T[size];
		for (int z = 0; z < size; z++)
		{
			mskey[z] = key[z];
			msstr[z] = str[z];
		}
		for (int q = 0; q < size; q++)
		{
			if (mskey[q] == delkey)
			{
				flag = q;
			}
		}
		key = new int[size - 1];
		str = new T[size - 1];
		for (int w = 0; w < flag; w++)
		{
			key[w] = mskey[w];
			str[w] = msstr[w];
		}
		for (int r = flag + 1; r < size; r++)
		{
			key[r - 1] = mskey[r];
			str[r - 1] = msstr[r];
		}
		size = size - 1;
		delete[]mskey;
		delete[]msstr;
	}
	void Print()
	{
		for (int c = 0; c < size; c++)
		{
			cout << "Key :" << key[c] << " // " << "Value :" << str[c] << endl;
		}
	}
	void Search(int elsearch)
	{
		for (int k = 0; k < size; k++)
		{
			if (key[k] == elsearch)
			{
				cout << "Key :" << key[k] << " // " << "Value :" << str[k] << endl;
			}
		}
	}
	void Sort()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (key[j] > key[j + 1])
				{
					int m;
					T n;
					m = key[j];
					n = str[j];
					key[j] = key[j + 1];
					str[j] = str[j + 1];
					key[j + 1] = m;
					str[j + 1] = n;
				}
			}
		}
		for (int o = 0; o < size; o++)
		{
			cout << "Key :" << key[o] << " // " << "Value :" << str[o] << endl;
		}
	}
	friend class Iterator<T>;
	int* GetKey()
	{
		return key;
	}
	T* GetStr()
	{
		return str;
	}
};

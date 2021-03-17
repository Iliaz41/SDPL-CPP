#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Painter
{
private:
	string name;
	int year;
	string NameOfCountry;
	string direction;
	int amount;
public:
	Painter()
	{
		this->name = "Empty";
		this->year = 0;
		this->NameOfCountry = "Empty";
		this->direction = "Empty";
		this->amount = 0;
	}
	Painter(string _name, int _year, string _NameOfCountry, string _direction, int _amount)
	{
		this->name = _name;
		this->year = _year;
		this->NameOfCountry = _NameOfCountry;
		this->direction = _direction;
		this->amount = _amount;
	}
	~Painter()
	{

	}
	friend class File;
	friend ostream& operator<<(ostream& out, const Painter& painter);
};

ostream& operator<<(ostream& out, const Painter& painter)
{
	out << "Painter :" << painter.name << "\t" << painter.year << "\t" << painter.NameOfCountry << "\t" << painter.direction << "\t" << painter.amount << endl;
	return out;
}

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
		if (number == 4)
		{
			cout << "File is closed" << endl;
		}
	}
};

class Map
{
private:
	int* key;
	Painter* ms;
	int size;
public:
	Map()
	{
		size = 0;
	}
	~Map()
	{
		delete[]key;
		delete[]ms;
	}
	void Add(int elkey, Painter elstr)
	{
		size++;
		if (size == 1)
		{
			key = new int[size];
			ms = new Painter[size];
			for (int i = 0; i < size; i++)
			{
				key[i] = elkey;
				ms[i] = elstr;
			}
		}
		if (size != 1)
		{
			int* BackupKey;
			Painter* BackupPainter;
			BackupKey = new int[size];
			BackupPainter = new Painter[size];
			for (int i = 0; i < size - 1; i++)
			{
				BackupKey[i] = key[i];
				BackupPainter[i] = ms[i];
			}
			BackupKey[size - 1] = elkey;
			BackupPainter[size - 1] = elstr;
			key = new int[size];
			ms = new Painter[size];
			for (int i = 0; i < size; i++)
			{
				key[i] = BackupKey[i];
				ms[i] = BackupPainter[i];
			}
		}
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
		Painter* msstr;
		mskey = new int[size];
		msstr = new Painter[size];
		for (int z = 0; z < size; z++)
		{
			mskey[z] = key[z];
			msstr[z] = ms[z];
		}
		for (int q = 0; q < size; q++)
		{
			if (mskey[q] == delkey)
			{
				flag = q;
			}
		}
		key = new int[size - 1];
		ms = new Painter[size - 1];
		for (int w = 0; w < flag; w++)
		{
			key[w] = mskey[w];
			ms[w] = msstr[w];
		}
		for (int r = flag + 1; r < size; r++)
		{
			key[r - 1] = mskey[r];
			ms[r - 1] = msstr[r];
		}
		size = size - 1;
		delete[]mskey;
		delete[]msstr;
	}
	void Print()
	{
		for (int c = 0; c < size; c++)
		{
			cout << "Key :" << key[c] << " // " << "Value :" << ms[c] << endl;
		}
	}
	friend class Painter;
	int& operator[](const int index);
};

int& Map::operator[](const int index)
{
	return key[index];
}

class File
{
private:
	string Path;
public:
	File()
	{
		this->Path = "Empty";
	}
	File(string _Path)
	{
		this->Path = _Path;
	}
	~File()
	{

	}
	friend class Map;
	friend class Painter;
	void Sorting(int* arr, int n)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
			{
				int tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	void Alphabet(int index)
	{
		if (index == 1)
		{
			this->ReadBin();
			return;
		}
		fstream f(Path, ios_base::binary | ios_base::out | ios_base::in);
		try
		{
			if (!f.is_open())
			{
				throw 4;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return;
		}
		Painter* ms;
		ms = new Painter[index];
		for (int i = 0; i < index; i++)
		{
			f.read((char*)&ms[i], sizeof(ms[i]));
		}
		f.close();
		fstream f1(Path, ios_base::binary | ios_base::out | ios_base::trunc);
		try
		{
			if (!f1.is_open())
			{
				throw 4;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return;
		}
		f1.close();
		fstream f2(Path, ios_base::binary | ios_base::out);
		try
		{
			if (!f2.is_open())
			{
				throw 4;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return;
		}
		cout << "Sorting by alphabet :  " << endl;
		int k = 0;
		int m = 97;
		while (k < 4)
		{
			while (m < 123)
			{
				for (int i = 0; i < index; i++)
				{
					if (ms[i].name[k] == m)
					{
						this->WriteBin(ms[i]);
					}
				}
				m++;
			}
			k++;
		}
		this->ReadBin();
		f2.close();
		delete[] ms;
	}
	void SortAmount(int index)
	{
		if (index == 1)
		{
			this->ReadBin();
			return;
		}
		fstream f(Path, ios_base::binary | ios_base::out | ios_base::in);
		try
		{
			if (!f.is_open())
			{
				throw 4;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return;
		}
		int* m;
		m = new int[index];
		Painter* ms;
		ms = new Painter[index];
		int i = 0;
		for (int k = 0; k < index; k++)
		{
			f.read((char*)&ms[i], sizeof(ms[i]));
			m[i] = ms[i].amount;
			i++;
		}
		Sorting(m, index);
		f.close();
		fstream f1(Path, ios_base::binary | ios_base::out | ios_base::trunc);
		try
		{
			if (!f1.is_open())
			{
				throw 4;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return;
		}
		f1.close();
		fstream f2(Path, ios_base::binary | ios_base::out);
		try
		{
			if (!f2.is_open())
			{
				throw 4;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return;
		}
		cout << "Sorting by amount :  " << endl;
		for (int i = 0; i < index; i++)
		{
			for (int j = 0; j < index; j++)
			{
				if (ms[j].amount == m[i])
				{
					this->WriteBin(ms[j]);
				}
			}
		}
		this->ReadBin();
		f2.close();
		delete[] ms;
		delete[] m;
	}
	void Del(int index, int n, Map& m)
	{
		m.Del(index);
		fstream f(Path, ios_base::binary | ios_base::out | ios_base::in);
		try
		{
			if (!f.is_open())
			{
				throw 4;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return;
		}
		Painter* ms;
		ms = new Painter[n];
		for (int i = 0; i < n; i++)
		{
			f.read((char*)&ms[i], sizeof(ms[i]));
		}
		f.close();
		fstream f1(Path, ios_base::binary | ios_base::out | ios_base::trunc);
		f1.close();
		fstream f2(Path, ios_base::binary | ios_base::out);
		for (int i = 0; i < index; i++)
		{
			this->WriteBin(ms[i]);
		}
		for (int i = index + 1; i < n; i++)
		{
			this->WriteBin(ms[i]);
		}
		cout << "After deletion: " << endl;
		this->ReadBin();
		f2.close();
	}
	void Search()
	{
		fstream f(Path, ios_base::binary | ios_base::out | ios_base::in);
		try
		{
			if (!f.is_open())
			{
				throw 4;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return;
		}
		Painter ms[10];
		int i = 0;
		int y;
		while (!f.eof())
		{
			f.read((char*)&ms[i], sizeof(ms[i]));
			i++;
		}
		cout << "Enter year : ";
		try
		{
			cin >> y;
			if (cin.fail())
			{
				throw 2;
			}
		}
		catch (int k)
		{
			Error ex(k);
			ex.Print();
			return;
		}
		cout << "Result : " << endl;
		for (int j = 0; j < i + 1; j++)
		{
			if (ms[j].year == y)
			{
				cout << "____________________________________" << endl;
				cout << ms[j] << endl;
			}
		}
		f.close();
	}
	void BinText()
	{
		fstream f(Path, ios_base::in | ios_base::binary);
		try
		{
			if (!f.is_open())
			{
				throw 4;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return;
		}
		char* txt;
		txt = new char[10];
		f.read(txt, 10);
		int count = 0;
		for (int i = 0; i < 10; i++)
		{
			if (txt[i] >= 97 && txt[i] <= 122 || txt[i] >= 65 && txt[i] <= 90)
			{
				count++;
			}
		}
		for (int i = 0; i < count; i++)
		{
			cout << txt[i];
		}
		cout << endl;
		f.close();
	}
	void ReadText()
	{
		string msg;
		fstream f(Path, ios_base::in);
		try
		{
			if (!f.is_open())
			{
				throw 4;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return;
		}
		cout << "File :" << endl;
		while (!f.eof())
		{
			while (getline(f, msg))
			{
				cout << msg << endl;
			}
		}
		f.close();
	}
	void WriteText()
	{
		string msg;
		fstream f(Path, ios_base::out | ios_base::app);
		try
		{
			if (!f.is_open())
			{
				throw 4;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return;
		}
		cout << "Enter text : ";
		cin >> msg;
		f << msg << "\n";
		f.close();
	}
	void WriteBin(Painter p)
	{
		fstream f(Path, ios_base::binary | ios_base::out | ios_base::app);
		try
		{
			if (!f.is_open())
			{
				throw 4;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return;
		}
		f.write((char*)&p, sizeof(p));
		f.close();
	}
	void ReadBin()
	{
		Painter p;
		fstream f(Path, ios_base::binary | ios_base::out | ios_base::in);
		try
		{
			if (!f.is_open())
			{
				throw 4;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return;
		}
		while (f.read((char*)&p, sizeof(Painter)))
		{
			cout << p;
			cout << "___________________" << endl;
		}
		f.close();
	}
};

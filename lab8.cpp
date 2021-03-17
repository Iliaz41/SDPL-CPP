#include "Header.h"

int main()
{
	int* ms;
	Painter p;
	string* _name;
	int* _year;
	string* _NameOfCountry;
	string* _direction;
	int* _amount;
	int index, ch;
	string _Path;
	cout << "1-Binary file\n2-Text file" << endl;
	cin >> ch;
	if (ch == 1)
	{
		_Path = "1.bin";
		File f(_Path);
		cout << "Input size map :" << endl;
		try
		{
			cin >> index;
			if (cin.fail())
			{
				throw 2;
			}
		}
		catch (int i)
		{
			Error ex(i);
			ex.Print();
			return 0;
		}
		Map m;
		_year = new int[index];
		_name = new string[index];
		_NameOfCountry = new string[index];
		_direction = new string[index];
		_amount = new int[index];
		for (int i = 0; i < index; i++)
		{
			cout << "Input name :" << endl;
			cin >> _name[i];
			cout << "Input year :" << endl;
			try
			{
				cin >> _year[i];
				if (cin.fail())
				{
					throw 2;
				}
			}
			catch (int i)
			{
				Error ex(i);
				ex.Print();
				return 0;
			}
			cout << "Input country :" << endl;
			cin >> _NameOfCountry[i];
			cout << "Input direction :" << endl;
			cin >> _direction[i];
			cout << "Input amount :" << endl;
			try
			{
				cin >> _amount[i];
				if (cin.fail())
				{
					throw 2;
				}
			}
			catch (int i)
			{
				Error ex(i);
				ex.Print();
				return 0;
			}
			Painter p(_name[i], _year[i], _NameOfCountry[i], _direction[i], _amount[i]);
			m.Add(i, p);
			f.WriteBin(p);
		}
		cout << "\nRead the file - 1" << "\nSearch - 2" << "\nSort - 3" << "\nSort by alphabet - 4" << "\nDeletion - 5" << endl;
		cin >> ch;
		if (ch == 1)
		{
			f.ReadBin();
		}
		if (ch == 2)
		{
			f.Search();
		}
		if (ch == 3)
		{
			f.SortAmount(index);
		}
		if (ch == 4)
		{
			f.Alphabet(index);
		}
		if (ch == 5)
		{
			int in;
			cout << "Enter index of element for deletion: ";
			try
			{
				cin >> in;
				if (cin.fail())
				{
					throw 2;
				}
			}
			catch (int i)
			{
				Error ex(i);
				ex.Print();
				return 0;
			}
			f.Del(in, index, m);
		}
		delete[] _name;
		delete[] _year;
		delete[] _NameOfCountry;
		delete[] _direction;
		delete[] _amount;
	}
	if (ch == 2)
	{
		_Path = "2.txt";
		File f(_Path);
		f.WriteText();
		f.ReadText();
		cout << "As a binary : " << endl;
		f.BinText();
	}
	return 0;
}

#include "lab9.h"

using namespace ex;

int main()
{
	Fun f;
	map<int, Cars> m;
	Cars cars;
	int amount, _id, _mileage, key;
	string _name, _surname, _midname;
	cout << "Enter the number of car owners :" << endl;
	try
	{
		cin >> amount;
		if (cin.fail())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Ex err(i);
		err.Print();
		return 0;
	}
	for (int i = 0; i < amount; i++)
	{
		cout << "Enter key :" << endl;
		try
		{
			cin >> key;
			if (cin.fail())
			{
				throw 1;
			}
		}
		catch (int i)
		{
			Ex err(i);
			err.Print();
			return 0;
		}
		cout << "Enter id :" << endl;
		try
		{
			cin >> _id;
			if (cin.fail())
			{
				throw 1;
			}
		}
		catch (int i)
		{
			Ex err(i);
			err.Print();
			return 0;
		}
		cout << "Enter owner name :" << endl;
		cin >> _name;
		cout << "Enter owner surname :" << endl;
		cin >> _surname;
		cout << "Enter owner midname :" << endl;
		cin >> _midname;
		cout << "Enter mileage :" << endl;
		try
		{
			cin >> _mileage;
			if (cin.fail())
			{
				throw 1;
			}
		}
		catch (int i)
		{
			Ex err(i);
			err.Print();
			return 0;
		}
		Cars cars(_id, _name, _surname, _midname, _mileage);
		m.emplace(key, cars);
		cout << "!Added new owner!" << endl;
		system("pause");
		system("CLS");
	}
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << "Key :" << (*it).first << "\n" << "Value(" << (*it).second << ")" << endl;
	}
	cout << "Enter key for del :";
	int delkey;
	try
	{
		cin >> delkey;
		if (cin.fail())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Ex err(i);
		err.Print();
		return 0;
	}
	m.erase(delkey);
	cout << "Enter key for search :";
	int elkey;
	Cars num;
	try
	{
		cin >> elkey;
		if (cin.fail())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Ex err(i);
		err.Print();
		return 0;
	}
	num = m.operator[](elkey);
	cout << num << endl;
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << "Key :" << (*it).first << "\n" << "Value(" << (*it).second << ")" << endl;
	}
	int keyforfun2;
	cout << "Enter key(for verification fun2)" << endl;
	cin >> keyforfun2;
	f.Fun2(m,keyforfun2);
	f.Fun3(m);
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		cout << "Key :" << (*it).first << "\n" << "Value(" << (*it).second << ")" << endl;
	}
	f.Fun1();
	system("pause");
	return 0;
}
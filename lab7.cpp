#include "lab7.h"

int main()
{
	int index;
	int* arrkey;
	string* arrstr;
	cout << "Input index: ";
	try
	{
		cin >> index;
		if (cin.fail())
		{
			throw 2;
		}
	}
	catch (int k)
	{
		Error er(k);
		er.Print();
		return 0;
	}
	arrkey = new int[index];
	arrstr = new string[index];
	for (int i = 0; i < index; i++)
	{
		cout << "Input element of arrkey [" << i << "]: ";
		try
		{
			cin >> arrkey[i];
			if (cin.fail())
			{
				throw 2;
			}
		}
		catch (int k)
		{
			Error er(k);
			er.Print();
			return 0;
		}
		try
		{
			for (int k = 0; k < i; k++)
			{
				if (arrkey[i] == arrkey[k])
				{
					throw 3;
				}
			}
		}
		catch (int k)
		{
			Error er(k);
			er.Print();
			return 0;
		}
	}
	for (int i = 0; i < index; i++)
	{
		cout << "Input element of arrstr [" << i << "]: ";
		cin >> arrstr[i];
	}
	Map<string> instance(arrkey, arrstr, index);
	Iterator<int> it(arrkey);
	Iterator<string> it1(arrstr);
	while (it != it.end(index, arrkey) && it1 != it1.end(index, arrstr))
	{
		cout << "Key :" << *it << " // " << "Value :" << *it1 << endl;
		it++;
		it1++;
	}
	int  elkey;
	string elstr;
	cout << "Input element(key) :";
	try
	{
		cin >> elkey;
		for (int k = 0; k < index; k++)
		{
			if (arrkey[k] == elkey)
			{
				throw 3;
			}
		}
	}
	catch (int k)
	{
		Error er(k);
		er.Print();
		return 0;
	}
	cout << "Input element(str) :";
	cin >> elstr;
	instance.Add(elkey, elstr);
	arrkey = instance.GetKey();
	arrstr = instance.GetStr();
	it = it.begin(arrkey);
	it1 = it1.begin(arrstr);
	index = index + 1;
	while (it != it.end(index, arrkey) && it1 != it1.end(index, arrstr))
	{
		cout << "Key :" << *it << " // " << "Value :" << *it1 << endl;
		it++;
		it1++;
	}
	cout << "Input element(key) for del :";
	int delkey;
	cin >> delkey;
	instance.Del(delkey);
	arrkey = instance.GetKey();
	arrstr = instance.GetStr();
	it = it.begin(arrkey);
	it1 = it1.begin(arrstr);
	index = index - 1;
	while (it != it.end(index, arrkey) && it1 != it1.end(index, arrstr))
	{
		cout << "Key :" << *it << " // " << "Value :" << *it1 << endl;
		it++;
		it1++;
	}
	cout << "Input element(key) for search :";
	int elsearch;
	cin >> elsearch;
	instance.Search(elsearch);
	cout << "Sorting :" << endl;
	instance.Sort();
	return 0;
}
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

namespace ex
{
	class Ex
	{
	protected:
		int error;
	public:
		Ex()
		{
			error = 0;
		}
		Ex(int _error)
		{
			error = _error;
		}
		~Ex()
		{

		};
		void Print()
		{
			if (this->error == 1)
			{
				cout << "Enter int" << endl;
			}
			if (this->error == 2)
			{
				cout << "Opening error" << endl;
			}
		}
	};

	class Cars
	{
	private:
		int id;
		string name;
		string surname;
		string midname;
		int mileage;
	public:
		Cars()
		{
			this->id = 0;
			this->name = "Empty";
			this->surname = "Empty";
			this->midname = "Empty";
			this->mileage = 0;
		}
		Cars(int _id, string _name, string _surname, string _midname, int _mileage)
		{
			this->id = _id;
			this->name = _name;
			this->surname = _surname;
			this->midname = _midname;
			this->mileage = _mileage;
		}
		~Cars()
		{

		}
		friend ostream& operator<<(ostream& out, const Cars& cars);
	};

	ostream& operator<<(ostream& out, const Cars& cars)
	{
		out << "\tCars:";
		out << "\tid:" << cars.id;
		out << "\tName:" << cars.name;
		out << "\tSurname:" << cars.surname;
		out << "\tMidname:" << cars.midname;
		out << "\tMileage:" << cars.mileage;
		return out;
	}

	class Fun
	{
		public:
			void Fun1()
			{
				int sum = 0;
				char ms[200];
				for (int i = 0; i < 200; i++)
				{
					ms[i] = '*';
				}
				fstream f;
				char ch;
				char ms1[10];
				for (int j = 0; j < 10; j++)
				{
					ms1[j] = ' ';
				}
				f.open("psks.txt");
				try
				{
					if (!f.is_open())
					{
						throw 2;
					}
					cout << "File 1 is opened! " << endl;
				}
				catch (int i)
				{
					Ex err(i);
					err.Print();
					return;
				}
				cout << "File(1): " << endl;
				int j = 0;
				while (f.get(ch))
				{
					cout << ch;
					ms[j] = ch;
					j++;
				}
				for (int i = 0; i < 200; i++)
				{
					if (ms[i] == '*')
					{
						break;
					}
					if (ms[i] == ' ')
					{
						int k = 0;
						for (int j = i + 1; j < 200; j++)
						{
							ms1[k] = ms[j];
							k++;
							if (ms[j] == ' ')
							{
								break;
							}
						}
						int i = atoi(ms1);
						if (i > 0)
						{
							sum = sum + i;
						}
						for (int j = 0; j < 10; j++)
						{
							ms1[j] = ' ';
						}
						continue;
					}
				}
				cout << "\nSum=" << sum << endl;
				f.close();
				fstream f1;
				f1.open("ksps.txt");
				try
				{
					if (!f1.is_open())
					{
						throw 2;
					}
					cout << "File 2 is opened! " << endl;
				}
				catch (int i)
				{
					Ex err(i);
					err.Print();
					return;
				}
				f1 << sum;
				cout << "Writing to file was successful!" << endl;
				f1.close();
			}

			void Fun2(map<int, Cars>& m, int keyforfun2)
			{
				int num;
				num = keyforfun2;
				for (auto it = m.begin(); it != m.end(); ++it)
				{
					if ((*it).first == num)
					{
						cout << "Desired item :" << (*it).first << (*it).second << endl;
					}
				}
			}

			void Fun3(map<int, Cars>& m)
			{
				int x;
				auto it = m.begin();
				while (it != m.end())
				{
					if ((*it).first > 30)
					{
						x = (*it).first;
						m.erase(x);
						break;
					}
					it++;
				}
			}
	};
}

using namespace ex;
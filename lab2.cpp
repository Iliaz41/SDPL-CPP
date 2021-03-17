#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Cars
{
	private:
		string m_name;
		string m_fam;
		string m_ot;
		int m_id;
		int m_mileage;

	public:
		Cars() {};
		Cars(string name, int id, string fam, string ot)
		{
			m_id = id;
			m_name = name;
			m_mileage = 0;
			m_fam = fam;
			m_ot = ot;
		}
		~Cars() {} ;
		friend void print(Cars& cars);
		friend class STO;
};
void print(Cars& cars)
{
	cout << "Id: \t" << cars.m_id << endl;
	cout << "Name: \t" << cars.m_name << endl;
	cout << "Fam: \t" << cars.m_fam << endl;
	cout << "Ot: \t" << cars.m_ot << endl;
	cout << "Mileage: \t" << cars.m_mileage << endl;
}

class STO
{
	private:
		int m_mileage1;
	public:
		STO() {};
		STO(int mileage1) :m_mileage1(mileage1)
		{

		}
		~STO()
		{

		}
		void setMileage(Cars &cars)
		{
			cars.m_mileage = m_mileage1;
		}
};
int main()
{
	system("color 5F");
	bool fid = true;
	bool fname = true;
	bool ffam = true;
	bool fot = true;
	bool fmileage = true;
	int id, mileage;
	string name,fam,ot;
	do
	{
		cout << "Vvod id: ";
		cin >> id;
		if (cin.fail())
			cout << "error" << endl;
		else
			fid = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fid);
	do
	{
		cout << "Vvod name: ";
		cin >> name;
		if (cin.fail())
			cout << "error" << endl;
		else
			fname = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fname);
	do
	{
		cout << "Vvod fam: ";
		cin >> fam;
		if (cin.fail())
			cout << "error" << endl;
		else
			ffam = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (ffam);
	do
	{
		cout << "Vvod ot: ";
		cin >> ot;
		if (cin.fail())
			cout << "error" << endl;
		else
			fot = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fot);
	Cars cars(name, id, fam, ot);
	print(cars);
	do
	{
		cout << "Vvod mileage: ";
		cin >> mileage;
		if (cin.fail())
			cout << "error" << endl;
		else
			fmileage = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (fmileage);
	STO sto(mileage);
	sto.setMileage(cars);
	print(cars);
	Cars mas[3] = 
	{
		Cars("Petr",14,"Ivanov","Semenovich"),
		Cars("Anton",856,"Petrov","Ivanovich"),
		Cars("Andrey",777,"Semenov","Petrovich"),
	};
	for (int i = 0; i < 3; i++)
	{
		print(mas[i]);
	}
	STO ms[3] =
	{
		STO(120000),
		STO(300000),
		STO(10000),
	};
	for (int i = 0; i < 3; i++)
	{
		ms[i].setMileage(mas[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		print(mas[i]);
	}
	return 0;
}
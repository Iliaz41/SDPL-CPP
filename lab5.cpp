#include "lab5.h"

int main()
{
	string Gname, Mname, Vname, MEname, Sname;
	int m_num, m_max, m_min;
	cout << "input garnish :" << endl;
	cin >> Gname;
	cout << "=====================================" << endl;
	cout << "input main dish :" << endl;
	cin >> Mname;
	cout << "=====================================" << endl;
	cout << "input vegetables :" << endl;
	cin >> Vname;
	cout << "=====================================" << endl;
	cout << "input num :" << endl;
	cin >> m_num;
	cout << "=====================================" << endl;
	cout << "input max :" << endl;
	cin >> m_max;
	cout << "=====================================" << endl;
	cout << "input min :" << endl;
	cin >> m_min;
	cout << "=====================================" << endl;
	Garnish garnish(Gname, m_num);
	MainDish maindish(Mname, m_min);
	Vegetables vegetables(Vname, m_max);
	Dish *dish[3];
	dish[0]=&garnish;
	dish[1]=&maindish;
	dish[2]=&vegetables;
	for (int i = 0; i < 3; i++)
	{
		dish[i]->CountDish();
		dish[i]->OutputDish();
		cout << "=====================================" << endl;
	}
	return 0;
}
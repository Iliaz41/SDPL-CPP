#include "lab4.h"

int main()
{
	string Dname, Gname, Mname, Vname, MEname, Sname;
	cout << "input dish :" << endl;
	cin >> Dname;
	cout << "=====================================" << endl;
	cout << "input garnish :" << endl;
	cin >> Gname;
	cout << "=====================================" << endl;
	cout << "input main dish :" << endl;
	cin >> Mname;
	cout << "=====================================" << endl;
	cout << "input vegetables :" << endl;
	cin >> Vname;
	cout << "=====================================" << endl;
	cout << "input meat :" << endl;
	cin >> MEname;
	cout << "=====================================" << endl;
	cout << "input spice :" << endl;
	cin >> Sname;
	cout << "=====================================" << endl;
	Spice spice(Dname, Gname, Mname, Vname, MEname, Sname);
	spice.OutputSpice();
	cout << "=====================================" << endl;
	Vegetables vegetables(Dname, Gname, Vname);
	vegetables.OutputVegetables();
	cout << "=====================================" << endl;
	Meat meat(Dname, Mname, MEname);
	meat.OutputMeat();
	cout << "=====================================" << endl;
	Garnish garnish(Dname, Gname);
	garnish.OutputGarnish();
	cout << "=====================================" << endl;
	MainDish maindish(Dname, Mname);
	maindish.OutputMainDish();
	cout << "=====================================" << endl;
	Dish dish(Dname);
	dish.OutputDish();
	return 0;
}
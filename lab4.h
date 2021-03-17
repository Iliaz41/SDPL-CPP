#pragma once
#include <iostream>
#include <string>
using namespace std;

class Dish
{
	protected :
		string d_name;
	public :
		Dish()
		{

		}
		Dish(string Dname)
		{
			this->d_name = Dname;
		}
		~Dish()
		{

		}
		void OutputDish()
		{
			cout << "dish :" << d_name << endl;
		}
};

class Garnish :virtual public Dish
{
	protected :
		string g_name;
	public:
		Garnish() :Dish()
		{
			this->g_name = "Empty";
		}
		Garnish(string Dname, string Gname) :Dish(Dname)
		{
			this->g_name = Gname;
		}
		~Garnish()
		{

		}
		void OutputGarnish()
		{
			cout << "dish :" << d_name << endl;
			cout << "garnish :" << g_name << endl;
		}
};

class Vegetables :virtual public Garnish
{
	protected :
		string v_name;
	public :
		Vegetables() :Garnish()
		{
			this->v_name = "Empty";
		}
		Vegetables(string Dname, string Gname, string Vname)
		{
			this->v_name = Vname;
			this->g_name = Gname;
			this->d_name = Dname;
		}
		~Vegetables()
		{

		}
		void OutputVegetables()
		{
			cout << "dish :" << d_name << endl;
			cout << "garnish :" << g_name << endl;
			cout << "vegetables :" << v_name << endl;
		}
};

class MainDish :virtual public Dish
{
	protected :
		string m_name;
	public :
		MainDish() :Dish()
		{
			this->m_name = "Empty";
		}
		MainDish(string Dname, string Mname) :Dish(Dname)
		{
			this->m_name = Mname;
		}
		~MainDish()
		{

		}
		void OutputMainDish()
		{
			cout << "dish :" << d_name << endl;
			cout << "main dish :" << m_name << endl;
		}
};

class Meat :virtual public MainDish
{
	protected :
		string me_name;
	public :
		Meat() :MainDish()
		{
			this->me_name = "Empty";
		}
		Meat(string Dname, string Mname,string MEname)
		{
			this->me_name = MEname;
			this->m_name = Mname;
			this->d_name = Dname;
		}
		~Meat()
		{

		}
		void OutputMeat()
		{
			cout << "dish :" << d_name << endl;
			cout << "main dish " << m_name << endl;
			cout << "meat :" << me_name << endl;
		}
};

class Spice :virtual public Meat, virtual public Vegetables
{
	protected :
		string s_name;
	public :
		Spice()
		{
			this->s_name = "Empty";
		}
		Spice(string Dname,string Gname,string Mname,string Vname,string MEname,string Sname)
		{
			this->s_name = Sname;
			this->d_name = Dname;
			this->g_name = Gname;
			this->me_name = MEname;
			this->m_name = Mname;
			this->v_name = Vname;
		}
		~Spice()
		{

		}
		void OutputSpice()
		{
			cout << "dish :" << d_name << endl;
			cout << "garnish :" << g_name << endl;
			cout << "main dish :" << m_name << endl;
			cout << "vegetables :" << v_name << endl;
			cout << "meat :" << me_name << endl;
			cout << "spice :" << s_name << endl;
		}
};
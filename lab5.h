#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Dish
{
	public :
		virtual void OutputDish() = 0;
		virtual void CountDish() = 0;
		virtual ~Dish()
		{

		}
};

class Garnish :public Dish
{
protected:
	string g_name;
	int num;
public:
	Garnish() 
	{
		this->g_name = "Empty";
		this -> num = 0;
	}
	Garnish(string Gname,int m_num)
	{
		this->g_name = Gname;
		this->num = m_num;
	}
	~Garnish()
	{

	}
	void OutputDish()
	{
		cout << "garnish :" << g_name << endl;
	}
	void CountDish() override
	{
		num++;
		cout << "output num :" << num << endl;
	}
};

class Vegetables :public Garnish
{
protected:
	string v_name;
	int max;
public:
	Vegetables()
	{
		this->v_name = "Empty";
		this->max = 0;
	}
	Vegetables(string Vname,int m_max)
	{
		this->v_name = Vname;
		this->max = m_max;
	}
	~Vegetables()
	{

	}
	void OutputDish()
	{
		cout << "vegetables :" << v_name << endl;
	}
	void CountDish() override
	{
		max--;
		cout << "output max :" << max << endl;
	}
};

class MainDish :public Dish
{
protected:
	string m_name;
	int min;
public:
	MainDish()
	{
		this->m_name = "Empty";
		this->min = 0;
	}
	MainDish(string Mname,int m_min)
	{
		this->m_name = Mname;
		this->min = m_min;
	}
	~MainDish()
	{

	}
	void OutputDish()
	{
		cout << "main dish :" << m_name << endl;
	}
	void CountDish() override
	{
		min = min + 1000000;
		cout << "output min :" << min << endl;
	}
};
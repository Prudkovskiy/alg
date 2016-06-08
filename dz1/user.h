#pragma once

#include <iostream>
#include <string>

using namespace std;
class user
{
protected:
	bool admin;
public:
	string name;
	user(string name);
	~user(void);
	void set_rignts();     //добавить права администратора
	bool get_adm();        //вывести права пользовател€
	user& operator=(user&);//перегрузка
};

user::user(string name)
{
	this->admin = false;
	this->name = name;
}

user::~user(void)
{

}

void user::set_rignts()
{
	this->admin = true;
}

bool user::get_adm()
{
	return this->admin;
}

user& user::operator=(user& us)//перегрузка равенства 
{
	name = us.name;
	this->admin = us.admin;
	return *this;//возвращаем ссылку на текущий объект
}
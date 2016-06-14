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

user::user(string uname)
{
	admin = false;
	name = uname;
}

user::~user(void)
{

}

void user::set_rignts()
{
	admin = true;
}

bool user::get_adm()
{
	return admin;
}

user& user::operator=(user& us)//перегрузка равенства 
{
	name = us.name;
	admin = us.admin;
	return *this;//возвращаем ссылку на текущий объект
}
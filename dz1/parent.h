#pragma once

#include <vector>
#include "user.h"
#include "directory.h"

using namespace std;

class parent {
public:
	vector <user*> users;
	string name;
	string address;
	directory* parent_dir;
	parent(string, string, vector<user*>, directory*);
	virtual ~parent();
	parent(parent& previous_parent);
	parent* operator=(parent*);//перегрузка

	//void del() { (*this).~parent(); }
};

parent::parent(string nam = "default", string adr = "default", vector<user*> users_, directory* dir = NULL) 
{
	*parent_dir = *dir;
	name = nam;
	address = adr;
	for (int i = 0; i < users_.size(); i++)
		users.push_back(users_[i]);
}

parent::~parent() 
{ 
	users.clear();
	cout << "dctor"; 
}

parent::parent(parent& previous_parent)
{
	name = previous_parent.name;
	address = previous_parent.address;
	for (int i = 0; i < users.size(); i++)
		users[i] = previous_parent.users[i];
}

parent* parent::operator=(parent* p)//перегрузка равенства 
{
	name = p->name;
	address = p->address;
	for (int i = 0; i < users.size(); i++)
		users[i] = p->users[i];
	
	return this;
}
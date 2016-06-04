#pragma once

#include <vector>
#include "user.h"

using namespace std;

class parent {
public:
	vector <user*> users;
	string name;
	parent(string, vector<user*>);
	virtual ~parent();
	void del() { (*this).~parent(); }
};

parent::parent(string fname = "default", vector<user*> users_) 
{
	name = fname;
	for (int i = 0; i < users_.size(); i++)
		users.push_back(users_[i]);
}

parent::~parent() 
{ 
	users.~vector;
	cout << "dctor"; 
}
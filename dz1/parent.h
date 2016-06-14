#pragma once

#include "address.h"
#include "user.h"

using namespace std;

class parent {
public:
	vector<user*> users;
	string name;
	address* adr;
	parent(string, address*, vector<user*>);
	virtual ~parent();
	parent(parent& previous_parent);
	void del() { this->~parent(); }
};

parent::parent(string nam = "default", address* address = NULL, vector<user*> users_ = vector<user*>())
{
	name = nam;
	adr = address;
	for (int i = 0; i < users_.size(); i++)
		users.push_back(users_[i]);
}

parent::~parent() 
{ 
	for (int i = 0; i < users.size(); i++)
		delete users[i];
	cout << " dctor parent " << endl; 
}

parent::parent(parent& previous_parent)
{
	name = previous_parent.name;
	adr = previous_parent.adr;
	for (int i = 0; i < users.size(); i++)
		users[i] = previous_parent.users[i];
}
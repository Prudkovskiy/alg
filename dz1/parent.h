#pragma once

#include <string>
#include <iostream>
#include "user.h"
#include <map>

using namespace std;

class parent {
public:
	map <string, Prava> users;
	string name;
	parent(string ,string);
	virtual ~parent();
	void del() { (*this).~parent(); }
	void dostup();
};

parent::parent(string username, string fname = "default") { 
	name = fname; 
	users[username] = { true, true };
	users["admin"] = { true, true };
}
parent::~parent() { cout << "dctor"; }
void parent::dostup() {

}
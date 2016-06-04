#pragma once

#include "parent.h"
#include <vector>

using namespace std;

class file : public parent {
private:
	string data;
public:
	file(string, vector<user*>, string);
	~file();
	void rename(user, string);
	string getname();
	void redact(user, string);
	string getdata(user);
	void del() { (*this).~file(); }
	
};

file::file(string fname = "default", vector<user*> users_, string fdata = "default") :
	parent(fname, users_)
{ data = fdata; }

file::~file() { cout << "dctor file"; }

void file::rename(user user, string fname)
{
	int k = 0;
	while ((k < users.size()) && (user.name != users[k]->name))
		k++;
	if ((k != users.size()) || (user.get_adm == true))
		name = fname;
	else
		throw 404;
}

string file::getname() { return name; }

void file::redact(user user, string fdata)
{
	int k = 0;
	while ((k < users.size()) && (user.name != users[k]->name))
		k++;
	if ((k != users.size()) || (user.get_adm == true))
		data = fdata;
	else
		throw 404;
}

string file::getdata(user user) 
{ 
	int k = 0;
	while ((k < users.size()) && (user.name != users[k]->name))
		k++;
	if ((k != users.size()) || (user.get_adm == true))
		return data;
	else
		throw 404;
}
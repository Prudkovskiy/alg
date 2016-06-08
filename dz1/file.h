#pragma once

#include "parent.h"

using namespace std;

class file : public parent {
private:
	string data;
public:
	file(string, string, vector<user*>, directory*, string);
	~file();
	void rename(user, string);
	void redact(user, string);
	string getdata(user);
};

file::file(string fname = "default", string adr = "default", vector<user*> users_, directory* dir = NULL, string fdata = "default") :
	parent(fname, adr, users_, dir)
{
	data = fdata; 	
}

file::~file() { cout << "dctor file"; }

void file::rename(user us, string fname)
{
	int k = 0;
	while ((k < users.size()) && (us.name != users[k]->name))
		k++;
	if ((k != users.size()) || (us.get_adm == true))
		name = fname;
	else
		throw 404;
}

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
#pragma once

#include "parent.h"

using namespace std;

class file : public parent {
	string data;
public:
	file(string, string, string);
	~file();
	void rename(string user, string);
	string getname();
	void redact(string user, string);
	string getdata();
	void del() { (*this).~file(); }
};

file::file( string user, string fname = "default", string fdata = "default"):parent(user, fname) { data = fdata;}
file::~file() { cout << "dctor file"; }
void file::rename(string user, string fname) { 
	if (users.count(user) && users[user].write) 
		name = fname;
	else
	{
		cout << "у вас нет прав" << endl;
	}
}
string file::getname() { return name; }
void file::redact(string user, string fdata) {
	if (users.count(user) && users[user].write)
		data = fdata;
	else
	{
		cout << "у вас нет прав" << endl;
	}
}
string file::getdata() { return data; }
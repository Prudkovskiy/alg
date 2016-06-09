#pragma once

#include "parent.h"

using namespace std;

class file : public parent {
private:
	string data;
	vector <string> history;
public:
	file(string, string, vector<user*>, directory*, string);
	~file();
	void rename(user, string);
	void redact(user, string);
	string getdata(user);
	vector<string> get_history();
};

file::file(string fname = "default", string adr = "default", vector<user*> users_, directory* dir = NULL, string fdata = "default") :
	parent(fname, adr, users_, dir)
{
	data = fdata; 	
}

file::~file() { 
	history.clear();
	cout << "dctor file";
}

void file::rename(user us, string fname)
{
	int k = 0;
	while ((k < users.size()) && (us.name != users[k]->name))
		k++;
	if ((k != users.size()) || (us.get_adm == true)) {
		history.push_back("success rename_file by " + us.name);
		name = fname;
	}
	else {
		history.push_back("fail rename_file by " + us.name);
		throw 404;
	}
}

void file::redact(user us, string fdata)
{
	int k = 0;
	while ((k < users.size()) && (us.name != users[k]->name))
		k++;
	if ((k != users.size()) || (us.get_adm == true)) {
		history.push_back("success write_in_file by " + us.name);
		data = fdata;
	}
	else {
		history.push_back("fail write_in_file by " + us.name);
		throw 404;
	}
}

string file::getdata(user us) 
{ 
	int k = 0;
	while ((k < users.size()) && (us.name != users[k]->name))
		k++;
	if ((k != users.size()) || (us.get_adm == true)) {
		history.push_back("success read_file by " + us.name);
		return data;
	}
	else {
		history.push_back("fail read_file by " + us.name);
		throw 404;
	}		
}

vector<string> file::get_history() {
	return history;
}
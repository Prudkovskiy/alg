#pragma once

#include "parent.h"

using namespace std;

class simlink : public parent {
public:
	parent* link;
	simlink(string, vector<user*>, parent*);
	~simlink();
	void rename(user, string);
	string getname();
	int getint() { return 2; }
	void del() { (*this).~simlink(); }
};

simlink::simlink(string sname = "default", vector<user*> user, parent* plink) :
	parent(sname, user)
{ link = plink; }

simlink::~simlink() { cout << "dctor simlink"; }

void simlink::rename(user user, string sname)
{
	int k = 0;
	while ((k < users.size()) && (user.name != users[k]->name))
		k++;
	if ((k != users.size()) || (user.get_adm == true))
		name = sname;
	else
		throw 404;
}

string simlink::getname() { return name; }
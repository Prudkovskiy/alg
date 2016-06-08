#pragma once

#include "parent.h"

using namespace std;

class simlink : public parent {
private:
	parent* link;
public:
	simlink(string, string, vector<user*>, directory*, parent*);
	~simlink();
	void rename(user, string);
	int getint() { return 2; }
};

simlink::simlink(string sname = "default", string adr = "default", vector<user*> users_, directory* dir = NULL, parent* plink) :
	parent(sname, adr, users_, dir)
{
	link = plink;
}

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
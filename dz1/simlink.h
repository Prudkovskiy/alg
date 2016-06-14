#pragma once

#include "parent.h"

using namespace std;

class simlink : public parent {
public:
	file* link;
	simlink(string, address*, vector<user*>, file*);
	~simlink();
	void rename(user*, string);
	void del() { this->~simlink(); }
};

simlink::simlink(string sname = "default", address* adr = NULL, vector<user*> users_ = vector<user*>(), file* plink = nullptr) :
	parent(sname, adr, users_)
{
	link = plink;
}

simlink::~simlink() { cout << "dctor simlink"; }

void simlink::rename(user* us, string sname)
{
	int k = 0;
	while ((k < users.size()) && (us->name != users[k]->name))
		k++;
	if ((k != users.size()) || (us->get_adm() == true))
		name = sname;
	else
		throw 404;
}
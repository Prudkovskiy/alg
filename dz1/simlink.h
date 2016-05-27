#pragma once

#include "parent.h"

using namespace std;

class simlink : public parent {
public:
	parent* link;
	simlink(string, parent*, string);
	~simlink();
	void rename(string);
	string getname();
	int getint() { return 2; }
	void del() { (*this).~simlink(); }
};

simlink::simlink(string user, parent* plink, string fname = "default"): parent(user, fname) { link = plink; }
simlink::~simlink() { cout << "dctor simlink"; }
void simlink::rename(string fname) { name = fname; }
string simlink::getname() { return name; }
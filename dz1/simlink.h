#include "stdafx.h"
#include "string.h"
#include "iostream"
#include "vector"

#include "parent.h"

using namespace std;

class simlink : public parent {
public:
	simlink();
	simlink(string);
	~simlink();
	void rename(string);
	string getname();
};
simlink::simlink() { name = "default"; }
simlink::simlink(string fname) { name = fname; }
simlink::~simlink() { cout << "dctor"; }
void simlink::rename(string fname) { name = fname; }
string simlink::getname() { return name; }

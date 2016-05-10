#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class parent {
public:
	string name;
	parent();
	parent(string);
	virtual ~parent();
	int getint() { return -1; }
	void del() { (*this).~parent(); }
};

parent::parent() { name = "default"; }
parent::parent(string fname) { name = fname; }
parent::~parent() { cout << "dctor"; }
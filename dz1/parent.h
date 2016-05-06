#include "stdafx.h"
#include "string.h"
#include "iostream"

using namespace std;

class parent {
public:
	string name;
	parent();
	parent(string);
	~parent();
};

parent::parent() { name = "default"; }
parent::parent(string fname) { name = fname; }
parent::~parent() { cout << "dctor"; }
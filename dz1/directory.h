#include "stdafx.h"
#include "string.h"
#include "iostream"
#include "vector"

#include "parent.h"

using namespace std;

class directory : public parent {
public:
	vector <parent*> mas;
	directory();
	directory(string);
	~directory();
	void add(parent&);
};
directory::directory() { name = "default"; }
directory::directory(string dname) { name = dname; }
directory::~directory() { mas.clear(); }
void directory::add(parent &child) { mas.push_back(&child); }

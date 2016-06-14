#pragma once

#include <iostream>
#include <string>
#include <vector>

class directory;
using namespace std;
class address {
public:
	vector<directory*> way;

	address(vector<directory*>);
	~address();
};

address::address(vector<directory*> adr = vector<directory*>()) {
	way = adr;
}

address::~address() {
	for (int i = 0; i < way.size(); i++)
		delete way[i];
	cout << "dctor address" << endl;
}

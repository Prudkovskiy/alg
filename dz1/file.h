#include "parent.h"

using namespace std; 

class file : public parent {
	string data;
public:
	file();
	file(string, string);
	~file();
	void rename(string);
	string getname();
	void redact(string);
	string getdata();
	int getint() { return 1; }
	void del() { (*this).~file(); }
};

file::file() { name = "default"; data = "default"; }
file::file(string fname, string fdata) { name = fname; data = fdata; }
file::~file() { cout << "dctor"; }
void file::rename(string fname) { name = fname; }
string file::getname() { return name; }
void file::redact(string fdata) { data = fdata; }
string file::getdata() { return data; }
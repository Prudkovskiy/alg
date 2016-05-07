#include "vector"

#include "file.h"
#include "simlink.h"

using namespace std;

class directory : public parent {
public:
	vector <parent*> mas;
	directory();
	directory(string);
	~directory();
	void add(parent&);
	void deletedir(string);
	int getint() { return 3; }
	parent findfile(string);
};

directory::directory() { name = "default"; }

directory::directory(string dname) { name = dname; }

directory::~directory() { mas.clear(); }

void directory::add(parent &child) { mas.push_back(&child); }

void directory::deletedir(string name) {
	for (int i = 0; i < mas.size(); i++) {
		if ((*mas[i]).getint() == 1)
			(*mas[i]).del();
		if ((*mas[i]).getint() == 2)
			(*mas[i]).del();
		if ((*mas[i]).getint() == 3)
			deletedir((*mas[i]).name);
	}
}
parent directory::findfile(string name) {  //поиск файлов в папке рекурсией
	for (int i = 0; i < mas.size(); i++) {
		if ((*mas[i]).getint() == 1)
			return (*mas[i]);
		if ((*mas[i]).getint() == 3)
			findfile(name);
	}
}

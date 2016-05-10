#include <vector>

#include "file.h"
#include "simlink.h"

using namespace std;

class directory : public parent {
	vector <string> inf;
public:
	vector <parent*> mas;
	directory();
	directory(string);
	~directory();
	void del() { (*this).~directory(); }
	void add(parent&);
	void show();
	void deletedir(string);
	int getint() { return 3; }
	file findfile(string);
	directory copy();
};

directory::directory() { name = "default"; }

directory::directory(string dname) { name = dname; }

directory::~directory() { mas.clear(); }

void directory::add(parent &child) { mas.push_back(&child); }

void directory::show() {
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i]->getint() == 1)
			cout << mas[i]->name << "  " << "file" << endl;
		if (mas[i]->getint() == 2)
			cout << mas[i]->name << "  " << "simlink" << endl;
		if (mas[i]->getint() == 3)
			cout << mas[i]->name << "  " << "directory" << endl;
	}
}

void directory::deletedir(string name) { //удаление папки вместе с содержимым
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i]->getint() == 1)
			mas[i]->del();
		if (mas[i]->getint() == 2)
			mas[i]->del();
		if (mas[i]->getint() == 3) {
			directory* d = static_cast<directory*>(mas[i]);
			if (d->mas.size() == 0)
				del();
			else
				deletedir(mas[i]->name);
		}
			
	}
}

file directory::findfile(string name) {  //поиск файлов в папке рекурсией
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i]->name == name)
			if (mas[i]->getint() == 1) {
			file* f = dynamic_cast<file*>(mas[i]);
			return *f;
		}
			
		if (mas[i]->getint() == 3) {
			directory* d = static_cast<directory*>(mas[i]);
			directory D = *d;
			D->findfile(name);
		}
	}
}

directory directory::copy() { //копия дерикторий 
	directory d;
	for (int i = 0; i < mas.size(); i++) {
			d.add(*mas[i]);
	}
}

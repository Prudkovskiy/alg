#include <vector>

#include "file.h"
#include "simlink.h"

using namespace std;

class directory : public parent {
	vector <string> inf;
public:
	vector <file*> fil;
	vector <directory*> dir;
	vector <simlink*> sim;

	directory();
	directory(string);
	~directory();
	string getname() { return name; };
	void del() { (*this).~directory(); }
	void add();
	void show();
	void deletedir(string);
	file findfile(string);
	directory copy();
};

directory::directory() { name = "default"; }

directory::directory(string dname) { name = dname; }

directory::~directory() { fil.clear(); dir.clear(); sim.clear(); }

void directory::add() {
	char command[3];
	string name;
	string dat;

	cout << "добавить файл - fil" << endl;
	cout << "добавить символическую ссылку - sim" << endl;
	cout << "добавить папку - dir" << endl;

	scanf("%s", &command);
	switch (command[0]) {
	case 'f':
	{
		cout << "name of file: ";
		cin >> name;
		cout << "text: ";
		cin >> dat;
		file f(name, dat);
		fil.push_back(&f);
	}
	break;

	case 's':
	{
		cout << "name of simlink: ";
		cin >> name;
		simlink s(name);
		sim.push_back(&s);
	}
	break;

	case 'd':
	{
		cout << "name of directory: ";
		cin >> name;
		directory d(name);
		dir.push_back(&d);
	}	
	break;

	default:
		break;
	}
 }

void directory::show() {
	cout << "files: " << endl;
	if (fil.size() == 0)
		cout << "empty" << endl;
	else
		for (int i = 0; i < fil.size(); i++) {
			cout << fil[i]->getname() << endl;
		}

	cout << "simlinks: " << endl;
	if (sim.size() == 0)
		cout << "empty" << endl;
	else
		for (int i = 0; i < sim.size(); i++) 
			cout << sim[i]->getname() << endl;

	cout << "directories: " << endl;
	if (dir.size() == 0)
		cout << "empty" << endl;
	else
		for (int i = 0; i < dir.size(); i++) {
			cout << dir[i]->getname() << endl;
		}
}

void directory::deletedir(string name) { //удаление папки вместе с содержимым

	for (int i = 0; i < fil.size(); i++) 
		fil[i]->del();

	for (int i = 0; i < sim.size(); i++)
		sim[i]->del();

	for (int i = 0; i < dir.size(); i++)
		if (dir.size() == 0)
			del();
		else
			deletedir(dir[i]->getname());
}

file directory::findfile(string name) {  //поиск файлов в папке рекурсией
	int k;
	for (int j = 0; j < dir.size(); j++) {
		for (int i = 0; i < fil.size(); i++)
			if (fil[i]->name == name) {
				return *fil[i];
				k = 1;
			}
		if (k != 1) {
			dir[j]->findfile(name);
		}
	}
}

directory directory::copy() { //копия дерикторий 
	directory d;
	for (int i = 0; i < dir.size(); i++) {
		d.dir[i] = dir[i];
	}
	for (int i = 0; i < sim.size(); i++) {
		d.sim[i] = sim[i];
	}
	for (int i = 0; i < fil.size(); i++) {
		d.fil[i] = fil[i];
	}
}

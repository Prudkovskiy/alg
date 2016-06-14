#include "directory.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	vector <user*> users;
	string user_name;
	user* USER;

	cout << "Enter the NUMBER of users: ";
	int N;
	cin >> N;
	cout << "Enter the NAMES of users: <name> <rights> (ADMIN or not?)" << endl;
	for (int i = 0; i < N; i++) 
	{
		string right; 
		cin >> user_name; 
		user* USER = new user(user_name);
		cin >> right;
		if (right == "ADMIN")
			USER->set_rignts();
		users.push_back(USER);
	}
	cout << endl;

	cout << "Create your file system!!! Caps Lock ON!!! ;)" << endl;
	cout << endl;
	cout << "Enter the NAME of the user" << endl;
	cin >> user_name;
	for (int i = 0; i < N; i++)
		if (user_name == users[i]->name) 
			USER = users[i];
		else
		{
			USER = new user(user_name);
			users.push_back(USER);
		}

	string command;
	address* adr = new address();
	directory* dir = new directory("MAIN", adr, users);
	adr->way.push_back(dir);

	cout << endl;
	cout << "Your commands:" << endl;
	cout << endl;
	cout << "change user                  CHU" << endl;
	cout << "create new user              CRU" << endl;
	cout << "create directory             CRD" << endl;
	cout << "create file                  CRF" << endl;
	cout << "create simlink               CRS" << endl;
	cout << "show elements in directory   SHW" << endl;
	cout << "show all elements            ALL" << endl;
	cout << "delete directory             DD "  << endl;
	cout << "delete file                  DF "  << endl;
	cout << "delete simlink               DS "  << endl;
	cout << "move in directory            MIN" << endl;
	cout << "move out of directory        MUT" << endl;
	cout << "find file in directory       FF "  << endl;
	cout << "open file                    OPF" << endl;
	cout << "close file                   CLF" << endl;
	cout << endl;

	while (command != "END")
	{
		cout << endl;
		cin >> command;

		if (command == "CHU")
		{
			cout << endl;
			cout << "enter the name of user  ";
			cin >> user_name;
			int k = 0;
			for (int i = 0; i < users.size(); i++)
				if (user_name == users[i]->name) {
					USER = users[i];
					cout << "user has been changed, now it's " << USER->name << endl;
					dir = dir->get_on_start();
					adr->way.clear();
					adr->way.push_back(dir);
				}
				else k++;
			if (k == users.size())
			{
				cout << "uncorrect name!!!" << endl;
			}
		}

		if (command == "CRU")
			{
				cout << endl;
				dir = dir->get_on_start();
				adr->way.clear();
				adr->way.push_back(dir);

				cout << "Enter: <name> <rights> (ADMIN or not?)" << endl;
				string right;
				cin >> user_name;
				USER = new user(user_name);
				cin >> right;
				if (right == "ADMIN")
					USER->set_rignts();
				users.push_back(USER);
				dir->add_user(USER);
				cout << "new user " << USER->name <<" was created" <<  endl;
			}

		if (command == "CRD")
			{
				cout << endl;
				string name; string right; directory* d;
	
				cout << "name of directory: "; cin >> name;
				cout << "VIP or PUBLIC directory: "; cin >> right;
				if (right == "VIP") {
					vector<user*> us(1);
					user* u = new user(USER->name);
					*u = *USER;
					us[0] = u;
					d = new directory(name, adr, us);
				}
				else
				{
					vector<user*> us(users.size());
					for (int i = 0; i < users.size(); i++) {
						user* u = new user(USER->name);
						*u = *users[i];
						us[i] = u;
					}
					d = new directory(name, adr, us);
				}
			
				dir->add_directory(d);
				cout << "new directory was created" << endl;
			}

		if (command == "CRF")
		{
			cout << endl;
			string name; string data; string right; file* f;
				
			cout << "name of file: "; cin >> name;
			cout << "text in file: "; cin >> data;
			cout << "VIP or PUBLIC file: "; cin >> right;
			if (right == "VIP") {
				vector<user*> us(1);
				user* u = new user(USER->name);
				*u = *USER;
				us[0] = u;
				f = new file(name, adr, us);
			}
			else
			{
				vector<user*> us(users.size());
				for (int i = 0; i < users.size(); i++) {
					user* u = new user(USER->name);
					*u = *users[i];
					us[i] = u;
				}
				f = new file(name, adr, us);
			}

			dir->add_file(f);
			cout << "new file was created" << endl;
		}

		if (command == "CRS")
		{
			cout << endl;
			cout << "new simlink was created" << endl;
			
		}

		if (command == "SHW")
		{
			cout << endl;
			dir->show();
		}

		if (command == "ALL")
		{
			cout << endl;
			dir->show_All(0);
		}

		if (command == "DD")
		{
			cout << endl;
			string name;
			cout << "name of directory "; cin >> name;
			int k = 0;
			try {
				dir->delete_dir(USER, name);
			}
			catch (char* str) {
				cout << str << endl;
				k = 1;
			}
			if (k==0)
				cout << "the directory was deleted" << endl;
		}

		if (command == "DF") 
		{
			cout << endl;
			string name;
			cout << "name of file "; cin >> name;
			int k = 0;
			try {
				dir->delete_fil(USER, name);
			}
			catch (char* str) {
				cout << str << endl;
				k = 1;
			}
			if (k == 0)
				cout << "the file was deleted" << endl;
		}

		if (command == "DS") 
		{
			cout << endl;
		}

		if (command == "MIN")
		{
			cout << endl;
			string name;
			cout << "name of directory:  "; cin >> name;
			int k = 0;
			try {
				dir = dir->get_in(USER, name);
			}
			catch (char* str) {
				cout << str << endl;
				k = 1;
			}		
			if (k == 0) {
				adr->way.push_back(dir);
				cout << "success moving in " << name << endl;
			}
		}

		if (command == "MUT")
		{
			cout << endl;
			int k = 0;
			try {
				dir = dir->get_out();
			}
			catch (char* str) {
				cout << str << endl;
				k = 1;
			}
			if (k == 0)
			{
				adr->way.erase(adr->way.begin() + adr->way.size() - 1);
				cout << "success moving out" << endl;
			}
		}

		if (command == "FF") 
		{
			cout << endl;
			cout << "name of file: "; string name;
			cin >> name;
			file* f;
			int k = 0;
			try {
				f = dir->findfile(name);
				cout << "address of file: ";
				for (int i = 0; i < f->adr->way.size(); i++)
					cout << f->adr->way[i]->name << "/";
				cout << f->name << endl;
			}
			catch (char* str){
				cout << str << endl;
				k++;
			}
			if (k == 0)
				cout << "file " << f->name << " was founded!" << endl;
		}
	}
	/*for (int i = 0; i < N; i++) {
		string right = "USER";
		if (us[i].get_adm() == true)
			right = "ADMIN";
		cout << us[i].name << " " << right << endl;
	} */
	
	system("PAUSE");
	return 0;
}

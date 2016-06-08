//#include "directory.h"
#include "user.h"
#include <vector> 

int main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	vector <user> us;

	cout << "Enter the NUMBER of users: ";
	cin >> N;
	cout << "Enter the NAMES of the users: <name> <rights: ADMIN or USER>" << endl;
	for (int i = 0; i < N; i++) {
		string us_name;
		string right;

		cin >> us_name;
		user u(us_name);
		cin >> right;
		if (right=="ADMIN")
			u.set_rignts();
		us.push_back(u);
	}
	cout << endl;

	cout << "Create your file system!!!" << endl;
	cout << "Your commands:" << endl;
	cout << endl;
	cout << "create directory			  CRD" << endl;
	cout << "create file			      CRF" << endl;
	cout << "create simlink				  CRS" << endl;
	cout << "delete directory			  DD" << endl;
	cout << "delete file				  DF" << endl;
	cout << "delete simlink				  DS" << endl;
	cout << "move in directory			  MIN" << endl;
	cout << "move out of directory		  MUT" << endl;
	cout << "open file					  OPF" << endl;
	cout << "close file					  CLF" << endl;

	string command;

	while (command != "end") 
	{
		if (command == "CRD")
		{

		}
		if (command == "CRF")
		{

		}
		if (command == "CRS")
		{

		}
		if (command == "DD")
		{

		}
		if (command == "DF")
		{

		}
		if (command == "DS")
		{

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

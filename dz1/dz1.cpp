#include "directory.h"
#include "user.h"
#include <map>
int main()
{
	setlocale(LC_ALL, "Russian");

	string user="Иван";
	directory d(user);
	file f(user);
	simlink s(user, &f);

	d.add(user);
	d.add(user);
	d.show();

	//directory k = d.copy(user);
	//k.show();
	system("PAUSE");
	return 0;
}

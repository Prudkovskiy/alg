// lab_4.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "matrix.h"

int _tmain()
{
	int i = 0; int j = 0;
	int lim = 1000;
	int N, M; //строки, столбцы


		cout << "n*m : ROWS = ";
		cin >> N;
		cout << "      COLS = ";
		cin >> M;
		matrix<int> m1(N, M, lim, i);
		cout << "Your FIRST matrix" << endl;
		show(N, M, m1);

		cout << "\nNext matrix" << endl;
		matrix<int> m2(N, M, lim, i);
		cout << "\nYour SECOND matrix" << endl;
		show(N, M, m2);

		matrix<int> mtr2(M, N, lim);
		cout << "\nYour SECOND trans matrix" << endl;
		mtr2 = m2.transp();
		show(M, N, mtr2);
		
		matrix<int> m3(N, N, lim);
		try { m3 = m1 * mtr2; }
		catch (char* str) { cout << str; }
		cout << "\nMatrix MULTIPLICATION" << endl;
		show(N, N, m3);

		matrix<int> m4(N, N, lim);
		cout << "\nMatrix MULTIPLICATION * NUMBER" << endl;
		cout << "NUMBER = ";
		cin >> i;
		try { m4 = m3 * i; }
		catch (char* str) { cout << str; }
		show(N, N, m4);

	system("pause");
	return 0;
}




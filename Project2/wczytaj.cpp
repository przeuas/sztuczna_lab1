#include "wczytaj.h"
#include <iostream>
#include <fstream>

using namespace std;

typedef struct {
	int tab[10][10];
} tsMatrix;

int readFromFile(fstream & hf, tsMatrix & m)
{
	hf.open("data.txt");
	if (!hf.good())
	{
		cout << "Odmowa dostepu!" << endl;
		return 0;
	}
	int i = 0, j = 0, n = 0;
	while (hf >> m.tab[i][j]) {
		if (++j >= 10) {
			j = 0;
			i++;
			cout << "i'm in";
		}
		
		n++;
		if (n >= 100) break; // zabezpieczenie przed wczytaniem nadmiaru informacji

	}
	hf.close();
	return n; // zwracamy ilosc wczytanych liczb
}

void showMatrix(tsMatrix & m) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << m.tab[i][j] << "ds";

		cout << endl;
	}
}

int main()
{
	tsMatrix matrix;
	fstream hfile;

	if (readFromFile(hfile, matrix) == 100) // jesli wczytalismy 100 liczbr
		showMatrix(matrix);

	system("PAUSE");
	
	return 0;
}


wczytaj::wczytaj()
{
}


wczytaj::~wczytaj()
{
}

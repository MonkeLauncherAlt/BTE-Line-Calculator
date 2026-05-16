#include <iostream>
#include <algorithm>
#include <conio.h>

using namespace std;

void wykres () {
	system ("cls");
	int a = 0, b = 0, c = 1;
	
	cout << " Podaj d³ugoœæ x i d³ugoœæ y linii ukoœnej (po spacji)\n > ";
	cin >> a >> b;
	
	if (a == 0 || b == 0) {
		cout << "\n\n Dzbanie, czy ty chcia³eœ liczyæ krzyw¹ linii prostej?\n  *dies from cringe*";
	}
	
	else {
		// je¿eli jest pionowo zorientowana krzywa
		if (a > b) {
			swap (a, b);
		}
			
		// podzielenie na mo¿liwe najmniejsze fragmenty + obliczenie ile fragmentów
		for (int i = a; i > 1; i--) {
			if (a % i == 0 && b % i == 0) {
				a /= i;
				b /= i;
				c *= i;
			}
		}
		
		// tworzenie wykresu
		char tab[a][b];
		
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) tab[i][j] = ' ';
		}
		
		// ustalenie ukosu
		for (int i = 0; i < b - 1; i++) {
			tab[(i * a) / b][i] = '#';
			tab[(i * a) / b][i + 1] = '#';
		}
		tab[a - 1][b - 1] = '#';
		
		// usuwanie zbêdnych bloków
		for (int i = 0; i < a - 1; i++) {
			for (int j = 0; j < b; j++) {
				if (tab[i][j] != tab[i][j + 1]) tab[i][j] = ' ';
			}
		}
		
		
		// --== wyœwietlanie wszystkiego ==--
		
			// ile razy
			cout << "\n\n powtarzaj " << c << " razy:\n";
			
			// wyœwietlenie wykresu	
			cout << "  ";
			for (int i = 0; i < 2 * b + 1; i++) cout << "-";
			cout << "\b\n";
			
			for (int i = 0; i < a; i++) {
				cout << " | ";
				for (int j = 0; j < b; j++) {
					cout << tab[i][j] << " ";
				}
				cout << "|\n";
			}
			
			cout << "  ";
			for (int i = 0; i < 2 * b + 1; i++) cout << "-";
			
			// algorytm zliczania ci¹gów
			cout << "\n w formie ci¹gów bloków: \n  ";
			
			for (int i = 0; i < a; i++) {
				c = 0;
				for (int j = 0; j < b; j++) {
					if (tab[i][j] == '#') c++;
					
					if ((tab[i][j] != '#' && tab[i][j - 1] == '#') || (i == a - 1) && (j == b - 1)) {
						cout << c << " ";
						break;
					}
				}
			}
	}
	
	cout << "\n\n Wciœnij dowolny przycisk aby kontynuowaæ ...";
	getch();
}

int main () {
	setlocale (LC_ALL, "Polish");
	while (true) wykres();
} 

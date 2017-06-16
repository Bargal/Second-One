// lekcja - koniec 2 poziomu.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
/* Program ma wykonæ nastêpuj¹ce koki podane w kolejnoœci:
- losuje 10 liczb z przedzia³u 10-30 i zapisuje do tablicy
- wypisuje wylosowane liczby od pocz¹tku do koñca
- wypisuje wylosowane liczby od koñca do pocz¹tku
- znajduje najmniejsz¹ i najwiêksz¹ wylosowan¹ liczbê
- wypisuje najmniejsz¹ i najwiêksz¹ liczbê

**Program nie mo¿e u¿yæ innej pêtli ni¿ pêtla for
** wszystkie zadania maj¹ wykonywaæ funkcje        */

//														Referencje funkcji

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>


void wylosujLiczby(int tablica[], int a);
void wypiszTablice(int tablica[], int a);
void wypiszTabliceOdTylu(int tablica[], int a);
int znajdzMinimum(int tablica[], int a);
int znajdzMaksimum(int tablica[], int a);
void wypiszMinMax(int iMin, int iMax);



int main()												//main
{
	srand(time(NULL));
	int const t = 10;
	int tablica[t];

	wylosujLiczby(tablica, t);
	std::cout << "wylosowano" << std::endl;
	std::cout << " od przodu " << std::endl;
	wypiszTablice(tablica, t);
	std::cout << "od tylu " << std::endl;
	wypiszTabliceOdTylu(tablica, t);
	std::cout << "a teraz minimum i maximum " << std::endl;
	int iMin = znajdzMinimum(tablica, t);
	int iMax = znajdzMaksimum(tablica, t);
	wypiszMinMax(iMin, iMax);

	system("PAUSE");
	return 0;
}


void wylosujLiczby(int tablica[], int a)        //losowanie i wype³nianie tablicy
{
	for (int t = 0; t <= a; t++)
	{
		a = (std::rand() % 21) + 7;
		tablica[t] = a;
	}
}

void wypiszTablice(int tablica[], int a)        //wypisywanie tablicy
{
	for (int t = 0; t < a; t++)
		std::cout << tablica[t] << std::endl;
}

void wypiszTabliceOdTylu(int tablica[], int a)  //wypisywanie tablicy od ty³u
{
	for (a -=1; a >= 0; a--)
		std::cout << tablica[a] << std::endl;
}

int znajdzMinimum(int tablica[], int a)        //wyszukiwanie minimum
{
	int iMin = tablica[0];

	for (int t = 0; t < a; t++)
	{
		for (; iMin > tablica[t];)
			iMin = tablica[t];
	}return iMin;
}

int znajdzMaksimum(int tablica[], int a)       //wyszukiwanie maksimum
{
	int iMax = tablica[0];

	for (int t = 0; t < a; t++)
	{
		for (; iMax < tablica[t];)
			iMax = tablica[t];
	}return iMax;
}

void wypiszMinMax(int iMin, int iMax)           //wypisywanie minimum i maximum
{
	std::cout << "najnizsza wylosowana liczba to: " << iMin << std::endl;
	std::cout << "najwyzsza wylosowana liczba to: " << iMax << std::endl;
}

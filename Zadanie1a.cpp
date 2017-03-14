#include "stdafx.h"
#include <limits.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctime>


const int MAX = 10000; // liczba elementow do posortowania

using namespace std;

void losuj(unsigned long int tab[])
{
	for (int i = 0; i <MAX; i++)
	{
		//ULONG_MAX
		tab[i] = rand() % ULONG_MAX + 1;
	}
}
void losujRosnac(unsigned long int tab[])
{
	tab[0] = rand() % ULONG_MAX +1 ;
	for (int i = 1; i <MAX; i++)
	{
		//ULONG_MAX
		tab[i] = rand() % ULONG_MAX +tab[i-1] ;
	}
}
void losujMalejac(unsigned long int tab[])
{
	tab[0] = rand() % ULONG_MAX + 1;
	for (int i = 1; i <MAX; i++)
	{
		//ULONG_MAX
		tab[i] = rand() % tab[i - 1] + 1;
	}
}
void losujV(unsigned long int tab[])
{
	tab[0] = rand() % ULONG_MAX + 1;
	int i = 0;
	for (i; i <(MAX/2); i++)
	{
		//ULONG_MAX
		tab[i] = rand() % tab[i - 1] + 1;
	}	
	for (i; i < MAX; i++)
	{
		//ULONG_MAX
		tab[i] = rand() % ULONG_MAX + tab[i - 1];
	}
}
void losujStale(unsigned long int tab[])
{
	tab[0] = rand() % ULONG_MAX + 1;
	for (int i = 0; i <MAX; i++)
	{
		//ULONG_MAX
		tab[i] = tab[0];
	}
}

void wypisz(unsigned long int tab[])
{
	for (int i = 0; i <MAX; i++)
	{
		cout << tab[i] << endl;
	}
}

void insertionSort(unsigned long int tab[])
{
	int temp, j;

	for (int i = 1; i < MAX; i++)
	{
		temp = tab[i];

		for (j = i - 1; j >= 0 && tab[j] > temp; j--)
			tab[j + 1] = tab[j];

		tab[j + 1] = temp;
	}
}

int main()
{
	srand(time(NULL));  // do losowania zeby sie nie losowaly caly czas te same liczby
#pragma region TworzenieTablic


	unsigned long int losowa[MAX];
	unsigned long int rosnaca[MAX];
	unsigned long int malejaca[MAX];
	unsigned long int stala[MAX];
	unsigned long int vksztalt[MAX];

	losuj(losowa);
	losujRosnac(rosnaca);
	losujMalejac(malejaca);
	losujV(vksztalt);
	losujStale(stala);

#pragma endregion

#pragma region Wypisz

	cout << "-------LOSOWE---------------" << endl;
	wypisz(losowa);
	cout << "-------ROSNACE---------------" << endl;
	wypisz(rosnaca);
	cout << "-------MALEJACE---------------" << endl;
	wypisz(malejaca);
	cout << "-------V KSZTALT---------------" << endl;
	wypisz(vksztalt);
	cout << "-------STALA---------------" << endl;
	wypisz(stala);
	*/
	
#pragma endregion

	clock_t begin = clock();  // wlaczasz mierzenie czasu

	insertionSort(losowa); // tu wykonujesz obliczenia

	clock_t end = clock(); // tu konczysz czas
	// to umiescimy w jakies funkcji jak bedziemy mieli sortowania zrobione
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	
	cout << "Czas wykonania: " << elapsed_secs << endl; 


	getchar();
    return 0;
}

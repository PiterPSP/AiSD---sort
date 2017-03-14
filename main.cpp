#include <cstdlib>
#include <fstream>
#include <ctime>
//#include "stdafx.h"
#include <limits.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

const short A = 10000; // poczatkowa liczba elem do losowania, pozniej zwiekszana w petli o krok = A (A + A itd.)
const unsigned int MAX = 150000; // max liczba elemntow (w ostatnim kroku nr 15)

using namespace std;

short max_indeks(short data[], unsigned int n)
{
    int maxi = 0;
    for(int i = 1; i < n; i++)
    {
        if(data[i] > data[maxi])
        {
            maxi = i;
        }
    }
    return maxi;
}

void losuj(unsigned int tab[], unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		//ULONG_MAX
		tab[i] = rand() % ULONG_MAX + 1;
	}
}
void losujRosnac(unsigned int tab[], unsigned int n)
{
	tab[0] = rand() % ULONG_MAX +1 ;
	for (unsigned int i = 1; i <n; i++)
	{
		//ULONG_MAX
		tab[i] = rand() % ULONG_MAX +tab[i-1] ;
	}
}
void losujMalejac(unsigned int tab[], unsigned int n)
{
	tab[0] = rand() % ULONG_MAX + 1;
	for (unsigned int i = 1; i <n; i++)
	{
		//ULONG_MAX
		tab[i] = rand() % tab[i - 1] + 1;
	}
}
void losujV(unsigned int tab[], unsigned int n)
{
	tab[0] = rand() % ULONG_MAX + 1;
	unsigned int i = 0;
	for (i; i <(n/2); i++)
	{
		//ULONG_MAX
		tab[i] = rand() % tab[i - 1] + 1;
	}
	for (i; i < n; i++)
	{
		//ULONG_MAX
		tab[i] = rand() % ULONG_MAX + tab[i - 1];
	}
}
void losujStale(unsigned int tab[], unsigned int n)
{
	tab[0] = rand() % ULONG_MAX + 1;
	for (unsigned int i = 0; i <n; i++)
	{
		//ULONG_MAX
		tab[i] = tab[0];
	}
}

void wypisz(unsigned int data[], unsigned int n)
{
    for(unsigned int i=0; i<n; i++)
    {
        cout<<data[i]<<", ";
    }
}

bool if_sorted(unsigned int data[], unsigned int n)
{
    for(unsigned int i = 0; i < n - 1; i++)
    {
        if(data[i] > data[i + 1])
            return 0;
    }
    return 1;
}

void quick_sort(unsigned int data[], unsigned int n)
{

}

void heap_sort(unsigned int data[], unsigned int n)
{

}

void merge_sort(unsigned int data[], unsigned int n)
{

}

void insert_sort(unsigned int data[], unsigned int n)
{
    for(unsigned int i=1;i<n;i++)
    {
        unsigned int key = data[i];
        unsigned int j = i - 1;
        while(j >= 0 && data[j] > key)
        {
            data[j+1] = data[j];
            data[j] = key;
            j -= 1;
        }
    }
}

void selection_sort(unsigned int data[], unsigned int n)
{
    for(unsigned int i = n - 1; i >= 1; i--)
    {
        unsigned int maxi = i;
        for(unsigned int j = i - 1; j >= 0; j--)
        {
           if (data[j] > data[maxi])
            {
                maxi = j;
            }
        }
        swap(data[i], data[maxi]);
    }
}

int main()
{
    srand(time(NULL));

    unsigned int losowa[MAX], rosnaca[MAX], vksztalt[MAX], malejaca[MAX], stala[MAX];

	losuj(losowa, n);
	losujRosnac(rosnaca, n);
	losujMalejac(malejaca, n);
	losujV(vksztalt, n);
	losujStale(stala, n);

    double selection_time = 0, insert_time = 0, merge_time = 0, heap_time = 0, quick_time = 0;

    // LOSOWE

    unsigned int n = A;   //   n - liczba elem do losowania

    ofstream wyjscie;
    wyjscie.open("wyniki.txt");
    wyj<<"Wyniki pomiarow czasu wykonywania algorytmow sortowania:"<<endl<<endl<<endl<<"Czas sortowania dla:"<<endl<<endl;
    wyj<<"a) losowego zestawu danych:"<<endl<<endl;

    wyj<<"1) insert-sort: "<<endl;
    for(short i=0; i<15; i++)
    {
        losuj(losowa, n);
        clock_t begin = clock();
        insert_sort(losowa, n);
        clock_t end = clock();
        insert_time = double(end - begin) / CLOCKS_PER_SEC;
        wyj<<"pomiar dla "<<n<<" elementow: "<<insert_time<<"s"<<endl;
        n += A;
    }

    n = A

    wyj<<"1) selection-sort: "<<endl;
    for(short i=0; i<15; i++)
    {
        losuj(losowa, n);
        clock_t begin = clock();
        selection_sort(losowa, n);
        clock_t end = clock();
        selection_time = double(end - begin) / CLOCKS_PER_SEC;
        wyj<<"pomiar dla "<<n<<" elementow: "<<insert_time<<"s"<<endl;
        n += A;
    }

    n = A

    wyj<<"1) merge-sort: "<<endl;
    for(short i=0; i<15; i++)
    {
        losuj(losowa, n);
        clock_t begin = clock();
        merge_sort(losowa, n);
        clock_t end = clock();
        merge_time = double(end - begin) / CLOCKS_PER_SEC;
        wyj<<"pomiar dla "<<n<<" elementow: "<<insert_time<<"s"<<endl;
        n += A;
    }

    n = A

    wyj<<"1) insert-sort: "<<endl;
    for(short i=0; i<15; i++)
    {
        losuj(losowa, n);
        clock_t begin = clock();
        insert_sort(losowa, n);
        clock_t end = clock();
        insert_time = double(end - begin) / CLOCKS_PER_SEC;
        wyj<<"pomiar dla "<<n<<" elementow: "<<insert_time<<"s"<<endl;
        n += A;
    }


        // ROSNACE



        // MALEJACE



        // V_SHAPE



        // STALE


    return 0;
}

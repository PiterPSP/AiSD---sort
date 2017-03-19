#include <cstdlib>
#include <fstream>  // OBSLUGA STRUMIENIA WEJ/WYJ PLIKOW
#include <ctime>
#include <limits.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

const int MAX = 10;
#pragma region Losowania

void losuj( int tab[],  int n)
{
	for (unsigned int i = 0; i < n; i++)
	{
		//ULONG_MAX
		tab[i] = rand() % 25 + 1;
	}
}
void losujA( int tab[],  int n)
{
	tab[0] = 1;
	unsigned int i = 0;
	for (i; i < (n/2); i++)
	{
		tab[i] = tab[i - 1] + 1;
	}
	for (i; i < n; i++)
	{

		tab[i] = tab[i - 1] - 1;
	}

}
void wypisz( int data[],  int n)
{
	for (unsigned int i = 0; i<n; i++)
	{
		cout << data[i] << ", ";
	}
}

#pragma endregion


int part(int arr[], int l, int h)
{
    //rand:
    int a = l + (rand() % (h - l + 1));
    int x = arr[a];
    swap(arr[a],arr[h]);
    //


    //right:
    int x = arr[h];
    //


    //left:
    swap(arr[l],arr[h]);
    int x = arr[h];
    //


    //powy¿ej jedna z opcji, a od tad juz bez zmian

    int i = (l - 1);

    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}


void quicksort_iter(int tablica[], int l, int h)
{
    int stos[MAX];
    int top = -1;

    // push initial values of l and h to stack
    stos[ ++top ] = l;
    stos[ ++top ] = h;

    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stos[ top-- ];
        l = stos[ top-- ];

        // Set pivot element at its correct position
        // in sorted arr
        int p = part(tablica, l, h );

        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > l )
        {
            stos[ ++top ] = l;
            stos[ ++top ] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < h )
        {
            stos[ ++top ] = p + 1;
            stos[ ++top ] = h;
        }
    }
}


int main()
{
    srand(time(NULL));
	int tab[MAX];
	losuj(tab, MAX);
	wypisz(tab,MAX);
	cout<<endl<<endl;

    quicksort_iter(tab, 0, MAX - 1);

	wypisz(tab, MAX);


	return 0;
}

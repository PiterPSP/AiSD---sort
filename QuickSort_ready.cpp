#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

const short A = 10000; // poczatkowa liczba elem do losowania, pozniej zwiekszana w petli o krok = A (A + A itd.)
const int MAX = 150000; // max liczba elemntow (w ostatnim kroku nr 15)

using namespace std;

#pragma region Losowania

void losuj(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        //ULONG_MAX
        tab[i] = rand() % 500 + 1;
    }
}
void losujA(int tab[], int n)
{
    tab[0] = 1;
    int i = 1;
    for (i; i < (n / 2); i++)
    {
        tab[i] = tab[i - 1] + 1;
    }
    for (i; i < n; i++)
    {

        tab[i] = tab[i - 1] - 1;
    }

}
void wypisz(int data[], int n)
{
    for (unsigned int i = 0; i<n; i++)
    {
        cout << data[i] << ", ";
    }
}

#pragma endregion

#pragma region QSrekurencyjny




int partitionn(int tablica[], int p, int r) // dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
{
    //right:
    //swap(tablica[p], tablica[r]);

    //mid:
    swap(tablica[p+((r-p+1)/2)], tablica[p]);

    //rand
    //int a = p + (rand() % (r - p + 1));
    //swap(tablica[a], tablica[p]);


    int x = tablica[p]; // obieramy x
    int i = p, j = r, w; // i, j - indeksy w tabeli
    while (true) // petla nieskonczona - wychodzimy z niej tylko przez return j
    {
        while (tablica[j] > x) // dopoki elementy sa wieksze od x
            j--;
        while (tablica[i] < x) // dopoki elementy sa mniejsze od x
            i++;
        if (i < j) // zamieniamy miejscami gdy i < j
        {
            w = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = w;
            i++;
            j--;
        }
        else // gdy i >= j zwracamy j jako punkt podzialu tablicy
            return j;
    }
}

void quicksort(int tablica[], int p, int r) // sortowanie szybkie
{
    int q;
    if (p < r)
    {
        q = partitionn(tablica,p,r); // dzielimy tablice na dwie czesci; q oznacza punkt podzialu
        quicksort(tablica, p, q); // wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
        quicksort(tablica, q+1, r); // wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
    }
}

#pragma endregion

#pragma region QSIteracyjny


int part(int arr[], int l, int h)
{
    //rand:
    int a = l + (rand() % (h - l + 1));
    int x = arr[a];
    swap(arr[a], arr[h]);
    //


    //right:
    //int x = arr[h];


    //srodek:
    //swap(arr[l+((h-l+1)/2)], arr[h]);
    //int x = arr[h];


    //powy¿ej jedna z opcji, a od tad juz bez zmian

    int i = (l - 1);

    for (int j = l; j <= h - 1; j++)
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
    stos[++top] = l;
    stos[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop h and l
        h = stos[top--];
        l = stos[top--];

        // Set pivot element at its correct position
        // in sorted arr
        int p = part(tablica, l, h);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l)
        {
            stos[++top] = l;
            stos[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h)
        {
            stos[++top] = p + 1;
            stos[++top] = h;
        }
    }
}

#pragma endregion

void resetuj_tablice( int glowna[],  int temp[],  int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        temp[i] = glowna[i];
    }
}

bool if_sorted( int data[],  int n)
{
    for (unsigned int i = 0; i < n - 1; i++)
    {
        if (data[i] > data[i + 1])
            return 0;
    }
    return 1;
}

int main()
{
    srand(time(NULL));
    int temp[MAX];
    int losowa[MAX];
    double iteracyjnytime = 0;
    double rekurencyjnytime = 0;
    losujA(losowa, MAX);
    int n = A;
    //quicksort(tab, 0, MAX - 1); // wywolanie funkcji sortujacej
    //quicksort_iter(tab, 0, MAX - 1);


    ofstream wyj;   // TWORZENIE STRUMIENIA WYJSCIA PLIKU
    wyj.open("reku_mid_.txt");     // OTWIERANIE (TWORZENIE) PLIKU SDO WYPISANIA WYNIKOW
    wyj << "Wyniki pomiarow czasu wykonywania algorytmow sortowania Quicksort:" << endl << endl << endl << "Czas sortowania dla:" << endl << endl;


    #pragma region MyRegion



    		wyj << "Rekurencyjny: " << endl;
    		for (short i = 0; i < 15; i++)   // 15 POMIAROW, OD 10K DO 150K ELEMENTOW
    		{
                losujA(temp, n);
    			clock_t begin = clock();
    			cout<<"sort nr"<<i+1<<endl;
    			quicksort(temp, 0, n);       //SORTOWANIE NA TABLICY TEMP
    			clock_t end = clock();
    			rekurencyjnytime = double(end - begin) / CLOCKS_PER_SEC;
    			wyj <<  rekurencyjnytime <<  "s" << endl;
    			cout << "pomiar dla " << n << " elementow: " << rekurencyjnytime << "saa" << endl;
    			if (!if_sorted(temp, n))
    			{
    				cout << "ZLE posortowano" << endl;
    			}
    			n += A;   // ZWIEKSZANIE LICZBY ELEMENTOW DO POSORTOWANIA - KROK POMIAROWY CO A =10K
    		}
    n = A;

    wyj << "Rekurencyjny: " << endl;
    for (short i = 0; i < 15; i++)   // 15 POMIAROW, OD 10K DO 150K ELEMENTOW
    {
        losuj(temp, n);     //RESETOWANIE TABLICY TEMP, BY BYLA UNSORTED
        clock_t begin = clock();
        quicksort(temp, 0, n-1);       //SORTOWANIE NA TABLICY TEMP
        clock_t end = clock();
        iteracyjnytime = double(end - begin) / CLOCKS_PER_SEC;
        wyj << iteracyjnytime << endl;
        if (!if_sorted(temp, n))
        {
            cout << "ZLE posortowano" << endl;
        }
        n += A;         // ZWIEKSZANIE LICZBY ELEMENTOW DO POSORTOWANIA - KROK POMIAROWY CO A =10K
    }
    n = A;      // RESET DO WYJSCIOWEJ LICZBY 10K ELEMENTOW PRZED WYKONANIEM KOLEJNEJ PETLI I SORTOWAN
    wyj.close();

    #pragma endregion
    cout << "finished" << endl;
    return 0;
}

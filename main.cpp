#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void wypisz(short data[], short n)
{
    for(int i=0; i<n; i++)
    {
        cout<<data[i]<<", ";
    }
}

bool if_sorted(short data[], short n)
{
    for(int i = 0; i < n - 1; i++)
    {
        if(data[i] > data[i + 1])
            return 0;
    }
    return 1;
    asfsaf
        
        sfafas
}


void insert_sort(short data[], int n)
{
    for(int i=1;i<n;i++)
    {
        short key = data[i];
        short j = i - 1;
        while(j >= 0 && data[j] > key)
        {
            data[j+1] = data[j];
            data[j] = key;
            j -= 1;
        }
    }
}

/*
short max_indeks(short data[], short n)
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
*/

void selection_sort(short data[], int n)
{
    for(int i = n - 1; i >= 1; i--)
    {
        int maxi = i;
        for(int j = i - 1; j >= 0; j--)
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

    short n=10, data[10];

    for(int i=0; i<n; i++)
    {
        data[i] = (rand() % 201) - 100;
        cout<<data[i]<<", ";
    }
    cout<<endl;

    selection_sort(data, n);

    if(!if_sorted(data, n))
    {
        cout<<"blad sortowania"<<endl<<endl;
    }

    wypisz(data, n);

    return 0;
}

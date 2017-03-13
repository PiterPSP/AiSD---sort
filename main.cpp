#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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

    insert_sort(data, n);

    for(int i=0; i<n; i++)
    {
        cout<<data[i]<<", ";
    }



    return 0;
}

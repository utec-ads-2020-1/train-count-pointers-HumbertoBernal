#include <iostream>
#include <stdio.h>

using namespace std;

int max(int *iptr[], int n);

int max(int* iptr[] , int n){
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (* iptr[i] > max){ max = * iptr[i]; }
    }

    return max;

}

int main() {
    int n, i;
    int array[100];
    int *iptr[100];

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> (array[(i + 3) % n]);
        iptr[i] = &(array[(i + 3) % n]);
    }
    cout <<  max(iptr, n) << endl;
    return 0;
}
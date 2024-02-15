#include<iostream>
#include<ctime>
#include<random>
#include<cstdlib>
#include<cstring>
using namespace std;
main () {
    int size;
    cin >> size;
    int *a = new int [size];

    for (int i=0; i<= size; i++) {
        a[i] = rand()%1000001;
    }

    for (int i=0; i<= size; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
    int query;
    cin >> query;
    srand(time(0));
    for (int i=0; i<=size; i++) {
        if (a[i]==query) cout << query << " were in index " << i;
    }
    }
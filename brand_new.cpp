#include<iostream>
#include<ctime>
#include<random>
#include<cstdlib>
#include<cstring>
using namespace std;

main () {
    int size;
    cin >> size;
    int *m = new int [size];
for(int i=0;i<=size; i++){ m[i]= rand()%1000;}
int temp;
for(int i=1;i<=size;i++){
    for(int j=i;j>0&&m[j-1]>m[j];j--){
        swap(m[j-1],m[j]);
    }

cout <<endl;
for(int i=0;i<=size;i++){ cout<<m[i]<<" ";}
}
cout<<endl;
int q;
cin>>q;
int a,f;
// f- это серединный элемент
int r=size-1,l=0;
srand(time(0));
while(r>=1){
    f=(r+l)/2;
    if (m[f]==q){
        a=f;
        break;
    }
    if(q<m[f])r=f-1;
    if(q>m[f])r=f+1;
}
cout <<q<<" index"<<f;
cout<<"\nruntime = "<<clock()/1000.0<<endl;

}
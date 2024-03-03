#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <chrono>
#include<fstream>
#include <sstream> 

int binpoisk(int m, int n, int mas[], int r, int l)
{    
 r=n-1;
 l=0;
 int mid=0;
    while (l<=r) 
 {
    mid = (l + r) / 2; 
    if (mas[mid] < m)
       l = mid+1;
    if(mas[mid]>m)
       r=mid-1;
    if (mas[mid] == m)
    {
       return mid;
    }
 }
}

 int main()
{ 
   std::ofstream out;
   out.open("binpoisk2.txt");
   
   int m = 1000007;
   for(int n=100; n<1000000; n+=10000)
   {
      

   int* mas = new int[1000000];
   srand(time(NULL));
   for(int i = 0; i < 1000000; i++) {
      mas[i] = rand() % 1000000; 
   }
   std::sort(mas, mas+1000000);
   for(int n=100; n<1000000; n+=100)
   {
      unsigned cnt_binpoisk = 100*std::max(50, (10000000 / n));
      auto c = std::chrono::steady_clock::now();
      for(auto cnt = cnt_binpoisk; cnt!=0; --cnt)
         binpoisk(m,n,mas,n-1,0);
      auto d= std::chrono::steady_clock::now();   
      auto t= std::chrono::duration_cast<std::chrono::microseconds>(d - c);

      out<<n<<" "<<double(t.count()) / cnt_binpoisk <<std::endl;
      std::cout << (double(n) / 1000000)*100 << "\% done\n";

   }
   delete[] mas;
   out.close();
   
}}
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <chrono>
#include<fstream>
#include <sstream> 


int poisk(int m,int n, int mas[])
{      
 for(int i=0; i<n; i++)
 {
    if(mas[i]==m)
    {
      return i;
    } 
 }
 
}
 int main()
{ 
   
   std::ofstream f;
   f.open("poisk2.txt");
   int m = 1000007;
   for(int n=100; n<1000000; n+=10000)
   {
      int* mas = new int[n];
      srand(time(NULL));
      for(int i = 0; i < n; i++) {
         mas[i] = rand() % 1000000; 
      }
      std::sort(mas, mas+n);

      auto b = std::chrono::steady_clock::now();
      unsigned cnt_poisk = std::max(1, (200000 / n));
      for(auto cnt = cnt_poisk; cnt!=0; --cnt)
            poisk(m,n,mas);   
      auto e= std::chrono::steady_clock::now();   
      auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(e - b);
      
      f<<n<<" "<<double(time_span.count()) / cnt_poisk<<std::endl;
      std::cout << (double(n) / 1000000)*100 << "\% done\n";
      delete[] mas;
   }
   
   
   f.close();
}
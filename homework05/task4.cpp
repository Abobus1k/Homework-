#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; ++i)
        std::cin >> array[i];
    if(n%2==0)
      for (int i = 0; i < n / 2; ++i)
        std::cout<<array[i]<<" "<<array[n-i-1]<<" ";
  
    if(n%2==1)
      for (int i = 0; i <= (n-1) / 2; ++i)
      {
        if(i*2==n-1) std::cout<<array[i];
        else std::cout<<array[i]<<" "<<array[n-i-1]<<" ";
      }
    delete[] array;
}

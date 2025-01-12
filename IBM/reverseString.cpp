#include <bits/stdc++.h>
using namespace std;

void reverseString1(string& str)
{
  reverse(str.begin(), str.end());
}

void reverseString2(string& str)
{
  int i = 0, j = str.length() - 1;
  
  while(i <= j)
  {
    swap(str[i], str[j]);
    i++;
    j--;
  }
}

int main() 
{
  string str = "This is sample test.";
  std::cout << "Build-in func" << std::endl;
    cout << str<<endl;
    reverseString1(str);
    cout << str<<endl;
    
    std::cout << "My func" << std::endl;
    
    cout << str<<endl;
    reverseString2(str);
    cout << str<<endl;
    return 0;
}

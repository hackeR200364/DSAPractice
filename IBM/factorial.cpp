#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
  int p = 1;
  for(int i = 1; i <= n; i++)
  {
    p *= i;
  }
  
  return p;
}

int main() 
{
    cout << factorial(5);
    return 0;
}

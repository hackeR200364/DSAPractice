#include <bits/stdc++.h>
using namespace std;

long getMaxEvenSum(int a[], int n)
{
  int pos_sum = 0;
  
  for(int i = 0; i < n; i++)
  {
    if(a[i] > 0)
    {
      pos_sum += a[i];
    }
  }
  
  if(pos_sum % 2 == 0)
  {
    return pos_sum;
  }
  
  int ans = INT_MIN;
  for(int i = 0; i < n; i++)
  {
    if(a[i] % 2 != 0)
    {
      if(a[i] > 0)
      {
        ans = max(ans, pos_sum - a[i]);
      }
      else
      {
        ans = max(ans, pos_sum + a[i]);
      }
    }
  }
  
  return ans;
}

int main() 
{
    int a[] = {-1,-2,-3,8,7};
    int n = sizeof(a) / sizeof(a[0]);
    std::cout << getMaxEvenSum(a, n) << std::endl;
    return 0;
}

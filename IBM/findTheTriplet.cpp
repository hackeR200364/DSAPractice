#include <bits/stdc++.h>
using namespace std;

int findTheTriplet(int arr[], int n, int d)
{
  int ans = 0;
  for(int i = 0; i < n - 2; i++)
  {
    for(int j = i + 1; j < n-1; j++)
    {
      for(int k = j + 1; k < n; k++)
      {
        if((arr[i] + arr[j] + arr[k]) % d == 0)
        {
          ans++;
        }
      }
    }
  }
  
  return ans;
}

int main() 
{
  int n = 5, d = 5;
  int price[n] = {3,3,4,7,8};
    cout << findTheTriplet(price, n, d) << endl;
    return 0;
}

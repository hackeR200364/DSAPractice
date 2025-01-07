#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> oddEvenTransform(vector<int> arr, int n)
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < arr.size(); j++)
    {
      if(arr[j] % 2 == 0)
      {
        arr[j] -= 3;
      }
      else
      {
        arr[j] += 3;
      }
    }
  }
  
  return arr;
}

int main() 
{
  int n = 3;
  vector<int> arr = {3,4,9};
  vector<int> res = oddEvenTransform(arr, n);
  for(int i = 0; i < res.size(); i++)
  {
    cout << res[i] << ", ";
  }
  
  return 0;
}

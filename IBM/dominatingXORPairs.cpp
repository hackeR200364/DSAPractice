#include <bits/stdc++.h>
using namespace std;

int dominatingXORPairs(const std::vector<int>& arr)
{
  int N = arr.size();
  int ans = 0;
  
  int bits[32] = {0};
  
  for(int i = 0; i < N; i++)
  {
    int val = log2l(arr[i]);
    ans += bits[val];
    bits[val]++;
  }
  
  return N * (N-1) / 2 - ans; 
}

int main() 
{
  vector<int> arr = {4,3,5,2};
    cout << dominatingXORPairs(arr);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<long> arrayChallenge(vector<long> &arr)
{
  
  int n = arr.size();
  int sum;
  vector<long> ans;
  ans.push_back(0);
  
  for(int i = 1; i < n; i++)
  {
    sum = 0;
    
    for(int j = 0; j < i; j++)
    {
      int diff = arr[i] - arr[j];
      sum += diff;
    }
    
    ans.push_back(sum);
  }
  
  return ans;
  
}

int main() 
{
    vector<long> arr = {2,4,3};
    vector<long> res = arrayChallenge(arr);
    
    for(int i = 0; i < res.size(); i++)
    {
      std::cout << res[i] << std::endl;
    }
    
    return 0;
}

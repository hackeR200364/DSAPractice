#include <bits/stdc++.h>
using namespace std;

vector<string> getLatestKRequest(const vector<string>& requests, int k){
 
 vector<string> ans;
 unordered_map<string, bool> check;
 int cnt = 0;
 
 for(int i = requests.size()-1; i >= 0; i--)
 {
   if(cnt == k)
   {
     return ans;
   }
   
   if(check[requests[i]] != true)
   {
     cnt++;
     check[requests[i]] = true;
     ans.push_back(requests[i]);
   }
 }
  
}

int main() 
{
    vector<string> requests = {"item1", "item2", "item3", "item1", "item3"};
    int k = 3;
    
    vector<string> res = getLatestKRequest(requests, k);
    
    for(int i = 0; i < res.size() ; i++)
    {
      std::cout << res[i] << std::endl;
    }
    return 0;
}

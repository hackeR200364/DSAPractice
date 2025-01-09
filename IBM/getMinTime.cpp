#include <bits/stdc++.h>
using namespace std;

vector<int> getMinTime(int cacheSize,int cacheTime, int serverTime,vector<string> urls)
{
  std::vector<int> timeTaken;
  std::queue<string> queue;
  unordered_set<string> cacheSet;
  
  for(const string& url : urls)
  {
    if(cacheSet.count(url) > 0)
    {
      timeTaken.push_back(cacheTime);
    }
    else
    {
      if(queue.size() >= cacheSize)
      {
        string frontUrl = queue.front();
        queue.pop();
        cacheSet.erase(frontUrl);
      }
      
      timeTaken.push_back(serverTime);
      queue.push(url);
      cacheSet.insert(url);
    }
  }
  
  return timeTaken;
}

int main() 
{
    int cacheSize = 2, cacheTime = 2, serverTime = 3;
    
    std::vector<string> urls = {"www.google.com", "www.yahoo.com", "www.google.com", "www.yahoo.com", "www.coursera.com"} ;
    
    std::vector<int> res = getMinTime(cacheSize, cacheTime, serverTime, urls);
    
    for(int time : res)
    {
      std::cout << "time: " << time << std::endl;
    }
    return 0;
}

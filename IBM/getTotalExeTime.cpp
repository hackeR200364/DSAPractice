#include <bits/stdc++.h>
using namespace std;

vector<int> getTotalExeTime(int n, const vector<string>& logs)
{
  std::vector<int> res(n,0);
  std::stack<int> funcStack;
  int prevTime = 0;
  
  for(const string& log : logs)
  {
    stringstream ss(log);
    string token;
    vector<string> logParts;
    
    while(getline(ss, token, ':'))
    {
      logParts.push_back(token);
    }
    
    int funcId = stoi(logParts[0]);
    string action = logParts[1];
    int timestamp = stoi(logParts[2]);
    
    if(action == "start")
    {
      if(!funcStack.empty())
      {
        res[funcStack.top()] += timestamp - prevTime;
      }
      
      funcStack.push(funcId);
      prevTime = timestamp;
    }
    else if(action == "end")
    {
      res[funcStack.top()] += timestamp - prevTime + 1;
      funcStack.pop();
      prevTime = timestamp + 1;
    }
  }
  
  return res;
}

int main() 
{
    int n = 3;
    std::vector<string> logs = {
      "0:start:0",
      "1:start:2",
      "2:start:3",
      "2:end:4",
      "1:end:5",
      "0:end:6"
    };
    
    vector<int> exeTimes = getTotalExeTime(n, logs);
    
    for(int i = 0; i < exeTimes.size(); i++)
    {
      std::cout << exeTimes[i] << std::endl;
    }
    return 0;
}

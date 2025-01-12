#include <bits/stdc++.h>
using namespace std;

string getSmallestString(string word, string subStr)
{
  int n = word.length();
  int m = subStr.length();
  
  if(m > n)
  {
    return "-1";
  }
  
  for(int start = 0; start <= n-m; start++)
  {
    bool match = true;
    string res = word;
    for(int i = 0; i < m; i++)
    {
      if(word[start+i] == '?' || word[start + i] == subStr[i])
      {
        res[start + i] = subStr[i];
      }
      else
      {
        match = false;
        break;
      }
    }
    
    if(match)
    {
      for(int j = 0; j < n; j++)
      {
        if(res[j] == '?')
        {
          res[j] = 'a';
        }
      }
      
      return res;
    }
  }
  
  return "-1";
}

int main() 
{
    cout << getSmallestString("as?b?e?gf", "dbk");
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int getMaxOccur(string components, int minLen, int maxLen, int maxUniq)
{
  int n = components.length();
  int maxOccur = 0;
  
  for(int length = minLen; length <= maxLen; length++)
  {
    unordered_map<string, int> subStrCount;
    unordered_map<char, int> charCount;
    
    int uniqChars = 0;
    
    for(int i = 0; i < n; i++)
    {
      char currChar = components[i];
      charCount[currChar]++;
      
      if(i >= length)
      {
        char leftChar = components[i - length];
        charCount[leftChar]--;
        
        if(charCount[leftChar] == 0)
        {
          charCount.erase(leftChar);
        }
      }
    
    
    if(charCount.size() <= maxUniq)
    {
      uniqChars = charCount.size();
    }
    
    if(i >= length - 1 && uniqChars <= maxUniq)
    {
      string subStr = components.substr(i - length+1, length);
      subStrCount[subStr]++;
      maxOccur = max(maxOccur, subStrCount[subStr]);
    }
    }
  }
  
  return maxOccur;
}

int main() 
{
  
    cout << getMaxOccur("abcde", 2,3,3)<<endl;
    cout << getMaxOccur("abcde", 2,4,26)<<endl;
    return 0;
}

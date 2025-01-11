#include <bits/stdc++.h>
using namespace std;

class Solution {
  public: 
  string smallest_lexicographical_string(string word, string substr)
  {
    int len_word = word.length();
    int len_substr = substr.length();
    
    for(int i = 0; i <= len_word - len_substr; i++)
    {
      bool match_found = true;
      string temp_word = word;
      
      for(int j = 0; j < len_substr; j++)
      {
        if(temp_word[i+j] != '?' && temp_word[i+j] != substr[j])
        {
          match_found = false;
          break;
        }
        
        temp_word[i+j] = substr[j];
      }
      
      if(match_found)
      {
        for(int k = 0; k < len_word ; k++)
        {
          if(temp_word[k] == '?')
          {
            temp_word[k] = 'a';
          }
        }
        
        return temp_word;
      }
    }
    
    return "-1";
  };
};

int main() 
{
  Solution solution;
  string res = solution.smallest_lexicographical_string("as?b?e?gf", "dbk");
    cout << res << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int findMinimumMoves(string &word)
{
  int moves = 0;
  unordered_map<char, int> cmp;
  for(int i = 0; i < word.length(); i++)
  {
    cmp[word[i]]++;
  }
  
  for(auto c:cmp)
  {
    if(c.second > 1)
    {
      moves += c.second / 2;
    }
  }
  
  return moves;
}

int main() 
{
  string word = "baabacaa";
    cout << findMinimumMoves(word) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int missedLec(int numChapters, int b, int e)
{
  std::vector<int> classes ;
  int noOfLec = numChapters * (e+1);
  
  for(int i = 0; i < noOfLec; i++)
  {
    classes.push_back(i % numChapters);
  }
  
  unordered_set<int> disCh;
    for(int i = b; i <= e; i++)
    {
      disCh.insert(classes[i]);
    }
    
    return disCh.size();
}

int main() 
{
    cout << missedLec(5,13,98);
    return 0;
}

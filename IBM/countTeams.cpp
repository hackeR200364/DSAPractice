#include <bits/stdc++.h>
using namespace std;

int countTeams(int teamSize_1, int teamSize_2, int p)
{
  int minT1 = p / teamSize_1;
  int rem1 = p % teamSize_1;
  
  while (minT1 >= 0)
  {
    if(rem1 % teamSize_2 == 0)
    {
      break;
    }
    
    minT1--;
    rem1 += teamSize_1;
  }
  
  
  int minT2 = p / teamSize_2;
  int rem2 = p % teamSize_2;
  
  while (minT2 >= 0)
  {
    if(rem2 % teamSize_1 == 0)
    {
      break;
    }
    
    minT2--;
    rem2 += teamSize_2;
  }
  
  
  if(minT1 < 0 && minT2 < 0) 
  {
    return -1;
  }
  else if(minT1 < 0)
  {
    minT2 + rem2/teamSize_1;
  }
  else if(minT2 < 0)
  {
    minT1 + rem1/teamSize_2;
  }
  else
  {
    return min(minT2 + rem2/teamSize_1, minT1 + rem1/teamSize_2);
  }
}

int main() 
{
  int teamSize_1 = 3, teamSize_2 = 4, p = 7;
    cout << countTeams(teamSize_1, teamSize_2, p);
    return 0;
}

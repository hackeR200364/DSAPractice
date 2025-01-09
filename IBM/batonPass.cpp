#include <bits/stdc++.h>
using namespace std;

std::vector<int> batonPass(int friends, long long time)
{
  int cycleLength = (friends - 1) * 2;
  long long effectiveTime = (time - 1) % cycleLength + 1;
  
  int pos;
  if(effectiveTime <= friends)
  {
    pos = static_cast<int>(effectiveTime);
  }
  else
  {
    pos = 2 * friends - static_cast<int>(effectiveTime);
  }
  
  int passer, receiver;
  
  if(effectiveTime <= friends)
  {
    passer = pos;
    receiver = (pos < friends) ? pos + 1 : friends;
  }
  else
  {
    passer = pos;
    receiver = (pos > 1) ? pos - 1 : 1;
  }
  
  return {passer, receiver};
  
  
}

int main() 
{
  int friends = 4;
  long long time = 5;
  vector<int> res = batonPass(friends, time);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}

#include <iostream>
using namespace std;
int seqSum(int i, int j, int k)
{
  int sum = 0;
  
  for(int l = i; l <= j; l++)
  {
    sum += l;
  }
  
  for(int l = j - 1; l >= k; l--)
  {
    sum += l;
  }
  
  return sum;
  
}

int main() 
{
    cout << seqSum(0, 5, -1)<< endl;
    return 0;
}

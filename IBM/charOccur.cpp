#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s; //a3b4a1c5g6
    cin>>s;
    int a[255] = {0};
    
    for(int i = 0; i < s.size(); i += 2)
    {
      a[s[i]] += (s[i+1] - '0');
    }
    
    string ans;
    
    for(int i = 0; i < 255; i++)
    {
      if(a[i] != 0)
      {
        ans += i;
        ans += (a[i] + '0');
      }
    }
    
    std::cout << ans << std::endl;
    return 0;
}

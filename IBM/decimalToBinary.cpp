#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    string b;
    
    while(n >0)
    {
      b += ((n % 2) + '0');
      n /= 2;
    }
    
    reverse(b.begin(), b.end());
    
    std::cout << b << std::endl;
    return 0;
}

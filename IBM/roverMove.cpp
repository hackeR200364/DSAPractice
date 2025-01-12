#include <bits/stdc++.h>
using namespace std;

int roverMove(int n, std::vector<string> commands)
{
  int r = 0, c = 0;
  for(const string& command : commands)
  {
    if(command == "UP" && r > 0)
    {
      r -= 1;
    }
    else if (command == "DOWN" && r < n-1)
    {
      r += 1;
    }
    else if (command == "LEFT" && c > 0)
    {
      c -= 1;
    }
    else if (command == "RIGHT" && c < n-1)
    {
      c += 1;
    }
  }
  
  return (r * n) + c;
}

int main() 
{
  std::vector<string> commands = {"RIGHT", "UP", "DOWN", "LEFT", "DOWN", "DOWN"} ;
    cout << roverMove(4, commands) << endl;
    return 0;
}

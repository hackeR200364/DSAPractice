#include <bits/stdc++.h>
using namespace std;

vector<int> missingPrisoner(const vector<vector<int>> locations)
{
  unordered_set<int> x_coords;
  unordered_set<int> y_coords;
  
  for(const auto& loc : locations)
  {
    x_coords.insert(loc[0]);
    y_coords.insert(loc[1]);
  }
  
  int missing_x = 0;
  for(int x: x_coords)
  {
    std::cout << "x = " << x << std::endl;
    int count = 0;
    for(const auto& loc : locations)
    {
      if(loc[0] == x)
      {
        count++;
      }
      
      std::cout << "loc "<<loc[0] << " and count = " << count << std::endl;
    }
    std::cout << "count = " << count << std::endl;
    if(count == 1)
    {
      missing_x = x;
      break;
    }
  }
  
  int missing_y = 0;
  for(int y: y_coords)
  {
    std::cout << "y = " << y << std::endl;
    int count = 0;
    for(const auto& loc : locations)
    {
      if(loc[1] == y)
      {
        count++;
      }
      
      std::cout << "loc "<<loc[1] << " and count = " << count << std::endl;
    }
    std::cout << "count = " << count << std::endl;
    if(count == 1)
    {
      missing_y = y;
      break;
    }
  }
  
  return {missing_x, missing_y};
}

int main() 
{
  vector<vector<int>> locations = {{1,1}, {1,2},{2,1}, {4,4}, {4,6}, {9,4}, {9,6}};
  vector<int> res = missingPrisoner(locations);
  
  std::cout <<"x = " << res[0] << " " << "y = " << res[1] << std::endl;
  
    return 0;
}

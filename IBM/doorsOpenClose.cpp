#include <bits/stdc++.h>

using namespace std;

vector<int> doorsOpenClose(int p, int d)
{
  map<int, bool> doors;
  
  for(int i = 1; i <= d; i++)
  {
    doors[i] = false;
  }
  
  int openDoors = 0, closeDoors = 0;
  for(int person = 1; person <= p; person++)
  {
    for(int door = person; door <= doors.size(); door += person)
    {
      doors[door] = !doors[door];
    }
  }
  
  for(int i = 1; i <= p; i++)
  {
    if(doors[i] == true)
    {
      openDoors++;
    }
    else
    {
      closeDoors++;
    }
  }
  
  return {openDoors, closeDoors};
}

vector<int> doorsOpenClose2(int p, int d)
{
  int openDoors = static_cast<int>(std::floor(std::sqrt(d)));
  int closedDoors = d - openDoors;
  return {openDoors, closedDoors};
}

int main() 
{
  auto start = clock();

    std::vector<int> res = doorsOpenClose(100, 100);
    std::cout << "Opened Doors = " << res[0] << " Closed Doors = " << res[1] << std::endl;

    auto end = clock();

    double duration_seconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    double duration_microseconds = duration_seconds * 1000000.0; // Correct conversion

    std::cout << "Time taken by myFunction: " << duration_microseconds << " microseconds" << std::endl;
              
    std::cout << "Second Function" << std::endl;
    auto start2 = clock();

    std::vector<int> res2 = doorsOpenClose2(100, 100);
    std::cout << "Opened Doors = " << res2[0] << " Closed Doors = " << res2[1] << std::endl;

    auto end2 = clock();

    double duration_seconds2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;
    double duration_microseconds2 = duration_seconds2 * 1000000.0; // Correct conversion

    std::cout << "Time taken by myFunction: " << duration_microseconds2 << " microseconds" << std::endl;
    
    return 0;
}

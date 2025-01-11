#include <bits/stdc++.h>
using namespace std;

int findTotalCost(std::vector<int>& arr )
{
  int total_cost = 0;
  
  while(arr.size() > 1)
  {
    auto min_element_it = min_element(arr.begin(), arr.end());
    auto max_element_it = max_element(arr.begin(), arr.end());
    
    int min_element = *min_element_it;
    int max_element = *max_element_it;
    
    int cost= ceil(static_cast<double>(min_element + max_element) / (max_element - min_element + 1));
    
    int min_idx = min_element_it - arr.begin();
    int max_idx = max_element_it - arr.begin();
    
    arr.erase(arr.begin() + max_idx);
    arr.erase(arr.begin() + min_idx);
    
    arr.push_back(min_element + max_element);
    
    total_cost += cost;
  }
  
  return total_cost;
}

int main() 
{
  vector<int> arr = {2,3,4,5,7};
    cout << findTotalCost(arr)<<endl;
    
    vector<int> arr2 = {3,5,2,1,9,6};
    cout << findTotalCost(arr2)<<endl;
    
    vector<int> arr3 = {8,8,8,8};
    cout << findTotalCost(arr3)<<endl;
    return 0;
}

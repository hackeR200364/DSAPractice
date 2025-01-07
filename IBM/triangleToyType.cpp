#include <bits/stdc++.h>
using namespace std;

vector<string> triangleType(const vector<string>& triangleToy){
 
 vector<string> ans;
 
 for(const string& sides: triangleToy)
 {
   
   stringstream ss(sides);
   
   int side1, side2, side3;
   
   ss >> side1 >> side2 >> side3;
   
   if((side1 + side2 > side3) && (side2 + side3 > side1) && (side3 + side1 > side2))
   {
     if((side1 == side2) && (side2 == side3))
     {
       
       ans.push_back("Equilateral");
     }
     else if((side1 == side2) || (side2 == side3) || (side3 == side1))
     {
       ans.push_back("Isosceles");
     }
     else
     {
       ans.push_back("None of these");
     }
   }
   else
   {
     ans.push_back("None of these");
   }
   
 }
 
 return ans;
  
}

int main() 
{
    vector<string> triangleToy = {"2 2 1", "3 3 3", "3 4 5", "1 1 3"};
    
    vector<string> res = triangleType(triangleToy);
    
    for(int i = 0; i < res.size() ; i++)
    {
      std::cout << res[i] << std::endl;
    }
    return 0;
}

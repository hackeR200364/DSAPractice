#include <bits/stdc++.h>
using namespace std;

int priceCheck(vector<string> products, vector<float> productPrices, vector<string> productSold, vector<float> soldPrice)
{
  
  int err = 0;
  
  unordered_map<string, float> productAndPrice;
  
  for(int i = 0; i < products.size(); i++)
  {
    productAndPrice[products[i]] = productPrices[i];
  }
  
  for(int i = 0; i < productSold.size(); i++)
  {
    if(productAndPrice.find(productSold[i]) != productAndPrice.end())
    {
      float price = productAndPrice[productSold[i]];
      
      if(price != soldPrice[i])
      {
        err++;
      }
    }
  }
  
  return err;
  
}

int main() 
{
    vector<string> products = {"eggs", "milk", "cheese"};
    vector<float> productPrices = {2.89, 3.29, 5.79};
    vector<string> productSold = {"eggs","eggs", "cheese", "milk"};
    vector<float> soldPrice = {2.89, 2.99, 5.97, 3.29};
    
    int errors = priceCheck(products, productPrices, productSold, soldPrice); // Call the function and store the result
    cout << "Number of price errors: " << errors << endl; // Print the result

    return 0;
}

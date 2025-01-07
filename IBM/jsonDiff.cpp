#include <bits/stdc++.h>
using namespace std;

std::map<string, string> jsonParse(const string& jsonString)
{
  
  map<string, string> res;
  size_t pos = 0;
  
  while(pos < jsonString.size())
  {
    size_t key_start = jsonString.find('"', pos +1);
    size_t key_end = jsonString.find('"', key_start +1);
    size_t value_start = jsonString.find('"', key_end +1);
    size_t value_end = jsonString.find('"', value_start +1);
    
    if(key_start != string::npos && key_end != string::npos && value_start != string::npos && value_end != string::npos)
    {
      string key = jsonString.substr(key_start + 1, key_end - key_start - 1);
      string value = jsonString.substr(value_start + 1, value_end - value_start - 1);
      res[key] = value;
      pos = value_end + 1;
    }
    else
    {
      break;
    }
  }
  
  return res;
  
}

std::vector<string> getssoNpitf(const string& json1, const string& json2)
{
  vector<string> diff;
  
  map<string, string> map1 = jsonParse(json1);
  map<string, string> map2 = jsonParse(json2);
  
  auto keys = (map1.size() < map2.size()) ? map1 : map2;
  
  for(const auto& pair : keys)
  {
    const string& key = pair.first;
    
    if (map1.count(key) && map2.count(key))
    {
      if(map1[key] != map2[key])
      {
        diff.push_back(key);
      }
    }
  }
  
  sort(diff.begin(), diff.end());
  return diff;
}

int main() 
{
    string json1 = R"({"hello": "world", "hi": "hello", "you": "me"})";
    string json2 = R"({"hello": "world","hi": "helloo", "you": "me"})";
    
    vector<string> res = getssoNpitf(json1, json2);
    
    for(const auto& key : res)
    {
      std::cout << key << std::endl;
    }
    
    return 0;
}

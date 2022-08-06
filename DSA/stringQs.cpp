#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void lowerCase(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
    cout << str << endl;
}

void upperCase(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    lowerCase(str);
}

void sortString(string str)
{
    sort(str.begin(), str.end());

    // INBUILD UPPERCASE FUNCTION
    transform(str.begin(), str.end(), str.begin(), ::toupper); // transform(stringBegin, stringEnding, startingFromWhere, ::operation)
    cout << str << endl;

    // INBUILD LOWERCASE FUNCTION
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << str << endl;
}

void largestNum(string str)
{
    sort(str.begin(), str.end(), greater<int>());
    cout << str << endl;
}

void maxCountedAlpha(string str)
{
    int freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i] - 'a']++;
    }

    char ans = 'a';
    int maxF = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] >= maxF)
        {
            maxF = freq[i];
            ans = i + 'a';
        }
    }

    cout << "Alphabet is : " << ans << endl;
    cout << "Number of times repeating = " << maxF << endl;
}

int main()
{
    string strALPHA = "aewuifvhaweruicvn";
    sortString(strALPHA);
    maxCountedAlpha(strALPHA);

    string strNUM = "12359";
    largestNum(strNUM);
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    // WITHPUT SPACES
    // string str;
    // cin >> str;
    // cout << str << endl;

    // WITH SPACES
    // getline(cin, str);
    // cout << str;
    // cout << "\n";

    // APPENDING STRING

    // s1.append(s2);
    // cout << s1 << endl;

    // CONCATENATION
    string s1 = "Rup";
    string s2 = "am";
    cout << s1 + s2 << endl;

    // ACCESSING A PERTICULAR LETTER OF A STRING
    cout << s1[1] << endl;

    // COMPARING TWO STRINGS
    cout << s2.compare(s1) << endl;

    string s = "RupamKarmakar";

    // FOR SHOWING THE LENGTH OF A STRING
    cout << s.size() << endl;
    // or
    cout << s.length() << endl;

    string s3 = "07082003";

    // FOR CONVERTING ANY STRING TO INTEGER
    int x = stoi(s3);
    cout << x + 2 << endl;

    // FOR CONVERTING ANY INTEGER TO STRING
    cout << to_string(x) + " 2" << endl;

    // FOR SORTING ANY STRING
    string s4 = "sdiufgascbhliaweughwierg";
    sort(s4.begin(), s4.end());
    cout << s4 << endl;

    // FOR SHOWING ANY PARTICULAR PART OF A STRING
    cout << s.substr(5, 5); // substr(formWhichPosition , number of letters);

    // FOR SHOWING A STRING THROUGH LOOP
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i] << endl;
    }

    // FOR INSERTING ANY STRING IN A STRING
    s.insert(5, " Hello ");
    cout << s << endl;

    // FOR ERASING A PERTICULAR LETTER OF A STRING
    s.erase(3, 3); // erase(fromWhichElement , numberOfElements)
    cout << s << endl;

    // TO FIND IN A STRING
    cout << s.find("Rup") << endl;

    // CHECK IF THE STRING IS EMPTY OR NOT
    s1.clear();
    if (s1.empty())
    {
        cout << "String is empty" << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

void reverseString(string s)
{
    if (s.length() == 0)
    {
        return;
    }

    string ros = s.substr(1);
    reverseString(ros);
    cout << s[0];
}

int fib(int n)
{

    if (n == 0 || n == 1)
    {
        return n;
    }

    return (fib(n - 1) + fib(n - 2));
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    int prevFact = factorial(n - 1);
    return n * prevFact;
}

int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }

    int prevPower = power(n, p - 1);
    return n * prevPower;
}

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int prevSum = sum(n - 1);
    return (n + prevSum);
}

void replacePi(string s)
{
    if (s.length() == 0)
    {
        return;
    }

    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replacePi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacePi(s.substr(1));
    }
}

void towerOfHanoi(int n, char src, char dest, char helper)
{
    if (n == 0)
    {
        return;
    }

    towerOfHanoi(n - 1, src, helper, dest);
    cout << "Move from " << src << " to " << dest << endl;

    towerOfHanoi(n - 1, helper, dest, src);
}

string removeDup(string s)
{
    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];
    string ans = removeDup(s.substr(1));

    if (ch == ans[0])
    {
        return ans;
    }
    else
    {
        return (ch + ans);
    }
}

string moveAllX(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string ans = moveAllX(s.substr(1));

    if (ch == 'x' || ch == 'X')
    {
        return ans + ch;
    }
    return ch + ans;
}

void subSeq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);

    subSeq(ros, ans);
    subSeq(ros, ans + ch);
}

void subSeq2(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);

    subSeq2(ros, ans);
    subSeq2(ros, (ans + ch));
    subSeq2(ros, (ans + to_string(code)));
}

string keypadArr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string code = keypadArr[ch - '0'];
    string ros = s.substr(1);

    for (int i = 0; i < code.length(); i++)
    {
        keypad(ros, (ans + code[i]));
    }
}

void permutation(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);

        permutation(ros, (ans + ch));
    }
}

int countPath(int s, int e)
{
    if (s == e)
    {
        return 1;
    }

    if (s > e)
    {
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += countPath((s + i), e);
    }

    return count;
}

int countPathMaze(int n, int i, int j)
{
    if (i == (n - 1) && j == (n - 1))
    {
        return 1;
    }

    if (i >= n || j >= n)
    {
        return 0;
    }

    return (countPathMaze(n, (i + 1), j) + countPathMaze(n, i, (j + 1)));
}

int main()
{
    int n;
    int p;

    // cin >> n;
    // cout << sum(n) << endl;

    // cin >> n >> p;
    // cout << power(n, p);

    // cin >> n;
    // cout << factorial(n) << endl;

    // cin >> n;
    // cout << fib(n) << endl;

    // reverseString("binod");

    // replacePi("pippxxppiixipi");

    // towerOfHanoi(3, 'A', 'C', 'B');

    // cout << removeDup("aaaabbbeeecdddd") << endl;

    // cout << moveAllX("axxbdxcefxhix") << endl;

    // subSeq("ABC", "");
    // cout << endl;

    // subSeq2("AB", "");

    // keypad("23", "");

    // permutation("ABC", "");

    // cout << countPath(0, 3) << endl;

    cout << countPathMaze(3, 0, 0) << endl;

    return 0;
}
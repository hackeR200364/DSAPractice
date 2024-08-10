#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<sstream>

using namespace std;

int binaryToDecimal(int n)
{
	
	int ans = 0;
	int x = 1;
	while(n>0)
	{
		int y = n % 10;
		ans += x*y;
		x *= 2;
		n /= 10;
	}
	return ans;
	
}

int octalToDecimal(int n)
{
	int ans = 0;
	int x = 1;
	while(n>0)
	{
		int y = n % 10;
		ans += x*y;
		x *= 8;
		n /= 10;
	}
	return ans;
}

int hexaDecimalToDecimal(string n)
{
	int ans = 0;
	int x = 1;
	
	int s = n.size();
	for(int i= s-1; i>=0; i--)
	{
		if(n[i]>='0' && n[i]<='9')
		{
			ans += x*(n[i]-'0');
		}
		else if(n[i]>='A' && n[i]<='F')
		{
			ans += x*(n[i]-'A' + 10);
		}
		x *= 16;
	}
	return ans;
}

int decimalToBinary(int n)
{
	int x = 1;
	int ans = 0;
	while(x<=n)
	{
		x *= 2;
	}
	x/=2;
	
	while(x>0)
	{
		int lastDigit = n/x;
		n -= lastDigit*x;
		x /= 2;
		ans = ans*10 + lastDigit;
	}
	return ans;
}

int decimalToOctal(int n)
{
	int x = 1;
	int ans = 0;
	while(x<=n)
	{
		x *= 8;
	}
	x/=8;
	
	while(x>0)
	{
		int lastDigit = n/x;
		n -= lastDigit*x;
		x /= 8;
		ans = ans*10 + lastDigit;
	}
	return ans;
}

string decimalToHexadecimal(int n)
{
	int x = 1;
	string ans = "";
	while(x<=n)
	{
		x *= 16;
	}
	x/=16;
	
	while(x>0)
	{
		int lastDigit = n/x;
		n -= lastDigit*x;
		x /= 16;
		int l = lastDigit;
		
		if(lastDigit <= 9)
		{
			ans = ans + to_string(lastDigit);
		}
		else 
		{
			char c = 'A' + lastDigit - 10;
			ans.push_back(c);
		}
		
	}
	return ans;
}

int main()
{
    int n;
    char res;
    cout<<"For Binary to Decimal enter 'B'\nFor Octal to Decimal enter 'O'\nFor Hexa Decimal to Decimal enter 'H'\nFor Decimal to Binary enter 'D'\nFor Decimal to Octal enter '1'\nFor Decimal to Octal enter '2'\n";
    cin>>res;
    switch(res)
    {
    	case 'B':
    		cout<<"n = ";
    		cin >> n;
    		cout << binaryToDecimal(n) << endl;
    		break;
    		
    	case 'O':
    		cout<<"n = ";
    		cin >> n;
    		cout << octalToDecimal(n) << endl;
    		break;
    		
    	case 'H':
    		{
    		string s;
    		cout<<"n = ";
    		cin >> s;
    		cout << hexaDecimalToDecimal(s) << endl;
    		break;
			}
    	
    	case 'D':
    		cout<<"n = ";
    		cin >> n;
    		cout << decimalToBinary(n) << endl;
    		break;
    		
    	case '1':
    		cout << "n = ";
    		cin >> n;
    		cout << decimalToOctal(n) << endl;
    		break;
    		
    	case '2':
    		cout << "n = ";
    		cin >> n;
    		cout << decimalToHexadecimal(n) << endl;
    		break;
    		
    	default:
    		cout << "Please choose correct option" << endl;
    		break;
    		
	}
    
    return 0;    
}

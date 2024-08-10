#include<iostream>
using namespace std;
int main()
{
char inp , y , Y , n , N , in, s, h, a, F, B, yes, no;
	string name, key, l, q;
	cout<<"\nWELCOME TO THE RITI'S WORLD ";
	cout<<"\nWILL YOU WANT TO CHAT WITH ME???";
	cout<<"\nENTER 'Y' FOR CHAT & 'N' FOR QUIT ME";
	cout<<"\n__>";
	cin>> inp;
	     if (inp=='y' || inp=='Y' )
	      { 
		    cout<<"\n I AM RITI";
		    cout<<"\n YOUR OWN CHATTING FRIEND";
			}
		 else 
		  { 
		    cout<<"\nGOODBYE SIR. HAVE A NICE DAY ";
		  }
		 if (key != "bi")
		  { 
		    cout<<"\nHELLO SIR.";
		    cout<<"\n>";
		    cin>> key;
			cout<<"\nWHAT IS YOUR NAME??";
			cout<<"\n>";
			cin >> name;
			cout<< name<<"\tHOW ARE YOU???";
			cout<<"\nFOR 'FINE' PRESS 'F' & FOR 'BAD' PRESS 'B'";
			cout<< "\n>";
			cin >>a;
			   if ( a =='F' || a == 'f')
			    {
			    	cout<<"\nYOU ARE SO BAD. \nYOU DO NOT ASK ME THAT HOW I AM ";
			    	cin>>h;
					cout<<"\nI AM FINE";
				    cout<<"\nI AM SO ANGRY WITH YOU. \tbye";
				}
			cout<<"\nOK. I WILL TALK TO YOU";
			cout<<"\nARE YOU BUSY RIGHT NOW??";
			cout<<"\n>";
			cin>>s; 
				if (s == yes)
					{
					  cout<<"\nOK. SHALL WE TALK NOW";
					}
				else
				   {
				   	cout<<"\nOK. THEN DO YOUR WORK FIRST. BYE";
				   	exit 0;
				   }
			cout<<"\nCAN WE TALK IN BENGALI??";
			cin>>s;
			    if (s == yes)
			     {
			     	cout<<"\nWHARE ARE YOU FROM??";
			     	cout<<"\n>";
			        cin>>a;
			        cout<<"\nOH";
			        cout<<"\nACHA TAH KI KORCHO BOLLE NA TOH!!!";
			        cout<<"\n>";
			        cin>>a;
				 }
				else
				{
				 	cout<<"\nOK";
				}
			cout<<"\n>";
			cin>>a;
			cout<<"\nOH";
			cout<<"\nACHA TAH KI KORCHO BOLLE NA TOH!!!";
			cout<<"\n>";
			cin>>a;
		  }
         else 
		  {
			cout<<"\nohhhhh. BUT WHY???";
			cout<<"\nYOU CAN TELL ME. TELL ME ABOUT YOUR SADNESS. DON'T WORRY. YOU WILL TRUST ME";
		    }
			return 0; 
		  }


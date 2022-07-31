#include<iostream>
using namespace std;

int main(){
	
//	int i = 1;
//	int j = 1;
//	int k;
//				  //(After Use)  //(After Use)   //(Before Use) //(Before Use)
//	    //1 //1   //1->2         //1->2          //2->3         //2->3
//	k = i  + j +   i++         +  j++         +   ++i          +  ++j;
//	
//	cout<<"K = "<<k<<endl;
//	cout<<"I = "<<i<<endl;
//	cout<<"J = "<<j<<endl;

	int i = 1;
	int k;
	    //(After Use)  //(Before Use)   //(Before Use) //(After Use)
	    //1->2         //2->1          //1->2          //2->1
	k =   i++        -  --i          +   ++i          +  i--;
	
	cout<<"K = "<<k<<endl;
	cout<<"I = "<<i<<endl;
	
	return 0;
}

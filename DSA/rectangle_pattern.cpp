#include<iostream>
using namespace std;

int main(){
    
    int r , c;
    cout<<"Please enter Row"<<endl;
    cin>>r;
    cout<<"Please enter Column"<<endl;
    cin>>c;
    
    for(int i = 0; i < c; i++){
    	for(int j = 0; j < r; j++){
    		cout<<"*";
		}
		
		cout<<endl;
		
	}
    
    
    return 0;    
}

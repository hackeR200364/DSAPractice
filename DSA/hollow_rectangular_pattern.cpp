#include<iostream>
using namespace std;

int main(){
    
    int r , c;
    cout<<"Please enter Row"<<endl;
    cin>>r;
    cout<<"Please enter Column"<<endl;
    cin>>c;
    
    for(int i = 0; i <= r; i++){
    	
    	for(int j = 0; j <= c; j++){
    		
    		if(i == 0 || i == r || j == 0 || j == c){
    			
    			cout<<"*";
    			
			}else{
				
				cout<<" ";
				
			}
		}
		
		cout<<endl;
		
	}
    
    
    return 0;    
}

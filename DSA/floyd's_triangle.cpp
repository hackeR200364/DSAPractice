#include<iostream>
using namespace std;

int main(){
    
	int c, count = 1;
	cin>>c;
	for(int i=0; i<=c; i++){
		for(int j=0; j<i; j++){
			cout<<count<<" ";
			
			count++;
		}
		cout<<endl;
	}
    
    
    return 0;    
}

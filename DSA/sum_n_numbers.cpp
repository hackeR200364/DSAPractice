#include<iostream>
using namespace std;

int main(){
	
	int n, sum = 0;
    char res;
    cout<<"Please choose a option\nPlease enter 'a' for loop-sum & 'b' for formula-sum"<<endl;
    cin>>res;
    
    switch(res){
    	case 'a':
    		cin>>n;
    		for(int i=1; i<=n; i++){
    			sum += i;
			}
			cout<<"Loop-sum of n numbers = "<<sum<<endl;
			break;
		case 'b':
			cin>>n;
			sum = (n*(n+1))/2;
			cout<<"Formula-sum of n numbers = "<<sum<<endl;
			break;
		default:
			cout<<"Please enter correct option"<<endl;
			break;
	}
    	
    
    
    
    return 0;    
}

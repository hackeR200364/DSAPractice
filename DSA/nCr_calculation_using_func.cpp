#include<iostream>
using namespace std;

int fact(int n){
	
	int factorial = 1;
	for(int i=2; i<=n; i++){
		factorial*=i;
	}
	return factorial;
}

int nCr(int n , int r){
	
	int factUpperAns = fact(n);
	int factLowerFirstAns = fact((n-r));
	int factLowerSecondAns = fact(r);
	
	double nCrAnswer = factUpperAns/(factLowerFirstAns * factLowerSecondAns);
	
	return nCrAnswer;
	
}

int main(){
    int n,r;
    cin>>n>>r;
    
    int ans = nCr(n,r);
    cout<<ans<<endl;
    
    return 0;    
}

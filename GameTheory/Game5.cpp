#include <bits/stdc++.h>
using namespace std;
long long n;

int main(){
	long long act[2000];
	act[0] = 1;
	for(int i = 0 ; act[i] < (1LL<<60);i+=2){
		act[i+1] = act[i]*9;
		act[i+2] = act[i+1]*2; 
	}
	while(cin >> n){
		int i;
		for(i = 1 ; i < 2000 ; i++)
			if(act[i] >= n) break;
		cout << (i%2 ? "Stan wins.":"Ollie wins.")<<endl;
	}
	return 0;
}
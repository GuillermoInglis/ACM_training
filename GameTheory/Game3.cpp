#include <bits/stdc++.h>
using namespace std;
int n,m;

int minmax(int a,int b, bool ply){	
	if(b == 0) 
		if(ply) 
			return 0;
		else return 1;

	if(ply)
		if(a/b == 1) return minmax(b,a%b,!ply);
		else return max(minmax(b,a%b,!ply),minmax(b + a%b,b,!ply)); 
	else
		if(a/b == 1) return minmax(b,a%b,!ply);
		else return min(minmax(b,a%b,!ply),minmax(b + a%b,b,!ply));
}


int main(){
	while(cin >> n >> m){
		if(!n && !m) break;
		cout << (minmax(max(n,m),min(n,m),true)? "Stan wins":"Ollie wins") << endl;
	}
	return 0;
}
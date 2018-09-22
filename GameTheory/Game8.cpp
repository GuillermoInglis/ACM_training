#include <bits/stdc++.h>
using namespace std;
long long n,i;
long long data[10000000];

int minmax(long long  act, bool ply){
	if( 2*act < n )
		if(ply) return  max(minmax(act*2,!ply),minmax(act+1,!ply));
		else 	return  min(minmax(act*2,!ply),minmax(act+1,!ply));
	else
		if( (n-act) & 1 ) return  (ply? -1 : 1);
		else  return (ply? 1 : -1);
}

int main(){
	cin >> n;
	while(cin >> n){

		cout << ( minmax(1,true)== 1? "Ivica":"Marica") << endl;
		
	}
	return 0;
}
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
	vector <int> data = 
	data[0] = 2;
	for(i = 0 ; data[i] < (3000) ; i += 8){
		data[i+1] = data[i]+8; 
		data[i+2] = data[i+1]+24;
		data[i+3] = data[i+2]+8;
		data[i+4] = data[i+3]+88;
		data[i+5] = data[i+4]+8; 
		data[i+6] = data[i+5]+24;
		data[i+7] = data[i+6]+8;
		data[i+8] = data[i+7]+344;
	}
	while(cin >> n){

		next = (n-2)%512 + 1;
		
		prev = next-2


		for(i = 0 ; 10000 ; i ++)
			if( n < data[i] ){
				cout << n <<" "<< data[i] << endl;
				if((n == data[i]-1) || (n == data[i-1]+1) ) cout << "Ivica " << endl;
				else cout << "Marica ";
				break;
			}
		cout << ( minmax(1,true)== 1? "Ivica":"Marica") << endl;
		
	}
	return 0;
}
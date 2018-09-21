#include <bits/stdc++.h>
using namespace std;
int T,a,n,cases = 0,ans;

int main(){
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n;
		for(int i = 1 ; i <= n ; i++){
			cin >> a;
			while(a--)
				ans = ans ^ i;
		}
		cout <<(ans?"Tom Wins":"Hanks Wins")<< endl;
	}
	return 0;
}
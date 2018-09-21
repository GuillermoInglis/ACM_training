#include <bits/stdc++.h>
using namespace std;
int T,a,b,n,m,ans;

int main(){
	cin >> T;
	while(T--){
		cin >> m >> n;
		cin >> a >> b;
		ans = (a)^(b)^(m - a -1)^(n-b-1);
		cout << (ans? "Gretel":"Hansel") << endl;
	}
	return 0;
}
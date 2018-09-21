#include <bits/stdc++.h>
using namespace std;
char n;
vector<vector<char> > tab;

map <vector<vector<char> >,char> mm;

int ask(){
	int ans = 0;
	bool aux;
	for(int i = 0 ; i < 4 ; i++){
		aux = tab[i][0] != '.';
		for(int j = 1 ; j < 4 ; j++) if(tab[i][j] !=tab[i][0]) aux = false;
		if(aux) if(tab[i][0] == 'x') return 1; else return -1;
		aux = tab[0][i] != '.';
		for(int j = 1 ; j < 4 ; j++) if(tab[j][i] !=tab[0][i]) aux = false;
		if(aux) if(tab[0][i] == 'x') return 1; else return -1;
	}

	aux =  tab[0][0] != '.';
	for(int i = 1 ; i < 4 ; i++) if(tab[i][i] != tab[0][0]) aux = false;
	if(aux) if(tab[0][0] == 'x') return 1; else return -1;
	aux =  tab[0][3] != '.';
	for(int i = 1 ; i < 4 ; i++) if(tab[i][3-i] != tab[0][3]) aux = false;
	if(aux) if(tab[0][3] == 'x') return 1; else return -1;

	return 0;
}
int minmax(bool ply, bool inicio = false){	
	
	if(mm.count(tab)>0) return mm[tab];
	if(ask() != 0) return mm[tab] = ask();
	int res = 0; bool flag = false;
	char act = (ply? 'x' : 'o');
	for(int l = 0 ; l < 4 ;l++)
		for(int k = 0 ; k < 4; k++)
			if(tab[l][k] == '.'){
				tab[l][k] = act;
				if (ply) {
					if(!flag) res = minmax(!ply,false);
					else res = max(minmax(!ply,false),res);
				}
				else { 
					if(!flag) res = minmax(!ply,false);
					else res = min(minmax(!ply,false),res);
				}
				if(inicio) cout << "fidel" << endl;
				tab[l][k] = '.';
				if(inicio && res == 1){ cout <<"xd " << res <<endl; return l*4+k;}
				if(res == 1 && ply) {return mm[tab] = 1;}
				if(res == -1 && !ply){return mm[tab] = -1;}
				flag = true;
			}
	if(!inicio) return mm[tab] = res;
	return -900;
}

int main(){
	while(cin >> n){
		if(n == '$') break;
		tab.clear();
		for(int i = 0 ; i < 4;i++){
			vector <char> aux;
			for(int j = 0 ; j < 4; j++)
				cin >> n,aux.push_back(n);
			tab.push_back(aux);
		}
		//cout << ask() << endl;
		cout << minmax(true,true)<< endl;
		
	}

	return 0;
}
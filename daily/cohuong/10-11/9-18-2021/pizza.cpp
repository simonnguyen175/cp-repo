#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int t, tt = 1, type;
int trie[N][26], cnt1[N], cnt2[N];
string s;

void Add(string s){
	int id = 0;
	for(int i = 0; i < s.size(); i ++){
		if( trie[id][s[i]-'a'] == -1 )
			trie[id][s[i]-'a'] = ++tt;
		id = trie[id][s[i]-'a'];
		cnt2[id] ++;
	}
	cnt1[id] ++;
}

int Count1(string s){
	int res = 0, id = 0;
	for(int i = 0; i < s.size(); i ++){
		if( trie[id][s[i]-'a'] == -1 ) break;
		id = trie[id][s[i]-'a'];
		res += cnt1[id];
	}
    return res;
}

int Count2(string s){
	int id = 0;
	for(int i = 0; i < s.size(); i ++){
		if( trie[id][s[i]-'a']== -1 ) return 0;
		id = trie[id][s[i]-'a'];
	}
	return cnt2[id];
}

int main(){
	cin >> t;
	memset(trie, -1, sizeof trie);
	while( t -- ){
		cin >> type >> s;
		if( type == 0 ) Add(s);
		if( type == 1 ) cout << Count1(s) << '\n';
		if( type == 2 ) cout << Count2(s) << '\n';
	}
	return 0;
}

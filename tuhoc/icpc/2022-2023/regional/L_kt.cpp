#include<bits/stdc++.h>
using namespace std;

string s;
int k, cnt[25];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> s >> k;
	
	memset(cnt, 0, sizeof cnt); 
	
	for (int i = 0; i < s.size(); i ++){
		cnt[s[i]-'a'] ++; 
		if ( i >= k ) cnt[s[i-k]-'a'] --; 
		int d = 0;
		for (int j = 0; j <= 25; j ++) if ( cnt[j] ){
			d ++;
		}
		if ( i >= k-1 ) assert(d>1);  
	}

    return 0;
}

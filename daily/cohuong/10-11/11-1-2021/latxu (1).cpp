#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 35 , inf = 1e9 , 
      r[] = {0 , 0 , 0 , 1 , -1} ,
      c[] = {0 , 1 , -1 , 0 , 0} ;

void file() {
	freopen("latxu.inp" , "r" , stdin);
	freopen("latxu.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int m , n , a[N][N] , cnt = 0 , id[N][N];
string str , s[N];

namespace sub3 {
	int f[N * N][N * N] , ans;
	int Gauss(int C) {
		int res = 0;
		memset(f , 0 , sizeof(f));
		
		for(int i = 1 ; i <= m ; i++) 
			for(int j = 1 ; j <= n ; j++) {
		 	   for(int k = 0 ; k < 5 ; k++) {
		 	   	 int nx = i + r[k] , ny = j + c[k];
		 	   	 if(nx > m || nx < 1 || ny < 1 || ny > n) continue;
		 	   	 f[id[i][j]][id[nx][ny]] = 1;
				}
				f[id[i][j]][cnt + 1] = a[i][j] ^ C;
		    }
        
		for(int i = 1 ; i <= cnt ; i++) {
			for(int j = 1 ; j <= cnt ; j++) 
				if(f[i][j]) {
					for(int k = 1 ; k <= cnt ; k++) if(k != i && f[k][j]) {
						for(int l = 1 ; l <= cnt + 1 ; l++) f[k][l] = f[i][l] ^ f[k][l];
					}
					break;
				}
	    }
	    
        for(int i = 1 ; i <= cnt ; i++) {
        	bool ok = false;
        	for(int j = 1 ; j <= cnt ; j++) if(f[i][j]) {
        		ok = true; 
        		break;
			}
			if(ok) res += f[i][cnt + 1];
			else {
				if(f[i][cnt + 1]) return inf;
			}
		}

		return res;
	}
	
	void solve() {
     	 ans = min(Gauss(0) , Gauss(1));
     	 cout << ((ans == inf) ? -1 : ans);
	}
}

int main() {
	file();
  while(cin >> str) {
  	s[++m] = str;
  	n = str.size();
  }
  for(int i = 1 ; i <= m ; i++)
   for(int j = 1 ; j <= n ; j++)
    a[i][j] = (s[i][j - 1] == 'b') ? 1 : 0 , id[i][j] = ++cnt;
  sub3::solve();
}


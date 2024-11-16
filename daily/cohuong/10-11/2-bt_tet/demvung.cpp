#include<bits/stdc++.h>
using namespace std;

const int row[4]={1,0,0,-1};
const int column[4]={0,-1,1,0};
int m, n, ans=0, a[21][21], b[21][21];
bool isPrime[100001];

void sieve(){
    memset(isPrime, true, sizeof isPrime);
    isPrime[1]=false;
    for (int i=2; i*i<=100000; i++)
        if ( isPrime[i] )
            for (int j=i*i; j<=100000; j+=i)
                if (isPrime[j]) isPrime[j]=false;
}

bool kt(int x, int y){
    if( x < 1|| x > m || y < 1 || y > n || b[x][y] != 0 ) return false;
    else return true;
}

void gen(int x, int y){
    b[x][y] = 1;
    for(int i=0; i<=3; i++){
        if( !kt(x + row[i] , y + column[i]) ) continue;
        gen(x+row[i], y+column[i]);
    }
}

int main(){
	freopen("demvung.inp", "r", stdin);
	freopen("demvung.out", "w", stdout);
    sieve();
    cin >> m >> n;
    for(int i=1; i <= m; i++)
        for(int j=1; j <= n; j++){
            cin >> a[i][j];
            if ( isPrime[a[i][j]] ) a[i][j]=0;
            b[i][j]=a[i][j];
        }
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++){
            if( b[i][j] == 0 ){
                ans++;
                gen(i,j);
            }
        }
    cout << ans << '\n';
    for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
    }
    return 0;
}

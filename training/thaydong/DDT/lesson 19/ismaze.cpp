#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll , ll>
#define fi first
#define se second
#define pb push_back

const int N = 3e3 + 5 , Row[] = {1 , 0 , -1 , 0} , Col[] = {0 , 1 , 0 , -1};

int n ;
char a[N][N];
bool vis[N][N];

bool outside(int x , int y) {
	return (x < 1 || x > n || y < 1 || y > n || a[x][y] == '1');
}

void DFS(int x , int y , int prex , int prey) {
	vis[x][y] = true;
    for(int t = 0 ; t < 4 ; t++) {
        int nx = x + Row[t] , ny = y + Col[t];
        if(outside(nx , ny) || (nx == prex && ny == prey)) continue;
        if(vis[nx][ny]) {
            cout << "No";
            exit(0);
        }
        DFS(nx , ny , x , y);
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	memset(vis , false , sizeof vis);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	for(int j = 1 ; j <= n ; j++)
		cin >> a[i][j];
	for (int i = 1 ; i <= n ; i++)
	for (int j = 1 ; j <= n ; j++)
		if(!vis[i][j] && a[i][j] == '0') DFS(i , j , 0 , 0);
	cout << "Yes";
	return 0;
}

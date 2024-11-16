#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;

int w, h, n;
vector<int> ans;
bool vis[N][N], down[N][N], up[N][N], Right[N][N], Left[N][N];

bool check(int x, int y){
    return ( x >= 1 && x <= w && y >= 1 && y <= h );
}

void bfs(int xu, int yu){
    vis[xu][yu] = 1; int tmp = 1;
    queue<pair<int, int>> q; q.push({xu, yu});

    while ( q.size() ){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if ( !Right[x][y] && !vis[x][y+1] && check(x, y+1) ){
            tmp ++;
            q.push({x, y+1});
            vis[x][y+1] = 1;
        }
        if ( !Left[x][y] && !vis[x][y-1] && check(x, y-1) ){
            tmp ++;
            q.push({x, y-1});
            vis[x][y-1] = 1;
        }
        if ( !up[x][y] && !vis[x+1][y] && check(x+1, y) ){
            tmp ++;
            q.push({x+1, y});
            vis[x+1][y] = 1;
        }
        if ( !down[x][y] && !vis[x-1][y] && check(x-1, y) ){
            tmp ++;
            q.push({x-1, y});
            vis[x-1][y] = 1;
        }
    }

    ans.push_back(tmp);
}

int main(){
    cin >> w >> h >> n;
    for (int i = 1; i <= n; i ++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if ( a == c ){
            int l = min(b, d), r = max(b, d);
            for (int i = l + 1; i <= min(w, r); i ++){
                Right[i][a] = Left[i][a+1] = 1;
            }
        }
        else if ( b == d ){
            int l = min(a, c), r = max(a, c);
            for (int i = l + 1; i <= min(h, r); i ++){
                up[b][i] = down[b+1][i] = 1;
            }
        }
    }


    for (int i = 1; i <= h; i ++)
        for (int j = 1; j <= w; j ++)
            if ( vis[i][j] ) continue;
            else bfs(i, j);

    sort(ans.begin(), ans.end(), greater<int>());

    for (auto v : ans) cout << v << '\n';
}

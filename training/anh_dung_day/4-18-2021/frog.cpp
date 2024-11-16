#include <bits/stdc++.h>
#define simon "frog"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e4+5e2+5;
const ll oo=1e15;
const int MOD=123456789;

struct opt{
    int val;
    int x;
    int y;
    int h;
};

int n, X, Y, a[N][N], dp[N];
vector<opt> pos;
opt row[N][5], col[N][5];

bool compare(opt a, opt b){
    if ( a.val < b.val ) return true;
    else return false;
}

void updateRowArray(int val, int rowX, int colX, int hX){
    int tmppos, tmpval=INT_MAX;
    for (int j=1; j<=4; j++)
        if ( tmpval > row[rowX][j].val ){
            tmpval=row[rowX][j].val;
            tmppos=j;
        }
    if ( tmpval < val ){
        row[rowX][tmppos].val=val;
        row[rowX][tmppos].y=colX;
        row[rowX][tmppos].h=hX;
    }
}

void updateColArray(int val, int rowX, int colX, int hX){
    int tmppos, tmpval=INT_MAX;
    for (int j=1; j<=4; j++)
        if ( tmpval > col[colX][j].val ){
            tmpval=col[colX][j].val;
            tmppos=j;
        }
    if ( tmpval < val ){
        col[colX][tmppos].val=val;
        col[colX][tmppos].x=rowX;
        col[colX][tmppos].h=hX;
    }
}

void updateDP(int i){
    /// cap nhat so duong di den nhat di den vi tri i
    int rowX=pos[i].x, colX=pos[i].y, hX=pos[i].val;

    // cap nhat theo hang
    for (int j=1; j<=4; j++){
        if ( row[rowX+1][j].val != 0 && row[rowX+1][j].h < hX )
            if ( row[rowX+1][j].y > colX+1 || row[rowX+1][j].y < colX-1 )
                dp[i]=max(dp[i], row[rowX+1][j].val + 1);

        if ( row[rowX-1][j].val != 0 && row[rowX-1][j].h < hX )
            if ( row[rowX-1][j].y > colX+1 || row[rowX-1][j].y < colX-1 )
                dp[i]=max(dp[i], row[rowX-1][j].val+1);
    }

    // cap nhat theo cot
    for (int j=1; j<=4; j++){
        if ( col[colX+1][j].val != 0 && col[colX+1][j].h < hX)
            if ( col[colX+1][j].x > rowX+1 || col[colX+1][j].x < rowX-1 )
                dp[i]=max(dp[i], col[colX+1][j].val+1);

        if ( col[colX-1][j].val != 0 && col[colX-1][j].h < hX )
            if ( col[colX-1][j].x > rowX+1 || col[colX-1][j].x < rowX-1 )
                dp[i]=max(dp[i], col[colX-1][j].val+1);
    }

    /// cap nhat mang row va mang col
    updateRowArray(dp[i], rowX, colX, hX);
    updateColArray(dp[i], rowX, colX, hX);
}

int main(){
    FASTio
    if ( fopen ( simon".inp","r" ) ){
        freopen ( simon".inp", "r", stdin );
        freopen ( simon".out", "w", stdout );
    }

    /// SETUP
    cin >> n >> X >> Y;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++){
            cin >> a[i][j];
            opt tmp;
            tmp.val=a[i][j]; tmp.x=i; tmp.y=j;
            pos.push_back(tmp);
        }
    sort(pos.begin(), pos.end(), compare);
    memset(dp, 0, sizeof dp);
    int id;
    for (int i=0; i<pos.size(); i++)
        if ( pos[i].x == X && pos[i].y == Y ){
            id=i;
            dp[id]=1;
            updateRowArray(dp[i], X, Y, pos[i].val);
            updateColArray(dp[i], X, Y, pos[i].val);
            break;
        }

    /// SOLVE
    for (int i=id+1; i<pos.size(); i++){
        updateDP(i);
    }

    /// lay kqua
    int ans=0;
    for (int i=id; i<pos.size(); i++)
        ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}

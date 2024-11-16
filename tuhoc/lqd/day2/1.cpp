#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e2 + 5;
const int oo = 1e9+7;

int n;
struct opt{
    int x, y, z;
};
opt a[N];
int mnz[2][N][N][N], mxz[2][N][N][N];
bool cky[2][N][N][N], ckz[2][N][N][N];
int Real[N];

int main(){
    vector<int> cont;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y >> a[i].z;
        cont.pb(a[i].y);
    }

    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    for (int i = 0; i < cont.size(); i ++)
        Real[i+1] = cont[i];

    int lim = cont.size();

    sort(a+1, a+1+n, [](opt a, opt b){
        return a.x < b.x;
    });

    memset(mxz, -0x3f, sizeof mxz);
    memset(mnz, 0x3f, sizeof mnz);

    for (int i = 1; i <= n; i ++)
    for (int mny = 1; mny <= lim; mny ++)
    for (int mxy = mny; mxy <= lim; mxy ++){
        for (int j = 1; j <= i; j ++)
            if ( Real[mny] > a[j].y || a[j].y > Real[mxy] ){
                mxz[0][i][mny][mxy] = max(mxz[0][i][mny][mxy], a[j].z);
                mnz[0][i][mny][mxy] = min(mnz[0][i][mny][mxy], a[j].z);
                ckz[0][i][mny][mxy] = 1;
            }
            else cky[0][i][mny][mxy] = 1;
    }

    for (int i = n; i >= 1; i --)
    for (int mny = 1; mny <= lim; mny ++)
    for (int mxy = mny; mxy <= lim; mxy ++){
        for (int j = i; j <= n; j ++)
            if ( Real[mny] > a[j].y || a[j].y > Real[mxy] ){
                mxz[1][i][mny][mxy] = max(mxz[1][i][mny][mxy], a[j].z);
                mnz[1][i][mny][mxy] = min(mnz[1][i][mny][mxy], a[j].z);
                ckz[1][i][mny][mxy] = 1;
            }
            else cky[1][i][mny][mxy] = 1;
    }

    ll ans = 4LL*oo;
    for (int i = 1; i <= n; i ++)
    for (int j = i; j <= n; j ++)
    for (int mny = 1; mny <= n; mny ++)
    for (int mxy = mny; mxy <= n; mxy ++)
    if ( ( cky[0][i-1][mny][mxy] && ckz[1][j+1][mny][mxy] )
      || ( ckz[0][i-1][mny][mxy] && cky[1][j+1][mny][mxy] )
      || ( ckz[0][i-1][mny][mxy] && cky[0][i-1][mny][mxy] )
      || ( ckz[1][j+1][mny][mxy] && cky[1][j+1][mny][mxy] )  ){
        int mnZ = min(mnz[0][i-1][mny][mxy], mnz[1][j+1][mny][mxy]);
        int mxZ = max(mxz[0][i-1][mny][mxy], mxz[1][j+1][mny][mxy]);

        ll tmp = a[j].x - a[i].x;
        tmp += Real[mxy] - Real[mny];
        tmp += mxZ - mnZ;

        ans = min(ans, tmp);
    }

    cout << ans;

    return 0;
}

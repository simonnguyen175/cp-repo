#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;

int n, m;
int a[N], cnt[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for( int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cnt[a[i]] ++;

    int mex = 0;
    while ( cnt[mex] )
        mex ++;

    for (int i = m + 1; i <= n; i ++){
        cnt[a[i-m]] --;
        cnt[a[i]] ++;
        if ( !cnt[a[i-m]] ) mex = min(a[i-m], mex);
    }

    cout << mex;
    return 0;
}

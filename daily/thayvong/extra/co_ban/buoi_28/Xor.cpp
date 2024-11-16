#include<bits/stdc++.h>
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "Xor"
using namespace std;
const int N=1e5+5;

int n, m, a[N], b[N];
vector<int> xo, c;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }

    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        xo.push_back(a[i]);
    }
    for (int i=1; i<=m; i++){
        cin >> b[i];
        xo.push_back(b[i]);
    }

    sort(xo.begin(), xo.end());
    int d=1;
    for (int i=1; i<xo.size(); i++)
        if ( xo[i] == xo[i-1] ) d++;
        else{
            if ( d == 1 ) c.push_back(xo[i-1]);
            d=1;
        }
    if ( d == 1 ) c.push_back(xo[xo.size()-1]);

    sort(c.begin(), c.end());
    if ( c.size() == 0 ) cout << "No Solution";
    else
        for (int i=0; i<c.size(); i++)
            cout << c[i] <<' ';
    return 0;
}

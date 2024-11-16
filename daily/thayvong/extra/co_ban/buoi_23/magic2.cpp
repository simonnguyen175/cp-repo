#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, a, b, c, k;

string magic(ll a, ll b, ll c, ll k){
    if ( (a==0 && b==0) || (b==0 && c==0) || (c==0 && a==0) ) return "No";
    if ( a < 0 && b > 0 && c < 0 ) return "No";
    if ( a > 0 && b < 0 && c > 0 ) return "No";
    if ( a > 0 ){
        int dem=0;
        if ( a >= b )
            while ( a >= b ){b*=2; dem++; if (dem > k) return "No";}
        if ( b >= c )
        while ( b >= c ){c*=2; dem++; if (dem > k) return "No";}
        if ( dem <= k ) return "Yes";
        else return "No";
    }
    else{
        int dem=0;
        while ( a >= b ){a*=2;dem++; if (dem > k) return "No";}
        if ( b >= 0 )
            while ( b >= c ){c*=2; dem++; if (dem > k) return "No";}
        else
            while ( b >= c ){b*=2;dem++; if (dem > k) return "No";}
        if ( dem <= k ) return "Yes";
        else return "No";
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    freopen("magic2.inp","r",stdin);
    freopen("magic2.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a >> b >> c >> k;
        cout << magic(a, b, c, k) <<'\n';
    }
    return 0;
}

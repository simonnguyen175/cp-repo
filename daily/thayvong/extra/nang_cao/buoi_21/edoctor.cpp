#include <bits/stdc++.h>
#define simon "edoctor"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e6+5;
const ll oo=1e15;
const int MOD=123456789;

int n;
ll a[N], k;
vector<int> part2;

int main(){
    FASTio
    if ( fopen ( simon".inp","r" ) ){
        freopen ( simon".inp", "r", stdin );
        freopen ( simon".out", "w", stdout );
    }
    cin >> n >> k;
    ll sumTime=0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        sumTime += a[i];
    }

    if ( sumTime <= k ){
        cout << -1;
        return 0;
    }

    int round=k/n;
    for (int i=1; i<=n; i++)
        a[i]-=round;

    k%=n;
    int j=1, cnt=0;
    for (j; j<=n; j++){
        if ( cnt == k ) break;
        if ( a[j] > 0 ){
            a[j]--;
            cnt++;
        }
    }

    for (int i=j; i<=n; i++)
        if ( a[i] > 0 ) cout << i <<' ';
    for (int i=1; i<j; i++)
        cout << i <<' ';

    return 0;
}

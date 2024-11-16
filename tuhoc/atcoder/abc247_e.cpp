#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n, X, Y;
int a[N];
vector<int> b;
ll ans = 0;

void xuli(){
    if ( !b.size() ) return;

    int len = b.size();
    ans += 1ll*len*(len+1)/2; len = 0;

    for (int x : b){
        if ( x == X ) ans -= 1LL*len*(len+1)/2, len = 0;
        else len ++;
    }
    ans -= 1LL*len*(len+1)/2; len = 0;

    for (int x : b){
        if ( x == Y ) ans -= 1LL*len*(len+1)/2, len = 0;
        else len ++;
    }
    ans -= 1LL*len*(len+1)/2; len = 0;

    for (int x : b){
        if ( x == X || x == Y ) ans += 1LL*len*(len+1)/2, len = 0;
        else len ++;
    }
    ans += 1LL*len*(len+1)/2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> X >> Y;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++){
        if ( a[i] > X || a[i] < Y ) xuli(), b.clear();
        else b.pb(a[i]);
    }
    xuli();

    cout << ans;
    return 0;
}

#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 6e4 + 5;

int n;
pair<int, int> a[N];
long long bit[N], ans = 0;

void updatePoint(int u, int v){
    int idx = u;
    while ( idx <= n ){
        bit[idx] += v;
        idx += idx & (-idx);
    }
}

long long getsum(int u){
    int idx = u;
    long long ans = 0;
    while ( idx > 0 ){
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

int main(){
    FASTio
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + 1 + n, greater<pair<int, int>>());

    /*
    for (int i = 1; i <= n; i ++)
        cout << a[i].first <<' ';
    cout << '\n';
    */

    updatePoint(a[1].second, 1);
    for (int i = 2; i <= n; i ++){
        //cout << a[i].second - 1 <<' ';
        //cout << getsum(a[i].second - 1) << '\n';
        ans += getsum(a[i].second - 1);
        updatePoint(a[i].second, 1);
    }

    cout << ans;

    return 0;
}

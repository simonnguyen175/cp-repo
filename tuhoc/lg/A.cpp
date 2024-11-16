#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, k;
long long a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    vector<long long> lef, rig;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        if ( a[i] < 0 ) lef.push_back(a[i]);
        else rig.push_back(a[i]);
    }

    sort(lef.begin(), lef.end());
    sort(rig.begin(), rig.end());
    long long ans = 0;
    for (int i = 0; i < lef.size(); i += k){
        ans += 2ll * abs(lef[i]);
    }

    for (int i = rig.size()-1; i >= 0; i -= k){
        ans += 2ll * abs(rig[i]);
    }

    cout << ans;

    return 0;
}

// 6 2 1 2 3 4 -1 -2

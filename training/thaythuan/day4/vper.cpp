#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int oo = 2e9;

int n;
vector<int> cont;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1, x; i <= n; i ++)
        cin >> x, cont.pb(x);

    int add = 0;
    sort(cont.begin(), cont.end());
    for (int i = 1; i < cont.size(); i ++)
        if ( cont[i] == cont[i-1] ) add ++;
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    int ans = oo;
    for (int i = 0; i < cont.size(); i ++)
        ans = min(ans, cont[i] - 1 - i + (int)cont.size()-i-1);

    cout << ans + add;

    return 0;
}

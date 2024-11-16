#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
pair<int, int> a[N];

int main(){
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    freopen("lamdep.inp", "r", stdin);
    freopen("lamdep.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + 1 + n);
    int ans = INT_MAX, pos = 0;
    for (int i = 1; i <= n - 3; i ++){
        if ( a[i+3].first - a[i].first < ans ){
            ans = a[i+3].first - a[i].first;
            pos = i;
        }
        else if ( a[i+3].first - a[i].first == ans ) pos = i;
    }
    vector<int> vtri;
    for (int i = pos; i <= pos + 3; i ++)
        vtri.push_back(a[i].second);
    sort(vtri.begin(), vtri.end());
    cout << ans << '\n';
    for (int x : vtri)
        cout << x << ' ';

    return 0;
}

//6
//3 4 7 5 10 8

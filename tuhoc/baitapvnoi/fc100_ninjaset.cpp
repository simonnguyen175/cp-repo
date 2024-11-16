#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n;
int p[N], v[N], id[N];
multiset<int> s[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> v[i] >> p[i];
        id[i] = i;
    }

    for (int i = n; i >= 1; i --){
        auto it = s[id[i]].lower_bound(v[i]);
        if ( it != s[id[i]].end() ) s[id[i]].erase(it);
        s[id[i]].insert(v[i]);

        if ( s[id[i]].size() < s[id[p[i]]].size() )
            s[id[p[i]]].insert(s[id[i]].begin(), s[id[i]].end());
        else{
            s[id[i]].insert(s[id[p[i]]].begin(), s[id[p[i]]].end());
            id[p[i]] = id[i];
        }
    }

    cout << (int)s[id[1]].size();

    return 0;
}

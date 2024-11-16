#include<bits/stdc++.h>
using namespace std;
const int n = 1e6;

long long s[n+5];
map<long long, vector<int>> d;

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);

    for (int i = 1; i <= n; i ++)
    for (int j = 2*i; j <= n; j += i){
        s[j] += i;
    }

    for (int i = 1; i <= n; i ++){
        for (int x : d[s[i]]) cout << x << ' ' << i << '\n';
        d[s[i]].push_back(i);
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n, mx;
vector<int> cur;

void gen(int n){
    if ( n == 0 ){
        for (auto x : cur)
            cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int i = min(n, mx); i >= 1; i --){
        cur.push_back(i);
        mx = i;
        gen(n - i);
        cur.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    mx = n;
    gen(n);

    return 0;
}

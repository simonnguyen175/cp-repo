#include<bits/stdc++.h>
using namespace std;

void build(int id, int l, int r){
    if ( l == r ){
        st[id].v1 = oo;
        st[id].v2 = oo;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> d;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    build(1, 1, n);

    for (int i = 1; i <= n; i ++)

    return 0;
}

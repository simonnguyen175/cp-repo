#include<bits/stdc++.h>
using namespace std;

int n, R, q;
float p;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> R >> q >> p;
    int cur = q, no = 0;
    multiset<int> cont;
    for (int i = 1, l, r; i <= R; i ++){
        cin >> l >> r;

        while ( cont.size() && *cont.cbegin() <= l ){
            auto it = cont.cbegin();
            cont.erase(it);
            cur ++;
        }

        if ( cur > 0 ){
            cur --;
            cont.insert(r);
        }
        else{
            no ++;
        }
    }

    if ( no*0.1/R > p ){
        cout << R-no << "/" << R << ": Yes";
    }
    else{
        cout << R-no << "/" << R << ": No";
    }

    return 0;
}

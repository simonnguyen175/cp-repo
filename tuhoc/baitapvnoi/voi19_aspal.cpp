#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9 + 7;

string P, Q;
int A[N], f[N][1030][2][2];

int add(int a, int b){
    a += b;
    if ( a > MOD ) a -= MOD;
    return a;
}

int sub(int a, int b){
    a -= b;
    if ( a < 0 ) a += MOD;
    return a;
}

string sub(string a, string b){
    while ( b.size() < a.size() ) b = '0' + b;

    string res = "";
    int borrow;
    for (int i  = a.size()-1; i >= 0; i --){
        int x = a[i] - '0', y = b[i] - '0';
        int s = x - y - borrow;
        if ( s < 0 ) s += 10, borrow = 1;
        else borrow = 0;
        res += (char) ( s + '0' );
    }
    while ( res.back() == '0' && res.size() >= 2 )
        res.erase(res.size()-1, 1);
    reverse(res.begin(), res.end());
    return res;
}

int calc(int id, int msk, bool ok1, bool ok2){
    if ( id > 5000 ) if ( ok2 ){
        if ( __builtin_popcount(msk) <= 1 ) return 1;
        else return 0;
    }
    else return 0;

    if ( f[id][msk][ok1][ok2] != -1 ) return f[id][msk][ok1][ok2];


    int res = 0;
    for (int c = 0; c <= max(ok1*9, A[id]); c ++){
        if ( c == 0 ){
            if ( ok2 ) res = add(res, calc(id+1, msk^(1<<c), ok1|(c<A[id]), ok2|(c>0)));
            else res = add(res, calc(id+1, msk, ok1|(c<A[id]), ok2));
        }
        else
            res = add(res, calc(id+1, msk^(1<<c), ok1|(c<A[id]), ok2|(c>0)));
    }

    f[id][msk][ok1][ok2] = res;

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("voi19_aspal.inp", "r") ){
        freopen("voi19_aspal.inp", "r", stdin);
        freopen("voi19_aspal.out", "w", stdout);
    }

    cin >> P >> Q;

     P = sub(P, "1");

    memset(A, 0, sizeof A);
    memset(f, -1, sizeof f);
    for (int i = Q.size()-1, j = 5000; i >= 0; i --, j --) A[j] = Q[i] - '0';

    for (int i = 1; i <= 5000; i ++) cout << A[i]; cout << '\n';

    int ans = calc(1, 0, 0, 0);

    memset(A, 0, sizeof A);
    memset(f, -1, sizeof f);
    for (int i = P.size()-1, j = 5000; i >= 0; i --, j --) A[j] = P[i] - '0';
    for (int i = 1; i <= 5000; i ++) cout << A[i]; cout << '\n';
    ans = sub(ans, calc(1, 0, 0, 0));

    cout << ans;

    return 0;
}

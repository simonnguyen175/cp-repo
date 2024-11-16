#include<bits/stdc++.h>
#define ll long long
#define sqr(x) x*x
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, k;
string a[N];
string s;
vector<int> b;
ll gt[N], bit[N], ans = 0, bonus;

ll mu(int a, int b){
    if ( b == 0 ) return 1;
    ll tmp = mu(a, b/2);
    if ( b % 2 ) return ((sqr(tmp)%MOD)*a)%MOD;
    return sqr(tmp)%MOD;
}

ll tinh(int n, int k){
    if ( k == 0 ) return 1;
    else return (bonus*gt[n])%MOD;
}

void update(int id){
    for (int i = id; i <= n; i += (i&(-i))) bit[i]++;
}

ll get(int id){
    ll res = 0;
    for (int i = id; i > 0; i -= (i&(-i))) res += bit[i];
    return res;
}

ll Find(string x){
    int d = 1, c = n;
    while ( d <= c ){
        int mid = ( d + c ) / 2;
        if ( a[mid] == x ) return mid;
        else
            if ( a[mid] < x ) d = mid + 1;
                else c = mid - 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a+1, a+1+n);

    cin >> s;
    string tmp = "";
    for (int i = 0; i < s.size(); i ++){
        tmp += s[i];
        int id = Find(tmp);
        if ( id ) b.push_back(id), tmp = "";
    }

    gt[0] = 1;
    for (int i = 1; i <= n; i ++) gt[i] = (gt[i-1] * i)%MOD;

    bonus = mu(gt[n-k], MOD-2);
    for (int i = 0; i < b.size(); i ++){
        ans = ( ans + ((b[i]-1-get(b[i]-1))*tinh(n-i-1, k-i-1))%MOD ) % MOD;
        update(b[i]);
    }
    cout << (ans+1)%MOD;
    return 0;
}

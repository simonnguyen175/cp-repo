Nguyên Minhh
Minhh đã gửi Hôm nay lúc 12:32
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000005 , MOD = 1e9 + 7;
ll n, Max = 0, m;
pi a[N] , st[4 * N] , ans;
unordered_map <ll , int> pos;
vector < int > v;
void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

pi com ( pi a , pi b)
{
    if (a.fi < b.fi ) return a;
    if (a.fi == b.fi) return {a.fi , (a.se + b.se) % MOD};
    return b;
}

void update(int id , int l , int r, int x, pi val)
{
    if ( l > x || r < x) return;
    if (l == r )
    {
        st[id] = com(st[id] , val);
        return ;
    }
    int mid = (l + r) / 2;
    update(id * 2, l , mid, x , val);
    update(id * 2 + 1, mid + 1, r, x, val);
    st[id] = com(st[id * 2] , st[id * 2 + 1]);
}

pi get(int id , int l , int r, int x)
{
    if (r < x) return {LLONG_MAX , 0};
    if ( l >= x ) return st[id];
    if (l == r)  return st[id];
    int mid = (l + r) / 2;
    return com( get(id * 2 , l , mid , x) , get (id * 2 + 1 , mid + 1, r , x));
}

int main()
{
    file();
      cin >> n;

     for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se , v.pb(a[i].fi), v.pb(a[i].se);
     sort(v.begin(),v.end());
     v.erase(unique(v.begin(),v.end()),v.end());
     m = v.size();
     for(int i = 0; i < m; i++)     pos[v[i]] = i + 1;
     sort(a + 1 , a + n + 1 , greater<pi>() );

    for(int i = 1; i < 4 * N ; i++) st[i] = {LLONG_MAX , 0};

     for (int i = 1; i <= n; i++)
     {
       if(a[i] .fi > Max)       ans = {a[i].se , 1};
       else     ans = get(1 , 1 , m , pos[a[i].fi])  , ans.fi += (a[i].se -a[i].fi);
       update(1 , 1 , m, pos[a[i].se] , ans );
         Max = max(a[i].se , Max);
     }
     cout << st[1].se;
     return 0;
}

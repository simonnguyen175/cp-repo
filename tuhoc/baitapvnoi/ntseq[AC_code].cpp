#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ii pair<ll,ll>
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
#define pb push_back
const string FILE_NAME = "";
using namespace std;
const int maxx = 1e5;
const int mod = 1e9 + 7;
int n , a[maxx + 3];
vector<ll> ve;
ii bit[maxx + 3], ans;
void file()
{
	FASTio
	if (fopen((FILE_NAME + ".inp").c_str() , "r"))
	{
		freopen((FILE_NAME + ".inp").c_str() , "r" , stdin);
		freopen((FILE_NAME + ".out").c_str() , "w" , stdout);
	}
}
ii get(ll id)
{
    ii res = {0 , 0};
    while(id >= 1)
    {
        if(res.fi < bit[id].fi) res = bit[id];
        else if(res.fi == bit[id].fi) res.se = (res.se + bit[id].se) % mod;
        id -= id & (-id);
    }
    if(!res.fi) return {1, 1};
    res.fi++;
    return res;
}
void update(int id , ii res)
{
    while(id <= maxx + 5)
    {
        if(bit[id].fi < res.fi) bit[id] = res;
        else if(res.fi == bit[id].fi) bit[id].se = (res.se + bit[id].se) % mod;
        id += id & (-id);
    }
}
int main()
{
	//file();
    cin >> n;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        ve.push_back(++a[i]);
    }
    sort(ve.begin(), ve.end());
    for(ll i = 1 ; i <= n ; i++)
		a[i] = lower_bound(ve.begin() , ve.end(), a[i]) - ve.begin() + 1;

    for(ll i = 1 ; i <= n ; i++)
    {
        ans = get(a[i] - 1);
        update(a[i] , ans);
    }
    ans = get(maxx + 2);
    cout << ans.se;
    return 0;
}

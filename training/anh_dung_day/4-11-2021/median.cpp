#include <bits/stdc++.h>
#define simon "checkpoint"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e5+1;
const ll oo=1e18;

int n, k, a[N], ans;
int More[N], Less[N];
map<int, int> hieuso;

int main(){
    FASTio
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    //set up phan truoc gtri k
    int pos;
    hieuso[0]=1;
    for(int i=1; i<=n && a[i] != k ; i++){
        if ( a[i] < k ) Less[i]=Less[i-1]+1;
            else Less[i]=Less[i-1];
        if ( a[i] > k ) More[i]=More[i-1]+1;
            else More[i]=More[i-1];
        pos=i;
        hieuso[More[i]-Less[i]]++;
    }
    pos++;
    More[pos]=More[pos-1];
    Less[pos]=Less[pos-1];
    ans+=hieuso[More[pos]-Less[pos]];
    //cout << ans <<' '<<pos << '\n';
    // xuli phan sau
    for (int i=pos+1; i<=n; i++){
        if ( a[i] < k ) Less[i]=Less[i-1]+1;
            else Less[i]=Less[i-1];
        if ( a[i] > k ) More[i]=More[i-1]+1;
            else More[i]=More[i-1];
        ans+=hieuso[More[i]-Less[i]];
    }
    cout << ans;
    return 0;
}

#include<bits/stdc++.h>
#define simon "stove"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, k, a[N], ans=INT_MAX ;
vector<int> interval;



int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    int time = a[n]-a[1]+1; ans = time;

    for (int i=2; i<=n; i++)
        interval.push_back(a[i]-a[i-1]-1);

    sort(interval.begin(), interval.end(), greater<int>());

    int nghi = 0;
    for (int i=0; i<k-1; i++){
        nghi += interval[i];
        ans = min(ans, time - nghi);
    }

    cout << ans;
    return 0;
}

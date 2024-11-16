#include <bits/stdc++.h>
using namespace std;

int t,n;
pair<int,int> a[100001];


int solve(int n, pair<int,int> a[]){
    sort(a+1,a+1+n);
    int ans=0, x;
    long long s=0;
    priority_queue<int> q;
    for (int i=1; i<=n; i++){
        s+=a[i].second;
        q.push(a[i].second);
        if ( s <= a[i].first ) ans++;
        else {
            x = q.top();
            s = s-x;
            q.pop();
        }
    }
    return ans;
}

int main(){
    freopen("workmax.inp","r",stdin);
    freopen("workmax.out","w",stdout);
    cin >> t;
    for (int e=1; e <=t; e++){
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> a[i].second >> a[i].first;
        cout << solve(n,a) <<"\n";
    }
}

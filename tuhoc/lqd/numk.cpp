#include<bits/stdc++.h>
using namespace std;

int k, m, d[20];
bool vis[1000005];

int main(){
    cin >> k >> m;
    for (int i = 1; i <= k; i ++)
        cin >> d[i];

    sort(d + 1, d + 1 + k);
    memset(vis, 0, sizeof vis);

    queue<pair<string, int>> q;

    for (int i = 1; i <= k; i ++){
        if ( d[i] == 0 ) continue;
        string s = "";
        s += (char) (d[i]+'0');
        q.push({s, d[i]%m});
        vis[d[i]%m] = 1;
    }

    int cnt = 0;

    while ( q.size() ){
        cnt ++;
        if ( cnt > 1500000 ){
            cout << -1;
            break;
        }

        string su = q.front().first;
        int du = q.front().second;
        q.pop();

        if ( du == 0 ){
            cout << su;
            break;
        }

        for (int i = 1; i <= k; i ++){
            string sv = su + (char)(d[i]+'0');
            int dv = (du*10 + d[i])%m;

            if ( vis[dv] ) continue;

            q.push({sv, dv});
        }
    }

    return 0;
}

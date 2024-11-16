#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, t;
ll cnt, tt;
vector<int> ans;
int x[20], a[20];

bool check(){
    for (int i = 1; i <= n; i ++)
        if ( x[i] != a[i] ) return false;
    return true;
}

void gen(int id){
    for (int i = 1; i <= n; i ++){
        a[id] = i;
        if ( id == n ){
            int tmp[4];
            tmp[1] = a[1]; tmp[2] = a[2]; tmp[3] = a[3];
            sort(tmp + 1, tmp + 4);
            if ( tmp[1] + tmp[2] <= tmp[3] ) continue;

            bool flag = 1;
            for (int j = 4; j <= n; j ++){
                if ( a[j] > tmp[3] ) tmp[3] = a[j];
                else if ( a[j] < tmp[1] ){
                    tmp[2] = tmp[1];
                    tmp[1] = a[j];
                }
                else if ( a[j] < tmp[2] ) tmp[2] = a[j];

                if ( tmp[1] + tmp[2] <= tmp[3] ){flag = 0; break;}
            }

            if ( !flag ) continue;

            cnt ++;
            if ( check() ) tt = cnt;

            if ( cnt == t )
                for (int j = 1; j <= n; j ++) ans.push_back(a[j]);

            continue;
        }
        else gen(id+1);
    }
}

int main(){
    cin >> n >> t;
    for (int i = 1; i <= n; i ++)
        cin >> x[i];
    if ( n <= 9 )
    gen(1);

    cout << cnt << '\n';
    for (auto it : ans) cout << it << ' '; cout << '\n';
    cout << tt;

    return 0;
}

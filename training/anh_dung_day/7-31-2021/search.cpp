#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n, q;
int Next[N][27], Cnt[N][27];

int main(){
    cin >> n >> q;

    int cnt = 0;

    for (int i = 1; i <= n; i ++){
        string s;
        cin >> s;

        int id = 0;
        for (int j = 0; j < s.size(); j ++){
            if ( Next[id][s[j]-'a'] ){
                id = Next[id][s[j]-'a'];
                Cnt[id][s[j]-'a'] ++;
                continue;
            }
            Next[id][s[j]-'a'] = ++cnt;
            id = Next[id][s[j]-'a'];
            Cnt[id][s[j]-'a'] ++;
        }
    }

    while ( q -- ){
        string s;
        cin >> s;

        int id = 0;
        bool flag = 1;
        for (int j = 0; j < s.size(); j ++){
            if ( Next[id][s[j]-'a'] ) {id = Next[id][s[j]-'a']; continue;}
            else{
                flag = 0;
                break;
            }
        }

        if ( !flag ) cout << 0 << '\n';
        else cout << Cnt[id][s[s.size()-1]-'a'] << '\n';
    }
}

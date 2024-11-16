#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n;
long long a[N], mn[N];
bool check[N];

int main(){
    while ( cin >> n ){
        for (int i = 1; i <= n; i ++) cin >> a[i];

        deque<long long> dq;
        memset (check , 0 , sizeof (check));

        for (int i = n; i >= 1; i--){
            long long tmp = a[i], pos;

            while( dq.size() && a[i] >= a[dq.back()] ){
                tmp = min(mn[dq.back()], tmp);
                dq.pop_back();
            }

            if ( !dq.size() ) pos = i;
            else pos = dq.back();

            mn[i] = a[i];
            if ( pos != i ) mn[pos] = min(mn[pos], tmp);

            if ( a[i] - mn[pos] >= 150000 || pos == i )  check[i] = 1;

            dq.push_back(i);
        }

        dq.clear();

        for (int i = 1; i <= n; i++){
            long long tmp = a[i], pos;
            while ( dq.size() != 0 && a[i] >= a[dq.back()] ){
                tmp = min(mn[dq.back()], tmp);
                dq.pop_back();
            }

            if ( !dq.size() ) pos = i;
            else pos = dq.back();

            mn[i] = a[i];
            if ( pos != i ) mn[pos] = min(mn[pos], tmp);

            if ( ( a[i] - mn[pos] >= 150000 || pos == i ) && check[i] == 1 )
                cout << i << ' ';

            dq.push_back(i);
        }

        cout << '\n';
    }
}

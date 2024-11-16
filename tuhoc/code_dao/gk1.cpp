#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<long long> arr;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        long long x;
        cin >> x;
        arr.push_back(x); 
    }

    cin >> m;
    while ( m -- ){
        int t;
        cin >> t; 
        if ( t == 1 ){
            long long x; 
            cin >> x;
            arr.push_back(x);
        }
        if ( t == 2 ){
            long long x;
            cin >> x;
            arr.insert(arr.begin(), x);
        }
        if ( t == 3 ){
            long long x, y;
            cin >> x >> y; 
            long long cur = 1; 
            x = arr[x-1]; 
            while ( x ){
                cur = cur * (x%10);
                cur %= y; 
                x /= 10;
            }
            if ( cur == 0 ) cout << "Mình thật đẹp trai\n";
            else cout << "Đề khó quá\n"; 
        }
        if ( t == 4 ){
            long long x, y;
            cin >> x >> y;
            bool ck = 0;
            for (int i = 0; i < arr.size(); i ++) 
                if ( arr[i] % x == y ){
                    ck = 1; 
                    cout << i + 1 << '\n';
                    break;
                }
            if ( !ck ) cout << "Bị đánh dấu bài rồi\n";
        }
    }

    return 0;
}
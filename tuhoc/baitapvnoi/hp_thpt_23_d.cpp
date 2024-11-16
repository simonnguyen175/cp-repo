    #include<bits/stdc++.h>
    using namespace std;
    const int N = 1e6 + 5; 

    int t, n, k; 
    int a[N]; 

    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);

        cin >> t;
        while ( t -- ){
            cin >> n >> k;
            for (int i = 1; i <= n; i ++) 
                cin >> a[i]; 

            sort(a + 1, a + 1 + n); 
            int id = 1, ck = 0; 
            for (int i = n; i >= 1; i --){
                while ( a[id] + a[i] < k && id < i ) id ++; 
                if ( id < i && a[id] + a[i] == k ) ck = 1; 
            }

            if ( !(k % 2) ) cout << 0;
            else cout << ck; 
        }

        return 0; 
    }

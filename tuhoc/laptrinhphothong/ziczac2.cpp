#include <bits/stdc++.h>
using namespace std ;

int n, a[1001];

int main(){
    cin >> n ;
    for (int i=1; i<=n; i++)
    	cin >> a[i];
    int temp=1, ans = INT_MIN;
	for (int i=2; i<=n; i++){
        if ( a[i]*a[i-1] <= 0 )
        	temp++;
        if ( a[i]*a[i-1] >= 0){
            ans = max (ans, temp);
            temp = 1 ;
        }
    }
	ans = max (ans,temp);
    cout << ans ;
}

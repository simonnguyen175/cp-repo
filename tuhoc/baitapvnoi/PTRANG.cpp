#include <bits/stdc++.h>
using namespace std;
#define N 6001
#define INF 1e8+7

int w[N], l, n, tmp, f[N];

int main() {
    cin >> n >> l;
	for(int i=1; i<=n; i++){
        cin >> tmp;
        w[i] = w[i-1] + tmp;
    }
	for(int i=1; i<=n; i++){
		f[i] = INF;
		for (int j=i-1; j>=0; j--){
			if( w[i] - w[j] > l ) break;
			f[i] = min(f[i],max(f[j],l-(w[i]-w[j])));
        }
	}
    cout << f[n];
	return 0;
}

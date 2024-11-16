#include<bits/stdc++.h>
using namespace std;

int main(){
	int x;
	x = rand();
	int lo = 0, hi = 1000000;
	while ( lo <= hi ){
		int mid = (lo + hi)/2;
		if ( mid < x ){
			lo = mid + 1;
		}
		else if ( mid > x ){
			hi = mid - 1;
		}
		else { cout << mid; break; }
	}
	return 0;
}

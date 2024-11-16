#include <bits/stdc++.h>
using namespace std;

int Count(int x,int y){
	if(y==-1){
		return 0;
	}
	if(!x){
		return 1;
	}
	int p=31-__builtin_clz(x);
	if(__builtin_popcount(x)==1){
		return y/(1<<(p+1))+1;
	}
	return Count(x^(1<<p),(1<<p)-1)*((y+1)/(1<<(p+1)))+Count(x^(1<<p),min(1<<p,(y+1)%(1<<(p+1)))-1);
}

int Count(int x,int l,int r){
	int ans=Count(x,r)-Count(x,l-1);
	if(l){
		ans+=!(l&x)&&!((l-1)&x);
	}
	return ans;
}

int Count(int x,int y,int u,int v){
	return Count(x,y,v)+Count(y,x,u)-!(x&y);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int N,M,Q;
	cin>>N>>M>>Q;

	for(int i=0;i<Q;++i){
		int64_t x,y,u,v;
		cin>>x>>y>>u>>v;
		cout<<Count(x,y,u,v)<<'\n';
	}
	return 0;
}

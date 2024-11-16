#include<bits/stdc++.h>
using namespace std;
template<typename T> ostream& operator<<(ostream& os, vector<T> a){os<<"( ";for(T &x:a)os<<x<<" ";os<<")\n";return os;}
template<typename T> ostream& operator<<(ostream& os, pair<T,T> a){os<<"("<<a.first<<" "<<a.second<<") ";return os;}
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
#define all(a) a.begin(),a.end()
#define debug(a) cerr<<#a<<" = "<<a<<endl
#define x first
#define y second
//===========================Head=========================//

//////////////////////Fast IO//////////////////////////
int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

void writeInt(int x){
    if (x>=10) writeInt(x/10);
    putchar(x%10+'0');
}
void writeInt(int x,char c){
    writeInt(x);
    putchar(c);
}
////////////////////////End Fast IO/////////////////////////

struct trapezoid{
    int x1,y1,x2,y2;
    int id;

    bool operator<(const trapezoid &o) const{
        if (x1!=o.x1) return x1<o.x1;
        if (y1!=o.y1) return y1<o.y1;
        if (x2!=o.x2) return x2<o.x2;
        y2<o.y2;
    }

    void read(){
        x1=readInt();
        y1=readInt();
        x2=readInt();
        y2=readInt();
    }

    bool less_than(trapezoid &o){
        return x2<o.x1 && y2<o.y1;
    }

    void show(){
        printf("shape %d:   %d %d %d %d\n",id,x1,y1,x2,y2);
    }

} a[1000002];

int pre[1000002], n, L[1000002];
int g[2000002];

void update(int x,int val){
    for (;x<=n*2;x+=x&-x) g[x]=max(g[x],val);
}

int show(int x){
    int ans=0;
    for (;x;x-=x&-x) ans=max(ans,g[x]);
    return ans;
}

main(){
    //freopen("ESEA.inp","r",stdin);
    //freopen("ESEA.out","w",stdout);
    int t=readInt();
    while(t--){
        n=readInt();
        set<int> A,B;
        for (int i=1;i<=n;++i){
            a[i].read();
            A.insert(a[i].x1);
            A.insert(a[i].x2);
            B.insert(a[i].y1);
            B.insert(a[i].y2);
            a[i].id=i;
        }

        {//roi rac hoa
            vi tmp(all(A));
            #define abc(x) x=lower_bound(all(tmp),x)-tmp.begin()+1
            for (int i=1;i<=n;++i){
                abc(a[i].x1);
                abc(a[i].x2);
            }
            tmp=vi(all(B));
            for (int i=1;i<=n;++i){
                abc(a[i].y1);
                abc(a[i].y2);
            }
        }
        sort(a+1,a+1+n);
        priority_queue<pii> Heap;
        memset(g,0,sizeof(g));
        for (int i=1;i<=n;++i){
            while (Heap.size()){
                int j=Heap.top().second;
                if (a[j].x2 >= a[i].x1) break;
                Heap.pop();
                update(a[j].y2,L[j]);
            }
            L[i]=show(a[i].y1-1)+1;
            Heap.push({-a[i].x2,i});
        }

        int x=0;
        for (int i=1;i<=n;++i) x=max(x,L[i]);
        //cout<<x<<endl;continue;
        vvi ans(x);
        for (int i=1;i<=n;++i) ans[L[i]-1].push_back(a[i].id);
        writeInt(ans.size(),'\n');
        for (vi &i:ans){
            writeInt(i.size(),' ');//printf("%d ",ans[i+1]-ans[i]);
            for (int t:i) writeInt(t,' ');//printf("%d ",a[j].id);
            putchar('\n');//printf("\n");
        }
    }
}
/*
1
10
31 68 74 91
29 55 91 67
-17 -29 91 -4
-61 62 53 86
-25 60 60 75
0 -38 0 96
-16 -54 8 70
-36 -39 22 -18
44 30 58 37
-25 -87 65 -70
*/

#include <bits/stdc++.h>
using namespace std;

const string NAME = "PathBFS";     // problem name
const string TestType = "Themis";  // "CMS", "Themis"

const int NTEST = 20;           // number of tests

mt19937_64 rd;

long long Rand(long long lo,long long hi){
    return rd() % (hi - lo + 1) + lo;
}


void makeTest(){
    int n = Rand(10,20);
    int m = Rand(30,(n-1)*(n-1)/2);
    vector <int> v;
    vector <pair<int,int>> edge;
    int mark[n+1][n+1]; // mang danh dau cac canh da duoc them
    for(int i = 1; i <= n; ++i) v.push_back(i);
    random_shuffle(v.begin(),v.end()); // xay dung cay khung
    for(int i = 0; i < n - 1; ++i)
    {
        int x = v[i];
        int y = v[i+1];
        if (x > y) swap(x,y);
        edge.push_back( make_pair(x,y) );
        mark[x][y] = mark[y][x] = 1;
    }
    int t = m;
    m -=(n-1);
    while(m > 0)
    {
        int x = Rand(1,n-1);
        int y = Rand(x+1,n);
        if (mark[x][y] != 1)
        {
            m--;
            edge.push_back(make_pair(x,y));
            mark[x][y]=mark[y][x]=1;
        }
    }
    sort(edge.begin(),edge.end());
    int a = Rand(1,n/2);
    int b = Rand(a+1,n);
    cout << n << ' ' << t << ' ' << a << ' ' << b << '\n';
    for (int i = 0; i < t; ++i) cout << edge[i].first << ' ' << edge[i].second << '\n';
}

int main(){
    unsigned randomSeed = chrono::system_clock::now().time_since_epoch().count();
    rd.seed(randomSeed);
    makeTest();
}





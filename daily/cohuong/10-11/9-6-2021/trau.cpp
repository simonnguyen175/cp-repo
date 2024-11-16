#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int path[maxn];
int first = 0;
vector<vector<int>> edge(maxn);
int n,m,u,v;

void print()
{
    vector <int> res;
    res.push_back(v);
    while(v!=u)
    {
        v = path[v];
        res.push_back(v);
    }
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << '\n';
}

void bfs(int x)
{
    vector <int> pos; // khai bao vector lam hang doi
    pos.push_back(x); // them dinh u vao dau hang doi
    int fisrt = 0; // khai bao bien chi  so dau hang doi
    while(first < pos.size())
    {
        int a = pos[first]; first++; // lay phan tu dau tien
        for(int i = 0; i < edge[a].size();i++) // duyet qua cac dinh ke cua a
        {
            int b = edge[a][i];
            if (b == v)
            {
                path[b] = a;
                print();
                exit(0);
            }
            if (path[b] == 0 && b != x) // chu y neu gan mang path la -1 thi path[u] = 0 va so sanh path[b] == -1
            {
                pos.push_back(b); // them dinh vao sau hang cho de duyet
                path[b] = a; // them dinh lien truoc cua b la a
            }
        }
    }
}

int main()
{
    //freopen("t.inp","r",stdin);
    memset(path,0,sizeof path);
    cin >> n >> m >> u >> v;
    for (int x,y,i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    bfs(u);
}

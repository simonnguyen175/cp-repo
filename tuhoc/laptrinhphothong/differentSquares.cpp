#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> matrix;
int main()
{
    string s = "@";
    string p = "";
    int d = 0;
    for (int i = 0; i < matrix.size() - 1; i++)
        for (int j = 0; j < matrix[0].size() - 1; j++)
        {
            p = "";
            p = p + "@" + char(matrix[i][j] + 48) + " " + char(matrix[i][j + 1] + 48) + " " + char(matrix[i + 1][j]+48) + " " + char(matrix[i+1][j + 1] + 48) + "@ ";
            if (s.find(p) < 0 || s.find(p) > s.length() - 1){
                d++;
                s = s + p;
            }
        }
    return d;
}

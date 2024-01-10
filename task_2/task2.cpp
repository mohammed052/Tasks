#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;
int cmp = 0;

void dfs(int i, int j, int count, vector<vector<string>> &arr)
{
    int n = arr[0].size();
    for (int k = -1; k <= 1; k++)
    {
        for (int l = -1; l <= 1; l++)
        {
            if (k == 0 && l == 0)
                continue;
            int row = i + k, col = j + l;
            if (row > 4)
            {
                if (count + 1 > cmp)
                {
                    cmp = count + 1;
                    ans = arr;
                    ans[i][j] = to_string(count);
                }
            }
            else if (row >= 0 && col >= 0 && col < n && arr[row][col] == ".")
            {
                arr[i][j] = to_string(count);
                dfs(row, col, count + 1, arr);
                arr[i][j] = ".";
            }
        }
    }
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    vector<vector<string>> arr(5);
    for (auto &i : arr)
    {
        string temp;
        in >> temp;
        for (int j = 0; j < temp.size(); j++)
        {
            string cmp = "";
            cmp += temp[j];
            i.push_back(cmp);
        }
    }

    int n = arr[0].size();
    for (int i = 0; i < n; i++)
    {
        if (arr[0][i] == ".")
        {
            dfs(0, i, 0, arr);
        }
    }

    if (cmp == 0)
    {
        out << -1 << endl;
        for (int i = 0; i < 5; i++)
        {
            for (auto j : ans[i])
            {
                out << j << " ";
            }
            out<<"Prints"  << endl;
        }
    }
    else
    {
        out << cmp << endl;
        for (int i = 0; i < 5; i++)
        {
            for (auto j : ans[i])
            {
                out << j << " ";
            }
            out << endl;
        }
    }

    in.close();
    out.close();
    return 0;
}

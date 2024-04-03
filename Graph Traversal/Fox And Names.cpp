#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;
vector<char> g[26];

string topologicalSort()
{
    queue<char> q;
    vector<int> indegree(26, 0);

    for (int i = 0; i < 26; ++i)
    {
        for (char c : g[i])
        {
            indegree[c - 'a']++;
        }
    }

    for (int i = 0; i < 26; ++i)
    {
        if (indegree[i] == 0)
        {
            q.push('a' + i);
        }
    }

    string result;
    while (!q.empty())
    {
        char node = q.front();
        q.pop();
        result.push_back(node);
        for (char c : g[node - 'a'])
        {
            indegree[c - 'a']--;
            if (indegree[c - 'a'] == 0)
            {
                q.push(c);
            }
        }
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    int n;
    cin >> n;
    vector<string> names(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> names[i];
    }

    for(int i = 1; i < n; i++)
    {
        int j = 0, len = min(names[i].size(), names[i-1].size());
        while(names[i][j] == names[i-1][j] && j < len-1)
        {
            j++;
        }

        if(names[i][j] != names[i-1][j])
        {
            g[names[i-1][j] - 'a'].push_back(names[i][j]);
        }
        else if(names[i].size() < names[i-1].size())
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    string ans = topologicalSort();
    if(ans.size() != 26)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    else cout << ans << endl;
}

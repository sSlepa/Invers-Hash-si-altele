///https://www.pbinfo.ro/probleme/3580/chromosome
/// Raul Ardelean solution to K Shorthest paths problem

#include <bits/stdc++.h>
#define cin in
#define cout out
#define pii pair<int, int>
#define piv pair<int, vector<int>>
#define eb emplace_back
using namespace std;

const string file_name("chromosome");

ifstream in(file_name + ".in");
ofstream out(file_name + ".out");

int n, m, k, src, dst, x, y, c, ap[1005];
vector<pii> G[1005];
vector<piv> ans;
priority_queue<piv, vector<piv>, greater<piv>> pq;

void read()
{
    cin >> n >> m >> k >> src >> dst;

    while (m--)
    {
        cin >> x >> y >> c;
        G[x].eb(y, c);
    }
}

void dial()
{
    int cost, nod;
    pq.emplace(0, vector<int>{src});

    while (!pq.empty() and ap[dst] < k)
    {
        vector<int> v;
        tie(cost, v) = pq.top();
        pq.pop();
        nod = v.back();
        ap[nod]++;
        if (nod == dst)
        {
            ans.eb(cost, v);
            continue;
        }
        if (ap[nod] <= k)
        {
            for (auto x : G[nod])
                if (find(v.begin(), v.end(), x.first) == v.end()) /// daca nu am trecut prin nodul x.first, il adaugam
                {
                    v.eb(x.first);
                    pq.emplace(cost + x.second, v);
                    v.pop_back();
                }
        }
    }
}

void write()
{
    sort(ans.begin(), ans.end(), [](piv a, piv b)
         {
             if (a.first != b.first)
                 return a.first < b.first;

             vector<int> v1, v2;
             v1 = a.second;
             v2 = b.second;
             reverse(v1.begin(), v1.end());
             reverse(v2.begin(), v2.end());

             return v1 < v2; });

    cout << ans.size() << '\n';

    for (auto x : ans)
    {
        cout << x.first << ' ' << x.second.size() << '\n';
        for (auto y : x.second)
            cout << y << ' ';
        cout << '\n';
    }
}

int main()
{
    read();
    dial();
    write();
    return 0;
}

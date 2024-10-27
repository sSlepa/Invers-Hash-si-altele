#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <map>
#include <cmath>
#include <chrono>
#include <set>
#include <iomanip>
#include <list>
#include <sstream>
#include <functional>
#include <numeric>
#include <string>
#include <unordered_set>
#include <random>
#include <string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL
#define MOD 1000000007
#define MODC 984162946217979097
#define lsb(i) (i & -i)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tup tuple<int,int,int>
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ost;

///__builtin_popcount(x)

ifstream cin("date.in");
ofstream cout("date.out");

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int n,m;
int a[1005][1005];
int b[1005][1005];

bool inmat(int i,int j){

    return i >= 1 && i <= n && j >= 1 && j <= m;

}

void lee(){

    queue<pair<int,int> > q;
    q.push({1,1});
    b[1][1] = 1;
    while(!q.empty()){

        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int d = 0 ; d < 4 ; ++d){
            int ii = dx[d] + x;
            int jj = dy[d] + y;
            if(inmat(ii,jj) && a[ii][jj] != 1 && b[ii][jj] == 0){
                b[ii][jj] = b[x][y] + 1;
                q.push({ii,jj});
            }
        }
    }
    cout << b[n][m] - 1;
}

int main(){
    
    fastio;
    
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
            cin >> a[i][j];

    lee();
    
    
    
    return 0;
}

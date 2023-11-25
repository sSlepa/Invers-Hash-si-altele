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

using namespace std;
using namespace chrono;
#define Inf 0x3f3f3f3f
#define MAX 2000000000000000000LL
#define MOD 1000000007
#define MODC 984162946217979097
#define lsb(i) (i & -i)
#define pii pair<int,int>
#define tup tuple<int,int,int>
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

///__builtin_popcount(x)

ifstream cin("date.in");
ofstream cout("date.out");

vector<int> prefix_function(string s) {
    int n = (int)s.length();

    vector<int> pi(n);
    for (int i = 1 ; i < n; ++i){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if(s[i] == s[j])
            j++;

        pi[i] = j;
    }
    return pi;

}

int main(){

    fastio
    string s,t;
    while(getline(cin,s)){
        getline(cin,t);
        
        string KMP = s + "#" + t;
        vector<int> rez = prefix_function(KMP);
        int cnt = 0;
        for(int i = s.size() + 1 ; i < rez.size() ; ++i){
            if(rez[i] == s.size())
                cout << cnt - s.size() + 1 << ' ';

            cnt++;
        }

        rez.clear();
        cout << '\n';

    }

    return 0;
}

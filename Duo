ll ezpow(ll a, ll b){

    ll ans = 1;
    for(; b ; b >>= 1){
        if(b & 1)
            ans = (ll) ans * a % mod;
        a = (ll) a * a % mod;
    }

   return ans;
}
void pau(){

    poww[0] = 1;
    for(int i = 1 ; i <= 300000 ; ++i)
        poww[i] = (poww[i - 1] * p) % mod;

}
void compute(){

    for(int i = 0 ; i <= 300000 ; ++i)
        inverse[i] = ezpow(poww[i],mod - 2);
}
////////////////////////////////////////////////////
struct hash_pair {
   template <class T1, class T2>
   size_t operator()(const pair<T1, T2> &p) const{
      auto hash1 = hash<T1>{}(p.fi);
      auto hash2 = hash<T2>{}(p.se);

      if (hash1 != hash2)
         return hash1 ^ hash2;
      
      return hash1;
   }
};

int n, x, y, X, Y, X_, Y_, a, b, c, d;
unordered_map<pair<int, int>, int, hash_pair> points;

//////////////////////////////////////////////////////////

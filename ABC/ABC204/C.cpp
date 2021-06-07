#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx") // AtCoderはavx2に対応していないので注意
#pragma GCC optimize("O3") // 最適化オプション
#pragma GCC optimize("unroll-loops") // ループ展開
#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr)


#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
#define SET_PRECISION(x) cout<< fixed << setprecision((x))
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

using ll = long long;
using vi_t  = vector<int>;
using vvi_t = vector<vector<int> >;
using vl_t  = vector<ll>;
using vvl_t = vector<vector<ll> >;
using pii_t = pair<int, int>;
using pll_t = pair<ll, ll>;

using Graph = vector<vector<int>>;

vi_t str2numvec(const std::string& str);
vector<string> split(const string &str, char delim);

vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
  __MAGIC__;
  int N, M;
  cin >> N >> M;

  Graph G(N);

  int A, B;
  REP(i, M) {
    cin >> A >> B;
    --A; --B;
    G[A].push_back(B);
////    --A; --B;
////    //cout << "A = " << A << ", B= " << B << endl;
////    paths[A][B] = 1;
////    //cout << "\t" << "add " << A << " to " << B << endl;
////
////    REP(j, N) {
////      if ( paths[j][A] ) {
////        paths[j][B] = 1;
////        //cout << "\t" << "add " << j << " to " << B << endl;
////      }
////    }
////    REP(j, N) {
////      if ( paths[B][j] ) {
////        paths[A][j] = 1;
////        //cout << "\t" << "add " << j << " to " << B << endl;
////      }
////    }
  }


  int sum=0;
  //for(const auto& v : paths) {
  //  for(const auto& x : v) {
  //    cout << x << " ";
  //    if(x) ++sum;
  //  }
  //  cout << endl;
  //}
  for(int i=0; i<N; ++i) {
    seen.assign(N, false);
    dfs(G, i);
    for(const auto& x:seen) {
      if( x ) ++sum;
    }
//    cout << "i=" << i << " -> "<< sum << endl;
  }
  cout << sum << endl;

  return 0;
}

//-----------------------------
// ヘルパー関数群
//-----------------------------
vi_t str2numvec(const std::string& str)
{
  vi_t v(str.size());
  for(int i=0, n=str.size(); i<n; ++i) {
      v[i] = str[i] - '0';
  }
  return v;
}

vector<string> split(const string &str, char delim)
{
  vector<string> res;
  size_t current = 0, found;
  while((found = str.find_first_of(delim, current)) != string::npos){
    res.push_back(string(str, current, found - current));
    current = found + 1;
  }
  res.push_back(string(str, current, str.size() - current));
  return res;
}
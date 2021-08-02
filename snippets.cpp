//
//
//----------------------------------------------------------------
vi_t str2numvec(const std::string& str)
{
    vi_t v(str.size());
    for(int i=0, n=str.size(); i<n; ++i) {
        v[i] = str[i] - '0';
    }
    return v;
}
//----------------------------------------------------------------


//
//
//----------------------------------------------------------------
template<typename T>
vi_t to_unique(std::vector<T>& v)
{
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
}
//----------------------------------------------------------------


//
//
//----------------------------------------------------------------
void strReplace(std::string& str, const std::string& from, const std::string& to) {
  std::string::size_type pos = 0;
  while(pos = str.find(from, pos), pos != std::string::npos) {
    str.replace(pos, from.length(), to);
    pos += to.length();
  }
}
//----------------------------------------------------------------


//----------------------------------------------------------------
//1.) find_first_ofを利用する方法
//　利点: 多分一番シンプルで高速？
//　欠点: デリミタが1文字という制限がある。
//----------------------------------------------------------------
vector<string> split(const string &str, char delim){
  vector<string> res;
  size_t current = 0, found;
  while((found = str.find_first_of(delim, current)) != string::npos){
    res.push_back(string(str, current, found - current));
    current = found + 1;
  }
  res.push_back(string(str, current, str.size() - current));
  return res;
}
//----------------------------------------------------------------
//2.) findを利用する方法
//　利点: デリミタが複数文字も許容
//　欠点: 1より若干遅い
//----------------------------------------------------------------
vector<string> split(const string &str, const string &delim){
  vector<string> res;
  size_t current = 0, found, delimlen = delim.size();
  while((found = str.find(delim, current)) != string::npos){
    res.push_back(string(str, current, found - current));
    current = found + delimlen;
  }
  res.push_back(string(str, current, str.size() - current));
  return res;
}
//----------------------------------------------------------------


//----------------------------------------------------------------
//1.) 左の空白を取り除く
//----------------------------------------------------------------
std::string trimLeftSpace(const std::string& str)
{
  // remove space or tabs
  return str.substr( str.find_first_not_of(" \t") );
}
//----------------------------------------------------------------
//2.) 右の空白・改行を取り除く
//----------------------------------------------------------------
std::string trimRightSpace(const std::string& str)
{
  // remove space or or tabs or new lines
  return str.substr(0, str.find_last_not_of(" \t\n")+1 );
}
//----------------------------------------------------------------


//
// 高速 O(sqrt(n)) でnの約数を昇順で列挙する
//----------------------------------------------------------------
vl_t divisor(ll n)
{
  vl_t res;
  for(ll i=1; i*i<=n; ++i) {
    if( n%i==0 ) {
      res.push_back(i);
      if( i*i!=n ) {
        res.push_back(n/i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}
//----------------------------------------------------------------


//
//
//----------------------------------------------------------------
string dec2Naray(ll x, int n)
{
    // 10進数 → n進数 変換を行う
    // 9進数までにしか対応してないので注意
    // 16進数ぐらいまでは拡張した方が良さそう
    // n進数 → 10進数 変換も用意すべき
    string s;
    while( x ) {
        s = to_string(x%n) + s;
        x /= n;
    }
    return s;
}
//----------------------------------------------------------------


//----------------------------------------------------------------
// ノードの最大値がNの場合にあるノード i から ノード j へ移動可能か否かを
//  seen[j]
// に詰める。すなわちdfs()を呼ぶたびにseenの中身をリセットしないといけない
// ことに注意して使用する
//　計算量：O(N+M)   N:頂点数, M:辺数
//----------------------------------------------------------------
//  for(int i=0; i<N; ++i) {
//    seen.assign(N, false);
//    dfs(G, i);
//    int reachable_from_i = 0;
//    for(const auto& j : seen) if(j) ++reachable_from_i;
//  }
//----------------------------------------------------------------
vector<bool> seen;
void dfs(const vvi_t& G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}
//----------------------------------------------------------------


//----------------------------------------------------------------
// 各辺の重みが1である隣接リスト表記のグラフに対して
// あるノード from から各ノードへの最短経路 の距離を求める
// ノード to へ到達するための経路が存在しない場合は dist[to] = INT_MAX
// となって返ってくる
//　計算量：O()   N:頂点数, M:辺数
//----------------------------------------------------------------
vi_t bfs(const vvi_t& G, int from) {
  vi_t dist(G.size(), INT_MAX);
  queue<int> q;
  q.push(from); dist[from]=0;
  while(q.size()) {
    int v = q.front(); q.pop();
    for(auto u : G[v]) {
      if(dist[u]!=INT_MAX) continue;
      dist[u] = dist[v]+1;
      q.push(u);
    }
  }
  return dist;
}

//----------------------------------------------------------------
// トポロジカルソート
// DAGから入力次数が0の頂点を1つ取り除いたグラフは
// 必ずDAGであるという性質を利用する
// 計算量：計算量：O(N+M)   N:頂点数, M:辺数
//----------------------------------------------------------------
vi_t topological_sort(const vvi_t& G) {
  vi_t res;
  const int N = G.size();
  stack<int> S;
  vi_t degree(N, 0);

  // 拡頂点の入力次数を計算 O(|E|)
  for(const auto& edges : G) {
    for(const auto& edge : edges) {
      ++degree[edge];
    }
  }

  // 入力次数 == 0 の頂点を計算 O(|V|)
  REP(i, N) {
    if(degree[i]==0) S.push(i);
  }

  while ( S.size()>0)
  {
    int u = S.top(); S.pop();
    res.emplace_back(u);
    for(const auto& v : G[u]) {
      --degree[v];
      if( degree[v]==0 ) S.push(v);
    }
  }
  return res;
}

//----------------------------------------------------------------
// 重さ W_i, 価値 V_i の商品iを
// vector<pii_t> v // [重さ, 価値]
// に詰めておいて、商品一覧からいくつか商品を選んでW以内に収める
// という典型的なナップサック問題を解くコード
//----------------------------------------------------------------
ll knapsack(const vector<pii_t>& v, int w){
  int n = v.size();
  vvl_t dp(n+1, vl_t(w+1, 0));
  for(int i=1;i<n+1;i++) {
    for(int j=1;j<w+1;j++){
      if(v[i-1].first<=j){
        dp[i][j]=max(v[i-1].second+dp[i-1][j-v[i-1].first],dp[i-1][j]);
      }
      else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[n][w];
}

//----------------------------------------------------------------
// Longest Common Subsequence
// 共通部分文字列を返す
// 計算量：O(|S||T|)
//----------------------------------------------------------------
string lcs(const string& S, const string& T)
{
  vvi_t dp(S.size()+1, vi_t(T.size()+1, 0));
  REP(i, S.size()) {
    REP(j, T.size()) {
      if(S[i]==T[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1]);
    }
  }

  int len =  dp[S.size()][T.size()];
  int i=S.size()-1;
  int j=T.size()-1;
  string res = "";
  while(len > 0) {
    if( S[i]==T[j] ) {
      res = S[i] + res;
      --i; --j; --len;
    } else if(dp[i+1][j+1]==dp[i][j+1]) {
      --i;
    } else {
      --j;
    }
  }
  return res;
}
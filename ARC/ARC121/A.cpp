#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr)
#define SET_PRECISION(x) cout<< fixed << setprecision((x))
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef vector<int> vi_t;
typedef vector<vector<int> > vvi_t;
typedef vector<ll> vl_t;
typedef vector<vector<ll> > vvl_t;
typedef pair<int, int> pii_t;

vi_t str2numvec(const std::string& str);
vector<string> split(const string &str, char delim);

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
    __MAGIC__;
    int N;
    cin >> N;
    std::vector<pair<long, int> > X(N);
    std::vector<pair<long, int> > Y(N);
    vl_t x(N);
    vl_t y(N);
    for(int i=0; i<N; ++i) {
        cin >> x[i] >> y[i];
        X[i].first = x[i];
        Y[i].first = y[i];
        X[i].second = i;
        Y[i].second = i;
    }
    std::sort(X.begin(), X.end());
    std::sort(Y.begin(), Y.end());


//    ll dx1 = std::abs(X[0].first - X[N-1].first);
//    ll dy1 = std::abs(Y[0].first - Y[N-1].first);
//    ll dx2 = std::max( std::abs(X[1].first - X[N-1].first), std::abs(X[0].first - X[N-2].first) );
//    ll dy2 = std::max( std::abs(Y[1].first - Y[N-1].first), std::abs(Y[0].first - Y[N-2].first) );

    set<pii_t> S;
    S.insert( std::make_pair(min(X[0].second,X[N-1].second), max(X[0].second,X[N-1].second)) );
    S.insert( std::make_pair(min(Y[0].second,Y[N-1].second), max(Y[0].second,Y[N-1].second)) );
    if( std::abs(X[1].first - X[N-1].first) > std::abs(X[0].first - X[N-2].first) ) {
        S.insert( std::make_pair(min(X[1].second,X[N-1].second), max(X[1].second,X[N-1].second)) );
    } else {
        S.insert( std::make_pair(min(X[0].second,X[N-2].second), max(X[0].second,X[N-2].second)) );
    }
    if( std::abs(Y[1].first - Y[N-1].first) > std::abs(Y[0].first - Y[N-2].first) ) {
        S.insert( std::make_pair(min(Y[1].second,Y[N-1].second), max(Y[1].second,Y[N-1].second)) );
    } else {
        S.insert( std::make_pair(min(Y[0].second,Y[N-2].second), max(Y[0].second,Y[N-2].second)) );
    }

    vl_t d;
    for(auto [m, M] : S) {
        d.push_back( std::max(std::abs(x[M]-x[m]), std::abs(y[M]-y[m])) );
    }
    std::sort(d.rbegin(), d.rend());
    cout << d[1] << endl;

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
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
    vector<pii_t> p(N);
    for(auto& [x, y] : p) cin >> x >> y;

    REP(i, N) {
        REP(j, i) {
            REP(k, j) {
                auto [x1, y1] = p[i];
                auto [x2, y2] = p[j];
                auto [x3, y3] = p[k];
                x1 -= x3;
                x2 -= x3;
                y1 -= y3;
                y2 -= y3;
                if(x1 * y2 == x2 * y1){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;

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
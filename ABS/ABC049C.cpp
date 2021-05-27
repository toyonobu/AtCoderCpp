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

string dec2Naray(ll x, int n);
vi_t str2numvec(const std::string& str);
vector<string> split(const string &str, char delim);

bool startsWith(const std::string& str, const std::string& prefix)
{
    if(str.size() < prefix.size()) return false;
    return std::equal(std::begin(prefix), std::end(prefix), std::begin(str));
}

bool endsWith(const std::string& str, const std::string& postfix)
{
    if(str.size() < postfix.size()) return false;
    return std::equal(std::rbegin(postfix), std::rend(postfix), std::rbegin(str));
}

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
    __MAGIC__;
    string S;
    cin >> S;
    std::string s;
    while(true) {
        if (endsWith(S, "dreamer")) {
            s = "dreamer";
            S = S.substr(0, S.size()-s.size());
        } else if (endsWith(S, "dream")) {
            s = "dream";
            S = S.substr(0, S.size()-s.size());
        } else if (endsWith(S, "eraser")) {
            s = "eraser";
            S = S.substr(0, S.size()-s.size());
        } else if (endsWith(S, "erase")) {
            s = "erase";
            S = S.substr(0, S.size()-s.size());
        } else {
            PRINT_YESNO(S.size()==0);
            break;
        }
    }

    return 0;
}

//-----------------------------
// ヘルパー関数群
//-----------------------------
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
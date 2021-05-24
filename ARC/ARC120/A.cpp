#include <bits/stdc++.h>
using namespace std;

#define PRINT_JesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_JESNO(condition) cout<<((condition)?"YES":"NO")<<endl
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


//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
    __MAGIC__;
    int N;
    cin >> N;
    vl_t A(N);
    vl_t SUM_A(N);
    vl_t MAX_A(N);
    vl_t Res(N);
    ll tmp;
    REP(i, N) {
        cin >> tmp;
        A[i] = tmp;
        if(i==0) {
            SUM_A[i] = A[0];
            MAX_A[i] = A[0];
            Res[i] = SUM_A[0];
        } else {
            SUM_A[i] = SUM_A[i-1] + A[i];
            MAX_A[i] = A[i] > MAX_A[i-1] ? A[i] : MAX_A[i-1];
            Res[i] = Res[i-1] + SUM_A[i];
        }

        cout << Res[i] + (i+1) * MAX_A[i] << endl;
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
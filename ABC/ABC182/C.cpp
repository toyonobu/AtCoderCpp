#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr)
#define SET_PRECISION(x) cout<< fixed << setprecision((x))

typedef long long ll;
typedef vector<int> vi_t;
typedef vector<vector<int> > vvi_t;
typedef vector<ll> vl_t;
typedef vector<vector<ll> > vvl_t;

string dec2Naray(ll x, int n);
vi_t str2numvec(const std::string& str);

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
    __MAGIC__;
    string S;
    cin >> S;
    auto v = str2numvec(S);
    vi_t ideal(3);
    ll ideal_sum=0;
    for (const auto& x : v) {
        ideal_sum += x%3;
        ideal_sum = ideal_sum%3;
        ++ideal[x%3];
    }

    int N = S.size();

    if (ideal_sum == 0) {
        cout << "0" << endl;
        return 0;
    } else if (ideal_sum == 2) {
        if (N>1 && ideal[2]) {
            cout << "1" <<endl;
            return 0;
        } else if (N>2 && ideal[1] >= 2) {
            cout << "2" << endl;
            return 0;
        }
    } else {//ideal_sum==1
        if (N>1 && ideal[1]) {
            cout << "1" <<endl;
            return 0;
        } else if (N>2 && ideal[2] >= 2) {
            cout << "2" << endl;
            return 0;
        }
    }
    cout << "-1" << endl;

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

#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr)

typedef long long ll;
string dec2Naray(ll x, int n);

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
    __MAGIC__;
    ll N, M, T;
    cin >> N >> M >> T;

    ll power = N;
    ll now = 0, A, B, diff;
    for(ll i=0; i<M; ++i) {
        cin >> A >> B;
        diff = A - now;
        if(power <= diff) {
            cout << "No" << endl;
            return 0;
        }
        power -= diff;
        now = A;

        diff = B-A;
        now = B;
        power = min( N, power + diff);
    }
    diff = T - B;
    PRINT_YesNo( power > diff );

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
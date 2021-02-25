#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;

ll func(string s)
{
    if (s == "0") return 0;

    sort(s.begin(), s.end());
    stringstream ss = stringstream(s);
    ll inc;
    ss >> inc;

    string s2 = "";
    for (auto x : s) {
        s2 = x + s2;
    }
    stringstream ss2 = stringstream(s2);
    ll dec;
    ss2 >> dec;

    return dec - inc;
}

int main()
{
    string N;
    ll K;
    cin >> N >> K;
    if (K==0) {
        cout << N << endl;
    } else {
        ll res = func(N);
        for(ll i=0; i<K-1; ++i) {
            res = func( to_string(res) );
        }
        cout << res << endl;
    }
    return 0;
}

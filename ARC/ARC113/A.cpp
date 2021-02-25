#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;

int main()
{
    ll K;
    cin >> K;

    ll res = 0;
    for(ll A=1; A<=K; ++A) {
        for(ll B=1; A*B<=K; ++B) {
            for(ll C=1; A*B*C<=K; ++C) {
                ++res;
            }
        }
    }

    cout << res << endl;
    return 0;
}

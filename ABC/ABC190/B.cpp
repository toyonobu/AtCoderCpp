#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl;
typedef long long ll;

int main()
{
    ll N, S, D;
    ll X, Y;
    cin >> N >> S >> D;
    for (ll i=0; i<N; ++i) {
        cin >> X >> Y;
        if( X<S && Y>D) {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;

    return 0;
}

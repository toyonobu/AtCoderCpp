#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<string> S(N);
    for(auto& s : S) cin >> s;

    unordered_set<string> hash(S.begin(), S.end());

    for(const auto& s : S) {
        if( hash.count("!"+s) ) {
            cout << s << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;

    return 0;
}

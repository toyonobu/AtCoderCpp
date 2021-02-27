#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr)

typedef long long ll;

string dec2Naray(ll x, int n);

int main()
{
    __MAGIC__;
    int N;
    cin >> N;

    unordered_set<int> sevens;

    for(int i=1; i<=N; ++i) {
        auto dec = to_string(i);
        auto oct = dec2Naray(i, 8);
        if( dec.find("7")!=string::npos ||
            oct.find("7")!=string::npos) {
            sevens.insert( i );
        }
    }
    cout << N - sevens.size() << endl;

    return 0;
}


string dec2Naray(ll x, int n)
{
    string s;
    while( x ) {
        s = to_string(x%n) + s;
        x /= n;
    }
    return s;
}

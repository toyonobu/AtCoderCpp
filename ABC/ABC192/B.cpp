#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;

int main()
{
    string S;
    cin >> S;
    int n = S.size();
    int i=0;
    for (auto x : S) {
        if (i%2) {
            // 奇数
            if (!isupper(x)) {
                cout <<"No" << endl;
                return 0;
            }
        } else {
            if (isupper(x)) {
                cout <<"No" << endl;
                return 0;
            }
        }
        ++i;
    }
    cout <<"Yes"<<endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr)

typedef long long ll;

int main()
{
    __MAGIC__;

    int H, W;
    cin >> H >> W;
    vector<int> v;
    int A;
    for(int h=0; h<H; ++h) {
        for(int w=0; w<W; ++w) {
            cin >> A;
            v.emplace_back(A);
        }
    }
    int min = *min_element(v.begin(), v.end());
    int sum=0;
    for(const auto x :v) {
        sum += x - min;
    }
    cout << sum << endl;
    return 0;
}

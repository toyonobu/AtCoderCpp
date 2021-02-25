#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> v(N);
    for (auto& x : v) {cin >> x;}

    for (int i=0; i<N; ++i) {
        if (v[i] != X) {cout << v[i] << " ";}
    }

    return 0;
}

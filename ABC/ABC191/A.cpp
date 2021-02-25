#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;

int main() {
    int V, T, S, D;
    cin >> V >> T >> S >> D;

    PRINT_YesNo( D < V*T || D > V*S );

    return 0;
}

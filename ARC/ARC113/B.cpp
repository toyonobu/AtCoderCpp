#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;0

int val_of_1st(ll x)
{
    return x % 10;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, C;
    cin >> A >> B >> C;

    const int row = 10;
    const int mod4 = 4;
    int master[row][mod4] = {
        {0,0,0,0},
        {1,1,1,1},
        {6,2,4,8},
        {1,3,9,7},
        {6,4,6,4},
        {5,5,5,5},
        {6,6,6,6},
        {1,7,9,3},
        {6,8,4,2},
        {1,9,1,9}
    };

    ll tmp = master[B%4][C%4];
    ll result = master[ val_of_1st(A) ][tmp%4];
    cout << result <<endl;

    return 0;
}

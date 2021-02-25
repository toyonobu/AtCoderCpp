#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H,W;
    cin >> H >> W;
    vector<string> v(H);
    for (int y=0; y<H; ++y) {cin>>v[y];}

    int result=0;
    for (int y=0; y<H-1; ++y) {
        for (int x=0; x<W-1; ++x) {
            int np=(v[y][x]=='#') + (v[y][x+1]=='#') + (v[y+1][x]=='#') + (v[y+1][x+1]=='#');
            if( np%2 ) ++result;
        }
    }
    cout << result << endl;

    return 0;
}

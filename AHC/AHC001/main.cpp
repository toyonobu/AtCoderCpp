#include <bits/stdc++.h>
using namespace std;

#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr)

typedef long long ll;
typedef vector<int> vi_t;
typedef vector<vector<int> > vvi_t;
typedef vector<ll> vl_t;
typedef vector<vector<ll> > vvl_t;

tuple<int, int, int, int> getExtendablility(const vector<tuple<int, int, int, int> >& rects, int iPos);

int getExtendablilityXL(const vector<tuple<int, int, int, int> >& rects, int iPos);
int getExtendablilityXR(const vector<tuple<int, int, int, int> >& rects, int iPos);
int getExtendablilityYL(const vector<tuple<int, int, int, int> >& rects, int iPos);
int getExtendablilityYR(const vector<tuple<int, int, int, int> >& rects, int iPos);

int main()
{
    __MAGIC__;
    int N;
    cin >> N;
    vector<tuple<int, int, int> > v(N);
    for(auto& [r, x, y]:v) {
        cin >> x;
        cin >> y;
        cin >> r;
    }

    int i;
    vector<tuple<int, int, int, int> > res(N);
    i=0;
    for(auto& [xl, yl, xr, yr]:res) {
        auto& [r, x, y] = v[i];
        xl = x;
        yl = y;
        xr = x + 1;
        yr = y + 1;
        ++i;
    }

    for(int i=0, n=res.size(); i<n; ++i) {
        auto& [xl, yl, xr, yr] = res[i];
        xl -= getExtendablilityXL(res, i);
    }
    for(int i=0, n=res.size(); i<n; ++i) {
        auto& [xl, yl, xr, yr] = res[i];
        xr += getExtendablilityXR(res, i);
    }
    int min=20000; int index=0;
    for(int i=0, n=res.size(); i<n; ++i) {
        auto& [xl, yl, xr, yr] = res[i];
        if( yl < min ) {
            min = yl;
            index = i;
        }
    }
    get<1>(res[index]) = 0;
    for(int i=0, n=res.size(); i<n; ++i) {
        auto& [xl, yl, xr, yr] = res[i];
        yr += getExtendablilityYR(res, i);
    }

    for(auto& [xl, yl, xr, yr]:res) {
        cout << xl << " "
             << yl << " "
             << xr << " "
             << yr << endl;
    }

    return 0;
}

tuple<int, int, int, int> getExtendablility(const vector<tuple<int, int, int, int> >& rects, int iPos)
{
    const auto& [xl, yl, xr, yr] = rects[iPos];
    tuple<int, int, int, int> res = make_tuple(20000, 20000, 20000, 20000);
    auto& [res_xl, res_yl, res_xr, res_yr] = res;

    for(int i=0, n=rects.size(); i<n; ++i) {
        if(i==iPos) continue;
        const auto& [Xl, Yl, Xr, Yr] = rects[i];
        int dxl = xl - Xr > 0 ? xl - Xr : 20000;
        int dyl = yl - Yr > 0 ? xl - Yr : 20000;
        int dxr = Xl - xr > 0 ? Xl - xr : 20000;
        int dyr = Yl - yr > 0 ? Yl - yr : 20000;

        res_xl = min(res_xl, dxl);
        res_yl = min(res_yl, dyl);
        res_xr = min(res_xr, dxr);
        res_yr = min(res_yr, dyr);
    }
    res_xl = min(res_xl, xl);
    res_yl = min(res_yl, yl);
    res_xr = min(res_xr, 10000 - xr);
    res_yr = min(res_yr, 10000 - yr);

    return res;
}

int getExtendablilityXL(const vector<tuple<int, int, int, int> >& rects, int iPos)
{
    const auto& [xl, yl, xr, yr] = rects[iPos];
    int res = xl;

    for(int i=0, n=rects.size(); i<n; ++i) {
        if(i==iPos) continue;
        const auto& [Xl, Yl, Xr, Yr] = rects[i];
        if (yl>Yl || yr<Yl) continue;

        int d = xl -Xr >= 0 ? xl -Xr : 20000;
        res = min(d, res);
    }

    return res;
}


int getExtendablilityXR(const vector<tuple<int, int, int, int> >& rects, int iPos)
{
    const auto& [xl, yl, xr, yr] = rects[iPos];
    int res = 10000 - xr;

    for(int i=0, n=rects.size(); i<n; ++i) {
        if(i==iPos) continue;
        const auto& [Xl, Yl, Xr, Yr] = rects[i];
        if (yl>Yl || yr<Yl) continue;

        int d = Xl -xr >= 0 ? Xl -xr : 20000;
        res = min(d, res);
    }

    return res;
}


int getExtendablilityYL(const vector<tuple<int, int, int, int> >& rects, int iPos)
{
    const auto& [xl, yl, xr, yr] = rects[iPos];
    int res = yl;

    for(int i=0, n=rects.size(); i<n; ++i) {
        if(i==iPos) continue;
        const auto& [Xl, Yl, Xr, Yr] = rects[i];
        int d = yl -Yr >= 0 ? yl -Yr : 20000;
        res = min(d, res);
    }

    return res;
}


int getExtendablilityYR(const vector<tuple<int, int, int, int> >& rects, int iPos)
{
    const auto& [xl, yl, xr, yr] = rects[iPos];
    int res = 10000 - yr;

    for(int i=0, n=rects.size(); i<n; ++i) {
        if(i==iPos) continue;
        const auto& [Xl, Yl, Xr, Yr] = rects[i];
        int d = Yl -yr >= 0 ? Yl -yr : 20000;
        res = min(d, res);
    }

    return res;
}

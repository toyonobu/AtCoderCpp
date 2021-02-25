#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;

//class Radix {
//private:
//  const char* s;
//  int a[128];
//public:
//  Radix(const char* s = "0123456789ABCDEF") : s(s) {
//    int i;
//    for(i = 0; s[i]; ++i)
//      a[(int)s[i]] = i;
//  }
//  std::string to(long long p, int q) {
//    ll i;
//    if(!p)
//      return "0";
//    char t[128] = { };
//    for(i = 63; p; --i) {
//      t[i] = s[p % q];
//      p /= q;
//    }
//    return std::string(t + i + 1);
//  }
//  std::string to(const std::string& t, int p, int q) {
//    return to(to(t, p), q);
//  }
//  long long to(const std::string& t, int p) {
//    int i;
//    long long sm = a[(int)t[0]];
//    for(i = 1; i < (int)t.length(); ++i)
//      sm = sm * p + a[(int)t[i]];
//    return sm;
//  }
//};


int main()
{
    string tmp;
    ll M;
    cin >> tmp >> M;
    int s_max=0;
    for (int i=0; i<tmp.size(); ++i) {
        int x;
        char* sss = const_cast<char*>(tmp.c_str());
        string ssss = to_string(sss[i]);
        auto ss = stringstream( ssss );
        ss >> x;
        x -=48;
        if (x > s_max) s_max = x;
    }


    int res=0;
    //Radix r;
    while( 1 ) {
        ll cal;
        std::from_chars(tmp.c_str(), tmp.c_str()+sizeof(tmp), cal, s_max + res  +1);
        //ll cal = r.to(tmp, s_max + res  +1);
        if (cal < 0) cal = -cal;
        //cout << cal << ": " << M <<endl;
        if ( cal > M ) break;

        ++res;
    }
    cout<<res<<endl;

    return 0;
}

//
//
//----------------------------------------------------------------
vi_t str2numvec(const std::string& str)
{
    vi_t v(str.size());
    for(int i=0, n=str.size(); i<n; ++i) {
        v[i] = str[i] - '0';
    }
    return v;
}
//----------------------------------------------------------------


//
//
//----------------------------------------------------------------
void strReplace(std::string& str, const std::string& from, const std::string& to) {
  std::string::size_type pos = 0;
  while(pos = str.find(from, pos), pos != std::string::npos) {
    str.replace(pos, from.length(), to);
    pos += to.length();
  }
}
//----------------------------------------------------------------


//----------------------------------------------------------------
//1.) find_first_ofを利用する方法
//　利点: 多分一番シンプルで高速？
//　欠点: デリミタが1文字という制限がある。
//----------------------------------------------------------------
vector<string> split(const string &str, char delim){
  vector<string> res;
  size_t current = 0, found;
  while((found = str.find_first_of(delim, current)) != string::npos){
    res.push_back(string(str, current, found - current));
    current = found + 1;
  }
  res.push_back(string(str, current, str.size() - current));
  return res;
}
//----------------------------------------------------------------
//2.) findを利用する方法
//　利点: デリミタが複数文字も許容
//　欠点: 1より若干遅い
//----------------------------------------------------------------
vector<string> split(const string &str, const string &delim){
  vector<string> res;
  size_t current = 0, found, delimlen = delim.size();
  while((found = str.find(delim, current)) != string::npos){
    res.push_back(string(str, current, found - current));
    current = found + delimlen;
  }
  res.push_back(string(str, current, str.size() - current));
  return res;
}
//----------------------------------------------------------------


//----------------------------------------------------------------
//1.) 左の空白を取り除く
//----------------------------------------------------------------
std::string trimLeftSpace(const std::string& str)
{
  // remove space or tabs
  return str.substr( str.find_first_not_of(" \t") );
}
//----------------------------------------------------------------
//2.) 右の空白・改行を取り除く
//----------------------------------------------------------------
std::string trimRightSpace(const std::string& str)
{
  // remove space or or tabs or new lines
  return str.substr(0, str.find_last_not_of(" \t\n")+1 );
}
//----------------------------------------------------------------



//
//
//----------------------------------------------------------------
string dec2Naray(ll x, int n)
{
    // 10進数 → n進数 変換を行う
    // 9進数までにしか対応してないので注意
    // 16進数ぐらいまでは拡張した方が良さそう
    // n進数 → 10進数 変換も用意すべき
    string s;
    while( x ) {
        s = to_string(x%n) + s;
        x /= n;
    }
    return s;
}
//----------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//This function checks wheather a line is comment or not 
//If the first two character is "//" or "/*" then it is a comment otherwise it is not
bool is_comment(char c, char ch) {
    if(ch=='/' && ch=='/') return true;
    if(ch=='/' && ch=='*') return true;
    return false;
}

void solve(){
    string s;getline(cin, s);
    cout << "Expression " << ": " << s << endl;
    bool ok = 0;
    int n = s.size();
    for(int i=0;i<n-1;i++){
        if(is_comment(s[i],s[i+1])) ok = true;
    }
    cout << "Is Comment: " << (ok ? "Yes" : "No") << endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}
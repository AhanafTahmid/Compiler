#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

bool is_operator(char c) {
    string op = "+-*/%=<>!&|^";
    for (int i = 0; i<op.size(); i++) {
        if (c == op[i]) {
            return true;
        }
    }
    return false;
}

//This function counts the total number of operators
int total_operators(string s) {
    int cnt = 0;
    for(int i=0;i<s.size();i++) if(is_operator(s[i])) cnt++;
    return cnt;
}

void solve(){
    string s;cin>>s;
    cout << "Expression " << ": " << s << endl;
    cout << "Number of operators: " << total_operators(s) << endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}
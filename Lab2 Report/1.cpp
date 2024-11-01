//Comments has been added as instructed

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//This function checks whether the character is an operator or not
bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
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
//Id: C223101

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//This function checks valid strings if it follows: a+

bool valid(string &s){
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i]!='a') return false;
    }
    return true;
}

void solve(){
    string s;cin>>s;
    cout << "Expression " << ": " << s << endl;
    cout << (valid(s)?"The string follows a+":"The string does not follow a+") << endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}
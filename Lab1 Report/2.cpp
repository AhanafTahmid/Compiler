//Id: C223101

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//This function checks valid strings if it follows: a+

// aaabbbbb
// bbbb
bool valid(string &s){
    int n = s.size();
    int ct = 0;
    for(int i=0;i<n;i++){
        //if after 'b' another character comes then it is invalid
        if(i+1<n && s[i]=='b' && s[i+1]!='b') return false;
        //if the character is neither a or b then it is false
        if(s[i]!='a' && s[i]!='b') return false;
        ct+= s[i]=='b';
    }
    //if 0 'b's then it invalid
    if(ct==0) return false;
    return true;
}

void solve(){
    string s;cin>>s;
    cout << "Expression " << ": " << s << endl;
    cout << (valid(s)?"The string follows a*b+":"The string does not follow a*b+") << endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}
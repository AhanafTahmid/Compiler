//Comments has been added as instructed

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//This function checks wheather the character is an operator or not
bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

//This function checks for valid expressions
//There are 4 if else statements. Chronologically if-else workings are below:
//1. checks wheather two consecutive characters are operator, in that case it is invalid
//2. checks if the current character is wheather an alphabet or a digit. In that case it is invalid, set last_operator = false;
//3. check for parentheses ending and closing
//4. same as step 3
//step 3 and 4 is basically to check if brackets are ending and closing correctly

bool is_valid_expression(string s) {
    int parentheses = 0;
    bool last_operator = true; 

    for (char c : s) {
        if (is_operator(c)) {
            if (last_operator) {
                return false;
            }
            last_operator = true;
        } else if(isalpha(c) || isdigit(c) ) {
            last_operator = false;
        } else if (c == '(') {
            parentheses++;
        } else if (c == ')') {
            if (parentheses == 0) {
                return false;
            }
            parentheses--;
        }
    }

    if(!last_operator && parentheses) return true;
    else false;
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
    bool is_valid = is_valid_expression(s);
    cout << "Is valid: " << (is_valid ? "Yes" : "No") << endl << endl;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--)solve(); 
    return 0;
}
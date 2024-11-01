//This is quite a big code, So explanation is written properly in comments whenever necessary

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

//Keywords
set<string> keywords = {
    "const", "int", "double", "string", "char", "long long", 
    "long", "bool", "for", "do", "while", "void", "float"
};

//this function is to check wheather "keyword" exist in our substring
bool is_keyword(string& substr) {
    return keywords.find(substr) != keywords.end();
}

//for checking operators
bool is_operator(char c) {
    string op = "+-*/%=<>!&|^";
    for (int i = 0; i < op.size(); i++) {
        if (c == op[i]) {
            return true;
        }
    }
    return false;
}

//this is to stop extending our susbstring 
//whenever any character appear that act as boundary
bool is_delimiter(char c) {
    string op = ".{};() \",#\t\n";
    for (int i = 0; i < op.size(); i++) {
        if (c == op[i] || isdigit(c)) {
            return true;
        }
    }
    return false;
}

void solve() {
    ifstream inputFile("/Volumes/Files/Programming/Compiler/Lab2 Report/file.cpp");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return;
    }

    string line;
    int total_lines = 0;
    bool in_multiline_comment = false;

    while (getline(inputFile, line)) {
        total_lines++;
        int n = line.size();
        bool flag = false;

        //This line is for ignoring the single line comment
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && line[i] == '/' && line[i + 1] == '/') {
                flag = true;
                break;
            }
        }
        if (flag) continue;//don't go below, if it was a single comment

        //for multiline comment, ignore lines until "*/" found in another line
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && line[i] == '/' && line[i + 1] == '*') {
                in_multiline_comment = true;
                i++;
                break;
            }
        }

        if(in_multiline_comment){
            for (int i = 0; i < n; i++) {
                if (i + 1 < n && line[i] == '*' && line[i + 1] == '/') {
                    in_multiline_comment = false;
                    i++;
                    break;
                }
            }
        }
        
        if (in_multiline_comment) continue;//don't go below, until multiline comment is closed





        //this is the main part of identifying identifer and keyword
        string substr="";
        for (size_t i = 0; i < line.length(); i++) {
            if (is_operator(line[i]) || is_delimiter(line[i]) ) {
                if (!substr.empty()) {
                    // Check if the substring is a keyword or identifier
                    if (is_keyword(substr)) {
                        cout << substr << " - Keyword\n";
                    } else {
                        cout << substr << " - Identifier\n";
                    }
                    substr.clear();  // Reset substring
                }
            } else {
                //Building the substring from here
                substr += line[i];
            }
        }

        if (!substr.empty()) {  // Check for any remaining substr
            if (is_keyword(substr)) {
                cout << substr << " - Keyword\n";
            } else {
                cout << substr << " - Identifier\n";
            }
        }
    }
    inputFile.close();
    cout << "Total lines: " << total_lines << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve(); 
    return 0;
}
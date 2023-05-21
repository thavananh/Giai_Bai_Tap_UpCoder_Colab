#include <bits/stdc++.h>
using namespace std;

void An(string& s);
void _An(string& s);

int main() {
    int n = 0;  cin >> n;  cin.ignore();
    string ten[20], email[20];
    for(int i = 0; i < n; i++){
        string temp = ""; getline(cin, temp);
        An(temp);
        _An(temp);
        ten[i] = temp.substr(temp.rfind(" ") + 1);
        email[i] = ten[i];
        int an = 0;
        while(an != string::npos){
            if(an == 0) {email[i] += temp[an];}
            else {email[i] += temp[an + 1];}
            an = temp.find(" ", an + 1);
        }
        email[i][email[i].length() - 1] = '@';
        email[i] += "gmail.com";
        ten[i] = email[i].substr(0, email[i].find("@"));
    }
    for(int i = 0; i < n - 1; i++){
        int k = 2;
        for(int j = i + 1; j < n; j++){
            if(email[i] == email[j]) {
                email[j] = ten[j] + to_string(k) + "@gmail.com";
                k++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(i != n - 1)  {cout << email[i] << endl;}
        else            {cout << email[i];}
    }
    return 0;
}

void An(string& s){
    while(s[0] == ' ')  {s.erase(0, 1);}
    while(s[s.length() - 1] == ' ') {s.erase(s.length() - 1, 1);}
    for(int i = 0; i < s.length() - 1; i++){
        if(s[i] == ' ' && s[i + 1] == ' ')  {s.erase(i, 1); i--;}
    }
}
void _An(string& s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z')  {s[i] += 32;}
    }
}

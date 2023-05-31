#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<string>
using namespace std;

string chuanHoa(string s){
    for(int i = 0; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }
    vector<string> v;
    stringstream ss(s);
    string token;
    while(ss >> token){
        v.push_back(token);
    }
    s = "";
    s += v[v.size() - 1];
    for(int i = 0; i < v.size() - 1; i++){
        s += (v[i])[0];
    }
    return s;
}

int main(){
    int n;
    string s[100];
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, s[i]);
        s[i] = chuanHoa(s[i]);
    }
    map<string, int> mp;
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
        cout << s[i];
        if(mp[s[i]] != 1) 
            cout << mp[s[i]];
        cout << "@gmail.com";
        if(i < n - 1) cout << endl;
    }
    return 0;
}

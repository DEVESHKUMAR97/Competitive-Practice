#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define casenum cout << "Case " << ++tt << ": "
#define endl '\n'
using namespace std;

vector < pair <string , string > > books;
map <string, int> mp;

void convert_in_pair(string s){
    string author, title, temp;
    int count = 0;

    int flag = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '"'){
            count++;
        }
        temp += s[i];
        if(flag == 0 && count == 2){
            title = temp;
            temp = "";
            flag = 1;
        }
    }
    author = temp;
    books.push_back({author, title});
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    cout<<fixed<<setprecision(10);

    string s;
    
    while(getline(cin, s), s != "END"){
        convert_in_pair(s);
    }
    sort(books.begin(), books.end());
        int n = books.size();
        for(int i = 0; i < n; i++){
        cerr << books[i].first << " " << books[i].second << endl;
    }

    int placed[n];
    for(int i = 0; i < n; i++){
        placed[i] = 1;
    }

    for(int i = 0; i < n; i++){
        mp[books[i].second] = i;
    }

    string ttl;
    map <string, int> returns;
    string last_present_title;
    while(getline(cin, s), s != "END"){
        if(s[0] == 'B'){
            placed[mp[ttl]] = 0;
            cout << "B" << endl;
        } else if(s[0] == 'R'){
            cout << "R\n";
            returns[ttl] = 1;
        } else {
            cout << "S\n";
            for(int i = 0; i < n; i++){
                if(placed[i] == 0 && returns[books[i].second] == 1){
                    if(i == 0){
                        cout << "Put " << books[i].second << " first\n";
                        last_present_title = books[i].second;
                    } else {
                        cout << "Put " << books[i].second << " after " << last_present_title << endl;
                        last_present_title = books[i].second; 
                    }
                    returns[books[i].second] = 0;
                } else if(placed[i] == 1){
                    last_present_title = books[i].second;
                }
            }
            returns.clear();
        }
        cout << "placed: ";
        for(int i = 0; i < n; i++){
            cout << placed[i] << " ";
        }
        cout << endl;
        cout << "returns: ";
        for(auto itr = returns.begin(); itr != mp.end(); itr++){
            cout << "{" << itr->first << "," << itr->second << "}, ";
        }
        cout << endl;
    }

    return 0;
}  


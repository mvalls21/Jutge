#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct elem {
    bool appear;
    string word;
};

void print(const vector<elem>& v){
    int n = v.size();
    bool first = true;

    cout << '{';
    for (int i = 0; i < n; ++i) if (v[i].appear) {
        if (not first) cout << ',';
        cout << v[i].word;
        first = false;
    }
    cout << '}' << endl;
}

void subsets(vector<elem>& v, int i){
    if (i >= 0){
        v[i].appear = true;
        subsets(v, i - 1);
        v[i].appear = false;
        subsets(v, i - 1);
    }
    else print(v);
}

int main(){
    int n;
    cin >> n;

    vector<elem> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].word;

    subsets(v, n - 1);
}
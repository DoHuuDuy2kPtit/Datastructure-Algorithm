 #include<bits/stdc++.h>

 using namespace std;

bool compare(pair<int,int> &p1, pair<int,int> &p2){
    if(p1.second == p2.second) return p1.first < p2.first;
    else return p1.second > p2.second;
}

void printSorted(int a[],int n){
    map<int,int> m;
    for(int i = 0; i < n; i++) m[a[i]]++;

    vector< pair<int,int> > p;

    // int i = 0;
    // for(auto it = m.begin(); it != m.end(); ++it)
    //     p[i++] = make_pair(it->first,it->second);

    for(auto it: m){
        p.push_back({it.first,it.second});
    }

    sort(p.begin(),p.end(),compare);

    for(int i = 0; i < p.size(); i++){
        int freq = p[i].second;
        while(freq--){
            cout << p[i].first <<" ";
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        printSorted(a,n);
        cout << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1,0),B(N+1,0),dp(N+1,0),root;
    for(int i = 2; i < N+1; i++) cin >> A.at(i);
    for(int i = 3; i < N+1; i++) cin >> B.at(i);

    dp.at(2) = A.at(2);
    for(int i = 3; i < N+1; i++){
        int dp_1 = A.at(i) + dp.at(i-1);
        int dp_2 = B.at(i) + dp.at(i-2);
        dp.at(i) = min(dp_1,dp_2);
    }

    int place = N;
    while(true){
        // cout << place << endl;
        root.push_back(place);
        if(place == 1) break;
        if(place == 2){
            place -= 1;
            continue;
        }
        int root_1 = dp.at(place-1) + A.at(place);
        int root_2 = dp.at(place-2) + B.at(place);
        if(root_1 > root_2) place -= 2;
        else place -= 1;
    }

    cout << root.size() << endl;
    reverse(root.begin(),root.end());
    for(int i = 0; i < root.size(); i++) cout << root.at(i) << " ";
    return 0;
}

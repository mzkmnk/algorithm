#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1),B(N+1),dp(N+1),result;
    for(int i = 2; i < N+1; i++) cin >> A.at(i);
    for(int i = 3; i < N+1; i++) cin >> B.at(i);
    dp.at(2) = A.at(2);
    for(int i = 3; i < N+1; i++) dp.at(i) = min(A.at(i) + dp.at(i-1),B.at(i) + dp.at(i-2));
    int place = N;
    while(place > 0){
        result .push_back(place);
        if(dp.at(place) - A.at(place) == dp.at(place - 1)){
            place--;
        }else{
            place -= 2;
        }
    }
    sort(result.begin(),result.end());
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++) cout << result.at(i) << " ";
    cout << endl;
    return 0;
}
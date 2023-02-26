#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,A,B;
    cin >> N >> A >> B;
    vector<bool> dp(N+1,false);
    //fristについてのdp
    for(int i = A; i < B; i++) dp.at(i) = true;
    for(int i = B; i < N+1; i++){
        if(dp.at(i-A) == false || dp.at(i-B) == false) dp.at(i) = true;
    }
    for(int i = 0; i < N+1; i++) cout << dp.at(i) << " ";
    if(dp.at(N)) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
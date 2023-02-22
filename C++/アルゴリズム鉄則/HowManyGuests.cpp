#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> A(N),cumulative(N+1,0);
    for(int i = 0; i < N; i++) cin >> A.at(i);
    for(int i = 1; i < N+1; i++) cumulative.at(i) = cumulative.at(i-1) + A.at(i-1);
    
    for(int _ = 0; _ < M; _++){
        int L,R;
        cin >> L >> R;
        cout << cumulative.at(R) - cumulative.at(L-1) << endl;
    }
}
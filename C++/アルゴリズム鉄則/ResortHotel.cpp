#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1,0);
    for(int i = 1; i < N+1; i++) cin >> A.at(i);
    vector<int> camulative_L(N+1,0),camulative_R(N+1,0);
    for(int i = 1; i < N+1; i++) camulative_L.at(i) = max(camulative_L.at(i-1),A.at(i));
    // for(int i = 0; i < N+1; i++) cout << camulative_L.at(i) << " ";
    // cout << endl;
    // camulative_R.at(N) = A.at(N);
    for(int i = N-1; i > 0; i--) camulative_R.at(i) = max(camulative_R.at(i+1),A.at(i));
    // for(int i = 0; i < N+1; i++) cout << camulative_R.at(i) << " ";
    // cout << endl;

    int D;
    cin >> D;

    for(int d = 0; d < D; d++){
        int L,R,result = 0;
        cin >> L >> R;
        result = max(camulative_L.at(L-1),camulative_R.at(R+1));
        cout << result << endl;
    }
    return 0;
}   
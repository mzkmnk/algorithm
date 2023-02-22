#include <iostream>
#include <vector>
using namespace std;

int main(){
    int D,N;
    cin >> D >> N;
    vector<int> n(D+1,0);
    for(int i = 0; i < N; i++){
        int L,R;
        cin >> L >> R;
        for(int j = L; j < R+1; j++){
            n.at(j)++;
        }
    }
    for(int i = 1; i < D+1; i++) cout << n.at(i) << endl;
}
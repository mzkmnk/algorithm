#include <iostream>
#include <vector>
using namespace std;

int main(){
    int H,W,N;
    cin >> H >> W >> N;
    vector<vector<int> > camulative(H+1, vector<int>(W+1,0));
    for(int cnt = 0; cnt < N; cnt++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        camulative.at(a-1).at(b-1) += 1;
        camulative.at(c).at(d) += 1;
        camulative.at(a-1).at(d) -= 1;
        camulative.at(c).at(b-1) -= 1;
    }

    //列
    for(int w = 0; w < W+1; w++){
        for(int h = 1; h < H+1; h++){
            camulative.at(h).at(w) += camulative.at(h-1).at(w);
        }
    }
    //行
    for(int h = 0; h < H+1; h++){
        for(int w = 1; w < W+1; w++){
            camulative.at(h).at(w) += camulative.at(h).at(w-1);
        }
    }
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            cout << camulative.at(h).at(w) << " ";
        }
        cout << endl;
    }
}
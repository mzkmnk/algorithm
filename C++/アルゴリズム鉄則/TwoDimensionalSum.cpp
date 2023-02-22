#include <iostream>
#include <vector>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<int> > maze(H, vector<int>(W)),camulative(H+1,vector<int>(W+1,0));

    for(int h = 0; h < H; h++) for(int w = 0; w < W; w++) cin >> maze.at(h).at(w);
    for(int h = 1; h < H+1; h++){
        for(int w = 1; w < W+1; w++){
            camulative.at(h).at(w) = camulative.at(h).at(w-1) + maze.at(h-1).at(w-1);
        }
    }


    int q;
    cin >> q;
    for(int _ = 0; _ < q; _++){
        int a,b,c,d,sum = 0;
        cin >> a >> b >> c >> d;
        for(int i = a; i < c + 1; i++) sum += camulative.at(i).at(d) - camulative.at(i).at(b-1);
        cout << sum << endl;
    }
}
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> block(N+1);
    for(int i = 1; i < N+1; i++) block.at(i) = i;
    vector<vector<int> > PA(N+1,vector<int>(2));
    for(int i = 1; i < N+1; i++) cin >> PA.at(i).at(0) >> PA.at(i).at(1);
    //貪欲法は無理だった！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
    cout << "---------------------" << endl;
    int left = 1, right = N,score = 0;
    for(int i = 1; i < N; i++){
        //-------------
        cout << score << endl;
        for(int i = 1; i < N+1;i++){
            for(int j = 0; j < 2; j++){
                cout << PA.at(i).at(j) << " ";
            }
            cout << endl;
        }
        cout << "left = " << left << " right = " << right << endl;
        //--------------
        int left_index = PA.at(left).at(0),left_score = PA.at(left).at(1),
        right_index = PA.at(right).at(0),right_score = PA.at(right).at(1);
        if(left_index == 0 && right_index == 0){
            left++;
            right--;
            continue;
        }
        if(left_index == 0 || right_index == 0){
            if(left_index == 0){
                right--;
                score += right_score;
                PA.at(right).at(0) = 0;
                continue;
            }else{
                cout << "score = " << score << endl;
                cout << "right = " << right << endl;
                cout << "left_score = " << left_score << endl;
                left++;
                score += left_score;
                PA.at(left).at(0) = 0;
                continue;
            }
        }
        if(left_score > right_score){
            left++;
            PA.at(right).at(0) = 0;
            score += left_score;
        }else{
            right--;
            PA.at(left).at(0) = 0;
            score += right_score;
        }
    }
    cout << score << endl;
    return 0;
}
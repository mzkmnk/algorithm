
    for(int i = 1; i < N*N+1; i++){
        int num = K - AB.at(i);
        int left = 1, right = N*N+1,mid = (right + left) / 2;;
        while(right - left > 0){
            if(num >= CD.at(mid)) left = mid;
            else right = mid - 1;
            mid = (right + left) / 2;
        }
        if(num == CD.at(mid)){
            cout << mid << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
    int sum, avg, val, min, tmp;

    vector<vector<int>> v(10,vector<int>(10));

    for(int i = 1; i <= 9; ++i){
        sum = 0;
        for(int j = 1; j <= 9; ++j){
             scanf("%d",&v[i][j]);
             sum += v[i][j];
        }
        avg = (sum / 9.0) + 0.5; //소수 첫 째 자리에서 반올림
        printf("%d ",avg);
        min=2147000000;
        for(int j = 1; j <= 9; ++j){
            tmp = abs(v[i][j] - avg);
            if(tmp < min){
                min = tmp;
                val = v[i][j];
            }
            else if(tmp == min){
               if(v[i][j] > val) val = v[i][j];
            }
        }
        printf("%d\n",val);
    }
    return 0;
}
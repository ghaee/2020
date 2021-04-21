#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// three pointers

int main(int argc, char** argv){
    int n, min = 214700000;
    int *p2, *p3, *p5;
    cin >> n;
    vector<int> ugly(n+1);
    ugly[1]=1;
    p2 = &ugly[1];
    p3 = &ugly[1];
    p5 = &ugly[1];
   
    for(int i = 2; i <= n; ++i){
        if(*p2 * 2 < *p3 * 3){
            min = *p2 * 2;
        }
        else{
            min = *p3 * 3;
        } 
        if(*p5 * 5 < min) {
            min = *p5 * 5;
        }
        if(*p2 * 2 == min) p2++;
        if(*p3 * 3 == min) p3++;
        if(*p5 * 5 == min) p5++;
        ugly[i] = min;
    }
    cout << ugly[n] << endl;
    
    //system("PAUSE");
    return 0;
}
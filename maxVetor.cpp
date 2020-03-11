#include <iostream>

using namespace std;

int max_vet(int V[], int n){
    if(n == 1){
        return 0;
    }else{
        int S = max_vet(V, n-1);
        if(V[S] > V[n-1])
            return S;
        else
            return n-1;
    }
}

int main(){
    int vec[5] = {1, 2, 3, 4, 5};
    int m = max_vet(vec, 5);
    cout << vec[m] << endl;

    return 0;
}
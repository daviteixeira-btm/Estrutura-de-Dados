#include <iostream>

using namespace std;

int torre_hanoi(int n, char A, char B, char C){
    if(n == 0){
        return n;
    }else{
        torre_hanoi(n-1, A, C, B);
        cout << A << "->" << C << endl;
        torre_hanoi(n-1, B, A, C);
    }
}

int main(){
    
    int numero;
    cin >> numero;
    
    torre_hanoi(numero, 'A', 'B', 'C');
    
    return 0;
}
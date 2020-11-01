#include <iostream>
#define MAX 31

using namespace std;

int main(){

char str[MAX], copia[MAX];
int i = 0, compstr;

cout << "\n\nEntre com um texto" << endl;
cin >> str;

for(compstr=0; str[compstr]; compstr++);

while (str[i] != '\0'){
   copia[i] = str[compstr-i-1];   
   i++;
}
copia[i] = '\0';

cout << "\n\nString Invertida: \n" << copia;

}
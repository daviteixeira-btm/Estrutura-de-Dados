#include <iostream>
#include "QX_Stack.h"

using namespace std;

int strlen(char* s){
    int size = 0;
    for(int i=0; s[i]; i++){
        size++;
    }
    return size;
}

bool formatABC(char* s){
    int size = strlen(s);
    QX_Stack p(size);

    //percorro minha string e adicionar na minha pilha

    bool x = false, y = false;

    for(int i = 0; s[i]; i++){
        char c = s[i];
        p.push(c);
    }

    while(!p.isEmpty()){

        char c = p.pop();

        if(x == false && (c =='a'|| c=='b')){
            continue;
        }else if( x==false &&  c=='c' ){
            x = true;
            p.push(c);
        }else if((c == 'a'||c=='b')){
            y = true;
            p.push(c);
        }else{
            std::cout << "*\n";
            return false;
        }
    }
    return x&&y;
}

int main(){
    char s[] = "abbbcbbba";
    cout << "A string ta no padrao: " << formatABC(s) << endl;
}
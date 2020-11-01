DuasPilhas::DuasPilhas(int n){
    v = new int[n];
    topoA = 0;
    topoB = (n-1);
    capacidade = n;
}

bool DuasPilhas::vaziaA(){
    return topoA == 0;
}

bool DuasPilhas::vaziaB(){
    return topoB == (capacidade -1);
}

void DuasPilhas::empilhaA(int x){
    if(topoA > topoB || topoA > (capacidade-1)){
        cout << "Nao e possivel empilhar" << end;
    }else{
        v[topoA] = x;
        topoA++;
    }
}

void DuasPilhas::empilhaB(int x){
    if(topoB < TopoA || topoB < 0){
        cout << "Nao e possivel empilhar" << endl;
    }else{
        v[topoB] = x;
        topoB--;
    }
}

int c = topoB + 1;
if(vaziaB()){
    cout << "Nao existe elemento na pilha B." << endl;
}else{
    while(c < capacidade){
        cout << v[c] << endl;
        c++;
    }
}
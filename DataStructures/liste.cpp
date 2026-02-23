#include <iostream>
#include <cstring>
#include <stack>

using namespace std;
#define Inf 0x3f3f3f3f

//ifstream cin("dijkstra.in");
//ofstream cout("dijkstra.out");

struct nod{
    int info;
    nod * urm;
};

nod *L;

/// Lista vida

void init(nod *L){

    L=NULL;

}
/// Creeaza lista cu nodul x;
void ListaUnNod(nod *&L,int x){

    L = new nod;
    L->info = x;
    L->urm = NULL;
}

/// Adauga x la inceputul listei
void AdInceput(nod *&L,int x){

    nod *p;
    p = new nod;
    p->info = x;
    p->urm = L;
    L=p;

}
/// Parcurgerea
void parcurgere(nod *&L){

    for(nod *p = L;p!=NULL;p=p->urm)
        cout << p->info << ' ';

    cout << '\n';

}
/// Adaug dupa pozitia nodului P dat.
void afis(){

    while(L->urm!=NULL){
        cout << L->info << ' ';
        L = L ->urm;
    }

}
/// Sterg primu nod
void StergePrimuNod(nod *&L){

    nod *p = L;
    L = L->urm;
    delete p;

}
void inserareApel(nod * & p, nod * q, int x)
{
    nod *n= new nod;
    n->info=x;
    if(p==q)
    {
       n->urm=q;
       p=n;
       return;
    }
    nod *t=p;
    while(t->urm != NULL && t->urm !=q)
        t=t->urm;
    t->urm=n;
    n->urm=q;

}
void inserare(nod *p){
    
    nod * t = p;
    while(t->urm){

        if(t->info % 2 == 0)
            inserareApel(p,t, 2 * t->info);
        
        t = t->urm;
    } 
}

   // 4 2 2 3 4 5 6 7

int main(){

    init(L);
    for(int i=1;i<=10;++i)
        AdInceput(L,i);

    inserare(L);
    afis();
    
    

    return 0;
}

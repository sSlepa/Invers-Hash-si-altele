https://www.pbinfo.ro/probleme/1337/susan

#include <fstream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
#define Inf 0x3f3f3f3f

ifstream cin("turn.in");
ofstream cout("turn.out");

int dy[]={1,-1,0,0};
int dz[]={0,0,1,-1};

queue< tuple<int,int,int> > q;

int n;
int a[101][101][101];
int b[101][101][101];
int z,sa,sd,g;
int x,y,w;

int is,js,ks;
int ifi,jfi,kfi;

bool inmat(int i,int j,int k){

    return i >= 1 && j >= 1 && k >= 1 && i <= n && j <= n && k <= n;

}
void lee(int i,int j,int k){

    b[i][j][k] = 1;
    q.push(make_tuple(i,j,k));

    while(!q.empty()){
        int x,y,w; 
        tie(x,y,w) = q.front(); /*
            Echivalentul a x = q.front().first;
                            y = q.front().second;
                            w = q.front().third; (Nu exista .third); 
                            asa ca folosim tie(x,y,w) si atribuie de la stanga la dreapta corect
        */
        q.pop();
        if(a[x][y][w] != 4){ /// Daca nu ne aflam pe o groapa putem inainte pe acelasi nivel al turnului
        for(int d = 0 ; d < 4 ; ++d){
            int ii = x; /// Nivelul ramane acelasi, doar camerele se schimba;
            int jj = y + dy[d];
            int kk = w + dz[d];
            if(inmat(ii,jj,kk) && a[ii][jj][kk] != 1 && b[ii][jj][kk] == 0)
                b[ii][jj][kk] = b[x][y][w] + 1,q.push(make_tuple(ii,jj,kk));
            }
        }
        if(a[x][y][w] == 4){ /// Daca ne aflam cumva pe o groapa suntem obligati sa 
                            /// Coboram vertical pana gasim o casuta diferita de 4;
            int ii = x;
            int cnt = 0;
            while(a[ii][y][w] == 4) /// Cat timp suntem pe o groapa
                ii--,cnt++; /// Contorizam cate sunt si scadem nivelul la care ne aflam
        
            if(inmat(ii,y,w) && a[ii][y][w] != 1 && b[ii][y][w] == 0) /// Verificam sa fim in matrice
                b[ii][y][w] = b[x][y][w] + cnt,q.push(make_tuple(ii,y,w)); /// Modificam valorea corespunzator 
                                                                            /// adunand (cnt) nu 1 deoarece 
                                                                            /// am cazut prin
                                                                            /// (cnt) gropi;
        }
        else if(a[x][y][w] == 3){ /// Daca ne aflam la o scara efectuam o operatie simpla in care
                                /// urcam / coboram un nivel, y si w ramanand neschimbate
            
            int ii = x - 1;
           
            if(inmat(ii,y,w) && a[ii][y][w] != 1 && b[ii][y][w] == 0)
                b[ii][y][w] = b[x][y][w] + 1,q.push(make_tuple(ii,y,w));
            
        }
        else if(a[x][y][w] == 2){

            int ii = x + 1;

            if(inmat(ii,y,w) && a[ii][y][w] != 1 && b[ii][y][w] == 0)
                b[ii][y][w] = b[x][y][w] + 1,q.push(make_tuple(ii,y,w));
                
        }
    }
}
int main(){

    cin >> n;
    cin >> z >> sa >> sd >> g;
    for(int i = 1 ; i <= z ; ++i){ /// Marcarea zidurilor cu valorea 1;
        cin >> x >> y >> w;
        a[x][y][w] = 1;
    }
    for(int i = 1 ; i <= sa ; ++i){
        cin >> x >> y >> w; /// Marcarea scarilor ascendente cu 2;
        a[x][y][w] = 2;
    }
    for(int i = 1 ; i <= sd ; ++i){
        cin >> x >> y >> w; /// Marcarea scarilor descendente cu 3
        a[x][y][w] = 3;
    }
    for(int i = 1 ; i <= g ; ++i){
        cin >> x >> y >> w; /// Marcarea gropilor cu 4
        a[x][y][w] = 4;
    }

    cin >> is >> js >> ks;
    cin >> ifi >> jfi >> kfi;

    lee(is,js,ks);

    cout << b[ifi][jfi][kfi];


    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

std::ifstream in("input.txt");
std::ofstream out("output.txt");
class DKA{
    int N;
    int qo;
    bool* qk;
    map <int, map<char,int>> F;
    int current = qo;
public:
    DKA(int N, int qo):N(N),qo(qo){
        qk = new bool[N];
        for(int i = 0; i < N; i++){
            qk[i] = false;
        }
    }
    void F_push(int i,int j ,char a){
        F[i].insert(make_pair(a,j));
    }
    void qk_push(int i){qk[i] = true;}
    void step(char a){
        current = (F[current])[a];
    }
    bool checkqk(){return qk[current];}
    void check(string h){
        for(auto it = h.begin(); it != h.end(); it++){
            step(*it);
        }
        if(checkqk()){
            out << ("YES") << endl;
        }
        else{
            out << ("NO") << endl;
        }
        current = qo;
    }
};
int main() {
    int N, qo, k ,l ,p;
    in >> N >> qo >> k ;
    DKA A(N,qo);
    for(int i = 0; i < k; i++){
        int t;
        in >> t;
        A.qk_push(t);
    }
    in >> l;
    for(int i = 0 ; i < l; i++){
        int g,h;
        char a;
        in >> g >>h >> a;
        A.F_push(g,h,a);
    }
    in >> p;
    for(int i = 0; i < p; i++){
        string h;
        in >> h;
        A.check(h);
        cout << endl;
    }


    return 0;
}

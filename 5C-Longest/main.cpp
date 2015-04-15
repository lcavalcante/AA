//Lucas Cavalcante
#include <bits/stdc++.h>
#include <inttypes.h>

using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define SZ(S) ((int) ((S).size()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define MOD 1000000007
#define MAX64 0x7FFFFFFFFFFFFFFF
#define NUM 2015

typedef pair<int, int> ii;

typedef vector<int> vi;

typedef vector<ii> vii;

int maxLen, sequences;

int LIS(string entrada, int size){
    int aberto = 0;
    int len = 0;
    int sequences =0;
    int maxLen = 0;
    REP(i, size){
        if(size-1 != i){
            if(entrada[i] == ')'){
                if(aberto-1>=0){
                    len++;
                    aberto--;
                }
                else {
                    len = 0;
                    aberto = 0;
                }
            }
            else {
                if(aberto = 0){
                    DEBUG("comecar uma nova");
                    if(len > maxLen){
                        sequences = 1;
                        maxLen = len;
                    }
                    else if(len == maxLen){
                        sequences++;
                    }
                    len = 1;
                    aberto++;
                }
                else{
                    aberto++;
                    len++;
                
                }
            }
        }
        else{
            DEBUG("final\n");
            if(aberto==1){
                DEBUG("pode fechar\n")
                if(entrada[i] == ')'){
                    DEBUG("é (\n");
                    aberto--;    
                    len++;
                    if(len > maxLen){
                        sequences = 1;
                        maxLen = len;
                    }
                    else if(len == maxLen){
                        sequences++;
                    }

                }
            }
    
        }
        DEBUG(aberto);
        DEBUG(len);
        DEBUG(sequences);
        DEBUG(i);
    }
    return sequences;
}

int main(){

    string entrada;

    cin >> entrada;

    printf("%d", LIS(entrada, SZ(entrada)));

    return 0;
}

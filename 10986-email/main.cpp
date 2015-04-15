// Lucas Medeiros Cavalcante

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <utility>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iterator>
#include <math.h>
#include <queue>
#include <map>
#include <new>
#include <set>

#define NUM 20005
#define MAXINT 2147483647

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> adj;
vi dist;
priority_queue<ii, vector<ii>, greater<ii> > pq;

void imprime_vizinhos(vector<pair <int, int> > vizinhos){
    for(int i = 0; i < (int)vizinhos.size(); i++){
        cout << "fim/dist -- > " << vizinhos.at(i).first << "/" <<vizinhos.at(i).second << "**/**" << endl;
    }
}

void dijkstra(int source){
    dist[source] = 0;
    pq.push(make_pair(0, source));

    while(!pq.empty()){
        ii atual = pq.top();
        pq.pop();
        int distance = atual.first, no = atual.second;
        if(distance == dist[no]){
            for(int i = 0; i < (int)adj[no].size(); i++){
                ii vizinho = adj[no][i];
                if(dist[no] + vizinho.second < dist[vizinho.first]){
                    dist[vizinho.first] = dist[no] + vizinho.second;
                    pq.push(make_pair(dist[vizinho.first], vizinho.first));
                }
            }
        }
    }
}

int main(){
    int cases;
    int iter = 1;
    cin >> cases;
    while(cases--){
        int servers, cables, source, destiny;

        cin >> servers >> cables >> source >> destiny;

        adj.assign(servers, vii());

        while(cables--){
            int s, d, speed;

            cin >> s >> d >> speed;

            (adj.at(s)).push_back(make_pair(d, speed));
            (adj.at(d)).push_back(make_pair(s, speed));
        }

        dist.assign(servers, MAXINT);

        dijkstra(source);

        if(dist[destiny] != MAXINT){
            cout << "Case #" << iter << ": " << dist[destiny] << endl;
        }
        else {
            cout << "Case #" << iter << ": unreachable"  << endl;
        }
        iter++;

    }


    return 0;
}

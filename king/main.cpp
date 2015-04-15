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
using namespace std;

vector<int> list_conecteds(int node){
    vector<int> adj;
    if(node >= 0 && node < 64){

    if(node - 8 >= 0){
            adj.push_back(node -8) ;
    }

    if(node + 8 < 64){
            adj.push_back(node +8);
    }

    if(node % 8 != 0){
            if(node - 1 >= 0)
            adj.push_back(node  - 1);

            if(node + 7 < 64)
            adj.push_back(node + 7);

            if(node - 9 >= 0)
            adj.push_back(node - 9);
    }

    if((node + 1) % 8 != 0){
            if(node + 1 < 64)
            adj.push_back(node + 1);

            if(node - 7 >= 0)
            adj.push_back(node - 7);

            if(node + 9 < 64)
            adj.push_back(node + 9);
    }
    }

    return adj;

}

map<int, pair <int , int> > dist;

pair<int ,int> bfs(int source, int destiny){

    dist[source] = make_pair(0,0);
    queue<int> fila;
    fila.push(source);

    while(!fila.empty()){
        int atual = fila.front();
       // cout << "\n---------->" << atual << endl;
        fila.pop();
        vector<int> vizinhos = list_conecteds(atual);
        //cout << "vizinhos: " <<  endl;
/*
        for(int i = 0; i < vizinhos.size(); i++){
            cout << vizinhos.at(i) << ", " ;
        }*/
        for(int i = 0; i < (int)vizinhos.size(); i++){
            int vi = vizinhos.at(i);
            if (dist.count(vi) < 1){
                dist[vi] = make_pair(dist[atual].first + 1, atual);
                fila.push(vi);
            }
            else {
                if(dist[vi].first > dist[atual].first + 1){
                    dist[vi] = make_pair(dist[atual].first + 1, atual);
                }
            }
           // cout << "dist vizinho: " <<vi << "/" << dist[vi].first << endl;
        }
    }

    return dist[destiny];
}

string path(int num1 , int num2){
    if(num2 == num1 + 1){
        return "R";
    }
    if(num2 == num1 - 1){
        return "L";
    }
    if(num2 == num1 - 8){
        return "U";
    }
    if(num2 == num1 + 8){
        return "D";
    }
    if(num2 == num1 - 7){
        return "RU";
    }
    if(num2 == num1 + 9){
        return "RD";
    }
    if(num2 == num1 - 9){
        return "LU";
    }
    else      return "LD";

}

pair<int , int> entrada_to_numero(string s){
    int num1;
    int num2;
    if(s.at(0) == 'a'){
        num1 = 1;
    }
    if(s.at(0) == 'b'){
        num1 = 2;
    }
    if(s.at(0) == 'c'){
        num1 = 3;
    }
    if(s.at(0) == 'd'){
        num1 = 4;
    }
    if(s.at(0) == 'e'){
        num1 = 5;
    }
    if(s.at(0) == 'f'){
        num1 = 6;
    }
    if(s.at(0) == 'g'){
        num1 = 7;
    }
    if(s.at(0) == 'h'){
        num1 = 8;
    }
    if(s.at(1) == '1'){
        num2 = 1;
    }
    if(s.at(1) == '2'){
        num2 = 2;
    }
    if(s.at(1) == '3'){
        num2 = 3;
    }
    if(s.at(1) == '4'){
        num2 = 4;
    }
    if(s.at(1) == '5'){
        num2 = 5;
    }
    if(s.at(1) == '6'){
        num2 = 6;
    }
    if(s.at(1) == '7'){
        num2 = 7;
    }
    if(s.at(1) == '8'){
        num2 = 8;
    }
    return make_pair(num1 , num2);
}

int main()
{
//bfs(0,63);
//bfs(0,63);
    string source, destiny;
    pair< int, int> s,d;

    cin >> source >> destiny;

    s = entrada_to_numero(source );
    d = entrada_to_numero(destiny);

    cout << "s: " << s.first << endl;
    cout << "s: " << s.second << endl;
    int cont = (s.first*8) - s.second;
    /*
    for(int i = 0; i <= s.first; i++ ){
        for(int k = 0; k <= s.second; k++){
            cont+=1;
        }

    } */
    cout << "C: " << cont << endl;

    cout << "d: " << d.first << endl;
    cout << "d: " << d.second << endl;
    int cont2=d.first*8 - d.second;
    /*
    for(int i = 0; i <= d.first; i++ ){
        for(int k = 0; k<=d.second; k++){
            cont2+=1;
        }

    }*/
     cout << "D: " << cont2 << endl;
    //cout << s << endl;
   // cout << d << endl;



    pair <int, int> resposta = bfs(cont,cont2);
    vector <string> caminho;

    int num1 = cont2;

    cout << resposta.first << endl;

    while(num1 != cont){

        int num2 = dist[num1].second;
       // cout << "num1/num2: " << num1 << "/" << num2 << endl;
      //  cout << path(num2,num1) << endl;
        caminho.push_back(path(num2,num1));
        num1 = num2;
    }

    for(int i = caminho.size()-1; i >= 0 ; i--){
            cout << caminho.at(i) << endl;
        }


   return 0;
}

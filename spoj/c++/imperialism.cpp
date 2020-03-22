//https://www.spoj.com/problems/IMPER/
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <utility>
#include <set>
#include <iterator>
#include <sstream>  
#include <map>
#include <stdio.h>
#include <iomanip>  
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
static vector<map<int,bool> > ady;
static vector<bool> visitados;
int n,maxDist,nodoLejano;
typedef map<int,bool>::iterator it_type;
pair<int , int >dfs(int pos, int dist)
{
pair<int,int > r,aux;
    visitados[pos]=true;
    r.first=dist;
    r.second=pos;
    
    //cout << pos << endl;
    for(it_type iterator = ady[pos].begin(); iterator!= ady[pos].end(); iterator++)
    {    
    if(!visitados[iterator->first]){
        aux=dfs(iterator->first,dist+1);
        if(aux.first > r.first)
        r=aux;
    }
    }
    return r;
}
int main()
{
    cin >> n;
    while(n!= -1)
    {
    ady.clear();
    ady.resize(n+1);
    visitados.resize(n+1);
    fill(visitados.begin(),visitados.end(),false);
    for(int i=1; i <n ;i++)
    {
        int aux;
        cin >> aux;
        ady[i+1].insert(make_pair(aux,true));
        ady[aux].insert(make_pair(i+1,true));
    }
    pair<int,int> aux= dfs(1, 0);//devuelve el nodo mas lejano y su distancia;
    //first = distancia second= nodo;
    fill(visitados.begin(),visitados.end(),false);
    pair<int , int> aux2= dfs(aux.second,0);
    
    int a= aux2.first;
    //imprimo la mitad del diametro del arbol
    if(a % 2 != 0)
    {
    cout << round(a/2)+1<< endl;  
    }
    else{
    cout << a/2 << endl;
    }
    cin >>n;
    }
}
    
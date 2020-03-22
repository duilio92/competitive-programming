//https://www.spoj.com/problems/TAP2012D/
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <utility>
#include <set>
#include <iterator>
#include <sstream>  
#include <map>
using namespace std;
    
const  int MAX=100200;
struct trie {
    map <char,int>sig;
    bool final;
    int cantA;
    int cantB;
};
trie t[MAX];
int n;
    
void init()
{
    n = 1;
    t[0].sig.clear();
    t[0].final = false;
}
    
void insertar(string st,char team)
{
    int pos= 0;
    for(int i=0; i < st.size();i++){
    if(t[pos].sig.find(st[i])==t[pos].sig.end()){
        t[pos].sig[st[i]]= n;
        t[n].sig.clear();
        t[n].final = false;
        n++;
    }
    pos = t[pos].sig[st[i]];
    if(team=='a')
        t[pos].cantA++;
        if(team=='b')
        t[pos].cantB++;
    }
}
int contar()
{
    queue<int> cola;
    int tot=0;
    int aux;
    
    cola.push(0);
    while(!cola.empty())
    {
    aux=cola.front();
    //cout << "entre con:"<< aux << endl;
    cola.pop();
    if(aux!=0)
    {
        tot+= min(t[aux].cantA, t[aux].cantB);
    }
    for(map<char,int>::iterator it= t[aux].sig.begin();it != t[aux].sig.end(); it++)
    {
        //cout << "puse" << it->second << " "<< it->first <<endl;
        cola.push(it->second);
    }
    }
    return tot;
}
int main()
{ 
    int cant,aux,caracteres;
    string st;
    
    cin >> cant;
    while(cant!=-1){
    
    init();
    //limpio el trie;
    for(int i=0; i < MAX;i++)
    {
        t[i].sig.clear();
        t[i].cantA=0;
        t[i].cantB=0;
    }
    caracteres=0;
    aux=cant;
    while(aux>0){
        cin >>st;
        insertar(st,'a');
        caracteres+= st.size();
        aux--;
    }
    aux=cant;
    while(aux>0){
        cin >>st;
        insertar(st,'b');
        caracteres+= st.size();
        aux--;
    }
    
    cout << contar() <<endl; 
    cin >> cant;
    }
    
return 0;
} 
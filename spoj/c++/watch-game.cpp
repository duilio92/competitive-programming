//https://www.spoj.com/problems/TAP2013D/
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
#define ll long long int
#define FOR(it,A) for(typeof A.begin() it = A.begin();it!=A.end();it++)
using namespace std;
//falta correguir la impresion, probar en detenimiento un caso de prueba.
map<ll, set<ll> > v;
    
vector<ll>teams;
ll N,F,A,B,C,i,j,I,E,M;
int main()
{
    cin >> N >>F;
    teams.resize(N+1);
    cin >> A >> B >> C;
    teams[1]=A;
    for( i=2; i <= N;i++)
    {
    teams[i]=(B*teams[i-1]+C)%F;
    }
    //lei el estado inicial, cargo la estrutctura
    for( i=1; i <=N;i++)
    {
    ll t= teams[i];
    if(v.find(t)==v.end())
    {
        set<ll> aux;
        aux.insert(i);
        v.insert(make_pair(t,aux));
    }
    else
    {
        v[t].insert(i);
    }
    }
    //cargo las consultas;
    cin>> M;
    for(i=0; i < M;i++)
    {
    cin >> I>> E;
    //cargo el nuevo vecino
    v[teams[I]].erase(I);
    teams[I]=E;
    ll t=E;
    if(v.find(t)==v.end())
    {
        set<ll> aux;
        aux.insert(I);
        v.insert(make_pair(t,aux));
    }
    else
    {
        v[t].insert(I);
    }
    //busco sus vecinos fan del mismo equipo.
    if(v[t].size()==1)
    {
        cout << N <<" "<< N << endl;
        continue;
    }
    set<ll>::iterator next,prev;
    next= v[t].upper_bound(I);
    if(next==v[t].end())
    {
        next=v[t].begin();
    }
    ll sig= *next;
    ll ant;
    prev=v[t].find(I);
    if(prev==v[t].begin())
    {
    set<ll>::reverse_iterator pre;
    pre=v[t].rbegin();
    ant=*pre;
    }
    else{prev--; ant=*prev;}
    if(I<ant)
    {
        cout << I+ N-ant<<" ";
    }
    else
    {
        cout << I-ant<<" ";
    }
    if(I< sig)
    {
        cout << sig- I<< endl;
    }
    else
    {
        cout << N-I+sig<< endl;
    }
    } 
    return 0;
} 
    
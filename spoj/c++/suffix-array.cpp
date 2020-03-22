//https://www.spoj.com/problems/SARRAY/
//score is 50
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
#define MAXN 65536
#define MAXLG 17

/* suffix array ya llegue a puntuacion 50 con O(n lg2 n)
optimizaciones posibles:
    usar L en su ultima instancia en vez de reordenar todo para imprimir --listo
    usar radix sort para llegar a un tiempo de O (n lg n), cada ordenacion llevaria n en vez de n lg n. --haciendo
    evitar la variable aux.
    rescribir printf
*/
string S;
    
struct pairFinal
{
    int indice;
    int p;
}final[MAXN];
    
int cmp2(struct pairFinal a, struct pairFinal b)
{
    return a.p < b.p;
}
    
    
struct entry {
    int nr[2];
    int p;
} L[MAXN]; //L es el arreglo auxiliar para realizar las comparaciones en cada paso.
    
int cmp(struct entry a, struct entry b)
{
    int comp = (a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0));
    return comp;
}
int P[MAXLG][MAXN];//P es la matriz donde se construye el suffix array, en la ultima fila queda el suffix array completo
//cada posicion del arreglo P indica para un indice i en que posicion se encontraria el substring que inicia en la poscicion
    
int N,i,j,stp,cnt,aux;
string auxi;
void imprimoL()
{
    for(int i=0; i < N;i++)
    {
    cout << L[i].nr[0] <<" "<< L[i].nr[1] << " "<< L[i].p << endl;
    }
}
void imprimirLresultado(){
for(int i=0; i < N;i++){
    cout << L[i].p<< endl;}
}
    
    
void suffix_array(string H){
    N = H.size();
    for (i = 0; i < N; i ++) {
    P[0][i] = H[i] - '$';//seteo el valor numerico inicial de cada caracter
    }
    for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1){
    //cout << "paso " << stp <<"cnt "<< cnt <<endl;
    for (i = 0; i < N; i ++){
        L[i].nr[0] = P[stp-1][i];
        L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1; //asigno el valor a la segunda posicion de L si esta en rango, -1 caso contrario
        L[i].p = i;
    }
    /*cout << "L antes de ordenar"<< endl;  
    imprimoL();*/ 
    sort(L, L + N, cmp);//ordeno, podria optimizarse REVISAR  
    /*cout << "L despues de ordenar" << endl;
    imprimoL();*/    
    aux=stp;
    for (i = 0; i < N; i ++)
    {//remplaza con el mismo valor si es exactamente igual al anterior, con i si es distinto
        P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
    }
    /* //muestro el estado actual
    for(int j=0;j<N;j++) cout << "posicion "<< j << " "<<P[aux][j] <<" "<<S.substr(j,S.size())<<" " << endl; 
    cin >> auxi;
    //espero para mostrar el paso siguiente*/
    }
    
}
int main(){
    cin >> S;
    suffix_array(S);
    imprimirLresultado();
    } 
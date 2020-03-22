//https://www.spoj.com/problems/PRIME1/
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
    
const long long int length= sqrt(1000000000)+1;
vector<int>iniciales;//los primos que precalculo
vector<long long int> nuevos;//los nuevos que calculo para cada caso si hace falta
vector <long long int> nuevaCriba;
int p [31623];//criba inicial;
//completar y corregir,falta la impresion entre otros
    
void Actualizar(long long int primo, int inicio,int fin)//M es la posicion inicial;
{
    long long int aux= inicio % primo;
    if((inicio+aux) % primo ==0)
    {
    for(int i=aux; i <(fin-inicio)+1; i+=primo)
    {
        nuevaCriba[i]=primo;
    }
    }
    else
    {
    long long int aux2= primo-aux;
    for(int i=aux2; i <(fin-inicio)+1; i+=primo)
    {
        nuevaCriba[i]=primo;
    }
    }
}
    
int main()
{
int i,j,t,n,m;
    int N= length;
    iniciales.push_back(2);
    for(i =4; i <N ; i +=2) p [ i ] = 2 ;
    for( i =3; i <N ;i +=2)
    if (!p[i]) {
    iniciales.push_back(i);  
    for ( j=i*i; j<N ; j +=2*i ) p [j]= i ;
    }
    cin >> t;
    for(j=0; j < t ; j++)
    {
    nuevos.clear(); 
    nuevaCriba.clear();
    //imprimo el salto de linea salvo que sea el primer caso
    if(j!=0)cout << endl;
    cin >> m >> n;
    if(n <= length)//cae dentro de lo precalculado
    {
        for(i=0; i < iniciales.size();i++)
        {
        if(iniciales[i]>n)
            break;
        if(iniciales[i]< m)
            continue;
        cout << iniciales[i]<< endl;
        }
        continue; 
    }
    if(m< length)//cae en el medio de los dos
    {
        for(i=0; i < iniciales.size();i++)
        {
        if(iniciales[i]>=m)
            nuevos.push_back(iniciales[i]);
        }
        m=length+1;//para procesar lo que quedo afuera
    }
    
    //calculo lo que no cae en lo precalculado
    nuevaCriba.resize((n-m)+1);//los primos a calcular
        
    for(i=0; i< iniciales.size();i++)
    {
        long long int actual= iniciales[i];
        //tomo el primo y me fijo de desmarcar todos los numeros de los que es multipl en el array.
        Actualizar(actual,m,n);
        
    }
    for(i=0; i < nuevaCriba.size();i++)
    {
        if(!nuevaCriba[i])
        {
        nuevos.push_back(i+m);
        }
    }
    for(int i=0; i < nuevos.size();i++)
    {
        cout << nuevos[i]<< endl;
    }
    }
} 
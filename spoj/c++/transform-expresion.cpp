//https://www.spoj.com/problems/ONP/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
 
#define ll long long;
#define ull unsigned long long;
#define FOR(it,A)for(typeofA.begin() it =A.begin; it!=A.end();it++)
#define REP(i,n) for(int i=0; i <(n);i++)
 
using namespace std;
/*ONP - Transform the Expression SPOJ
*/
stack<char> pila;
string salida,entrada;
int damePrioridad(char c){
	 switch (c) {
		 case '^':
			return 5;
		  case '*':
			  return 3;
		  case '/':
			  return 4;
		 case '+':
			  return 1;
		  case '-':
			 return 2;
		  default:
			  return 0;
	 }
}
void agregarPila(char aux, int prioridad){
	if(pila.empty()){
		//cout<<"apilo "<< aux <<endl;
		pila.push(aux);
	}
	else{
		int pr =damePrioridad(aux);
		while(!pila.empty()){
			if(damePrioridad(pila.top())>=pr){
				salida += pila.top();
				//cout <<"desapilo "<<pila.top()<<"con " <<aux<<endl;
				pila.pop();
			}
			else{
				//cout<<"apilo "<< aux <<endl;
				pila.push(aux);
				break;
			}
		}
		if(pila.empty()){
			//cout<<"apilo "<< aux <<endl;
			pila.push(aux);
		}
 
 
	}
 
}
void procesarChar(char c){
	 switch (c) {
	 case '^':
		 agregarPila(c,damePrioridad(c));
	 	 break;
	  case '*':
		  agregarPila(c,damePrioridad(c));
		  break;
	  case '/':
		  agregarPila(c,damePrioridad(c));
		  break;
	  case '(':
		pila.push('(');
		break;
	  case ')':
	 	while((pila.top()!='(')&&(!pila.empty())){
	 		salida+= pila.top();
	 		pila.pop();
	 	}
	 	pila.pop();
	 	break;
	  case '+':
		  agregarPila(c,damePrioridad(c));
		  break;
	  case '-':
		 agregarPila(c,damePrioridad(c));
		 break;
	  default:         //seria un operando
		 salida += c;
		 break;
	  }
 
}
void procesar(){
	REP(i,entrada.length()){
		procesarChar(entrada[i]);
		//cout <<"salida "<<salida <<endl;
	}
	//cout <<pila.size()<<endl;
	while(!pila.empty()){
		salida+= pila.top();
		pila.pop();
	}
 
 
}
int main()
{
	int N;
	cin >> N;
	REP(i,N){
		salida="";
		cin >>entrada;
		procesar();
		cout << salida<<endl;
	}
	return 0;
}
/*
 * MaximumSum.cpp
 *
 *  Created on: 10/12/2014
 *      Author: duilio
 *      spoj problem:http://www.spoj.com/problems/KGSS/
 *      idea de la resolucion, crear segment Tree donde cada posicion tiene los dos maximo
 *      cosa de poder llevar bien los updates
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <math.h>
//solucion del problema maximumSum usando un rmq con segmentTree
using namespace std;
int m[100000];
struct rec{
	int mx1;
	int mx2;
};
static const struct rec NEUT = { 0, 0 };;
int N,st_length;
rec st_oper(rec a, rec b){
	rec nue;
	if(a.mx1>= b.mx1){
		nue.mx1=a.mx1;
		nue.mx2=max(max(b.mx1,a.mx2),b.mx2);
	}
	else{
		nue.mx1=b.mx1;
		nue.mx2=max(max(a.mx1,a.mx2),b.mx2);
	}
	return nue;
}
int st_initialize(int *m, rec *st_array,int N,int st_length){
	//la raiz queda en la posicion 1. Inicializo TODOS los nodos con valores neutros;
	for(int i=0; i <st_length;i++){st_array[i]=NEUT;}
	for(int i=0; i<N; i++){
		st_array[st_length/2+i].mx1=m[i];
		st_array[st_length/2+i].mx2=0;
	}//copio los elementos del arreglo en las hojas del st_array(en las hojas izquierdas si es que sobran lugares)
 
	int procesado=st_length/2;
	int resolver=procesado/2;
	while(resolver >0){
		for(int i=0; i <resolver; i++){
			st_array[resolver+i]=st_oper( st_array[procesado+i*2], st_array[procesado+i*2+1]);
		}
		procesado=resolver;
		resolver/=2;
	}
 
}
void st_update(int *m, rec *st_array,int N, int st_length, int Pos, int NuevoValor){
	m[Pos] = NuevoValor;
	st_array[st_length/2+Pos].mx1=NuevoValor;//actualizo la hoja y de ahi voy para arriba
	st_array[st_length/2+Pos].mx2=0;//actualizo la hoja y de ahi voy para arriba
	int posActualizar = (st_length/2+Pos)/2;//agregue un dividido 2, la hoja ya la actualize en las 2 lineas de arriba
	while(posActualizar > 0){
		rec auxiliar = st_oper(st_array[posActualizar*2],st_array[posActualizar*2+1]);
		if(auxiliar.mx1==st_array[posActualizar].mx1 && auxiliar.mx2 == st_array[posActualizar].mx2)//en el caso de que la operacion al tomar en cuenta el nuevo valor este no modifica el valor del nodo, salgo
			break;
		else{
			st_array[posActualizar]= auxiliar;
		}
		posActualizar/=2;
	}
}
 
rec st_querry(rec *st_array, int inf, int sup, int posInf, int posSup, int pos){
	//cout << posInf << " "<< posSup << endl; a esta funcion hay que llaramla inicialmente con pos en 1 posInf y posSup en 0 y st_length/2 respectivamente
	if((inf <=posInf) && (sup>=posSup) ){
		//si estoy totalmente dentro del rango o soy todo el rango devuelvo lo que calcule
		return st_array[pos];
	}
	if(sup < posInf || inf > posSup){//si los dos rangos son mutuamente exclusivos retorno un valor invalido
		return NEUT;
	}
	if(posSup==posInf+1|| posSup==posInf){//me fijo si estoy en un nodo hoja
		if((inf <=posInf) && (sup>=posSup) ){
				//si estoy totalmente dentro del rango o soy todo el rango devuelvo lo que calcule
				return st_array[pos];
		}
		else
				return NEUT;
	}
	rec izq=st_querry(st_array,inf,sup,posInf,(posInf+posSup)/2,pos*2);
	rec der=st_querry(st_array,inf,sup,(posInf+posSup)/2,posSup,pos*2+1);
	return st_oper(izq,der);
}
int simple_querry(int *m, int i, int j){
 
	int mx1= 0;
	int mx2=0;
		for(int k=i; k < j; k++){
			if(m[k]> mx1){
				mx2= mx1;
				mx1= m[k];
			}
			else if(mx2 < m[k]){
				mx2=m[k];
			}
		}
		return mx1+mx2;
}
void st_printArray(int *m, int N){
	cout <<"arreglo "<< endl;
	for(int i=0; i < N; i++){
		cout << m[i]<< " ";
	}
	cout << endl;
}
void st_printTree(rec *st_array, int st_length){
for(int i=1; i< st_length; i++){
	cout << st_array[i].mx1+st_array[i].mx2<<" ";
}
cout << endl;
}
int main(){
/*
	N=10;
	for(int i=0; i <N; i++){
		m[i]= rand() % 10000000;
	}
	int m[]={25,50,85,70,35,45,78,63,12,0};
	//inicializo el segment tree
	//la longitud del st_array depende de si la cantidad de hojas genera un st_array binario perfecto(son 2**X nodos), o si "sobran" hojas;
	st_length =2*pow(2,ceil(log2(N)));
	rec st_array[st_length];
	st_initialize(m,st_array,N,st_length);
	//st_printArray(m,N);
	cout << endl << endl;
	//st_printTree(st_array,st_length);
	cout << endl << endl;
	int i,j;
	int cantQuerry=1;
	for(int k=0; k < cantQuerry; k++){
		i= rand() % (N+1);
		j= rand() % (N+1);
		cout << "consulta: "<<k <<" "<<i<<" "<<j << endl;
		if(j< i){
			int aux= i;
			i= j;
			j= aux;
		}
		rec t = st_querry(st_array,i-1,j-1,0,st_length/2,1);
		cout << "resultado de la consulta "<< t.mx1 << " "<<t.mx2<< endl << endl;
		int pos = rand() % N;
		int value = rand() % 100;
		cout << "actualizo la posicion: "<<pos << "con el valor"<< value<< endl << endl;
		st_update(m,st_array,N,st_length,pos-1,value);
		cout << "arbol despues de actualizar "<< endl;
		st_printTree(st_array,st_length);
		cout << endl << endl;
 
	}
	//realizo las consultas del minimo en [i,j) y los comparo con hacerlas a mano;
	return 0;}
*/
	cin >> N;
	for(int i=0; i < N;i++){
		cin >> m[i];
	}
	st_length =2*pow(2,ceil(log2(N)));
	rec st_array[st_length];
	st_initialize(m,st_array,N,st_length);
	int cantQuerry;
	char aux; int i,j;
	cin >> cantQuerry;
	for(int k=0; k < cantQuerry; k++){
		cin >> aux;
		if(aux=='Q'){
			cin >> i;
			cin >> j;
			if(j< i){
				int a= i;
				i= j;
				j= a;
			}
			rec t = st_querry(st_array,i-1,j,0,st_length/2,1);//resto uno al  inicio porque en el enunciado arranca desde el 1 el arreglo,
			//no le resto al final porque es ] y el mio es uno mas con ) que es lo mismo
			cout << t.mx1+ t.mx2<< endl;
		}
		else{
			cin >> i; cin>> j;
			st_update(m,st_array,N,st_length,i-1,j);
			/*cout << "arbol despues de actualizar "<< endl;
		st_printTree(st_array,st_length);*/
		}
		}
}
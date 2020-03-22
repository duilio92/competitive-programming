//https://www.spoj.com/problems/MFLAR10/
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <utility>
#include <set>
#include <iterator>
#include <sstream>  
    
using namespace std;
int main()
{
stringstream linea;
string aux;
char letra;
bool cumple= true;
while(getline(cin, aux))
{
    //encuentro el primero
    if(aux[0]=='*')
    break;
    int i=0;
    while((aux[i]==' ') && (i< aux.size()-1))
    i++;
    
    letra=tolower(aux[i]);
    //cout << letra <<endl;
    cumple=true;
    
    for(int j=i;j< aux.size()-1;j++)
    {
    if(aux[j]==' ')
    {
        //cout << "aux de " <<j <<" "<< aux[j];
        if(letra!=(tolower(aux[j+1])))
        {cumple =false;
            break;
            }
    }
    }
    
    
    if(cumple){ cout << "Y"<< endl;}
    else {cout << "N" << endl;}
}
    
    
return 0;
} 
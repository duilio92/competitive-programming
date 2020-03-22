//https://www.spoj.com/problems/ACPC10A/
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
//spoj what's next
int main()
{
    int p,q,r;
    
    cin >> p >> q >> r;
    while(((p!=0)||(q!=0)||(r!=0)))
    {
    int diference = q-p;
    if(q+diference == r)
    {
    cout << "AP "<< r+diference << endl;
    }
    else
    {
    int prod= q/p;
    cout << "GP "<< r* prod << endl;
    } 
    
    
    cin >> p >> q >> r;
    }
} 
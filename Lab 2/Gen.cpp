#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int main(){
    ll x,y,z;
    srand(time(0));
    ofstream f1;

    f1.open("40k.txt");

    int a=40000;

    x=rand()%M;
    f1<<x;
    a-=1;

    while(a--){
        x=rand()%M;
        f1<<" ";
        f1<<x;
    }



    return 0;
}

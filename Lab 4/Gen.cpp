#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 10

int main(){
    ll x,y,z;
    srand(time(0));
    ofstream f1;

    f1.open("greedy.txt");

    int a=20;

    f1<<a;
    f1<<"\n";

    a-=1;

    while(a--){
        x=(rand()%M)+20;
        f1<<x;  //Knapsack size
        f1<<"\n";
        x=(rand()%5)+5;
        z= x;
        f1<<x;  // Number of Objects
        f1<<"\n";

        for(int i=1;i<=z;i++){
            f1<<i;
            f1<<" ";
            x=(rand()%7)+3;
            f1<<x;  // Object Weight
            f1<<" ";
            x=(rand()%10)+3;
            f1<<x;  // Object Profit
            f1<<"\n";
        }
    }


    return 0;
}

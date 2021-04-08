#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Count = 0;
ll fb[101];

ll fib(int a){
    if(a<=1){
        fb[a]=a;
        Count+=3;
        return a;
    }
    if(fb[a]!=-1){
        Count+=2;
        return fb[a];
    }
    fb[a]=fib(a-1)+fib(a-2);
    Count+=2;
    return fb[a];
}


int main(){
    int a;
    string x;
    ifstream f1,f2;

    f1.open("fibonacci.txt");

    while(!f1.eof()){
        memset(fb,-1,sizeof(fb));
        Count = 5;
        f1>>x;
        a=stod(x); Count+=2;
        fib(a);
        Count+=1;
        for(int i=0;i<a;i++){
            Count+=3;
            cout<<fb[i]<<" ";
        }
        cout<<"\n"<<endl;
        Count+=2;
        cout<<"N : "<<a<<"  Count: "<<Count<<"\n"<<endl;
    }

    f2.open("fibonacci.txt");

    while(!f2.eof()){
        Count=5;
        f2>>x;
        ll y=0,z=1;
        a=stod(x); Count+=4;
        cout<<"\n"<<y<<" "<<z<<" ";
        for(int i=0;i<a-2;i++){
            cout<<y+z<<" "; Count+=6;
            ll temp=y;
            y=z;
            z+=temp;
        }
        Count+=2;
        cout<<"\n\nN : "<<a<<"  Count: "<<Count<<"\n"<<endl;

    }

    return 0;
}

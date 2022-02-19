#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[53]={0};
int ct;
vector<int>xy;

bool is_safe(int x,int y, int &n){
    ct+=1;
    bool rslt=true;
    int f=1;

    for(int k=x-1;k>0;k--){
        if(arr[k]==y){
            rslt=false;
            break;
        }
        if((x+y)==(arr[k]+k) && y<n){
           rslt=false;
           break;
        }
        if(y>1 && arr[k]==(y-f)){
            rslt=false;
            break;
        }
        f+=1;
    }

    return rslt;
}

void N_Q(int a, int &n){
    ct+=1;
    for(int i=1;i<=n;i++){
        if(is_safe(a,i,n)){
            arr[a]=i;

            if(a==n){
                cout<<"\n  Solution: \n"<<endl;
                for(int j=1;j<=n;j++){
                    cout<<"  ";
                    for(int k=1;k<=n;k++){
                        if(arr[j]==k){
                            cout<<"Q   ";
                        }
                        else{
                            cout<<"*   ";
                        }
                    }
                    cout<<"\n"<<endl;
                }
            }
            else{
                N_Q(a+1,n);
            }
        }
    }
}

main(){
    int n;

    ifstream f1;

    f1.open("queen.txt");

    while(!f1.eof()){
        ct=0;
        f1>>n;
        cout<<"  Enter N: "<<n<<endl;
        if(n>0){
            N_Q(1,n);
            cout<<"Iteration: "<<ct<<"\n\n"<<endl;
        }

    }

    return 0;
}

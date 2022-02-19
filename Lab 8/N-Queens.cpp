#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[53]={0};
vector<int>xy;

bool is_safe(int x,int y, int &n){
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
    for(int i=1;i<=n;i++){
        if(is_safe(a,i,n)){
            arr[a]=i;

            if(a==n){
                cout<<"\n  Solution: ";
                for(int j=1;j<=n;j++){
                    cout<<arr[j]<<" ";
                }
                cout<<"\n"<<endl;
                break;
            }
            else{
                N_Q(a+1,n);
            }
        }

        else{
            cout<<"  Backtrack From Node: ";
            for(int j=1;j<a;j++){
                cout<<arr[j]<<" ";
            }
            cout<<i<<endl;
        }
    }
}

int main(){
    int n;

    cout<<"  Enter N: ";
    cin>>n;
    if(n>0){
        N_Q(1,n);
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>arr1;
ll C1,C2,Max,Min,Mx,Mn,mid;

void D_C(int i,int j){
    if(i==j){
        C1+=3;
        Mx=arr1[i];
        Mn=arr1[i];
    }
    else if(i==(j-1)){
        if(arr1[i]>arr1[j]){
            Mx=arr1[i];
            Mn=arr1[j];
            C1+=4;
        }
        else{
            Mx=arr1[j];
            Mn=arr1[i];
            C1+=4;
        }
    }
    else{
        mid=(i+j)/2;
        C1+=3;
        D_C(i,mid);
        D_C(mid+1,j);
        C1+=2;
    }
    if(Max<Mx){
        Max=Mx;
        C1+=2;
    }
    if(Min>Mn){
        Min=Mn;
        C1+=2;
    }
}

void S_F(){
    Max=arr1[0],Min=arr1[0];
    C2+2;
    for(int i=1;i<arr1.size();i++){
        C2+=2;
        if(arr1[i]>Max){
            Max=arr1[i];
            C2+=1;
        }
        else if(arr1[i]<Min){
            Min=arr1[i];
            C2+=1;
        }
        C2+=2;
    }
    C2+=2;
}

void solve(string a){
    string b;
    ifstream f1;

    f1.open(a);
    arr1.clear();

    while(!f1.eof()){
        f1>>b;
        arr1.push_back(stod(b));
    }

    C1=0,C2=0;

    Max=-1;Min=1e9;
    D_C(0,arr1.size()-1);

    cout<<" 1.Divide & Conquer:- Max: "<<Max<<"  Min: "<<Min<<"  Count: "<<C1<<endl;

    S_F();
    cout<<" 2.Straight Forward:- Max: "<<Max<<"  Min: "<<Min<<"  Count: "<<C2<<endl;


}

void menu(){
    cout<<"\n\tData Set\n  -------------------"<<endl;
    cout<<" 1. 10k\n 2. 20k\n 3. 30k\n 4. 40k\n 5. 50k\n 0. Exit\n"<<endl;
    cout<<" Enter your choice: ";
}

int main(){
    int x;

    while(1){
        menu();
        cin>>x;
        switch(x){
            case 1:  solve("10k.txt"); break;
            case 2:  solve("20k.txt"); break;
            case 3:  solve("30k.txt"); break;
            case 4:  solve("40k.txt"); break;
            case 5:  solve("50k.txt"); break;
            case 0:  cout<<"\n Exiting..."<<endl; break;
            default: cout<<"\n Invalid Input...\n"<<endl; break;
        }
        if(x==0){
            break;
        }
    }

    return 0;
}

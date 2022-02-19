#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string a,b;

    cout<<"Enter First String: ";
    cin>>a;
    cout<<"Enter Second String: ";
    cin>>b;

    int la,lb,i,j,n,m;

    la=a.size();
    lb=b.size();

    int arr[la+3][lb+3];

    for(i=0;i<=la;i++){
        for(j=0;j<=lb;j++){
            if(i==0 || j==0){
                arr[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else{
                arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
            }
        }
    }

    stack<char>st;

    i=la; j=lb;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            st.push(a[i-1]);
            i-=1;
            j-=1;
        }
        else if(arr[i][j-1]>arr[i-1][j]){
            j-=1;
        }
        else{
            i-=1;
        }
    }

    cout<<"\nSize: "<<st.size()<<endl;
    cout<<"\nLCS: ";
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    cout<<endl;


    return 0;
}

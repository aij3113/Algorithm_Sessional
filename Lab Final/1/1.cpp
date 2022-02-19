#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;
#define Max 1e17

vector<ll>arr;
ll n;

void input(ll n,ll i){
    string a,b="quick";
    b=b+to_string(i)+".txt";

    ifstream f1;

    f1.open(b);
    arr.clear();

    while(arr.size()<n){
        f1>>a;
        arr.push_back(stod(a));
    }
    arr.push_back(Max);

    f1.close();
}

void output(ll n){
    for(ll i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n"<<endl;
}

ll Partition(ll m,ll p){
    ll v= arr[m], i=m, j=p;

    while(i<j){
        do{
            i+=1;
        }
        while(arr[i]<v);

        do{
            j-=1;
        }
        while(arr[j]>v);

        if(i<j){
            ll q= arr[i];
            arr[i]=arr[j];
            arr[j]=q;
        }
    }
    arr[m]=arr[j];
    arr[j]=v;

    return j;
}

void quick_sort(ll left, ll right){
    if(left<right){
        ll j;
        j= Partition(left,right+1);

        quick_sort(left,j-1);
        quick_sort(j+1,right);
    }
}

int main(){
    ll i;

    for(i=1;i<4;i++){
        cout<<"Enter Number of Element_(from 5000 to 50000): ";
        cin>>n;

        input(n,i);

        auto start = high_resolution_clock::now();
        quick_sort(0,n-1);
        for(ll j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                cout<<"ok"<<endl;
            }
        }
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time for "<<n<<" : "<< duration.count()<<" milliseconds\n"<<endl;
    }

    return 0;
}

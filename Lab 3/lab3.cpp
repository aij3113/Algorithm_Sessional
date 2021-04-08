#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef long long ll;
#define Max 1e17

vector<ll>arr1,arr;
ll arr2[100000],n,c1,c2;

void input(ll n){
    string b;
    ifstream f1;

    f1.open("sort_i.txt");
    arr1.clear();
    arr.clear();

    while(arr1.size()<n){
        f1>>b;
        arr1.push_back(stod(b));
        arr.push_back(stod(b));
    }
    arr.push_back(Max);
}

void output(ll n){
    for(ll i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n"<<endl;
}

void marge(ll low,ll mid,ll high){
    ll h=low, i=low, j=mid+1;
    //ll arr2[high+7];

    while((h<=mid)&&(j<=high)){
            //c1+=1;
        if(arr1[h]<=arr1[j]){
            arr2[i]=arr1[h];
            h+=1;
            c1+=1;
        }
        else{
            arr2[i]=arr1[j];
            j+=1;
            c1+=1;
        }
        i+=1;
        //c1+=1;
    }
    if(h>mid){
        for(ll k=j;k<=high;k++){
            arr2[i]=arr1[k];
            i+=1;
            c1+=1;
        }
        //c1+=2;
    }
    else{
        for(ll k=h;k<=mid;k++){
            arr2[i]=arr1[k];
            i+=1;
            c1+=1;
        }
        //c1+=2;
    }

    for(ll i=low;i<=high;i++){
        arr1[i]=arr2[i];
        c1+=1;
    }
   // c1+=2;
}

void marge_sort(ll low,ll high){
    if(low<high){
        ll mid=(low+high)/2;
        //c1+=1;

        marge_sort(low,mid);
        marge_sort(mid+1,high);

        marge(low,mid,high);
        //c1+=3;
    }
}

ll Partition(ll m,ll p){
    ll v= arr[m], i=m, j=p;

    while(i<j){
        do{
            i+=1;
            //c2+=1;
        }
        while(arr[i]<v);

        do{
            j-=1;
            //c2+=1;
        }
        while(arr[j]>v);

        if(i<j){
            ll q= arr[i];
            arr[i]=arr[j];
            arr[j]=q;
            c2+=3;
        }
        //c2+=1;
    }
    arr[m]=arr[j];
    arr[j]=v;
    c2+=2;

    return j;
}

void quick_sort(ll left, ll right){
    if(left<right){
        ll j;
        j= Partition(left,right+1);
        //c2+=1;

        quick_sort(left,j-1);
        quick_sort(j+1,right);
        //c2+=2;
    }
}

int main(){
    int i;

    while(1){
        c1=0;
        c2=0;
        cout<<"Enter Number of Element_(Minimum 4000,_Press 0 to EXIT): ";
        cin>>n;
        if(n==0){
            cout<<"\n\tExited..."<<endl;
            break;
        }
        //else if(n<4000||n>40000){
          //  cout<<"\nInvalid Input\n"<<endl;
        //}
        else{
            input(n);
            auto start = high_resolution_clock::now();
            marge_sort(0,n-1);
            auto stop = high_resolution_clock::now();
            cout<<c1<<endl;
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

            auto start1 = high_resolution_clock::now();
            quick_sort(0,n-1);
            auto stop1 = high_resolution_clock::now();
            cout<<c2<<endl;
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            cout << "Time taken by function: "
         << duration1.count() << " microseconds\n" << endl;
            //output(n);
        }
    }

    return 0;
}


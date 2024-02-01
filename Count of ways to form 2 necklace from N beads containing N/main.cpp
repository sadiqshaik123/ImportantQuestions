#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}
int noofnecklace(int n){
    long long ans = factorial(n)/(factorial(n/2)*factorial(n/2));
    ans=ans*factorial(n/2-1);
    ans=ans*factorial(n/2-1);
    ans=ans/2;
    return ans;
}
int main(){
    int n;
    cout<<"N = ";
    cin>>n;
    int result=noofnecklace(n);
    cout<<result<<endl;
}

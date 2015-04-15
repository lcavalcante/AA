#include<iostream>
#include<cstdio>
using namespace std;
long long int arr[100000];
int c,n;
int f(int x){
int cowsplaced=1;
long long int lastpos=arr[0];
for(int i=0;i<n;i++){
if(arr[i]-lastpos>=x){
cowsplaced++;
if(cowsplaced==c)
return 1;
}
}
return 0;
}
long long int binSearch(){
long long int start=0,end=arr[n-1];
while(end-start>1){
long long int mid=end+(start-end)/2;
if(f(mid)==1)
start=mid;
else
end=mid;
}
return start;
}
int main(){
int t;
scanf("%d",&t);
while(t--){
scanf("%d %d",&n,&c);
for(int i=0;i<n;i++)
scanf("%lld",&arr[i]);
printf("%lld\n",binSearch());
}
}

#include <iostream>
using namespace std;

int main()
{
int n;
cin>>n;
int a;
int sum=0;
for(int i=0;i<n;i++)
{

cin>>a;
sum=sum+a;
}
if(2*(n-1)==sum)
{

cout<<"Yes\n";
}
else{

cout<<"No\n";
}
return 0;
}


#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;

if(n<=1)
cout<<"Not Prime";
bool prime=true;

for(int i=2;i*i<=n;i++)
{
if(n%i==0)
{
prime=false;
break;
}
}
if(prime)
cout<<"Prime";
else
cout<<"Not Prime";

return 0;
}

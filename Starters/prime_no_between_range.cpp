
#include<iostream>
using namespace std;
int main()
{
int start,end;
cin>>start>>end;

for(int n=start;n<=end;n++)
{
bool prime=true;
  if(n<=1)
    prime=false;
for(int i=2;i*i<=n;i++){
if(n%i==0)
{
prime=false;
break;
}
}
if(prime)
cout<<n<<" ";
}

return 0;
}

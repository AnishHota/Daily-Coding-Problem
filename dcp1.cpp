/* Given a list of numbers and a number k,return whether
any two numbers from the list add upto k
For example, given [10,15,3,7] and k of 17 return true
since 10+7=17
NOTE:Do this in one pass*/
#include<iostream>
using namespace std;
int main()
{
  int arr[]={10,15,3,7};
  int x = 17;
  int size = sizeof(arr)/sizeof(arr[0]);
  int hash[256]={};
  for(int i=0;i<size;i++)
  {
    hash[arr[i]]=1;
    if(hash[x-arr[i]]==1)
    {
      cout<<"True"<<endl;
      return 0;
    }
  }
  return 0;
}

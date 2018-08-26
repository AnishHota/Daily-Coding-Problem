/* Given a list of integers,write a function
that returns the largest sum of non-adjacent
numbers.Numbers can be 0 or negative.

For example,[2,4,6,2,5] should return
13, since we pick 2,6 and .[5,1,1,5]
should return 10,since we pick 5 and 5.
*/
#include<iostream>
using namespace std;
int findMax(int arr[],int n)
{
  int i,incl=arr[0],excl=0,excl_new;
  for(i=1;i<n;i++)
  {
    excl_new = max(incl,excl);
    incl = excl + arr[i];
    excl = excl_new;
  }
  return max(incl,excl);
}
int main()
{
  int arr[]={5,1,1,5};
  int size = sizeof(arr)/sizeof(arr[0]);
  int ans = findMax(arr,size);
  cout<<ans<<endl;
}

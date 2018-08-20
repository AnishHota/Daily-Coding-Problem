/* Given an array of integers,find the first missing
positive integer in linear time and constant space.In
other words, find the lowest positive integer that
doesn't exist in the array.The array can contain duplicates
and negative numbers as well.

For example, the input [3,4,-1,1] should give 2.
The input [1,2,0] should give 3.

You can modify the input array in-place.*/
#include<iostream>
using namespace std;
int findMissingNumber(int arr[],int size)
{
  int i,val,nextval;
  for(i=0;i<size;i++)
  {
    if(arr[i]<=0 || arr[i]>size)
      continue;

    val = arr[i];
    while(arr[val-1]!=val)
    {
      nextval = arr[val-1];
      arr[val-1] = val;
      val = nextval;
      if(val<0 || val>size)
        break;
    }
  }
  for(i=0;i<size;i++)
  {
    if(arr[i] != i+1)
      return i+1;
  }
  return size+1;
}
int main()
{
  int arr[] = {13,12,10};
  int size = sizeof(arr)/sizeof(arr[0]);
  int ans=findMissingNumber(arr,size);
  cout<<ans<<endl;
}

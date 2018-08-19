/* Given an array of integers,return a new array such
that each element at index i of the new array is the
product of all the numbers in the original array except
the one at i.
NOTE: You can't use division.
*/
#include<iostream>
using namespace std;
int main()
{
  int i;
  int arr[] = {1,2,3,4,5};
  int size = sizeof(arr)/sizeof(arr[0]);
  int left[size],right[size];
  left[0]=1;
  right[size-1]=1;
  for(i=1;i<size;i++)
  {
    left[i] = left[i-1]*arr[i-1];
  }
  for(i=size-2;i>=0;i--)
  {
    right[i] = right[i+1]*arr[i+1];
  }
  for(i=0;i<size;i++)
  {
    arr[i] = left[i]*right[i];
  }
  for(i=0;i<size;i++)
    cout<<arr[i]<<endl;
  return 0;
}

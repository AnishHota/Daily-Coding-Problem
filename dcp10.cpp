/* This problem was asked by Apple.

Implement a job scheduler which takes in a
function f and an integer n, and calls f
after n milliseconds.
*/
#include<iostream>
#include<unistd.h>
using namespace std;
void job()
{
  cout<<"Job completed"<<endl;
}
void sched(int n)
{
  sleep(n/1000);
  job();
}
int main()
{
  int n=3000;
  sched(n);
}

/*NOTE: I couldn't quite understand the question.

 This problem was asked by Jane Street.

cons(a,b) constructs a pair, and car(pair)
and cdr(pair) returns the first and last
element of that pair.For example,car(cons(3,4))
returns 3 and cdr(cons(3,4)) returns 4.

Given the implementation of cons:

def cons(a,b):
  def pair(f):
    return f(a,b)
  return pair
*/
#include<iostream>
#include<utility>
using namespace std;
pair<int,int> p;
pair<int,int> cons(int a,int b)
{
  p.first = a;
  p.second = b;
  return p;
}
int car(pair<int,int>)
{
  return p.first;
}
int cdr(pair<int,int>)
{
  return p.second;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<"Calling car: "<<car(cons(a,b))<<endl;
    cout<<"Calling cdr: "<<cdr(cons(a,b))<<endl;
    return 0;
}

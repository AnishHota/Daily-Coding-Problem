/* This problem was asked by Twitter.

Implement an autocomplete system. That is,
given a query string s and a set of all possible
query strings, return all strings in the set
that have s as a prefix.

For example, given the query string de and the
set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into
a more efficient data structure to speed up queries
*/
#include<iostream>
#include<string>
#include<regex> // Supported in C++11 onwards compilers
using namespace std;
vector<string> find_poss_query(string query,vector<string> queries)
{
  vector<string> temp;
  regex a(query+"(.*)");
  for(auto x:queries)
  {
    if(regex_match(x,a))
      temp.push_back(x);
  }
  return temp;
}
int main()
{
  string query = "de";
  vector<string> queries = {"dog","deer","dear"};
  vector<string> ans;
  ans = find_poss_query(query,queries);
  for(auto x: ans)
  {
    cout<<x<<" ";
  }
  cout<<endl;
  return 0;
}

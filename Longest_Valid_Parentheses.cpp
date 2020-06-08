#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  std::cin >> s;

  stack <  int  > list;
  int ans = 0 , res , emp = 0 ;
  list.push ( - 1 );
  for (  int i = 0 ; i < s.length() ; ++i ){
  if ( s[ i ] == '('){
  std::cout << "push" << '\n';
    list.push( i );
  }
  else if( s[ i ] == ')'){
    list.pop() ;
    std::cout << "pop" << '\n';
    res = i - list.top();
    //ans += res;
    emp = max( emp , res );
    if ( list.empty() )
      list.push( i );
  }
}
  /*
  for( char ch : s ){
    if( list.empty() && emp > 0 ){
       res = 0 ;
     }
    if( ch == '(' ){
      std::cout << "push ";
      list.push( ch );
      emp = 0 ;
    }
    else if ( ch == ')'){
      std::cout << "pop ";
      if( !list.empty() ){
        list.pop();
        res += 1;
        ans = max ( ans , res );
      }
      else
        emp += 1 ;
    }
  }
  //while (  )
  /*
  for ( char ch : list ){
    std::cout << "->"<< ch;
  }*/
  std::cout << " :: "<< emp << '\n';
  return 0;
}

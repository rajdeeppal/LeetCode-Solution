#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#include <queue>
#include <stack> 
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[]) {
  string s,pat;
  std::cin >> s >> pat ;
  stack < char > stck ;
  std::vector< char > p(pat.begin() ,  pat.end() );
  reverse(s.begin() , s.end() );
  for( char x : s ){
    stck.push( x );
  }


  char prev ;
  std::vector< char > not_match ;

  int f = 0 ;
  int pos ,i;
  for ( i = 0 ; i < p.size() ; ){
    if( ! stck.empty() ){
    char top = stck.top();
    if( p[ i ] == top ){
      //char m  = stck.top();
      stck.pop();
      std::cout << "match  "<< top << '\n';
      i++;
    }
    else if ( p[ i ] == '.' ){
      stck.pop();
      f = 0 ;
      i++;
    }
    else if(p[ i ] == '*' ){
      //char prev = p [ i - 1 ];
      std::cout << "*" << '\n';
      if( not_match.size() == 1 )
        not_match.clear();
      f = 1 ;
      pos = i + 1 ;
      i = i - 1 ;
    }

    else if( p [ i ] != top ){
      //if()
        if ( f == 1  ){
          i = pos;
          f = 0 ;
          }
        else {
            not_match.push_back ( p [ i ]); ///***end****
          std::cout << not_match.size() << '\n';
          i = i + 1 ;
          if( not_match.size() == 1 )
            continue;
          else{
              std::cout << " False " << '\n';
              break;
            }
            }
        }

      }
      else
          break;

    std::cout << "::"<< i  << '\n';

  }
  std::cout <<"end  i   p.size "<< i << ":"<<p.size()<< '\n';
  if( stck.empty() && p.back()=='*')
    std::cout << "true" << '\n';
  else if ( stck.empty() && i == p.size() )
    std::cout << "true" << '\n';
  else
    std::cout << "false" << '\n';
  return 0;
}

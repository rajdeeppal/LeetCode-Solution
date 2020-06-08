#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

  int n;
  std::cin >> n;
  std::vector< int > v(n);
  for ( int i = 0 ; i < n ; ++i){
    std::cin >> v[ i ];
  }
  int sum ;
  std::cin >> sum;
  int i = 0 , j = 0 , cursum = 0 , res = 0 , f = 0 ;


  std::map<int , int > map;
  int pref = 0;
  map[ pref ]++;
  int ans = 0;
  for ( int i = 0 ; i < n ; ++i){

      pref += v[ i ];
      int need = pref - sum;
      ans += map[ need ];
      map[ pref ]++;

  }

  std::cout << " :: "<< ans << '\n';;
  /*
  while( i < n && j < n ){

    if(f == 0 )
      {
        cursum += v [ j ];
      }
    if( cursum == sum ){
      std::cout << " : 1 :" << '\n';
      res++;
      j++;
    }
    else if( cursum > sum ){
      std::cout << " : 2 :" << '\n';
      cursum -= v[ i ];
      f = 1;
      i++;
    }
    else
    {
      f = 0 ;
      j++;
    }
  }
  std::cout << "::::"<< res << '\n';
  */

  return 0;
}

#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int make_bit_dig( int x ){
  set < int > dig;
  while( x > 0 ){
  int rem = x % 10 ;
  x /= 10;
  dig.insert( rem );
}
auto it1 = dig.begin();
auto it2 = dig.rbegin();
int big = *it2;
int small = *it1;
std::cout <<small <<big << '\n';
int digit = small * 7 + big * 11 ;
return (digit % 100);
}

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n ;
  std::vector < int > v(n);

  for ( int i = 0 ; i < n ; ++i ){
    std::cin >> v[ i ];
  }
  std::vector < int > bit_dig;

  for( int i = 0 ; i < n  ; ++i ){
    int p = make_bit_dig( v [ i ]);
    bit_dig.push_back(  p );
  }
  for ( int x : bit_dig ){
    std::cout << " : "<< x << '\n';
  }

  std::map< pair < int , int > , std::vector<int> > trace;
  int max = 0 , min = 0 , f = 0 ;
  for ( int i = 0 ; i < n ; ++i ){
    if ( bit_dig [ i ] >= 0 && bit_dig[ i ] < 10 ){
      min = 0, max = 10 ;
    }
    else if ( bit_dig [ i ] >= 10 && bit_dig[ i ] < 20 ){
      min = 10 , max = 20 ;
    }
    else if ( bit_dig [ i ] >= 20 && bit_dig[ i ] < 30 ){
      min = 20 , max = 30 ;
    }
    else if ( bit_dig [ i ] >= 30 && bit_dig[ i ] < 40 ){
      min = 30 , max = 40 ;
    }
    else if ( bit_dig [ i ] >= 40 && bit_dig[ i ] < 50 ){
      min = 40, max = 50 ;
    }
    else if ( bit_dig [ i ] >= 50 && bit_dig[ i ] < 60 ){
      min = 50, max = 60 ;
    }
    else if ( bit_dig [ i ] >= 60 && bit_dig[ i ] < 70 ){
      min = 60, max = 70 ;
    }
    else if ( bit_dig [ i ] >= 70 && bit_dig[ i ] < 80 ){
      min = 70, max = 80 ;
    }
    else if ( bit_dig [ i ] >= 80 && bit_dig[ i ] < 90 ){
      min =  80 , max = 90 ;
    }
    else if ( bit_dig [ i ] >= 90 && bit_dig[ i ] < 100 ){
      min = 90, max = 100 ;
    }

    for( int j = i + 2  ; j < n ; j+=2 ){
      if ( bit_dig [ j ] >= min && bit_dig [ j ] < max ){
        std::cout << "push map : { "<<min<<","<<max<<"}"<<bit_dig [ j ] << '\n';
        trace[ { min , max } ].push_back( bit_dig [ j ]);
        f = 1 ;
        bit_dig [ j ] = 101;
      }
    }
    //min = 0 ;
    //max = 0 ;
    if( f == 1 ){
        trace[ { min , max } ].push_back( bit_dig [ i ]);
        std::cout << "push map : " << "{" << min <<"," << max <<"}"<<bit_dig [ i ] << '\n';
        f = 0;
    }
    min = 0 ;
    max =  0;
  }
  int pair;
  int score = 0 ;
  for ( int i = 0 , j = 10; i <= 90 && j <= 100 ; i += 10 , j += 10){
    std::cout << " len "<<trace[{i,j}].size() << '\n';
    if( trace[ { i , j } ].size() == 2 ){
      pair = 1 ;
      score += pair;
    }
    else if (trace [ { i , j } ].size() > 2 ){
      pair = 2 ;
      score += pair;
    }
  }
  std::cout << "score : "<<score << '\n';
  return 0;
}

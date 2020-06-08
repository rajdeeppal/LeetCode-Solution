#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
int n;
std::cin >> n;
std::vector< std::vector< int > > v(n,std::vector<int>(n));

for(  int i = 0 ; i< n ; ++i){

  for( int j = 0 ; j < n ; ++j){

    std::cin >> v[ i ][ j ];
  }
}
std::vector< std::vector< int > > DP( n , std::vector < int > ( n ));

for( int i = 0 ; i < n ; ++i){

  for( int j = 0 ; j < n ; ++j){

    if( i == 0 && j == 0 )
        DP[ i ][ j ] = v[ i ][ j ];
    else if( i == 0 )
        DP[ i ][ j ] = DP[ i ][ j - 1 ] + v[ i ][ j ];
    else if( j == 0)
        DP[ i ][ j ]  = DP[ i - 1 ][ j ] + v[ i ][ j ];
    else
    {
      DP[ i ][ j ] = min(DP[ i - 1][ j ], DP[ i ][ j - 1 ]) + v[ i ][ j ];
    }
    /*if( i == 0  )
        DP[ i ][ j ] = INT_MAX;
    else if( j == 0 && i == 1)
        DP[ i ][ j ] = 0;
    else if( j == 0)
        DP[ i ][ j ] = INT_MAX;
    else {
        DP[ i ][ j ] = min( DP[ i ][ j - 1 ] , DP[ i - 1][ j ]) + v[ i - 1 ][ j - 1 ];

      }*/
    }

  }

for( std::vector<int> x : DP){
  for( int m : x ){
    std::cout << m << '\t';
  }
  std::cout  << '\n';
}
  return 0;
}

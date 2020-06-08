#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

  int n;
  std::cin >> n;
  std::vector<int> v(n);

  for( int i = 0 ; i< n ; ++i){
    std::cin >> v[ i ];
  }
  int target ;
  std::cout << "target" << '\n';
  std::cin >> target ;
  //std::vector< int > v;
  //int index1 = - 1;
  //int index2 = -1;
  //std::map< int , std::vector<int> > map;
  int not_mid = 0 ;
  for ( int i = 1 ; i < n ; ++i){
    if( v[ i ] < v [ i - 1] ){
        not_mid = i - 1 ;
      }

  }

  std::cout << "not mid"<< not_mid<< '\n';
  int low = 0 , heigh = n - 1 , mid;


  if( target <= v[ not_mid ] && target >= v[ low ] ){
  std::cout << "1 st " << '\n';
  heigh = not_mid;
  while ( low <= heigh) {
    mid = low + ( heigh - low ) / 2;
    if( v[ mid ] == target ) {
      std::cout << mid << '\n';
      break;
      }//return mid;
    else if( v[ mid ] < target ) low = mid + 1 ;
    else
      heigh = mid - 1;
  }
  std::cout << " - 1 " << '\n';
  //return -1;
  }

  else{
    std::cout << "2 nd " << '\n';
    low = not_mid + 1 ;
    std::cout << v[ low ]<<":"<<v[ heigh ] << '\n';

    while ( low <= heigh) {
      mid = low + ( heigh - low ) / 2;
      if( v[ mid ] == target ) {
        std::cout << mid << '\n';
        break;
      }//return mid;
      else if( v[ mid ] < target )
        low = mid + 1 ;
      else {
        heigh = mid - 1;
      }
    }
      std::cout << " - 1 " << '\n';
    //return -1;

  }
  return 0;
}

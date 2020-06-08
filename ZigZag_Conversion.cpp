#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  string input;
  std::cin >> input;
  int n = input.length();
  int row ;
  cin >> row;
  int r ;
  string out = "";
  int flag = 0;

  int cal = 2 * row  - 2 ;
  std::vector< string > v;
  int i ;
  for ( i = 0 ; i < n && i + cal < n ; i = i + cal){
      string str = input.substr( i , cal );
      v.push_back(str);
      str = "";
  }

  string str = input.substr( i );
  v.push_back(str);

  for ( string x : v ){
    std::cout << x << '\n';
  }
  int new_row ;
  std::map< int , std::vector< string > >m;

  for ( string s : v ){
    //new_row = row - 1 ;
    std::vector< int > vis( s.length() , 0 );
    int flag = 0;
    string a;
     a.push_back(s[0]);
     vis[ 0 ] = 1;
    m[ row ].push_back(a);
    for( int i = 1 , new_row = row - 1 ; i < row && new_row > 1 ; ++i){
      std::cout << new_row << '\n';
      for ( int j = i ; j < s.length() ; j += r){
          if( vis [ j ] == 0){
            out += s[ j ];
            r = 2 * new_row - 2;
            vis[ j ] = 1 ;
          }
      }
      //new_row -= 1;
      m[ new_row ].push_back(out);
      //if(flag == 1)
        //break;
      new_row -= 1;
      out = "";
    }
    for ( int x : vis ){
      std::cout<< x << "->";
    }
    out = "";
    for ( int i = 1 ; i < s.length() ; ++i){

      if( vis[ i ] == 0 ){
        out += s[ i ];
        vis[ i ] = 1;
      }
    }
    //std::cout << "new row - > " << new_row <<'\n';
    m[ 1 ].push_back(out);
    out = "";

  }

  std::vector<std::vector< string > > mp;

   for( auto it = m.begin() ; it != m.end() ; ++it){
     mp.push_back(it->second);
   }
   string new_str = "" ;
   for( int i = mp.size() - 1 ; i >= 0 ; --i ){
     for( int j = 0 ; j < mp[ i ].size() ; ++j ){
        new_str += mp[ i ][ j ];
     }
   }

   std::cout << "result : "<< new_str << '\n';

   for( std::vector< string > x : mp){
     for( string ch : x){
       std::cout << " : "<<ch;
     }
     std::cout  << '\n';
   }
  return 0;
}

/*class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};*/

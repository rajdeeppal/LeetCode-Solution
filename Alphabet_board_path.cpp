#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  std::vector< std::vector< char > > board;
  //std::vector< string > v(6);
/*
  for( int i = 0 ; i < 6 ; ++i){
    std::cin >> v[ i ];
  }
  */
  std::vector< string > v  {"abcde",
                                "fghij",
                                      "klmno",
                                            "pqrst",
                                                  "uvwxy",
                                                        "z" };
  std::vector< char > tmp;

  for ( string x : v ){
    for ( char ch : x ){
      tmp.push_back(ch);
    }
     board.push_back( tmp );
     tmp.clear();
  }
  //std::map < char , pair < int , int > > m;
  std::map< char , std::vector< int >  > m ;
  for ( int i = 0 ; i < board.size() ; ++i ){
    for( int j = 0 ; j < board[ i ].size() ; ++j ){
      //m[board[ i ][ j ]].insert( std::make_pair <int ,int > (i , j ) );
      m[board[ i ][ j ]].push_back( i );
      m[board[ i ][ j ]].push_back( j );
    }
  }

  string target ;
  std::cin >> target;
  string out ;
  std::vector<int> cur_pos( 2 , 0 );
  int x = 0 , y = 0 , old_x , old_y ;
  for ( char x : target ){
    int f = 0 ;
    auto it = m.find( x );
    if(it != m.end() ){
      auto itr  = it->second;
      x = itr.front();
      y = itr.back();
      old_x = cur_pos[ 0 ];
      old_y = cur_pos[ 1 ];
      cur_pos [ 0 ] = x ;
      cur_pos [ 1 ] = y ;
      if( old_x == x && old_y == y )
        out += "!";
      else {

        if ( x == 5 ){
          f = 1 ;
          x = 4 ; y = 0 ;
        }
        else if ( old_x == 5 ){
          out += "U";
          old_x  = 4 ;
          old_y = 0 ;
          }

          if ( x < old_x ) {
              int dif = old_x - x ;
              while ( dif != 0 ) {
              out += "U";
              dif--;
              }
            }
        else if( x > old_x ){
          int dif = x - old_x ;
          while ( dif != 0 ) {
          out += "D";
          dif--;
          }
        }
        if ( y < old_y ){
          int diff = old_y - y ;
          while( diff != 0 ){
          out += "L";
          diff--;
          }
        }
        else if( y > old_y ){
          int diff = y - old_y ;
          while (diff != 0 ) {
            out += "R";
            diff--;
          }
        }
        if( f == 1 ){
           out += "D!";
        }
        else
          out += "!";

    }

    }
  }

  std::cout << out << '\n';

  return 0;
}



#include <unordered_map>

using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {

        string result = "", board = "abcdefghijklmnopqrstuvwxyz";

        unordered_map<char, pair<int, int>> m;
        for (char c: board) {
            int row = (c - 'a') / 5;
            int col = (c - 'a') % 5;
            m[c] = {row, col};
        }

/*
        char cur = 'a';
        pair<int, int> p = {0, 0};

        for (char c: target) {

            int r_diff = m[c].first - m[cur].first;
            int c_diff = m[c].second - m[cur].second;

            do
            {

                for (int k = 0; k < abs(r_diff); k++) {
                    if (r_diff > 0 && (p.first + 1 <= 4 || (p.first + 1 == 5 && p.second == 0)) ) {
                        p.first += 1;
                        r_diff -= 1;
                        result += 'D';
                    } else if (r_diff < 0 && p.first - 1 >= 0) {
                        p.first -= 1;
                        r_diff += 1;
                        result += 'U';
                    } else {
                        break;
                    }
                }

                for (int k = 0; k < abs(c_diff); k++) {
                    if (c_diff > 0 && p.second + 1 <= 4) {
                        p.second += 1;
                        c_diff -= 1;
                        result += 'R';
                    } else if (c_diff < 0 && p.second - 1 >= 0) {
                        p.second -= 1;
                        c_diff += 1;
                        result += 'L';
                    } else {
                        break;
                    }
                }

            } while (r_diff != 0 || c_diff != 0);

            result += '!';

            cur = c;
            p = m[c];
        }

*/
        int row = 0, col = 0;
        for (char c : target) {

            // U L D R
            pair<int, int> p = m[c];

            result += string(max(row - p.first, 0), 'U');
            result += string(max(col - p.second, 0), 'L');
            result += string(max(p.first - row, 0), 'D');
            result += string(max(p.second - col, 0), 'R');
            result += '!';

            row = p.first;
            col = p.second;
        }

        return result;
    }
};

#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

bool check_post(std::map<char, std::vector<int>> v , char x){
auto itr = v.find(x);

if(itr != v.end()){

  std::cout<<" charater : "<< x << itr->second.size() << '\n';
if((itr->second.size()) > 1)
  return false;
}
return true;
}


int check_string( std::map<char, std::vector<int> >& trace , char x){
auto itr = trace.find(x);
auto it = itr->second.begin();

int p = *(it) + 1 ;
std::cout << "new i "<< p << '\n';
//auto it = itr->second.end();
//int p = *(--it);
//cout<<p;
//itr->second.erase(itr->second.begin(),itr->second.begin() + 1 );
itr->second.erase(it);

return p;
}

int main(int argc, char const *argv[]) {
  string str;
  std::cin >> str;
  int len = str.length();
  int l = 0;
  int best_len = 0 ;

  //std::cout << "/* message */" << '\n';
  std::map<char, std::vector<int> > trace;
  int i = 0;
  int j = 0;
  int maxi = -1 ;
  while ( i < len && j < len) {
    trace[str[j]].push_back(j);
    if(!check_post(trace,str[j]))
    {
        std::cout << "dupplicate" << '\n';

        int p = check_string( trace , str[j]);
        maxi = max( p , maxi );
        i = maxi;
        std::cout << "new i after maxi "<< i << '\n';
        l = j - i + 1;
        best_len = max( l , best_len);

    }
    else{
      l = j - i + 1;
      best_len = max( l , best_len);
    }
    j++;
    /* code */
  }
  l = (j - 1) - i + 1 ;
  std::cout << " l - > "<< l << '\n';
  best_len = max( l , best_len);
/*
  std::vector<std::vector<int> > v;

  for ( auto x : trace){
    v.push_back(x.second);
  }
  for( auto x : v){
    for( int m : x){
      std::cout<< m << " ";
    }
    std::cout  << '\n';
  }*/
  /*
for ( ){
  std::cout << it->first << " "<< '\n';
}*/
  std::cout << i << " "<< j - 1<<"   best length : "<<best_len;

  return 0;
}

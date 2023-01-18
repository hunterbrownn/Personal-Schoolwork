//Hunter Brown, ghb6mt, 3/13/22

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cmath>
#include "hashTable.h"
using namespace std;

hashTable::hashTable(int j){
  table.resize(getNextPrime(j*10));
}
hashTable::~hashTable(){
}

void hashTable::insert(string s){
  int i = hash(s)%table.size();
  table[i].push_front(s);
}

bool hashTable::find(string s){
  int i = hash(s)%table.size();
  if(table[i].size() == 1){
    if(table[i].front() == s)
      return true;
    else
      return false;
  }
  else{
    list<string>::iterator it;
    for(it = table[i].begin(); it!= table[i].end(); it++){
      //found on thispointer.com for different wasy to iterate over a list
      if(*it == s)
	return true;
    }
    return false;}
      
}

unsigned int hashTable:: hash(string s){
  unsigned int sum = 0;
  for(int i = 0; i <s.length(); i++){
    int j = s.at(i) - '0';
    sum += j*31+j;}
    return sum;
}

bool hashTable:: checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

 int hashTable:: getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

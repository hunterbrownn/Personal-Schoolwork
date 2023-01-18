//Hunter Brown, ghb6mt, 3/12/22

#include <vector>
#include <list>
#include <string>

using namespace std;

class hashTable {

 public:
  hashTable(int j);
  ~hashTable();
  vector<list<string> > table;
  void insert(string s);
  bool find(string s);

 private:
  unsigned int hash(string s);
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);
};

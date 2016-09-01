#ifndef ONEPGM_H
#define ONEPGM_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>


using namespace std;

ifstream fin;

string word;
string s;

int option;

bool flag;

class Node
{

private:

public:

  string NodeStr;
  char info;
  class Node *ptrs[256];

  Node();
  ~Node();
  void insert(string localStr,int posistion,class Node * root);
  void printfunc(class Node *root);
  void findword(string localStr, int posistion , class Node *root);
  void suggest(string localStr,int posistion,class Node *root);
  void closeFunction();
};



#endif

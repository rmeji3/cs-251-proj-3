#include <iostream>
#include "mymatrix.h"
#include <vector>
#include <fstream>
using namespace std;//make test case functions
bool testDefValInt()
{
  mymatrix<int> m(4,4);
  for(int x = 0; x < 4; x++)
  {
    for(int y = 0; y < 4; y++)
    {
      if(m(x,y) != 0)
      {
        return false;
      }
    }
  }
  return true;
}
bool testDefValString()
{
    mymatrix<string> m(4,4);
  for(int x = 0; x < 4; x++)
  {
    for(int y = 0; y < 4; y++)
    {
      if(m(x,y) != "")
      {
        return false;
      }
    }
  }
  return true;
}
bool testDefValBool()
{
    mymatrix<bool> m(4,4);
  for(int x = 0; x < 4; x++)
  {
    for(int y = 0; y < 4; y++)
    {
      if(m(x,y))
      {
        return false;
      }
    }
  }
  return true;
}
bool testNumRows()
{
  mymatrix<int> m(10,1);
  
  if(m.numrows()==10);
  return true;
  return false;
}
bool testLargeNumRows()
{
  mymatrix<int> m(10,1);
  
  if(m.numrows()==10);
  return true;
  return false;
}
bool testNumColsRect()
{
  mymatrix<int> m(9,9);
  for(int i = 0; i < 9; i ++)
    {
      if(m.numcols(i) != 9)
      {
        return false;
      }
    }
  return true;
}
bool testNumColsJagged()
{
  mymatrix<char> m(3,3);
  m.growcols(2,5);
  m.growcols(0,7);
  if(m.numcols(0) != 7 && m.numcols(2) != 5 && m.numcols(1) != 3)
  {
    return false;
  }
  return true;
}
bool testLargeNumColsJagged()
{
  mymatrix<char> m(3,3);
  m.growcols(2,17);
  m.growcols(0,35);
  if(m.numcols(0) != 35 && m.numcols(2) != 17 && m.numcols(1) != 3)
  {
    return false;
  }
  return true;
}
int main() {
  // mymatrix<double> s;
  // s._output();
cout << "*******mymatrix Debugger*******" << endl;
int pass = 0;
int fail = 0;
(testDefValInt()) ? pass++ : fail++;
(testDefValString()) ? pass++ : fail++;
(testDefValBool()) ? pass++ : fail++;
(testDefValInt()) ? pass++ : fail++;
(testDefValString()) ? pass++ : fail++;
(testNumRows()) ? pass++ : fail++;
(testLargeNumRows()) ? pass++ : fail++;
(testNumColsRect()) ? pass++ : fail++;
(testNumColsJagged()) ? pass++ : fail++;
(testLargeNumColsJagged()) ? pass++ : fail++;



  mymatrix<int> m;
  m._output();


cout << "Tests passed: " << pass << endl;
cout << "Tests failed: " << fail << endl;
  /*
  mymatrix<string> m(50,50);
  cout << endl; 
char heart = 3;
  for(int i = 0; i < 50; i++)
  {
    for(int j = 0; j < 50; j++)
      {
            m.at(i,j) = heart;      
      }

  }
  m.at(3,5) = '*';
  m.at(2,6) = '*';
  m.at(4,0) = '8';
  m.at(4,1) = '='; 
  m.at(4,2) = 'D'; 
  m.at(4,3) = '*';
  m.at(4,4) = '*';
  m.at(5,5) = '*'; 
  m.at(6,6) = '*';
 
 ofstream file("bozo.txt");
      for (int r = 0; r < 50; ++r)
    {
      for (int c = 0; c < 50; ++c)
      {
        file << m.at(r,c) << " ";
      }
      file << endl;
    }
   
   
 

  
  for(int i = 0; i < 5; i++){
    cout << "PEEN #" << i+1 << endl;
   m._output(); 
    
    cout << endl;
  }*/
   
  // m.growcols(0,5);
 // m(0,2) = 1;
  // m.grow(3,4);
  // cout << m.size() << endl;
  // m._output();
  // cout << "Num cols at 0 index: " << m.numcols(0) << "  Num rows: " << m.numrows() << endl;
  // cout << "test: " << m.at(0,2) << endl;
  // cout << "test: " << m.at(0,10) << endl;
  // m=m*2;
  // m._output();
}
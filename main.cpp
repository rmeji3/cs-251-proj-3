/*
Testing

Rafael Mejia
CS 251

This main will test all the matrix functions
Every function will be tested at least 3 times
it will count the number of test cases passed and failed


*/

#include <iostream>
#include "mymatrix.h"
#include <vector>
#include <fstream>
using namespace std;
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
bool testNumColsAfterMultipleGrowCols()
{
  mymatrix<char> m(3,4);
  m.growcols(2,17);
  m.growcols(0,35);
  m.growcols(0,35);
  m.growcols(0,35);
  m.growcols(0,35);
  m.growcols(0,90);
  m.growcols(0,90);
  m.growcols(0,91);
  
  if(m.numcols(0) != 91 && m.numcols(2) != 17 && m.numcols(1) != 4)
  {
    return false;
  }
  return true;
}
bool testSingleGrow()
{
  mymatrix<bool>m(2,2);
  m.grow(5,5);
  
  if(m.numrows() != 5)
    return false;
  
  for(int x = 0; x < 5; x++)
  {
    if(m.numcols(x) != 5)
      return false;
  }
  return true;
}
bool testmutipleGrow()
{
  mymatrix<bool>m(2,2);
  m.grow(5,5);
  
  if(m.numrows() != 5)
    return false;
  
  for(int x = 0; x < 5; x++)
  {
    if(m.numcols(x) != 5)
      return false;
  }
  m.grow(7,5);
  
  if(m.numrows() != 7)
    return false;
  for(int x = 0; x < 7; x++)
  {
    if(m.numcols(x) != 5)
      return false;
  }
   m.grow(10,8);
  
  if(m.numrows() != 10)
    return false;
  for(int x = 0; x < 10; x++)
  {
    if(m.numcols(x) != 8)
      return false;
  }
  m.grow(50,89);
  
  if(m.numrows() != 50)
    return false;
  for(int x = 0; x < 50; x++)
  {
    if(m.numcols(x) != 89)
      return false;
  }
  return true;
}
bool testJaggedGrow()
{
  mymatrix<string> m;
  m.growcols(0,20);
  m.growcols(1,20);
  m.growcols(2,15);
  m.growcols(3,15);
  m.grow(5,19);
  for(int x = 0; x < 2; x++)//test to see if the first two rows are still 20
  {
    if(m.numcols(x) != 20)
    {
      return false;
    }
  }
  for(int x = 2; x < m.numrows(); x++)//test rest to se if they grew to 19
  {
    if(m.numcols(x) != 19)
    {
      return false;
    }
  }
  return true;
}
bool testMultipleJaggedGrow()
{
  mymatrix<string> m;
  m.growcols(0,20);
  m.growcols(1,20);
  m.growcols(2,15);
  m.growcols(3,15);
  m.grow(5,19);
  for(int x = 0; x < 2; x++)//test to see if the first two rows are still 20
  {
    if(m.numcols(x) != 20)
    {
      return false;
    }
  }
  for(int x = 2; x < m.numrows(); x++)//test rest to se if they grew to 19
  {
    if(m.numcols(x) != 19)
    {
      return false;
    }
  }
 if(m.numrows() != 5)
    return false;
  m.growcols(0,30);
  m.growcols(1,30);
  m.grow(10,25);
  for(int x = 0; x < 2; x++)//test to see if the first two rows are still 20
  {
    if(m.numcols(x) != 30)
    {
      return false;
    }
  }
  for(int x = 2; x < m.numrows(); x++)//test rest to se if they grew to 19
  {
    if(m.numcols(x) != 25)
    {
      return false;
    }
  }
  if(m.numrows() != 10)
    return false;

  m.growcols(0,100);
  m.growcols(1,100);
  m.growcols(2,90);
  m.grow(500,70);
  for(int x = 0; x < 2; x++)//test to see if the first two rows are still 20
  {
    if(m.numcols(x) != 100)
    {
      return false;
    }
  }
  if(m.numcols(2) != 90)
    return false;
  for(int x = 3; x < m.numrows(); x++)//test rest to se if they grew to 19
  {
    if(m.numcols(x) != 70)
    {
      return false;
    }
  }
  if(m.numrows() != 500)
    return false;
  return true;
}
bool testScalar()
{
  mymatrix<int>m(10,10);
  
  for(int r = 0; r < m.numrows();r++)//first initialize vals to 10 
  {
    // int yes = m.numcols(r);
    // cout << yes << endl;
    for(int c = 0; c < m.numcols(r);c++)
    {
      m.at(r,c) = 10;
    }
  }
  
  m = m*2;//multiply by 2
   for(int r = 0; r < m.numrows();r++)//check if everything == 20
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 20)
        return false;
    }
  }
  return true;
  
}
bool testScalarMultiple()
{
  mymatrix<int>m(10,10);
  
  for(int r = 0; r < m.numrows();r++)//first initialize vals to 10 
  {
    // int yes = m.numcols(r);
    // cout << yes << endl;
    for(int c = 0; c < m.numcols(r);c++)
    {
      m.at(r,c) = 10;
    }
  }
  
  m = m*2;//multiply by 2
   for(int r = 0; r < m.numrows();r++)//check if everything == 20
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 20)
        return false;
    }
  }
  
  m = m*2;//multiply by 2
   for(int r = 0; r < m.numrows();r++)//check if everything == 40
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 40)
        return false;
    }
  }
  m = m*10;//multiply by 2
  for(int r = 0; r < m.numrows();r++)//check if everything == 400
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 400)
        return false;
    }
  }
  return true;
  
}
bool testScalarNegatives()
{
  mymatrix<int>m(10,10);
  
  for(int r = 0; r < m.numrows();r++)//first initialize vals to 10 
  {
    // int yes = m.numcols(r);
    // cout << yes << endl;
    for(int c = 0; c < m.numcols(r);c++)
    {
      m.at(r,c) = 10;
    }
  }
  
  m = m*-2;//multiply by 2
   for(int r = 0; r < m.numrows();r++)//check if everything == -20
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != -20)
        return false;
    }
  }
  
  m = m*2;//multiply by 2
   for(int r = 0; r < m.numrows();r++)//check if everything == -40
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != -40)
        return false;
    }
  }
  m = m*10;//multiply by 2
  for(int r = 0; r < m.numrows();r++)//check if everything == -400
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != -400)
        return false;
    }
  }
  m = m*-1;//multiply by 2
  for(int r = 0; r < m.numrows();r++)//check if everything == 400
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 400)
        return false;
    }
  }
  return true;
  
}
bool testScalarDoubles()
{
  mymatrix<double>m(10,10);
  
  for(int r = 0; r < m.numrows();r++)//first initialize vals to 10 
  {
    // int yes = m.numcols(r);
    // cout << yes << endl;
    for(int c = 0; c < m.numcols(r);c++)
    {
      m.at(r,c) = 10.0;
    }
  }
  
  m = m*-2;//multiply by 2
   for(int r = 0; r < m.numrows();r++)//check if everything == -20
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != -20)
        return false;
    }
  }
  
  m = m*2;//multiply by 2
   for(int r = 0; r < m.numrows();r++)//check if everything == -40
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != -40)
        return false;
    }
  }
  m = m*10;//multiply by 2
  for(int r = 0; r < m.numrows();r++)//check if everything == -400
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != -400)
        return false;
    }
  }
  m = m*-1;//multiply by 2
  for(int r = 0; r < m.numrows();r++)//check if everything == 400
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 400)
        return false;
    }
  }

  m = m*0.5;//multiply by 2
  for(int r = 0; r < m.numrows();r++)//check if everything == 200
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 200)
        return false;
    }
  }
  m = m*0.5;//multiply by 2
  for(int r = 0; r < m.numrows();r++)//check if everything == 100
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 100)
        return false;
    }
  }
  m = m*0.5;//multiply by 2
  for(int r = 0; r < m.numrows();r++)//check if everything == 50
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 50)
        return false;
    }
  }
  m = m*0.5;//multiply by 2
  for(int r = 0; r < m.numrows();r++)//check if everything == 25
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 25)
        return false;
    }
  }
  m = m*0.5;//multiply by 2
  for(int r = 0; r < m.numrows();r++)//check if everything == 12.5
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 12.5)
        return false;
    }
  }
  m = m*0.5;//multiply by 2
  for(int r = 0; r < m.numrows();r++)//check if everything == 6.25
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 6.25)
        return false;
    }
  }
  m = m*0.5;//multiply by 2
  for(int r = 0; r < m.numrows();r++)//check if everything == 3.125
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 3.125)
        return false;
    }
  }
  m = m*0.5;//multiply by 2
  for(int r = 0; r < m.numrows();r++)//check if everything == 1.5625
  {
    for(int c = 0; c < m.numcols(r);c++)
    {
      if(m.at(r,c) != 1.5625)
        return false;
    }
  }
    return true;
}
bool testScalarJagged()
{
  mymatrix<int> m;
  m.growcols(0,10);
  for(int c = 0; c < m.numcols(0); c++)
  {
    m.at(0,c) = 10;
  }
  for(int r = 1; r < m.numrows(); r++)
  {
    for(int c = 0; c < m.numcols(r); c++)
    {
      m.at(r,c) = 2;
    }
  }
  m = m *2;
  for(int c = 0; c < m.numcols(0); c++)
  {
    if(m.at(0,c) != 20)
      return false;
  }
  for(int r = 1; r < m.numrows(); r++)
  {
    for(int c = 0; c < m.numcols(r); c++)
    {
      if(m.at(r,c) != 4)
        return false;
    }
  }
  m = m *-2;
  for(int c = 0; c < m.numcols(0); c++)
  {
    if(m.at(0,c) != -40)
      return false;
  }
  for(int r = 1; r < m.numrows(); r++)
  {
    for(int c = 0; c < m.numcols(r); c++)
    {
      if(m.at(r,c) != -8)
        return false;
    }
  }
  
  return true;
}
bool testMatrixMult()
{
  
}
int main() {
  // mymatrix<double> s;
  // s._output();
cout << "*******mymatrix Debugger*******" << endl;
int pass = 0;
int fail = 0;
//********no need to test size and access operator as they are used in all test cases****
(testDefValInt()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testDefValInt" << endl);
(testDefValString()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testDefValString" << endl);
(testDefValBool()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testDefValBool" << endl);
(testDefValInt()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testDefValInt" << endl);
(testDefValString()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testDefValString" << endl);
(testNumRows()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testNumRows" << endl);
(testLargeNumRows()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testLargeNumRows" << endl);
(testNumColsRect()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testNumColsRect" << endl);
(testNumColsJagged()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testNumColsJagged" << endl);
(testLargeNumColsJagged()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testLargeNumColsJagged" << endl);
(testNumColsAfterMultipleGrowCols()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testNumColsAfterMultipleGrowCols" << endl);
(testSingleGrow()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testSingleGrow" << endl);
(testmutipleGrow()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testmutipleGrow" << endl);
(testJaggedGrow()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testJaggedGrow" << endl);
(testMultipleJaggedGrow()) ? (pass++,cout<<"") : (fail++, cout << "Failed test: testMultipleJaggedGrow" << endl);
(testScalar())? (pass++,cout<<"") : (fail++, cout << "Failed test: testScalar" << endl);
(testScalarMultiple())? (pass++,cout<<"") : (fail++, cout << "Failed test: testScalarMultiple" << endl);
(testScalarNegatives())? (pass++,cout<<"") : (fail++, cout << "Failed test: testScalarNegatives" << endl);
(testScalarDoubles())? (pass++,cout<<"") : (fail++, cout << "Failed test: testScalarDoubles" << endl);
(testScalarJagged())? (pass++,cout<<"") : (fail++, cout << "Failed test: testScalarJagged" << endl);
(testMatrixMult())? (pass++,cout<<"") : (fail++, cout << "Failed test: testMatrixMult" << endl);
cout << "Tests passed: " << pass << endl;
cout << "Tests failed: " << fail << endl;
}
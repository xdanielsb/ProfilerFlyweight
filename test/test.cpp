/**
    test.cpp
    Purpose: Create a bunch of soldiers to test 
             Flyweight design pattern.

    @author SANTOS Daniel, Quintana Gonzalo, Méry Andy
    @version 1.0 23/11/2019
*/
#define debug( x ) cout << #x << " = "<< x <<endl;
using namespace std;


const char* OP1 = "WITH_FLYWEIGHT";
const char* OP2 = "WITHOUT_FLYWEIGHT";

const int MAXS = (int)1e6;
const string COLOR = string(10, 'x');

namespace Test
{
  const char* BLUE = "BLUE";
  int i = 0;
  #include"../src/soldier.hpp"
  #include"../src/regular_soldier.hpp"

  long long memory_used = 0;
  void withFlyWeight()
  {
    log("\n\tExecuting code using FlyWeight Design Pattern:\n");
    ExtrinsicSoldier *ex = new ExtrinsicSoldier( BLUE ); 
    memory_used += ex->getSize();
    for( i = 0; i < MAXS ; i++)
    {
      Soldier<int> *e = nullptr;
      if( !(e = new Soldier<int>( i, i, ex)))
      {
        log("Error: out of memory creating the soldier %d \n", i);
        return;
      }
      memory_used += e->getSize() ;
      delete e;
    }

    log("\t\tTotal number of soldiers created %d\n", i);
    log("\t\tMemory used  = %lld bytes \n", memory_used);
    delete ex;
  }
  void withoutFlyWeight()
  {
    log("\n\tExecuting code without using FlyWeight Design Pattern:\n");
    for( i = 0; i < MAXS ; i++)
    {
      RSoldier<int> *e =  nullptr;
      if( !(e = new RSoldier<int>( i, i, COLOR)))
      {
        log("Error: out of memory creating the soldier %d \n", i);
        return;
      }
      memory_used += e->getSize();
      delete e;
    }
    log("\t\tTotal number of soldiers created %d\n", i);
    log("\t\tMemory used  = %lld bytes \n", memory_used);
  }
}


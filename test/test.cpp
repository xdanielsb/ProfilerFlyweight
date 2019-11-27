/**
    test.cpp
    Purpose: Create a bunch of soldiers to test 
             Flyweight design pattern.

    @author SANTOS Daniel, Quintana Gonzalo, Méry Andy
    @version 1.0 23/11/2019
*/
#define debug( x ) cout << #x << " = "<< x <<endl;
using namespace std;

namespace Test
{
  const int  SIZE_NAME_COLOR = 30000;
  const string COLOR_SOLDIER = string( SIZE_NAME_COLOR , 'h');
  /*
   * MAXS: int represents the total number of soldiers to create
   */
  static long long  MAXS = 1ll; 
  int i = 0;
  #include"../src/intrinsic_soldier.hpp"
  #include"../src/regular_soldier.hpp"

  unsigned long long memory_used = 0;
  void withFlyWeight()
  {
    log("\n\tExecuting code using FlyWeight Design Pattern:\n");
    
    shared_ptr<ExtrinsicSoldier> ex(new ExtrinsicSoldier( COLOR_SOLDIER ));
    
    memory_used += ex->getSize();
    for( i = 0; i < MAXS ; i++)
    {
      Soldier<int> *e;
      if( !( e = new Soldier<int>( i, i, ex) ) )
      {
        log("Error: out of memory creating the soldier %d \n", i);
        return;
      }
      memory_used += e->getSize() ;
      delete e;
    }

    log("\t\tTotal number of soldiers created = %d\n", i);
    log("\t\tMemory used  = %lld bytes \n", memory_used);
  }
  void withoutFlyWeight()
  {
    log("\n\tExecuting code without using FlyWeight Design Pattern:\n");
    for( i = 0; i < MAXS ; i++)
    {
      RSoldier< int> *e =  nullptr;
      if( !( e = new RSoldier< int>( i, i, COLOR_SOLDIER) ) )
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


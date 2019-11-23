#include<bits/stdc++.h>
#define log printf
#define debug( x ) cout << #x << " = "<< x <<endl;
using namespace std;


const char* OP1 = "WITH_FLYWEIGHT";
const char* OP2 = "WITHOUT_FLYWEIGHT";


const int MAXS = (int)1e6;
const string COLOR = string(10, 'x');

namespace Test{
  #include"src/soldier.hpp"
  #include"src/regular_soldier.hpp"
  long long memory_used = 0;
  void withFlyWeight(){
    log("\tExecuting code using FlyWeight Design Pattern.\n");
    ExtrinsicSoldier *ex = new ExtrinsicSoldier( COLOR ); 
    memory_used += ex->getSize();
    for( int i = 0; i < MAXS ; i++){
      Soldier *e =  new Soldier( i, i, ex);     
      memory_used += e->getSize() ;
      delete e;
    }
    log("\t\tMemory used  = %lld bytes \n", memory_used);
    delete ex;
  }
  void withoutFlyWeight(){
    log("\tExecuting code without using FlyWeight Design Pattern.\n");
    for( int i = 0; i < MAXS ; i++){
      RSoldier *e =  new RSoldier( i, i, COLOR);    
      memory_used += e->getSize();
      delete e;
    }
    log("\t\tMemory used  = %lld bytes \n", memory_used);
  }
}

int main( int argc, char *argv[] ){
  auto t1 = std::chrono::high_resolution_clock::now();
  if( argc <= 1){
    printf("You must specify an option to execute the programs, \
read the readme for more details.");
    return 0;
  }
  if( strcmp (argv[1], OP1) == 0){
    Test::withFlyWeight();
  }else if( strcmp (argv[1], OP2) == 0){
    Test::withoutFlyWeight();
  }else{
    log("Your option %s is not supported,\n\
the only options supported are:\n\
1- %s\n2- %s\n", argv[1], OP1, OP2);
  }
  auto t2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
  auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
  chrono::duration<long, std::micro> int_usec = int_ms;
  log("\t\tTime Consumed: %f ms\n", fp_ms.count());
  return 0;
}

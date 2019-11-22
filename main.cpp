#include<bits/stdc++.h>
using namespace std;
#include"soldier.hpp"
#include"regular_soldier.hpp"

const int MAXS = (int)1e6;


void withFlyWeight(){
  // Create the extrinsic Soldier
  ExtrinsicSoldier *ex = new ExtrinsicSoldier( "blue" );
  // create the soldiers  with Flyweight
  for( int i = 0; i < MAXS ; i++){
    Soldier *e =  new Soldier( i, i, ex);    
    delete e;
  }
  delete ex;
}

void withoutFlyWeight(){
    for( int i = 0; i < MAXS ; i++){
    RSoldier *e =  new RSoldier( i, i, "blue");    
    delete e;
  }

}


int main(){
  auto t1 = std::chrono::high_resolution_clock::now();
  
  if( 0){
    withFlyWeight();
  }else{
    withoutFlyWeight();
  }
  auto t2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
  auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
  chrono::duration<long, std::micro> int_usec = int_ms;
 
  cout  << fp_ms.count() << " ms" <<endl;
  return 0;
}

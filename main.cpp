#include<bits/stdc++.h>
#define debug( x ) cout << #x << " = "<< x <<endl;
using namespace std;
#include"soldier.hpp"
#include"regular_soldier.hpp"

const int MAXS = (int)1e6;


void withFlyWeight(){
  long long sc = 0;
  // Create the extrinsic Soldier
  ExtrinsicSoldier *ex = new ExtrinsicSoldier( "blue" ); 
  sc += ex->getSize();
  // create the soldiers  with Flyweight
  for( int i = 0; i < MAXS ; i++){
    Soldier *e =  new Soldier( i, i, ex);     
    sc += e->getSize() ;
    delete e;
  }
  
  cout << " Total memory consumed by Soldiers using FlyWeight = " << sc << " bytes " <<endl;
  delete ex;
}

void withoutFlyWeight(){
  long long sc = 0;
  for( int i = 0; i < MAXS ; i++){
    RSoldier *e =  new RSoldier( i, i, "blue");    
    sc += e->getSize();
    delete e;
  }

  cout << " Total memory consumed by Regular Soldiers  = " << sc << " bytes " <<endl;
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
 
  cout  << "Total time: " << fp_ms.count() << " ms" <<endl;
  return 0;
}

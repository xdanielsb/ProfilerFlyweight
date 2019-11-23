#ifndef CFSOLDIER
#define CFSOLDIER
class FactorySoldier{
  public:
  FactorySoldier(){}
  void createSoldier( int type ){
    if( type == 1){

    }else if ( type == 2){

    }else{
      assert( type > 2);
    }
  }
};
#endif

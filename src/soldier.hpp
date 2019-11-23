#include "extrinsic_soldier.hpp"
#ifndef CSOlDIER
#define CSOLDIER
class Soldier{
  private:
    int x;
    int y;
    ExtrinsicSoldier *ex;
  public:
    Soldier( int &_x, int &_y, ExtrinsicSoldier *_ex){
      this->x = _x;
      this->y = _y;
      this->ex = _ex;
    }
    ~Soldier(){}
    int getSize(){ 
      return sizeof( x ) + sizeof( y ) + sizeof( ex ) + sizeof( this );
    }
};
#endif

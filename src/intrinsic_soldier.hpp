#include "extrinsic_soldier.hpp"
#ifndef CSOlDIER
#define CSOLDIER
template <class T>
class Soldier
{
  private:
    T x;
    T y;
    ExtrinsicSoldier *ex;
  public:
    Soldier( T &_x, T &_y, ExtrinsicSoldier *_ex){
      this->x = _x;
      this->y = _y;
      this->ex = _ex;
    }
    ~Soldier(){}
    int getSize(){ 
      return sizeof( x ) + sizeof( y ) + sizeof(ex) + sizeof( this );
    }
};
#endif

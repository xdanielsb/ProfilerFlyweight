#include "extrinsic_soldier.hpp"
#ifndef CSOlDIER
#define CSOLDIER
template <class T>

/**
 *  The Soldier class which implements the intrisic behavior of the Flyweight Pattern Design.
 *  This object can compute its memory footprint with the getSize() method.
 */

class Soldier
{
  private:
    T x; ///< The position of the soldier on the x-axis. 
    T y; ///< The position of the soldier on the y-axis.
    shared_ptr<ExtrinsicSoldier> ex; ///< A pointer reference to the extrinsic_soldier. Allows access to the extrinsic properties.
  public:

    /**
     *  Constructor.
     *  @param _x x-axis position
     *  @param _y y-axis position
     *  @param _ex pointer reference to an extrinsic_soldier
     */
    Soldier( T &_x, T &_y, shared_ptr<ExtrinsicSoldier> _ex){
      this->x = _x;
      this->y = _y;
      this->ex = _ex;
    }

    /**
     *  Destructor
     */
    ~Soldier(){}

    /**
     *  Function which computes the memory footprint of the object.
     *  @return the amount of memory allocated to the object in bytes
     */
    int getSize(){ 
      return sizeof( x ) + sizeof( y ) + sizeof(ex) + sizeof( this );
    }
};
#endif

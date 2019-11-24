#ifndef CESOlDIER
#define CESOLDIER

/** 
 *  The ExtrinsicSoldier class which implements the exstrinsic behavior of the FlyWeight Pattern Design.
 *  This object can compute its memory footprint with the getSize() method.
 */

class ExtrinsicSoldier
{
  private:
    string color; ///< The color property is our extrinsic property.
  public:
  
  /**
   *  Constructor.
   *  @param _color any string of any length
   */
  ExtrinsicSoldier( const string &_color ): color(_color){}
  
  /**
   *  Destructor.
   */
  ~ExtrinsicSoldier(){}

  /**
   *  Function which computes the memory footprint of the object.
   *  @return the amount of memory allocated to the object in bytes
   */
  int getSize( )
  {
    return sizeof( this ) + color.size();
  }
};

#endif

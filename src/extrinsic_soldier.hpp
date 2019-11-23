#ifndef CESOlDIER
#define CESOLDIER
class ExtrinsicSoldier
{
  private:
    string color;
  public:
  ExtrinsicSoldier( const string &_color ): color(_color){}
  ~ExtrinsicSoldier(){}
  int getSize( )
  {
    return sizeof( this ) + color.size();
  }
};
#endif

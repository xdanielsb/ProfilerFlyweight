#ifndef CRSOlDIER
#define CRSOLDIER
class RSoldier{
  private:
    int x;
    int y;
    string color;
  public:
    RSoldier( int &_x, int &_y, string _color){
      this->x = _x;
      this->y = _y;
      this->color = _color;
    }
    ~RSoldier(){}
    int getSize(){ 
      return sizeof( x ) + sizeof( y ) + sizeof( color ) + sizeof( this );
    }
};
#endif

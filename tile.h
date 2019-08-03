#ifndef TILE_H
#define TILE_H
#include<QObject>
#include<QtWidgets/QPushButton>
class Tile: public QPushButton{
    Q_OBJECT
public:
    int getNumber();
    Tile(int tileNumber=0);
private:
    int m_Number;
};
#endif // TILE_H

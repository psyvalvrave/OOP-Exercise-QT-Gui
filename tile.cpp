#include<tile.h>
#include<QString>
#include<QtWidgets/QMainWindow>
Tile::Tile(int tileNumber):m_Number(tileNumber){
}
int Tile::getNumber(){
    return m_Number;
}

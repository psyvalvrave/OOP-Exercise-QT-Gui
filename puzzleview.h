#ifndef PUZZLEVIEW_H
#define PUZZLEVIEW_H
#include<QtWidgets>
#include<QtWidgets/QGridLayout>
#include<QtWidgets/QButtonGroup>
#include<puzzlemodel.h>
#include<tile.h>
class PuzzleView: public QWidget{
    Q_OBJECT
    PuzzleModel* m_Model;
    QGridLayout* m_Layout;
    QButtonGroup m_buttons;
public:
    PuzzleView(PuzzleModel * PuzzleModel, QWidget *parent = nullptr);
    int const TOTAL_SIZE = m_Model->m_Cols*m_Model->m_Rows;
    void basicSet();
public slots:
    void tryToSlide(QAbstractButton* button);
    void refresh();
    void ezW();
};



#endif // PUZZLEVIEW_H

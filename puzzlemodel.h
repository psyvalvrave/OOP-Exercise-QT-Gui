#ifndef PUZZLEMODEL_H
#define PUZZLEMODEL_H
#include<QList>
class PuzzleModel: public QObject{
public:
    PuzzleModel(QObject* parent=0);
    int value(int r, int c);
    bool slide(int tilenum);
    bool neighboring(int r, int c);
    bool orderCheck();
    int m_Rows=4;
    int m_Cols=4;
    QList<int> m_Positions;
    void ezWin();
public slots:
    void shuffle();
signals:
    void gridChanged();

};
#endif // PUZZLEMODEL_H

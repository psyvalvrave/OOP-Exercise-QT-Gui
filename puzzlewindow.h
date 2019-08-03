#ifndef PUZZLEWINDOW_H
#define PUZZLEWINDOW_H
#include<QtWidgets/QMainWindow>
#include<puzzlemodel.h>
#include<puzzleview.h>
class PuzzleWindow: public QMainWindow{
public:
    PuzzleWindow(QWidget *parent = 0);
};
#endif // PUZZLEWINDOW_H

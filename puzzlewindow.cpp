#include<puzzlewindow.h>

PuzzleWindow::PuzzleWindow(QWidget *parent):QMainWindow(parent){
    PuzzleModel* model = new PuzzleModel();
    PuzzleView *view  = new PuzzleView(model);
    view->show();
}

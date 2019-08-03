#include<puzzleview.h>
#include<QtWidgets/QMessageBox>

PuzzleView::PuzzleView(PuzzleModel *model, QWidget *parent):QWidget(parent),m_Model(model){
    m_Layout = new QGridLayout(this);
    Tile* tile(0);
    for(int i = 0;i<TOTAL_SIZE;i++){
        tile = new Tile(i);
        m_buttons.addButton(tile);
    }
    basicSet();
    refresh();
    connect(&m_buttons,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(tryToSlide(QAbstractButton*)));

}


void PuzzleView::tryToSlide(QAbstractButton *button){
    Tile* til = qobject_cast<Tile*>(button);
    int number = til->getNumber();
    m_Model->slide(number);
    basicSet();
    if(m_Model->orderCheck()){
        QMessageBox mbox;
        mbox.setText("You win!");
        mbox.exec();
    }
}

void PuzzleView::refresh(){
    for(int i=0;i<100;i++){
        int rand1 = rand()%TOTAL_SIZE;
        int rand2 = rand()%TOTAL_SIZE;
        this->m_Model->m_Positions.swap(rand1,rand2);
    }
    basicSet();

}

void PuzzleView::ezW(){
    m_Model->ezWin();
    basicSet();
}

void PuzzleView::basicSet(){
    QList<QAbstractButton*> list = m_buttons.buttons();
    for(int r=1;r<=m_Model->m_Rows;++r){
        for(int c=1;c<=m_Model->m_Cols;++c){
            int v = m_Model->value(r,c);
            QAbstractButton *b = list.at(v);
            if(v!=0){
                b->setText(QString::number(v));
            }
            else{
                b->setVisible(false);
            }
            m_Layout->addWidget(b,r,c);
        }
    }
    QPushButton *shuffle = new QPushButton("Shuffle");
    QPushButton *quit = new QPushButton("Quit");
    m_Layout->addWidget(shuffle,m_Model->m_Rows-1,m_Model->m_Cols+1);
    m_Layout->addWidget(quit,m_Model->m_Rows,m_Model->m_Cols+1);
    connect(shuffle,SIGNAL(clicked()),this,SLOT(refresh()));
    connect(quit,SIGNAL(clicked()),QApplication::instance(),SLOT(quit()));
    QPushButton *ezWin = new QPushButton("ezWin");
    m_Layout->addWidget(ezWin,m_Model->m_Rows-2,m_Model->m_Cols+1);
    connect(ezWin,SIGNAL(clicked()),this,SLOT(ezW()));
}

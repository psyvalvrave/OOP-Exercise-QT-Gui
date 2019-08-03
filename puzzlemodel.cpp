#include<puzzlemodel.h>
#include<stdlib.h>
PuzzleModel::PuzzleModel(QObject *parent):QObject(parent){
    for(int r=0;r<m_Rows*m_Cols;r++){
            m_Positions.append(r);
    }
    shuffle();
}

int PuzzleModel::value(int r, int c){
    return m_Positions[(m_Rows*(r-1)+c-1)];
}
bool PuzzleModel::neighboring(int r, int c){
    if(r==1){
        if(c==1){
            return ((value(r+1,c)==0)||(value(r,c+1)==0));
        }
        if(c==4){
            return ((value(r,c-1)==0)||(value(r+1,c)==0));
        }
        else{
            return ((value(r,c-1)==0)||(value(r+1,c)==0))||(value(r,c+1)==0);
        }
    }
    if(r==4){
        if(c==1){
            return ((value(r-1,c)==0)||(value(r,c+1)==0));
        }
        if(c==4){
            return ((value(r,c-1)==0)||(value(r-1,c)==0));
        }
        else{
            return ((value(r,c-1)==0)||(value(r-1,c)==0))||(value(r,c+1)==0);
        }
    }
    else{
        if(c==1){
            return ((value(r-1,c)==0)||(value(r,c+1)==0))||(value(r+1,c)==0);
        }
        if(c==4){
            return ((value(r-1,c)==0)||(value(r,c-1)==0))||(value(r+1,c)==0);
        }
        else{
            return ((value(r-1,c)==0)||(value(r,c-1)==0))||(value(r+1,c)==0)||(value(r,c+1)==0);
        }
    }
}

bool PuzzleModel::slide(int tilenum){
    int i = m_Positions.indexOf(tilenum);
    int c = i+1-m_Rows*((i/m_Rows+1)-1);
    if(neighboring(i/m_Rows+1,c)){
        m_Positions.swap(m_Positions.indexOf(0),i);
        return true;
    }
    return false;
}

void PuzzleModel::shuffle(){
    srand(time(NULL));
    for(int i=0;i<100;i++){
        int r = rand()%this->m_Positions.size();
        int s = rand()%this->m_Positions.size();
        this->m_Positions.swap(r,s);
    }

}

bool PuzzleModel::orderCheck(){
    for(int a=0;a<m_Positions.size()-1;a++){
        if(m_Positions[a]!=a+1){
            return false;
        } 
    }
    return true;
}

void PuzzleModel::ezWin(){
    for(int i=0;i<m_Rows*m_Cols-1;i++){
        m_Positions[i]=i+1;
    }
    m_Positions[m_Rows*m_Cols-1]=0;
}

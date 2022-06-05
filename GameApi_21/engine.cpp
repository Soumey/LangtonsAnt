#include "engine.h"

//======================================================================
// Implementacja klasy Engine:

Engine::Engine(int nnw, int nnk) : nw(nnw), nk(nnk)
{
   int i;
   T = new int* [nw];
   for(i=0; i<nw; i++)
      T[i] = new int [nk];
   for(int i=0; i<nw; i++)
      for(int j=0; j<nk; j++) {
         T[i][j] = 0;
      }
}
//----------------------------------------------------------------------
void Engine::Init(const char wz[])
{
}
//----------------------------------------------------------------------
void Engine::turnRight()
{
    dir++;
    if(dir>antleft)
    {
        dir=antup;
    }

}
//----------------------------------------------------------------------
void Engine::turnLeft()
{
 dir--;
    if(dir<antup)
    {
        dir=antleft;
    }
}
//----------------------------------------------------------------------
void Engine::moveForward()
{
 if(dir==antup){
    y--;
 }else if(dir==antright){
    x++;
 }else if(dir==antdown){
    y++;
 }else if(dir==antleft){
    x--;
 }
 if (x>nw){
    x=0;
 }else if(x<0){
 x=nw-1;
 }

 if (y>nk){
    y=0;
 }else if(y<0){
 x=nk-1;
 }

}
//----------------------------------------------------------------------
void Engine::Analiza()
{

    int state=T[x][y];
    if (state == 0)
    {
        turnRight();
        T[x][y]=1;
        moveForward();

    }else if(state==1)
    {
        turnLeft();
        T[x][y]=0;
        moveForward();

    }

}

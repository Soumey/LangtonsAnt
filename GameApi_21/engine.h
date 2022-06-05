#ifndef ENGINE_H
#define ENGINE_H

//======================================================================
class Engine
{
   protected:
      int nw, nk;
      int x=49;
      int y=24;
      int dir=0;
      const static int antup=0;
      const static int antright=1;
      const static int antdown=2;
      const static int antleft=3;

      int **T;
   protected:
      Engine(int nnw, int nnk);
      void turnRight();
      void turnLeft();
      void moveForward();
      virtual ~Engine() {
      for(int i{};i<nw;i++){
        delete []T[i];
      }
      delete[] T;
      }
      void Init(const char wz[]);
      void Analiza();
   private:
      Engine(const Engine& e);
      Engine& operator=(const Engine& e);
};
//----------------------------------------------------------------------

#endif

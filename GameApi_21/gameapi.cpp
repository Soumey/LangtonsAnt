#include "gameapi.h"

//----------------------------------------------------------------------
GameApi::GameApi(int nnw, int nnk) : Game(nnw, nnk)
{ }
//----------------------------------------------------------------------
void GameApi::View()
{
//   InvalidateRect(_hwnd, NULL, true);
   for(int i=0; i<nw; i++) {
      for(int j=0; j<nk; j++) {

         if(T[i][j]) (HBRUSH)::SelectObject( _hdc, _BgBrush );
         else (HBRUSH)::SelectObject( _hdc, _MyBrush );

         Rectangle( _hdc, i*dx, j*dy, i*dx+dx, j*dy+dy );
//         Ellipse( _hdc, i*dx, j*dy, i*dx+dx, j*dy+dy );
      }
   }
}
//----------------------------------------------------------------------
void GameApi::InitApi(HWND hwnd)
{
// 5. Brush
   _hwnd = hwnd;
   _hdc = GetDC( _hwnd );
   _MyBrush = ::CreateSolidBrush(0x00FFFFFF);
   _BgBrush = ::CreateSolidBrush(0x00F00F0F);
//   _BgBrush = (HBRUSH)::SelectObject( _hdc, WHITE_BRUSH );
}

GameApi::~GameApi()
{
//   ::DeleteObject( _MyBrush );
//   ::DeleteObject( _BgBrush );
}
//======================================================================

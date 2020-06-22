#include "./includes/mgame.h"
#include "./includes/mplayer.h"

#include <SFML/Graphics.hpp>



const int FPS = 60 ;
const double DELTA_TIME = double(1)/double(FPS);

int main()
{
    
    mgame maingame;
    maingame.initialize();
    maingame.run();
    
      
  
    return 0;
}

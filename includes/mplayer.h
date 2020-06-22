#ifndef MPLAYER_H
#define MPLAYER_H

#include<SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
class mplayer
{
private:
    void mmove();
    float x_pos;
    float y_pos;
    int height;
    int width;
    float velocity;
    int disp_x;
    int disp_y;
    sf::Sprite psprite;
    
    
public:
    mplayer(int x,int y,int h,int w);
    mplayer(sf::Texture &mtexture);
    mplayer();
    ~mplayer();
     
     int update(sf::Event &mevent);
     int settexture(sf::Texture &gtexture);
     sf::Sprite &get_sprite();
    
};

#endif

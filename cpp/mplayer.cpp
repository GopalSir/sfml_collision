#include "../includes/mplayer.h"



void mplayer::mmove()
{
   
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
     x_pos-=velocity;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
     x_pos+=velocity;

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
     y_pos-=velocity;

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
     y_pos+=velocity;

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
     ++velocity;

     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
     --velocity;
     
     psprite.setPosition(x_pos,y_pos);
    

};

int mplayer::update(sf::Event &event)
{
   if(event.type == sf::Event::KeyPressed)
    mmove();
}

mplayer::mplayer(int x,int y,int w,int h)
{
   psprite.setPosition(sf::Vector2f(x,y));
   //player.setOrigin(sf::Vector2f(w/2,h/2));
   psprite.setColor(sf::Color::Blue);
}

mplayer::mplayer(sf::Texture &mtexture)
{
    psprite.setTexture(mtexture);
    //psprite.setTextureRect(sf::IntRect(0,0,200,300));
    //psprite.setPosition(0,0);
    ;    
}

mplayer::mplayer()
{
    // psprite.setColor(sf::Color::Blue);
     psprite.setScale(1,1);
     velocity= 1.0f;
}


sf::Sprite &mplayer::get_sprite()
{
    return psprite;
}

int mplayer::settexture(sf::Texture &gtexture)
{
    psprite.setTexture(gtexture);
}

mplayer::~mplayer()
{

}
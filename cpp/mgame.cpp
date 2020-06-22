#include "../includes/mgame.h"
#include <iostream>


mgame::mgame(sf::String window_name)
{
    gwindow = new sf::RenderWindow(sf::VideoMode(800,400),window_name);
    
}
mgame::mgame()
{
    gwindow = new sf::RenderWindow(sf::VideoMode(800,400),"Default Window");
    game_ps= particle_system(1000,gwindow->getSize().x,gwindow->getSize().y);
    tempshape.setRadius(100);
    game_ps.setradius(0.1f);
    

}

void mgame::initialize()
{
    // calling constructor of particle system
    
    game_shapes.resize(game_ps.pno_of_particles());
     for(int i=0;i<game_ps.pno_of_particles();++i)
     {
         game_shapes[i].setRadius((float)(game_ps.getradius()));
         game_shapes[i].setOrigin(game_shapes[i].getRadius()/2,game_shapes[i].getRadius()/2);
         game_shapes[i].setFillColor(sf::Color::Green);
     }
    // now set_size of the particles
    //20 pixels for now
    
    
    //now particles are set to go and be updated with each game loop 
     gclock.restart();
}

void mgame::run()
{
    
     while(gwindow->isOpen())
     {
         
         update();
         render();
     }
}

void mgame::render()
{
    gwindow->clear();
    //  sprites and assign position from particle.getparticles()
   for(int i=0;i<game_ps.pno_of_particles();++i)
   {   
       gameparticles = game_ps.getparticles();
       game_shapes[i].setPosition(gameparticles[i].px,gameparticles[i].py);
       gwindow->draw(game_shapes[i]);
   }

   
   //gwindow->draw(tempshape);
   gwindow->display();
  
   
   
}

void mgame::update()
{
    while (gwindow->pollEvent(event))
    {
        switch (event.type)
    {
       case sf::Event::Closed :
            gwindow->close();  
            break;        
    }

    }
    
    
    
    deltatime = gclock.restart();
    game_ps.pupdate(deltatime.asSeconds()*20.0f);
   
    
    
}

bool mgame::windowopen()
{
    return gwindow->isOpen();
}
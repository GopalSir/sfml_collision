#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "./mplayer.h"
#include "./particle.h"
#include <vector>

constexpr float GRAVITY = 9.8;

class mgame{
    private:
    bool isPaused;
    sf::RenderWindow *gwindow;
    // this game's particle system
    particle_system game_ps;
    sf::Event event;
    std::vector<sf::CircleShape>game_shapes;
    sf::Clock gclock;
    sf::Time deltatime;
    std::vector<pstruct> gameparticles;

    sf::CircleShape tempshape;
    
    public:
        mgame(sf::String window_name);
        mgame();
        void initialize();
        void run();
        void update();
        void render();
        void addobject();
        bool windowopen();
};

#endif 
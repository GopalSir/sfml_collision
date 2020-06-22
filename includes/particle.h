#ifndef PARTICLE_H
#define PARTICLE_H
#include <SFML/Graphics.hpp>
#include <algorithm>
#include<ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iostream>
struct pstruct
{
    
    float vx;
    float vy;
    float px;
    float py;  

};

// contains and updates particles and returns state of each particle as pointer to 
//vector . Requires the boundary of window to simulate a box;
class particle_system
{
    public:
    // number of initial particles
    particle_system(int noip,int w_width,int w_height);   

     //default constructor
    particle_system() ;

    //needs to be called every physics update tick
    void pupdate(float deltatime);  

    //will return an arry of pstruct to draw be drawn by window
     std::vector<pstruct> getparticles();

     // get number of particles

     int pno_of_particles();

     float setradius(float s);     
     float getradius(); 
        
    private:

       int pheight;  // width of window
       int pwidth;   //height of window
       int pnoip;    // particles number of particles
       float pradius;
       
    // called to see if any two particles are in coliding stage with 
    //each other or the walls
    void pcheckcollision(int i,int j);
    void pcheckwall(int i);
    void dampvelocity(float &particle_velocity);
    std::vector<pstruct> particles;
    // container for all the particles
        
 
    

    
    

    

};

#endif //PARTICLE_H

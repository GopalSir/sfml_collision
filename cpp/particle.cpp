#include "../includes/particle.h"

// need the bounds to not exceed window boundary
particle_system::particle_system(int noip,int w_width,int w_height)
{
    srand(time(NULL));
    pnoip  =  noip;
    pwidth = w_width;
   pheight = w_height;
    int a=0,b=0,c=0,d=0;
    // populate the particles
    particles.resize(1);
    particles.clear();
    for(int i=0;i<noip;++i)
    {
        a=rand()%30;
        b=rand()%30;
        c=rand()%w_width;
        d=rand()%w_height;
        
        pstruct tempstruct;
        tempstruct.vx= float(a);
        tempstruct.vy= float(b);
        tempstruct.px= float(c);
        tempstruct.py= float(d);

        particles.push_back(tempstruct);
        
    }
}
 // default constructor pupulates with random values of noip and window width
 // height
particle_system::particle_system()
{
    const int noip = 30;
    pnoip = noip;
    const int w_width = 800;
    const int w_height = 400;
    pwidth = w_width;
    pheight = w_height; 

     srand(time(NULL));

    int a=0,b=0,c=0,d=0;
    // populate the particles
    particles.resize(1);
    particles.clear();
    for(int i=0;i<noip;++i)
    {
        a=rand()%30;
        b=rand()%30;
        c=rand()%w_width;
        d=rand()%w_height;


        pstruct tempstruct;
        tempstruct.vx= float(a);
        tempstruct.vy= float(b);
        tempstruct.px= float(c);
        tempstruct.py= float(d);

        particles.push_back(tempstruct);
        
    }

}

void particle_system::pcheckcollision(int i,int j)
{
    // if distance between centers is less than radii added together
    float dx = particles[i].px - particles[j].px;
    float dy = particles[i].py - particles[j].py;

    float cdist = sqrt( pow(dx,2) + pow(dy,2)   );
    //collision found
    if(cdist<=(2*pradius))
    {
        //now exchange the velocities
        std::swap(particles[i].px,particles[j].px);
        std::swap(particles[i].py,particles[j].py);
        
        
        dampvelocity(particles[i].vx);

        
        dampvelocity(particles[i].vy);

        
        dampvelocity(particles[j].vx);

        dampvelocity(particles[j].vy);
    }

    
    
}

void particle_system::pcheckwall(int i)
{
    // now check for 4 walls and flip the velocity accordingly
     // upper wall collide if px < radius
     //upper and lower collision are mutually exclusive so can be put in if else
     if(particles[i].py < pradius)
     {
         //flip y velocity
         particles[i].vy=-particles[i].vy;
         dampvelocity(particles[i].vx);
     }
     else if(  (pheight - particles[i].py) < pradius)
     {
         //flip y velocity
         particles[i].vy=-particles[i].vy;
         dampvelocity(particles[i].vx);
     }

        // left and right collisons are mutually exclusive so can be put in if else
      if( (pwidth -  particles[i].px) < pradius)
     {
         //flip y velocity
         particles[i].vx=-particles[i].vx;
         dampvelocity(particles[i].vy);
     }
     else if(particles[i].px < pradius)
     {
         //flip y velocity
         particles[i].vx=-particles[i].vx;
         dampvelocity(particles[i].vy);
     }
}

void particle_system::pupdate(float timestep)
{
   for(int i=0;i<pnoip;++i)
   {
       pcheckwall(i);
       for(int j=i+1;j<pnoip;++j)
       {
          pcheckcollision(i,j);      
       }
   }
    // now increment the px and py of all particles by given timestep
    for(int i=0;i<pnoip;++i)
    {
        particles[i].px+= particles[i].vx *timestep;
        particles[i].py+= particles[i].vy *timestep;
    }

}

std::vector<pstruct> particle_system::getparticles()
{
    return particles;
   
}

float particle_system::setradius(float s)
{
   pradius = s;
}


int particle_system::pno_of_particles()
{
    return pnoip;
}

float particle_system::getradius()
{
    return pradius;
}

void particle_system::dampvelocity(float &particle_velocity)
{
    particle_velocity=particle_velocity*(0.99f);
}

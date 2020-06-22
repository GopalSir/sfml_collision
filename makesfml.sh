#!/bin/sh

g++ -g -L /usr/lib/x86_64-linux-gnu comp.cpp ./cpp/mplayer.cpp ./cpp/mgame.cpp ./cpp/particle.cpp  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
echo indu game ban gaya
./a.out
exit 0

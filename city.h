#ifndef CITY_H
#define CITY_H

#include <string>
#include <iostream>
using namespace std;

class City{
  public:
    City();

    //desc: checks randomly for an empty slot in the city array 
    //pre: none
    //post: outputs a two digit number used to determine the coordinates
    int generateOpenPos();

    //desc: places the jewels in the city array
    //pre: none
    //post: saves the jewel positions
    void placeJewels();

    //desc: prints the whole city array
    //pre: none
    //post: outputs a 10 by 10 city array
    void printCity();

    //desc: places the robbers in the city array
    //pre: none
    //post: saves the robber positions
    void placeRobbers();

    //desc: places any object in the city like a robber
    //pre: the x position, y position, and the object
    //post: places desired object
    void placeObj(const int x, const int y, char object);

    //desc: returns the char in the city slot
    //pre: the x and y coord
    //post: returns what is at that position
    char getCity(int x, int y);

    
    char m_cityGrid[10][10];    
    //int getCityGrid() {return m_cityGrid[10][10];}
  private:
    int m_jewels = 47; 
};


#endif
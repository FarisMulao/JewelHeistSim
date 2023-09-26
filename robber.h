#ifndef ROBBER_H
#define ROBBER_H
#include <iostream>
using namespace std;


template <class T>
class Robber{
  private:
    int m_jewelCount = 0;
    int m_id;
    int m_xPos;
    int m_yPos;
    T m_bag[17];
    int m_worth = 0;
    bool m_active = 1;
    bool m_greedy = 1;
  public:
    //desc:checks if there is room in the bag and then adds the jewel to the bag
    //pre: needs loot to pick up
    //post: puts loot in bag and returns nothing
    void pickUpLoot(T jewel);

    //desc:randomly moves the robber
    //pre: none
    //post: moves the robber into a valid position
    void move();

    //desc: gets the x coordinate of the robber
    //pre: none
    //post: returns xPos
    int getXPos() const {return m_xPos;}

    //desc: gets the y coordinate of the robber
    //pre: none
    //post: returns yPos
    int getYPos() const {return m_yPos;}

    //desc: shows the id of the robber
    //pre: none
    //post: returns the robber id
    int getID() const {return m_id;}

    //desc: sets the position of the robber
    //pre: desired x and y coordinate
    //post: returns nothing and sets the robbers xPos and yPos
    void setPos(int x, int y);

    //desc: sets the id of the robber
    //pre: a desired id
    //post: returns nothing and sets the robber id
    void setID(int id);

    //desc: makes robber ordinary instead of greedy
    void setOrd();

    //desc: returns the jewelCount 
    int getJCount() const {return m_jewelCount;}

    //desc: returns the worth of the jewels
    int getJWorth() const {return m_worth;}

    //desc: decided how the greedy robber moves
    //pre: the city array and the object it moves towards
    //post: moves the greedy robber towards the desired object
    void greedyMove(char cityArr[][10], char obj);

    //desc: returns whether or not the robber is active/not arrested
    bool getActive() const {return m_active;}

    //desc: empties jewel bag
    //pre: none
    //post: the array of jewels becomes empty
    void loseJewels();

    //desc: checks whether or not the jewel bag is full
    //pre: none
    //post: returns 1 if full and 0 if not
    bool bagFull();

    //desc: loses half of the jewels in the current bag
    //pre: none
    //post: gets rid of top half of jewels in jewel bag
    void loseHalf();

};

#include "robber.hpp"
#endif
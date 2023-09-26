#ifndef POLICE_H
#define POLICE_H

class Police{
  public:

    //desc: takes an int and updates jewel count and robber caught count
    //pre: takes an int
    //post: updates jewel count and robber count
    void arrest(int worth);

    //desc: determines available directions to move and moves in that direction
    //pre: N/A
    //post: changes officer position
    void move();

    //desc: returns the police x position
    int getXPos() const {return m_xPos;}

    //desc: returns the police y position 
    int getYPos() const {return m_yPos;}

    //desc: sets the coords of the police
    //pre: x and y coords
    //post: changes the police coords
    void setPos(int x, int y);

    //desc: returns the number of jewels
    int getCount() const {return m_jCount;}

    //desc: police take the jewel so robbers cant
    //pre: value of the jewel
    //post: takes the jewel off of the board 
    void grabJewel(int amount);

    //desc: returns number of robbers caught
    int getRCaught() const {return m_rCaught;};
    
    
  private:
    int m_id = 1, m_xPos, m_yPos, m_jCount = 0, m_rCaught = 0;
};


#endif
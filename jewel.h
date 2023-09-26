#ifndef JEWEL_H
#define JEWEL_H

class Jewel{
  public:

    //desc: sets position of jewel
    //pre: int x and y or within city grid array range
    //post: updates location of specific object in jewel class
    void setPos(const int x, const int y);

    //desc: returns private x position of jewel class
    //pre: N/A
    //post: returns x position
    int getXPos() const {return m_xPos;}

    //desc: returns private y position of jewel class
    //pre: N/A
    //post: returns y position
    int getYPos() const {return m_yPos;}

    //desc: sets value of private integer to given int
    //pre: N/A
    //post: updates m_value
    void setValue(int a);

    //desc: returns private value of object in jewel class
    //pre: N/A
    //post: returns value position
    int getValue() const {return m_value;}

  private:
    int m_value = 0; 
    int m_xPos; 
    int m_yPos;
};



#endif
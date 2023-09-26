#include <string>
#include <iostream>
using namespace std;
#include "police.h"


void Police::move(){
  int place = rand() % 8;
  switch(place){
    case 0:
      if(m_xPos - 1 >= 0 && m_yPos - 1 >= 0){
        --m_xPos;
        --m_yPos;
      }
      else{
        return;
      }
      break;
    case 1:
      if(m_yPos - 1 >= 0){
        --m_yPos;
      }
      else{
        return;
      }
      break;
    case 2:
      if(m_xPos + 1 < 10 && m_yPos - 1 >= 0){
        ++m_xPos;
        --m_yPos;
      }
      else{
        return;
      }
      break;
    case 3:
      if(m_xPos - 1 >= 0){
        --m_xPos;
      }
      else{
        return;
      }
      break;
    case 4:
      if(m_xPos + 1 < 10){
        ++m_xPos;
      }
      else{
        return;
      }
      break;
    case 5:
      if(m_xPos - 1 >= 0 && m_yPos + 1 < 10){
        --m_xPos;
        ++m_yPos;
      }
      else{
        return;
      }
      break;
    case 6:
      if(m_yPos + 1 < 10){
        ++m_yPos;
      }
      else{
        return;
      }
      break;
    case 7:
      if(m_xPos + 1 < 10 && m_yPos + 1 < 10){
        ++m_xPos;
        ++m_yPos;
      }
      else{
        return;
      }
      break;
  }
  return;
};


void Police::arrest(int worth){
  m_jCount += worth;
  m_rCaught += 1;
};

void Police::setPos(int x, int y){
  m_xPos = x;
  m_yPos = y;
}

void Police::grabJewel(int amount){
  m_jCount += amount;
}


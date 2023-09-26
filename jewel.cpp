#include <string>
#include <iostream>
using namespace std;
#include "jewel.h"

void Jewel::setPos(const int x, const int y){
  m_xPos = x;
  m_yPos = y;
}

void Jewel::setValue(int a){
  m_value = a;
}


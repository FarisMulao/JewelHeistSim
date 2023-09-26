//Programmers: David Myers and Faris Mulaosmanovic
//File: city.cpp

#include <string>
#include <iostream>
using namespace std;
#include "city.h"
#include "robber.h"

City::City(){
  for(int i = 0; i < 10; i++){
    for(int k = 0; k < 10; k++){
      m_cityGrid[i][k] = ' ';
    }
  }
}

//Desc: Always returns a two double int the is equivalent to the x and y location of a free position of the city grid
//Pre: m_cityGrid
//Post: returns a two digit number the tens place being the x variable and the ones place being the y variable
int City::generateOpenPos(){
  int openPos, rX, rY;
  do{
    rX = rand() % 10;
    rY = rand() % 10;
    if(m_cityGrid[rX][rY] == ' '){
      openPos = rX*10 + rY;
      return openPos;
    }
  }while (m_cityGrid[rX][rY] != ' ');
  return ' ';
}


//works
void City::printCity(){
  for(int i = 0; i < 10; i++){
    cout << "\n-----------------------------------------\n| ";
    for(int j = 0; j < 10; j++){
      cout << m_cityGrid[j][i] << " | ";
    }
  }
  cout << "\n-----------------------------------------\n\n\n";
};


//works
void City::placeJewels(){
  for(int i = 0; i < m_jewels; i++){
    int a = generateOpenPos();
    m_cityGrid[a / 10][a % 10] = 'J';
  }
};


//works
void City::placeObj(const int x, const int y, char object){
  m_cityGrid[x][y] = object;
  return; 
}

char City::getCity(int x, int y){
  return m_cityGrid[x][y];
}



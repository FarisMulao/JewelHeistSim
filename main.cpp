//Programmers: David Myers and Faris Mulaosmanovic
//File: main.cpp
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
#include "jewel.h"
#include "city.h"
#include "robber.h"
#include "police.h"

int main() {

  //set random seed to 85
  srand(85);

  Jewel jewels[47];
  City city;
  Robber<Jewel> robbers[4];
  Police officer;
  int tempX, tempY, temp, coords[2], turn = 1, JVal = 0;
  bool continueGame = 1;
  int foundJewel;


  city.placeJewels();

  
  
  for(int i = 0; i < 4; i++){
    temp = city.generateOpenPos();
    if(i < 2){
      robbers[i].setOrd();
    }
    robbers[i].setID(i+1);
    robbers[i].setPos(temp/10,temp%10);
    city.placeObj(robbers[i].getXPos(), robbers[i].getYPos(), 'r');
  }

  temp = city.generateOpenPos();
  officer.setPos(temp/10,temp%10);
  city.placeObj(officer.getXPos(), officer.getYPos(), 'P');

  city.printCity();


  int a = 0;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(city.getCity(i, j) == 'J'){
        jewels[a].setPos(i,j);
        jewels[a].setValue(i+j+2);
        a++;
      }
    }
  }


int totalWorth;

  do{
    totalWorth = 0;
    
    //repeated code goes here
    for(int i = 0; i < 2; i++){ //moves ordinary robbers first
      if(robbers[i].getActive() == 1){
        do{
          tempX = robbers[i].getXPos();
          tempY = robbers[i].getYPos();
          robbers[i].move();
        }while(tempX == robbers[i].getXPos() && tempY ==  robbers[i].getYPos());

        //cout << tempX << ", " << tempY << "\n";
        //cout << robbers[i].getXPos() << ", " << robbers[i].getYPos() << "\n\n";

        //runs into officer
        if(city.getCity(robbers[i].getXPos(), robbers[i].getYPos()) == 'P'){
          officer.arrest(robbers[i].getJWorth());
          robbers[i].loseJewels();
          
        }

        //runs into jewel
        for(int j = 0; j < 47; j++){
          if((robbers[i].getXPos() == jewels[j].getXPos()) && (robbers[i].getYPos() == jewels[j].getYPos())){
            robbers[i].pickUpLoot(jewels[j]);
            city.placeObj(robbers[i].getXPos(), robbers[i].getYPos(), 'r');
          }
        }

        //runs into robber
        
        for(int j = 0; j < 4; j++){
          if((robbers[i].getXPos() == robbers[j].getXPos()) && (robbers[i].getYPos() == robbers[j].getYPos()) && (robbers[i].getID() != robbers[j].getID()) && (robbers[j].getActive() == 1)){
            city.placeObj(robbers[i].getXPos(), robbers[i].getYPos(), 'R');
          }
        }
        

        //runs into nothing
        if(city.getCity(robbers[i].getXPos(), robbers[i].getYPos()) == ' '){
          city.placeObj(robbers[i].getXPos(), robbers[i].getYPos(), 'r');
        }

        //position left
        if(city.getCity(tempX, tempY) == 'R'){
          city.placeObj(tempX, tempY, 'r');
        } else {
          city.placeObj(tempX, tempY, ' ');
        }
      }
    }




    int foundJewel;
    
    for(int i = 2; i < 4; i++){ //moves greedy robbers second
      do{
        foundJewel = 0;
        if(robbers[i].getActive() == 1){
          tempX = robbers[i].getXPos();
          tempY = robbers[i].getYPos();
          robbers[i].greedyMove(city.m_cityGrid, 'J');

          
            if(robbers[i].bagFull()){
              robbers[i].greedyMove(city.m_cityGrid, 'P');
            }
          
            //runs into officer
            if(city.getCity(robbers[i].getXPos(), robbers[i].getYPos()) == 'P'){
              officer.arrest(robbers[i].getJWorth());
              robbers[i].loseJewels();
              foundJewel = 0;
            }  
          
          //runs into robber
          if((city.getCity(robbers[i].getXPos(), robbers[i].getYPos()) == 'r') || (city.getCity(robbers[i].getXPos(), robbers[i].getYPos()) == 'R')){
            robbers[i].loseHalf();
            city.placeObj(robbers[i].getXPos(), robbers[i].getYPos(), 'R');
          }

          //runs into nothing
            if(city.getCity(robbers[i].getXPos(), robbers[i].getYPos()) == ' '){
              city.placeObj(robbers[i].getXPos(), robbers[i].getYPos(), 'r');
              foundJewel = 0;
            }

          //runs into jewel
          for(int j = 0; j < 47; j++){
            if((robbers[i].getXPos() == jewels[j].getXPos()) && (robbers[i].getYPos() == jewels[j].getYPos())){
            robbers[i].pickUpLoot(jewels[j]);
            city.placeObj(robbers[i].getXPos(), robbers[i].getYPos(), 'r');
            foundJewel += 1;
          }
        }
          
        //position left
        if(city.getCity(tempX, tempY) == 'R'){
          city.placeObj(tempX, tempY, 'r');
        } else {
          city.placeObj(tempX, tempY, ' ');
        }
         
      }

    }while((foundJewel != 0));
  }
    




    
    //moves officer third
    do{
      tempX = officer.getXPos();
      tempY = officer.getYPos();
      officer.move();
    }while(tempX == officer.getXPos() && tempY ==  officer.getYPos());

    //runs into robber
    
    if((city.getCity(officer.getXPos(), officer.getYPos()) == 'R') || (city.getCity(officer.getXPos(), officer.getYPos()) == 'r')){
      for(int i = 0; i < 4; i++){
        if((robbers[i].getXPos() == officer.getXPos()) && (robbers[i].getYPos() == officer.getYPos())){
          officer.arrest(robbers[i].getJWorth());
          robbers[i].loseJewels();
        }
      }
    }

    //runs into nothing
    if(city.getCity(officer.getXPos(), officer.getYPos()) == ' '){
      city.placeObj(officer.getXPos(), officer.getYPos(), 'P');
    }


    //runs into jewel
    if(city.getCity(officer.getXPos(), officer.getYPos()) == 'J'){
      for(int i = 0; i < 47; i++){
        if((officer.getXPos() == jewels[i].getXPos()) && (officer.getYPos() == jewels[i].getYPos())){
          officer.grabJewel(jewels[i].getValue());
          city.placeObj(officer.getXPos(), officer.getYPos(), 'P');
        }
      }
    }
    

    //position left
    city.placeObj(tempX, tempY, ' ');
    
    
    
    
    
    for(int i = 0; i < 4; i++){
      totalWorth += robbers[i].getJWorth();
    }

    //cout << "\033[2J\033[1;1H";
    city.printCity();
    turn++;
  }while((turn < 30) && (totalWorth < 438) && (officer.getRCaught() < 4));
  /*
  for(int i = 0; i < 47; i++){
    cout << jewels[i].getXPos() << ", " << jewels[i].getYPos() << "\n\n";
  }
  */




  

  








  cout << "Summary of the chase:\n";
  if(turn >= 30){
    cout << "\tThe robbers win the search because the maximum turns (30) has been played\n";
  } else if (totalWorth >= 438){
    cout << "\tThe robbers win the search because the total jewel amount is greater or equal to 438\n";
  } else if (officer.getRCaught() >= 4){
    cout << "\tThe police officer wins the round because he caught all of the robbers\n";
  }
  cout << "Police id: 1\n\tConfiscated jewels amount: $" << officer.getCount() <<"\n\tFinal number of robbers caught: " << officer.getRCaught();
  cout << "\nOrdinary Robber id: 1\n\tFinal number of jewels picked up: " << robbers[0].getJCount() << "\n\tTotal jewel worth: $" << robbers[0].getJWorth();
  cout << "\nOrdinary Robber id: 2\n\tFinal number of jewels picked up: " << robbers[1].getJCount() << "\n\tTotal jewel worth: $" << robbers[1].getJWorth();
  cout << "\nGreedy Robber id: 3\n\tFinal number of jewels picked up: " << robbers[2].getJCount() << "\n\tTotal jewel worth: $" << robbers[2].getJWorth();
  cout << "\nGreedy Robber id: 4\n\tFinal number of jewels picked up: " << robbers[3].getJCount() << "\n\tTotal jewel worth: $" << robbers[3].getJWorth() << "\n\n\n";

  
  return 0;
}


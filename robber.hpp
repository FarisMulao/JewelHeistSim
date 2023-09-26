template <class T>
void Robber<T>::pickUpLoot(T jewel) {
  if(m_jewelCount < 17){
    m_bag[m_jewelCount] = jewel;
    m_jewelCount++;
    m_worth += jewel.getValue();
    jewel.setPos(10, 10);
  }
  return;
}

template <class T>
bool Robber<T>::bagFull(){
  if(m_jewelCount == 16){
    return 1;
  }
  else{
    return 0;
  }
}

template <class T>
void Robber<T>::move(){
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
}

template <class T>
void Robber<T>::setPos(int x, int y){
  m_xPos = x;
  m_yPos = y;
  return;
}

template <class T>
void Robber<T>::setID(int id){
  m_id = id;
  return;
}

template <class T>
void Robber<T>::setOrd(){
  m_greedy = 0;
}







template <class T>
void Robber<T>::greedyMove(char cityArr[][10], char obj){
  int rD = rand() % 8;
  int tempX = m_xPos;
  int tempY = m_yPos;
  switch(rD){
    case 0:
      do{
        if(tempX - 1 >= 0 && tempY - 1 >= 0){
          tempX -= 1;
          tempY -= 1;
          if(cityArr[tempX][tempY] == obj){
            m_xPos -= 1;
            m_yPos -= 1;
            return;
          }
        }
      }while(tempX - 1 >= 0 && tempY - 1 >= 0);
      if(m_xPos == tempX && m_yPos == tempY){
        move();
      }
      break;

    case 1:
      do{
        if(tempY - 1 >= 0){
          tempY -= 1;
          if(cityArr[tempX][tempY] == obj){
            m_yPos -= 1;
            return;
          }
        }
      }while(tempY - 1 >= 0);
      if(m_xPos == tempX && m_yPos == tempY){
        move();
      }
      break;

    case 2:
      do{
        if(tempX + 1 < 10 && tempY - 1 >= 0){
          tempX += 1;
          tempY -= 1;
          if(cityArr[tempX][tempY] == obj){
            m_xPos += 1;
            m_yPos -= 1;
            return;
          }
        }
      }while(tempX + 1 < 10 && tempY - 1 >= 0);
      if(m_xPos == tempX && m_yPos == tempY){
        move();
      }
      break;

    case 3:
      do{
        if(tempX - 1 >= 0){
          tempX -= 1;
          if(cityArr[tempX][tempY] == obj){
            m_xPos -= 1;
            return;
          }
        }
      }while(tempX - 1 >= 0);
      if(m_xPos == tempX && m_yPos == tempY){
        move();
      }
      break;

    case 4:
      do{
        if(tempX + 1 < 10){
          tempX += 1;
          if(cityArr[tempX][tempY] == obj){
            m_xPos += 1;
            return;
          }
        }
      }while(tempX + 1 < 10);
      if(m_xPos == tempX && m_yPos == tempY){
        move();
      }
      break;

    case 5:
      do{
        if(tempX - 1 >= 0 && tempY + 1 < 10){
          tempX -= 1;
          tempY += 1;
          if(cityArr[tempX][tempY] == obj){
            m_xPos -= 1;
            m_yPos += 1;
            return;
          }
        }
      }while(tempX - 1 >= 0 && tempY + 1 < 10);
      if(m_xPos == tempX && m_yPos == tempY){
        move();
      }
      break;

    case 6:
      do{
        if(tempY + 1 < 10){
          tempY += 1;
          if(cityArr[tempX][tempY] == obj){
            m_yPos += 1;
            return;
          }
        }
      }while(tempY + 1 < 10);
      if(m_xPos == tempX && m_yPos == tempY){
        move();
      }
      break;

    case 7:
      do{
        if(tempX + 1 < 10 && tempY + 1 < 10){
          tempX += 1;
          tempY += 1;
          if(cityArr[tempX][tempY] == obj){
            m_xPos += 1;
            m_yPos += 1;
            return;
          }
        }
      }while(tempX + 1 < 10 && tempY + 1 < 10);
      if(m_xPos == tempX && m_yPos == tempY){
        move();
      }
      break;
  }
  return;
}








template <class T>
void Robber<T>::loseJewels(){
  m_worth = 0;
  m_active = 0;
  for(int i = 0; i < m_jewelCount; i++){
    m_bag[i] = {}; 
  }
  m_jewelCount = 0;
  m_xPos = 100;
  m_yPos = 100;
}

template <class T>
void Robber<T>::loseHalf(){
  int temp; 
  temp = m_jewelCount / 2;

  for(int i = m_jewelCount; i > (m_jewelCount - temp - 1); i--){
    m_bag[i] = {};
  }
  m_jewelCount = m_jewelCount - temp - 1;
  return;
  
}

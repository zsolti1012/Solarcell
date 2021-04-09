#include <Servo.h>
#include "Solarplant.h"
#include <Arduino.h>


Solarplant::Solarplant(int _lrpin, int _udpin,
               int _leftport,int _rightport,int _upport,int _downport)
{
    lrpint=_lrpin;
    udpin=_udpin;
    leftport=_leftport;
    rightport=_rightport;
    upport=_upport;
    downport=_downport;

    lrposition=90;
    udposition=0;
    
    
    diff=40;
    delaytime=20;
    
}

Solarplant::~Solarplant()
{
    //dtor
}

void Solarplant::Enable(){
  enabled=true;
}

void Solarplant::Disable(){
 enabled=false;
 
}
void Solarplant::StartPosition(){
  leftright.attach(lrpint);
  leftright.write(90);
  leftright.detach();
  
  updown.attach(udpin);
  updown.write(0);
  updown.detach();
}
void Solarplant::Move(){
 if(enabled){

  //Program
  leftright.attach(lrpint);
  updown.attach(udpin);

  
    
    left=analogRead(leftport);
    right=analogRead(rightport);
    down=analogRead(downport);
    up=analogRead(upport);
    

    
    
   if(left>100||right>100||up>100||down>100){
    //Left
    //------------------------
    
    if(left-diff>right &&lrposition>2){
      lrposition--;
      
      
      leftright.write(lrposition);
      delay(delaytime);
      leftright.detach();
    }

    

    //------------------------------------------

    //Right
    else if(right-diff>left &&lrposition<180){
      lrposition++;
      
      
      leftright.write(lrposition);
      delay(delaytime);
      leftright.detach();
    }

    


    //------------------------------------

    //Up
     else if(up-diff>down && udposition>0){
      udposition--;
      
      
      updown.write(udposition);
      delay(delaytime);
      updown.detach();
    }

    

    //Down
    else if(down-diff>up && udposition<90 ){
      udposition++;
      
      
      updown.write(udposition);
      delay(delaytime);
      updown.detach();
    }
  
 }
 }

}

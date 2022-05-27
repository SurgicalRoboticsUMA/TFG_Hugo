#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;


//Para el MOTOR 1
int direction1 = 4;
int speed1 = 3;

//Para el MOTOR 2
int direction2 = 12;
int speed2 = 11;

//Para el MOTOR 3
int direction3 = 8;
int speed3 = 5;

//Para el MOTOR 4
int direction4 = 7;
int speed4 = 6;

char valor;

void ROS_cmd( const std_msgs::UInt16& cmd_msg){

           valor = cmd_msg.data;
        
           
// ----------------------------------------------ROLL-----------------------------------------
// -------------------------------------------------------------------------------------------
          
        // Si se ha enviado la letra 'q' Giro EJE Z positivo.
        if(valor == 'q'){
          digitalWrite(direction1, LOW);
          
          analogWrite(speed1, 100);
      
          delay(50);
        }
        
        // Si se ha enviado la letra 'w'  Giro EJE Z negativo.
        else if(valor == 'w'){
          digitalWrite(direction1, HIGH);
        
          analogWrite(speed1, 100);
          
          delay(50);
        }
        
        
        // ----------------------------------------------PITCH-----------------------------------------
        // --------------------------------------------------------------------------------------------
        
        // Si se ha enviado la letra 'z' PITCH +.
        else if(valor == 'z'){
          
          digitalWrite(direction2, HIGH);
          analogWrite(speed2, 150);
          
          digitalWrite(direction3, LOW);
          analogWrite(speed3, 70);
          
          digitalWrite(direction4, LOW);
          analogWrite(speed4, 70);
          
        
          delay(50);
        }
        // Si se ha enviado la letra 'x' PITCH -
        else if(valor == 'x'){
          
          digitalWrite(direction2, LOW);
          analogWrite(speed2, 150);
          
          digitalWrite(direction3, HIGH);
          analogWrite(speed3, 70);
          
          digitalWrite(direction4, HIGH);
          analogWrite(speed4, 70);
          
        
          delay(50);
        }
        
        
        
        // ----------------------------------------------YAW------------------------------------------
        // -------------------------------------------------------------------------------------------
        
        // Si se ha enviado la letra 'o'  YAW .
        else if(valor == 'o'){
          digitalWrite(direction3, HIGH);
          analogWrite(speed3, 180);
          digitalWrite(direction4, HIGH);
          analogWrite(speed4, 180);
         
          delay(60);
        }
        // Si se ha enviado la letra 'p' YAW.
        else if(valor == 'p'){
          digitalWrite(direction3, LOW);
          analogWrite(speed3, 180);
            digitalWrite(direction4, LOW);
          analogWrite(speed4, 180);
         
          delay(60);
        }
        
        
        
        // ----------------------------------------------SCISSORS-----------------------------------------
        // -----------------------------------------------------------------------------------------------
        
        // Si se ha enviado la letra 'g' CIERRA PINZA.
        else if(valor == 'g'){
          digitalWrite(direction3, HIGH);
          analogWrite(speed3, 170);
            digitalWrite(direction4, LOW);
          analogWrite(speed4, 170);
        
          delay(70);
        }
        // Si se ha enviado la letra 'h' ABRE PINZA.
        else if(valor == 'h'){
          digitalWrite(direction3, LOW);
          analogWrite(speed3, 170);
            digitalWrite(direction4, HIGH);
          analogWrite(speed4, 170);
 
          delay(50);
        }
        
        
        
        
        valor = 'Y';
        
        analogWrite(speed1, 0);
        
        analogWrite(speed2, 0);
        
        analogWrite(speed3, 0);
        
        analogWrite(speed4, 0);

  
}


ros::Subscriber<std_msgs::UInt16> sub("/cmd_EndoWrist", ROS_cmd);


void setup() {
Serial.begin(9600);
//define pins
pinMode(direction1, OUTPUT);
pinMode(speed1, OUTPUT);

pinMode(direction2, OUTPUT);
pinMode(speed2, OUTPUT);

pinMode(direction3, OUTPUT);
pinMode(speed3, OUTPUT);

pinMode(direction4, OUTPUT);
pinMode(speed4, OUTPUT);


  nh.initNode();
  nh.subscribe(sub);

}

void loop() {
  
  nh.spinOnce();
  delay(1);

}

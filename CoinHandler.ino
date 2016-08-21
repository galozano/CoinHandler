#include <Servo.h>

const int coinInt = 0; 
volatile float coinsValue = 0.00;

//New coin inserted
int coinsChange = 0;                  

//Initialize Servo
Servo rightServo;
Servo leftServo;

void setup()
{
   //Serial Communication
  Serial.begin(9600);                 
   
  //Initialize both of the servos
  rightServo.attach(12);
  leftServo.attach(11);
   
  //This function basically calls the function coinInserted every time a coin is inserted
  attachInterrupt(coinInt, coinInserted, RISING);   

  //Set both servos to the right position
  rightServo.write(45);
  leftServo.write(60);
}

//Function call everytime a coin is inserted
void coinInserted()    
{
  int coinRise = 1;

  coinsValue = coinsValue + 1;  
  
  //new Coin was inserted
  coinsChange = 1;                           
}

void loop()
{
  //Check if a coin has been Inserted
  if(coinsChange == 1)          
  {
    //unflag that a coin has been inserted
    coinsChange = 0;              
   
    String printValue = "Credit:" + String(coinsValue);     
    //Print the Value of coins inserted
    Serial.println(printValue);   
   
    if(coinsValue > 2 || coinsValue == 2 ){
       rightServo.write(0);
       leftServo.write(0);
       delay(10000);
       
      rightServo.write(45);
      leftServo.write(60);
      coinsValue = 0.00;
    } 
  }
}

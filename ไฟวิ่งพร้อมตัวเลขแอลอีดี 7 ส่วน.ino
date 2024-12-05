//Seven segment push button counter
 const int a = 8; // For displaying segment  "a"
 const int b = 9; // For displaying segment  "b"
 const int c = 4; // For displaying segment  "c"
 const int d = 5; // For displaying segment  "d"
 const int e = 6; // For displaying segment  "e"
 const int f = 2; // For displaying segment  "f"
 const int g = 3; // For displaying segment  "g"
 int led1 = A5;
 int led2 = A4;
 int led3 = 7;
 int led4 = 10;
 int led5 = 11;
 int led6 = 12;
 int led7 = 13;
 int led8 = A2;
 char led_pin[]={led1,led2,led3,led4,led5,led6,led7,led8};
 bool bPress = false;
 const int buttonPin = A0;
 
 //Variables will change
 int buttonPushCounter = 1;
 int buttonState = 0;
 int lastButtonState = 0;
 int push=0;

 void setup()
 {
   pinMode(a,OUTPUT); // A
   pinMode(b,OUTPUT); // B
   pinMode(c,OUTPUT); // C
   pinMode(d,OUTPUT); // D
   pinMode(e,OUTPUT); // E
   pinMode(f,OUTPUT); // F
   pinMode(g,OUTPUT); // G
   pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
   pinMode(led3,OUTPUT);
   pinMode(led4,OUTPUT);
   pinMode(led5,OUTPUT);
   pinMode(led6,OUTPUT);
   pinMode(led7,OUTPUT);
   pinMode(led8,OUTPUT);
   pinMode(buttonPin,INPUT_PULLUP);
   Serial.begin(9600);
   displayDigit(buttonPushCounter);
 }
 
 void loop()
 {
   buttonState = digitalRead(buttonPin);//ไม่กด1 กด0
   
   //compare the buttonState to its revious state
   if(buttonState != lastButtonState)
   { 
     
     if(buttonState == LOW){
       push++;
     }
     Serial.print(buttonState);
     Serial.print(push);
     //if the state has changed,increment the counter
     if(push%2!=0 && push>0){
       push=-2;
       for (int x = 1; x <= 8; x++) {
       	buttonPushCounter=x;
        //if the current state is HIGH then the button went from off to on
        bPress = true;
        delay(1000);
        if(buttonPushCounter>8) buttonPushCounter = 8;
        Serial.println("on");
        if(bPress ){
           turnoff();
           displayDigit(buttonPushCounter);
           digitalWrite(led_pin[x-1],HIGH);
           Serial.print("NUMBER = ");
           Serial.println(buttonPushCounter);
         }
       }
     }
        else if(push%2!=0 && push<0 && buttonState == LOW ){
       		push=0;
         //if the current state is LOW then the button went from on to off
         for (int x = 8; x >= 1; x--) {
          buttonPushCounter=x;
          //if the current state is HIGH then the button went from off to on
          bPress = true;
          delay(1000);
          if(buttonPushCounter<1) buttonPushCounter = 1;
          Serial.println("on");
          if(bPress ){
             turnoff();
             displayDigit(buttonPushCounter);
             digitalWrite(led_pin[x-1],LOW);
             Serial.print("NUMBER = ");
             Serial.println(buttonPushCounter);
           }
         }
        }
     //Delay a little bit to avoid bouncing
     delay(1000);
   }
   //save the current state as the last state,for ext time through the loop
   lastButtonState = buttonState;
 }
 
 void displayDigit(int digit)
 {
   //condition for displaying segment a
   if(digit != 1 && digit !=4)
   digitalWrite(a,HIGH);
   
   //condition for displaying segment b
   if(digit != 5  && digit != 6)
   digitalWrite(b,HIGH);
   
   //condition for displaying segment c
   if(digit != 2)
   digitalWrite(c,HIGH);
   
   //condition for displaying segment d
   if(digit != 1 && digit !=4 && digit != 7)
   digitalWrite(d,HIGH);
   
   //condition for displaying segment e
   if(digit == 2 || digit ==6 || digit ==8 || digit == 0)
   digitalWrite(e,HIGH);
   
   //condition for displaying segment f
   if(digit != 1 && digit !=2 && digit != 3 && digit != 7)
   digitalWrite(f,HIGH);
   
   //condition for displaying segment g
   if(digit != 0 && digit !=1 && digit!= 7)
   digitalWrite(g,HIGH);
 }
 
 void turnoff()
 {
   digitalWrite(a,LOW);
   digitalWrite(b,LOW);
   digitalWrite(c,LOW);
   digitalWrite(d,LOW);
   digitalWrite(e,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,LOW);
 }
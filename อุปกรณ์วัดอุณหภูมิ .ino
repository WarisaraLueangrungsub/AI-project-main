int numPin1[] = {8,9,3,4,5,7,6,2};
int totalPin1 = 8;
int numPin2[] = {10,11,12,13};
int totalPin2 = 4;

void  setup() { 
  for(int i =0;i<totalPin1;i++){
   pinMode(numPin1[i],OUTPUT);
  }
   for(int i =0;i<totalPin2;i++){
   pinMode(numPin2[i],OUTPUT);
  }
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
   
   int temp = map(analogRead(A0),20,358,-40,125);
   
   int seg1= temp%10;
  
   int seg2=(temp/10)%10;
   
   int getValue = (temp > 100 ? 1:0);
  
   getValue = temp<0? -1:getValue;
   Serial.println(temp);
   
   int value[] = {0,abs(seg1),abs(seg2),getValue};
   for(int i =0;i<totalPin2;i++){
     LED(numPin2[i],value[i]);
   }
 }

void LED(int x,int y){
  switch(x){ 
   case 10: 
      digitalWrite(10, 1); //Common
      digitalWrite(11, 1); //Common
     break;
    case 11:
      digitalWrite(10, 0); //Common
      digitalWrite(11, 1); //Common
     break;
     case 12:
      digitalWrite(10, 1); //Common
      digitalWrite(11, 0); //Common
     break;
     case 13:
      digitalWrite(10, 1); //Common
      digitalWrite(11, 1); //Common
        break;
  }
  
   switch(y){
    case 0:  
      digitalWrite(8, 1); //A
      digitalWrite(9, 1); //B
      digitalWrite(3, 1); //C
      digitalWrite(4, 1); //D
      digitalWrite(5, 1); //E
      digitalWrite(7, 1); //F
      digitalWrite(6, 0); //G
      break;
    case 1: 
      digitalWrite(8, 0); //A
      digitalWrite(9, 1); //B
      digitalWrite(3, 1); //C
      digitalWrite(4, 0); //D
      digitalWrite(5, 0); //E
      digitalWrite(7, 0); //F
      digitalWrite(6, 0); //G
      break;
    case 2: 
      digitalWrite(8, 1); //A
      digitalWrite(9, 1); //B
      digitalWrite(3, 0); //C
      digitalWrite(4, 1); //D
      digitalWrite(5, 1); //E
      digitalWrite(7, 0); //F
      digitalWrite(6, 1); //G
      break;
    case 3:  
      digitalWrite(8, 1); //A
      digitalWrite(9, 1); //B
      digitalWrite(3, 1); //C
      digitalWrite(4, 1); //D
      digitalWrite(5, 0); //E
      digitalWrite(7, 0); //F
      digitalWrite(6, 1); //G
      break;
    case 4: 
      digitalWrite(8, 0); //A
      digitalWrite(9, 1); //B
      digitalWrite(3, 1); //C
      digitalWrite(4, 0); //D
      digitalWrite(5, 0); //E
      digitalWrite(7, 1); //F
      digitalWrite(6, 1); //G
      break;
    case 5: 
      digitalWrite(8, 1); //A
      digitalWrite(9, 0); //B
      digitalWrite(3, 1); //C
      digitalWrite(4, 1); //D
      digitalWrite(5, 0); //E
      digitalWrite(7, 1); //F
      digitalWrite(6, 1); //G
      break;
    case 6:  
      digitalWrite(8, 1); //A
      digitalWrite(9, 0); //B
      digitalWrite(3, 1); //C
      digitalWrite(4, 1); //D
      digitalWrite(5, 1); //E
      digitalWrite(7, 1); //F
      digitalWrite(6, 1); //G
      break;
    case 7: 
      digitalWrite(8, 1); //A
      digitalWrite(9, 1); //B
      digitalWrite(3, 1); //C
      digitalWrite(4, 0); //D
      digitalWrite(5, 0); //E
      digitalWrite(7, 0); //F
      digitalWrite(6, 0); //G
      break;
    case 8:  
      digitalWrite(8, 1); //A
      digitalWrite(9, 1); //B
      digitalWrite(3, 1); //C
      digitalWrite(4, 1); //D
      digitalWrite(5, 1); //E
      digitalWrite(7, 1); //F
      digitalWrite(6, 1); //G
      break;
    case 9:  
      digitalWrite(8, 1); //A
      digitalWrite(9, 1); //B
      digitalWrite(3, 1); //C
      digitalWrite(4, 1); //D
      digitalWrite(5, 0); //E
      digitalWrite(7, 1); //F
      digitalWrite(6, 1); //G
      break;
  }
  delay(20);
}
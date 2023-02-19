// Mario's ideas
// Displaying cat image on 8x8 LED Matrix (Multiplexing)

//   Raws 
#define R1 2
#define R2 3
#define R3 4
#define R4 5
#define   R5 6
#define R6 7
#define R7 A4
#define R8 A5
//Columns
#define C1   10
#define C2 11
#define C3 12
#define C4 13
#define C5 A0
#define   C6 A1
#define C7 A2
#define C8 A3

const int TouchPin = 8;
long randomNumber = random(20, 70);
long randomNumber2 = random(20, 70);

int pause=1;
int count = 1;

  int Cat   [8] [8] ={
  {0,0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0},
  };

  int CatLose [8] [8] ={
  {0,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,1,0},
  {0,0,1,0,0,1,0,0},
   {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,1,0,0,1,0,0},
  {0,1,0,0,0,0,1,0},
   {0,0,0,0,0,0,0,0},
  };

  int CatWin  [8] [8] ={
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  };

void setup() {
   pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
   pinMode(R3, OUTPUT);
   pinMode(R4, OUTPUT);
    pinMode(R5, OUTPUT);
   pinMode(R6, OUTPUT);
   pinMode(R7, OUTPUT);
    pinMode(R8, OUTPUT);
   pinMode(C1, OUTPUT);
   pinMode(C2, OUTPUT);
    pinMode(C3, OUTPUT);
   pinMode(C4, OUTPUT);
   pinMode(C5, OUTPUT);
    pinMode(C6, OUTPUT);
   pinMode(C7, OUTPUT);
   pinMode(C8, OUTPUT);

   digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);
  digitalWrite(R3,HIGH);
   digitalWrite(R4,HIGH);
  digitalWrite(R5,HIGH);
  digitalWrite(R6,HIGH);
   digitalWrite(R7,HIGH);
  digitalWrite(R8,HIGH);
  digitalWrite(C1,LOW);
   digitalWrite(C2,LOW);
  digitalWrite(C3,LOW);
  digitalWrite(C4,LOW);
   digitalWrite(C5,LOW);
  digitalWrite(C6,LOW);
  digitalWrite(C7,LOW);
   digitalWrite(C8,LOW);
   pinMode(TouchPin, INPUT);
}
     void SelectRow(int row){
  if (row==1)   digitalWrite(R1,LOW); else digitalWrite(R1,HIGH);
  if (row==2) digitalWrite(R2,LOW);   else digitalWrite(R2,HIGH);
  if (row==3) digitalWrite(R3,LOW); else digitalWrite(R3,HIGH);
   if (row==4) digitalWrite(R4,LOW); else digitalWrite(R4,HIGH);
  if (row==5)   digitalWrite(R5,LOW); else digitalWrite(R5,HIGH);
  if (row==6) digitalWrite(R6,LOW);   else digitalWrite(R6,HIGH);
  if (row==7) digitalWrite(R7,LOW); else digitalWrite(R7,HIGH);
   if (row==8) digitalWrite(R8,LOW); else digitalWrite(R8,HIGH);
}

void   SelectColumn(int column){
  if (column==1) digitalWrite(C1,HIGH); else digitalWrite(C1,LOW);
   if (column==2) digitalWrite(C2,HIGH); else digitalWrite(C2,LOW);
  if (column==3)   digitalWrite(C3,HIGH); else digitalWrite(C3,LOW);
  if (column==4) digitalWrite(C4,HIGH);   else digitalWrite(C4,LOW);
  if (column==5) digitalWrite(C5,HIGH); else digitalWrite(C5,LOW);
   if (column==6) digitalWrite(C6,HIGH); else digitalWrite(C6,LOW);
  if (column==7)   digitalWrite(C7,HIGH); else digitalWrite(C7,LOW);
  if (column==8) digitalWrite(C8,HIGH);   else digitalWrite(C8,LOW);

}



void   Set_LED_in_Active_Row(int column, int state){
  if (column==1) digitalWrite(C1,state);   
  if (column==2) digitalWrite(C2,state); 
  if (column==3) digitalWrite(C3,state);   
  if (column==4) digitalWrite(C4,state); 
  if (column==5) digitalWrite(C5,state);   
  if (column==6) digitalWrite(C6,state); 
  if (column==7) digitalWrite(C7,state);   
  if (column==8) digitalWrite(C8,state); 
}

int inc = 1;
int deathIndex = 0;
int winIndex = 1;
int count2 = 0;
int inc2 = 1;

void loop() {
    int sensorValue = digitalRead(TouchPin);

     for (int j=0;j<8;j++){
    SelectRow(j+1);
      for (int i=0;i<8;i++){
         Set_LED_in_Active_Row(i+1 ,Cat[j][i]);
      }
      delay(pause);
     }
     
if(count%randomNumber == 0 && inc != 8){
  Cat[inc][5]=1;
  if(inc != 1) {
    Cat[inc - 1][5] = 0;
  }
  inc++;
}

if(count%randomNumber2 == 0 && inc2 != 8){
  Cat[inc2][6]=1;
  if(inc2 != 1) {
    Cat[inc2 - 1][6] = 0;
  }
  inc2++;
}

if (count % (randomNumber + 30) == 0 && inc == 8) {
  inc = 1;
  Cat[7][5] = 0;
  randomNumber = random(20, 70);
}

if (count % (randomNumber2 + 30) == 0 && inc2 == 8) {
  inc2 = 1;
  Cat[7][6] = 0;
  randomNumber2 = random(20, 70);
}

if(sensorValue == 1) {
  if(Cat[7][5] == 0 && Cat[7][6] == 0) {
    if(count - count2 >= 100) {
        count2 = count;
        Cat[deathIndex][3] = 1;
        deathIndex++;
        if(deathIndex == 4) {
          for(int k = 0; k < 250; k++) {
            for (int j=0;j<8;j++){
              SelectRow(j+1);
              for (int i=0;i<8;i++){
                Set_LED_in_Active_Row(i+1 ,CatLose[j][i]);
              }
              delay(pause);
            }
            delay(pause);
          }
          exit(0);
        }
      }
    } else {
        if(count - count2 >= 100) {
          count2 = count;
          Cat[winIndex][7] = 1;
          winIndex++;
          if (winIndex == 7) {
            for(int k = 0; k < 250; k++) {
            for (int j=0;j<8;j++){
              SelectRow(j+1);
              for (int i=0;i<8;i++){
                Set_LED_in_Active_Row(i+1 ,CatWin[j][i]);
              }
              delay(pause);
            }
            delay(pause);
          }
          exit(0);
          }
      }
    }  
}



count++;
} 
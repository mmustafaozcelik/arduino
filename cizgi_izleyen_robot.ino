    #define sagmotorhiz 6
#define solmotorhiz 12
#define sagmotoron 11
#define solmotoron 8
#define sagmotorarka 9
#define solmotorarka 10
#define sag 2
#define sagic 5
#define sol 4
int sagsensor = 0, sagicsensor = 0, solsensor = 0;

void setup()
{
  pinMode(sagmotorhiz, OUTPUT);
  pinMode(solmotorhiz, OUTPUT);
  pinMode(sagmotoron, OUTPUT);
  pinMode(solmotoron, OUTPUT);
  pinMode(sagmotorarka, OUTPUT);
  pinMode(solmotorarka, OUTPUT);
  Serial.begin(9600);
  pinMode(sag, INPUT);
  pinMode(sagic, INPUT);
  pinMode(sol, INPUT);
}

void loop()
{
   sagsensor = digitalRead(sag);
  Serial.print("Sağ sensör:");
  Serial.print(sagsensor);
  sagicsensor = digitalRead(sagic);
  Serial.print("Sağiç sensör:");
  Serial.print(sagicsensor);
  solsensor = digitalRead(sol);
  Serial.print("Sol sensör:");
  Serial.println(solsensor);
 
  if(sagsensor==0 && sagicsensor==1 &&solsensor==0)
  {
    ileri();
  }
   if(sagsensor==1 && sagicsensor==1 &&solsensor==0)
  {
    sagdon();
  }
   if(sagsensor==0 && sagicsensor==1 &&solsensor==1)
  {
    soldon();
  }
  if(sagsensor==0 && sagicsensor==0 &&solsensor==1)
  {
    soldon();
  }
  
  if(sagsensor==1 && sagicsensor==0 && solsensor==0)
  {
   sagdon();
   
  } 
   if(sagsensor==1 && sagicsensor==1 &&solsensor==1)
  {
    ileri();
  }
  if(sagsensor==0 && sagicsensor==0 && solsensor==0)
  {
    dur();
   
  } 
}

void ileri()
{
  analogWrite(sagmotorhiz, 150);
  digitalWrite(sagmotoron, 1);
  digitalWrite(sagmotorarka, 0);

  analogWrite(solmotorhiz, 150);
  digitalWrite(solmotoron, 1);
  digitalWrite(solmotorarka, 0);
}

void soldon()
{
  analogWrite(sagmotorhiz, 150);
  digitalWrite(sagmotoron, 1);
  digitalWrite(sagmotorarka, 0);

  analogWrite(solmotorhiz, 150);
  digitalWrite(solmotoron, 0);
  digitalWrite(solmotorarka, 0);
}
void sagdon()
{
  analogWrite(sagmotorhiz, 150);
  digitalWrite(sagmotoron, 00);
  digitalWrite(sagmotorarka, );

  analogWrite(solmotorhiz, 150);
  digitalWrite(solmotoron, 1);
  digitalWrite(solmotorarka, 0);
}

void dur()
{
  analogWrite(sagmotorhiz, 150);
  digitalWrite(sagmotoron, 0);
  digitalWrite(sagmotorarka, 0);

  analogWrite(solmotorhiz, 150);
  digitalWrite(solmotoron, 0);
  digitalWrite(solmotorarka, 0);
}

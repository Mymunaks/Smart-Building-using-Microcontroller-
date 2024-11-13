#define ldr1 A0
#define ldr2 A1
#define ldr3 A2
#define ldr4 A3
#define flame1 2
#define flame2 3
#define Mq2 A4
#define led 8
#define buzzer 9
#define relay2 5
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

  pinMode(ldr1,INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3,INPUT);
  pinMode(ldr4,INPUT);

  pinMode(flame1,INPUT);
  pinMode(flame2,INPUT);
  pinMode(Mq2,INPUT);

  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(relay2,OUTPUT);
  digitalWrite(buzzer,LOW);
  digitalWrite(relay2,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  int Val_Mq2 = analogRead(Mq2);
  bool Val_flame1 = digitalRead(flame1);
  bool Val_flame2 = digitalRead(flame2);

  int Val_ldr1 = analogRead(ldr1);
  int Val_ldr2 = analogRead(ldr2);
  int Val_ldr3 = analogRead(ldr3);
  int Val_ldr4 = analogRead(ldr4);

  Val_Mq2 = map(Val_Mq2,0,1023,0,100);
  Val_ldr1 = map(Val_ldr1,0,1023,0,100);
  Val_ldr2 = map(Val_ldr2,0,1023,0,100);
  Val_ldr3 = map(Val_ldr3,0,1023,0,100);
  Val_ldr4 = map(Val_ldr4,0,1023,0,100);
  //delay(1000);
    Serial.println("Mq2");
  Serial.println(Val_Mq2);
  //delay(1000);
  
  if ( Val_ldr2 > 50 || Val_ldr4 > 50 || Val_ldr1 > 50)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }

  if (Val_flame1 == HIGH || Val_flame2 == HIGH)
  {
    digitalWrite(buzzer,HIGH);
    //delay(1000);
    Serial.println(Val_flame1);
    //delay(1000);
    Serial.println(Val_flame2);
    digitalWrite(relay2,LOW);
    delay(2000);//pump
  }
  else
  {
    digitalWrite(buzzer,LOW);
    digitalWrite(relay2,HIGH);
  }
  if (Val_Mq2 > 7)
  {
    digitalWrite(buzzer,HIGH);
  }
  else
  {
   digitalWrite(buzzer,LOW); 
  }
  
}

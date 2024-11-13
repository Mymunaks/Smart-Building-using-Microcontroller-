#define MONITOR_SERIAL Serial
#define RADAR_SERIAL Serial1
#define RADAR_RX_PIN 32
#define RADAR_TX_PIN 33
#define led 5
#define ldr1 2
#define ldr2 4
#define ldr3 22
#define ldr4 23
#define relay1 13
#include <ld2410.h>

ld2410 radar;

uint32_t lastReading = 0;
bool radarConnected = false;

void setup(void)
{
  MONITOR_SERIAL.begin(115200); //Feedback over Serial Monitor
  RADAR_SERIAL.begin(256000, SERIAL_8N1, RADAR_RX_PIN, RADAR_TX_PIN); //UART for monitoring the radar
  delay(500);
  pinMode(led,OUTPUT);
  pinMode(ldr1,INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3,INPUT);
  pinMode(ldr4,INPUT);
  pinMode(relay1,OUTPUT);
  digitalWrite(relay1,HIGH);

  MONITOR_SERIAL.print(F("\nConnect LD2410 radar TX to GPIO:"));
  MONITOR_SERIAL.println(RADAR_RX_PIN);
  MONITOR_SERIAL.print(F("Connect LD2410 radar RX to GPIO:"));
  MONITOR_SERIAL.println(RADAR_TX_PIN);
  MONITOR_SERIAL.print(F("LD2410 radar sensor initialising: "));
  if(radar.begin(RADAR_SERIAL))
  {
    MONITOR_SERIAL.println(F("OK"));
    MONITOR_SERIAL.print(F("LD2410 firmware version: "));
    MONITOR_SERIAL.print(radar.firmware_major_version);
    MONITOR_SERIAL.print('.');
    MONITOR_SERIAL.print(radar.firmware_minor_version);
    MONITOR_SERIAL.print('.');
    MONITOR_SERIAL.println(radar.firmware_bugfix_version, HEX);
  }
  else
  {
    MONITOR_SERIAL.println(F("not connected"));
  }
}

void loop()
{
  radar.read();
  if(radar.isConnected() && millis() - lastReading > 1000)  //Report every 1000ms
  {
    lastReading = millis();
    if(radar.presenceDetected())
    {
      int Val_ldr1 = digitalRead(ldr1);
      int Val_ldr2 = digitalRead(ldr2);
      int Val_ldr3 = digitalRead(ldr3);
      int Val_ldr4 = digitalRead(ldr4);
      Serial.print(Val_ldr1 );
      Serial.print(Val_ldr2 );
      Serial.print(Val_ldr3 );
      Serial.print(Val_ldr4 );

      if ( Val_ldr1 ==1 || Val_ldr2==1 || Val_ldr3 ==1 || Val_ldr4 == 1)
      {
        digitalWrite(led,HIGH);
        Serial.print("in if cond\n" );
        Serial.print(Val_ldr1 );
        Serial.print(Val_ldr2 );
        Serial.print(Val_ldr3 );
        Serial.print(Val_ldr4 );
      }
      else
      {
        digitalWrite(led,LOW);
      }

      //DC fan
      digitalWrite(relay1,LOW);
      Serial.print("Fan ON");
      Serial.print("Led ON");
      delay(1000);
      if(radar.stationaryTargetDetected())
      {
        Serial.print(F("Stationary target: "));
        Serial.print(radar.stationaryTargetDistance());
        Serial.print(F("cm energy:"));
        Serial.print(radar.stationaryTargetEnergy());
        Serial.print(' ');
      }
      if(radar.movingTargetDetected())
      {
        Serial.print(F("Moving target: "));
        Serial.print(radar.movingTargetDistance());
        Serial.print(F("cm energy:"));
        Serial.print(radar.movingTargetEnergy());
      }
      Serial.println();
    }
    else
    {
      Serial.println(F("No target"));
      digitalWrite(led,LOW);
      Serial.print("Led OFF");
      digitalWrite(relay1,HIGH);
      Serial.print("Fan OFF");
    }
  }
}





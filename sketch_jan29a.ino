#define BLYNK_TEMPLATE_ID           "TMPLWE-5x-cH"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "fUL25bfcYPkv8KSHEb4qGUmmuS4hunDG"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
String key ="";
unsigned long previousMillis = 0;       
bool isBuzz = false;

 long interval = 0;
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int slideVal = 0;
String targetVal = "12345";     // PASSCODE
bool state;
bool buzzState ;
// Your WiFi credentials.
// Set keyword to "" for open networks.
char ssid[] = "Sgt Peppers";  // WIFI NETWORK NAME
char pass[] = "cort560K";      // WIFI PASSWORD

BlynkTimer timer;
void setup()
{
  // Debug console
  
  Serial.begin(115200);
  
  //slideVal=0;
  state = false;
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  digitalWrite(D6, LOW);
  //digitalWrite(D7, LOW);
  buzzState =false;
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, key, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, key, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
 // timer.setInterval(1000L, myTimerEvent);
}

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  key=key+"0";
 // Blynk.virtualWrite(V1, value);
 //Serial.println("CALLED V0");
}
BLYNK_WRITE(V1)
{
  // Set incoming value from pin V0 to a variable
  key=key+"1";
 // Blynk.virtualWrite(V1, value);
}
BLYNK_WRITE(V2)
{
  // Set incoming value from pin V0 to a variable
  key=key+"2";
 // Blynk.virtualWrite(V1, value);
}
BLYNK_WRITE(V3)
{
  // Set incoming value from pin V0 to a variable
  key=key+"3";
 // Blynk.virtualWrite(V1, value);
}
BLYNK_WRITE(V4)
{
  // Set incoming value from pin V0 to a variable
  key=key+"4";
 // Blynk.virtualWrite(V1, value);
}
BLYNK_WRITE(V5)
{
  // Set incoming value from pin V0 to a variable
  key=key+"5";
 // Blynk.virtualWrite(V1, value);
}
BLYNK_WRITE(V6)
{
  // Set incoming value from pin V0 to a variable
  key=key+"6";
 // Blynk.virtualWrite(V1, value);
}
BLYNK_WRITE(V7)
{
  // Set incoming value from pin V0 to a variable
  key=key+"7";
 // Blynk.virtualWrite(V1, value);
}
BLYNK_WRITE(V8)
{
  // Set incoming value from pin V0 to a variable
  key=key+"8";
 // Blynk.virtualWrite(V1, value);
}
BLYNK_WRITE(V9)
{
  // Set incoming value from pin V0 to a variable
  key=key+"9";
 // Blynk.virtualWrite(V1, value);
}
BLYNK_WRITE(V10)
{
  if(key==targetVal)
    {
      Serial.println("SUCESS!");
      digitalWrite(D6,HIGH);
      delay(150);
      digitalWrite(D6,LOW);
      delay(50);
      /*digitalWrite(D6,HIGH);
      delay(150);
      digitalWrite(D6,LOW);*/
      interval=0;
      
    }
    else
    {
      Serial.println("INCORRECT PASSWORD!");
      isBuzz = true;
      interval = 1000;
      
    }
    
}
BLYNK_WRITE(V13)
{

 key="";
 isBuzz=false;
    
}
// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  Serial.println("CONNECTED to Wifi");
  digitalWrite(D7, HIGH);
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  //Blynk.virtualWrite(V2, 69);
}


void trimString()
{
  //Serial.println("ENTERED TRIMMING FUNC");
  int len=key.length();
  //String temp = key;
  
  //Serial.println(key.substring(len-1));
  //Serial.println(key.substring(len-2));
  if(key[len-1]==key[len-2])
    {
      key.remove(len-1);
    }
}
void beepBuzzer()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval ) 
  {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (buzzState == LOW) {
      buzzState = HIGH;
    } else {
      buzzState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(D6, buzzState);
    
  }
}
void loop()
{
  Blynk.run();
  //timer.run();
  if(key.length()>=2)
    trimString();
   //Blynk.virtualWrite(V2, slideVal);
  // Serial.println(key);
  if(isBuzz==true)
  beepBuzzer();
  else
  digitalWrite(D6, LOW);
   //beepBuzzer();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

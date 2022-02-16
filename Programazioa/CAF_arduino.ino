/*****
 
 All the resources for this project:
 https://randomnerdtutorials.com/
 
*****/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <MD_AD9833.h>
#include <SPI.h>

// Pins for SPI comm with the AD9833 IC
#define DATA  13  ///< SPI Data pin number
#define CLK   14  ///< SPI Clock pin number
#define FSYNC 15  ///< SPI Load pin number (FSYNC in AD9833 usage)

//Relearen pinak
int relay = 12;
//#define relayNO 4 //Normally Open
//#define relayNC 5 //Normally Close

String payload; // Jasota mezua
float freqF; // Frekuentzia gordetzeko float bezala.

MD_AD9833  AD(DATA, CLK, FSYNC); // Arbitrary SPI pins


// Change the credentials below, so your ESP8266 connects to your router
const char* ssid = "donbosco_caf";
const char* password = "DonBosco";

// Change the variable to your Raspberry Pi IP address, so it connects to your MQTT broker
//const char* mqtt_server = "192.168.4.1";
IPAddress mqtt_server(192, 168, 4, 1);

// Initializes the espClient. You should change the espClient name if you have multiple ESPs running in your home automation system
WiFiClient espClient;
PubSubClient client(espClient);


// Don't change the function below. This functions connects your ESP8266 to your router
void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected - ESP IP address: ");
  Serial.println(WiFi.localIP());
}


void callback(String topic, byte* message, unsigned int length) {


        Serial.println("CALLBAKC IRITSI");

  Serial.print("Message arrived on topic: ");
  Serial.println(topic);
  Serial.print(". Message: ");
 
  payload = "";
  for (int i = 0; i < length; i++) {
      payload += (char)message[i];
   }
  Serial.println(payload);

  //Serial.print(". To float: ");
    //Serial.println(freqF);
  
 if(topic=="donbosco_tester/frequency"){ 
       freqF = payload.toFloat();    
       freqF *= 2;
       Serial.print("Changing frequency to ");
       AD.setFrequency(MD_AD9833::CHAN_0, freqF);
       Serial.println(freqF);
    }
       
 /*if(topic=="donbosco_tester/stop"){
        Serial.print("Stoppin the frequency... ");     
        AD.setFrequency(MD_AD9833::CHAN_0, 0);
        Serial.print("Stopped signal. ");
    }*/
 if(topic=="donbosco_tester/relay"){
  Serial.println("RELAY TOPIC BARRUAN");
     Serial.print("Changing direction to... ");
    if(payload == "forward"){
      digitalWrite(relay, HIGH);
      Serial.println("PINA HIGH");
      Serial.println(payload);
     }
    if(payload == "backward"){
      digitalWrite(relay, LOW);
      Serial.println("PINA LOW");
      Serial.print(payload);
    }      
 }
 
 Serial.println();
}

// This functions reconnects your ESP8266 to your MQTT broker
// Change the function below if you want to subscribe to more topics with your ESP8266 

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");  
     
      client.subscribe("donbosco_tester/frequency");
      client.subscribe("donbosco_tester/stop");
      client.subscribe("donbosco_tester/relay");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  AD.begin();  
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  AD.setMode (MD_AD9833::MODE_SQUARE1);
  AD.setFrequency(MD_AD9833::CHAN_0, 0);
  digitalWrite(relay, LOW);

}

// For this project, you don't need to change anything in the loop function. Basically it ensures that you ESP is connected to your broker
void loop() {

//  digitalWrite(relay,HIGH);
//  delay(3000);
//  digitalWrite(relay,LOW);
//  delay(3000);

  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop()){
    client.connect("ESP8266Client");
          Serial.println("client.connect");
  }

  
} 

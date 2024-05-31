// Biblioteca
#include <Adafruit_Sensor.h>                                    
#include <DHT.h>                                                
#include <DHT_U.h>                                              
//----------------Define as constantes que a biblioteca necessita
 
#define DHTTYPE    DHT11                                    
 
 //Variáveis
int pinoDHT = 2;                                                
int pinoMotor = 9; 
DHT_Unified dht(pinoDHT, DHTTYPE);                              
 

// Preparação
void setup() {
 
  
 
  Serial.begin(9600);                                           
  pinMode(pinoMotor, OUTPUT);  
  dht.begin();                                                  
 
}
 

 
void loop() {
 
      delay(1500);                                                 
    
      sensors_event_t event;                                        
    
      dht.temperature().getEvent(&event);    
      
                             // Faz a leitura da temperatura

      if (isnan(event.temperature)) {                                                   
        Serial.println(F("Erro lendo a temperatura"));                                 
    
      } else {                                                                         
    
        if (event.temperature > 26){                                                   
    
          
          // Aciona o motor
          digitalWrite(pinoMotor, HIGH);                                                
    
        } else {                                                                       
    
          
          //Desativa o motor
          digitalWrite(pinoMotor, LOW);                                                 
    
        
    
        }
    
      if (isnan(event.temperature)) {                              
        Serial.println(F("Erro lendo a temperatura"));              
    
      } else {                                                     
        // Exibe temperatura
        Serial.print(F("Temperatura: "));                           
    
        Serial.print(event.temperature);                            
    
        Serial.println(F("°C"));                                   
    
      }
    
      dht.humidity().getEvent(&event);                              
    
      if (isnan(event.relative_humidity)) {                         
    
        Serial.println(F("Erro lendo a umidade"));                  
      } else {
        // exibe umidade relativa no ar
        Serial.print(F("Umidade: "));                               
    
        Serial.print(event.relative_humidity);                      
    
        Serial.println(F("%"));                                     
    
      }

    
      
 
  }
}
  
 
 

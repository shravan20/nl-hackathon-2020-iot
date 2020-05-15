#include<SoftwareSerial.h>
#include<TinyGPS.h>

/* Create Variable for latitude & longitude */
float lat = 0;
float lon = 0;

// For serial communication on other digital pins
SoftwareSerial gpsSerial(16,17); //rx,tx --> Lolin32 Module

//create GPS object
TinyGPS gps;

void setup(){
 
  Serial.begin(9600);
  gpsSerial.begin(9600);
   
}


void loop(){ 
	
	while(gpsSerial.available()){ //check for gps data

			if(gps.encode(gpsSerial.read())){ //encode the data in readable format
				 gps.f_get_position(&lat,&lon); // get latitude and longitude	
			}
	}	

	String latitude = String(lat,6); 
	String longitude = String(lon,6); 
	Serial.println(latitude+";"+longitude); 
	delay(1000); 

}

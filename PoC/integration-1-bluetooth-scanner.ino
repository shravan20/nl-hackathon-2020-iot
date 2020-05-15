#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

int scanTime = 5; //In seconds
BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
   void onResult(BLEAdvertisedDevice advertisedDevice) {
     Serial.printf("Advertised Device: %s \n", advertisedDevice.toString().c_str());
     String data = advertisedDevice.getName().c_str();
     Serial.println(data);
   }
};

void setup() {
 Serial.begin(115200);
 Serial.println("Scanning...");
 pinMode(15, OUTPUT);
 BLEDevice::init("ABCD");
 pBLEScan = BLEDevice::getScan(); //create new scan
 pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
 pBLEScan->setActiveScan(true); //active scan uses more power, but get results faster
 pBLEScan->setInterval(100);
 pBLEScan->setWindow(99);  // less or equal setInterval value
}

void loop() {
//  BLEAdvertisedDevice BLE = ;
 
 // put your main code here, to run repeatedly:
 BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
 Serial.print("Devices found: ");
//  Serial.print("Found devices print: ");
//  Serial.print(foundDevices);
 Serial.println(foundDevices.getCount());
//  
 Serial.println("Scan done!");
 pBLEScan->clearResults();   // delete results fromBLEScan buffer to release memory
 delay(2000);

 if(foundDevices.getCount() > 0){
     digitalWrite(15, HIGH);
     delay(2000);
 }
 digitalWrite(15, LOW);
 
 pBLEScan->clearResults();   // delete results fromBLEScan buffer to release memory
 delay(2000);
}

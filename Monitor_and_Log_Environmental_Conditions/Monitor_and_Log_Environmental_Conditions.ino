/* Mid-semester Project: Monitor and log environmental conditions
Goal: Building my first environmental monitoring system using open-source hardware
Author: Onan Agaba,
Instructor: Elad Levintal, PhD,
TAs; Devi-Orozcco Fuentes,
     Thi Thuc Nguyen,
Last Modified: May 14, 2025
*/

// Load libraries
#include <Wire.h>
#include <Adafruit_SHTC3.h>
#include <SparkFun_SCD4x_Arduino_Library.h>
#include <SD.h>
#include <SPI.h>

// Create Sensor and SD Card Objects
Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();
SCD4x scd4x;
File dataFile;

const int chipSelect = 10; // CS pin for SD card
const int ledPin = 13;      // LED pin

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  pinMode(ledPin, OUTPUT); // Set LED pin as output 

  Serial.println("Initializing System...");

  // Initialize SD card
  Serial.print("Initializing SD card... ");
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    while (1);
  }
  Serial.println("SD card OK.");

  // Initialize SHTC3 sensor
  Serial.print("Initializing SHTC3... ");
  if (!shtc3.begin()) {
    Serial.println("Couldn't find SHTC3!");
    while (1);
  }
  Serial.println("SHTC3 OK.");

  // Initialize SCD4x sensor
  Serial.print("Initializing SCD40... ");
  Wire.begin();
  if (!scd4x.begin()) {
    Serial.println("Couldn't find SCD40!");
    while (1);
  }
  scd4x.startPeriodicMeasurement();
  Serial.println("SCD40 OK.");

  // Always write the header
  dataFile = SD.open("envlog.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.println("millis,T_SHTC3,RH_SHTC3,T_SCD40,RH_SCD40,CO2");
    dataFile.close();
    Serial.println("Log header written.");
  } else {
    Serial.println("Failed to create log file.");
  }
}

void loop() {
  // LED ON before reading
  digitalWrite(ledPin, HIGH);  //ledPin
  delay(5000); // LED ON for 5 seconds
  // digital
 

  // Wait for SCD40 data
  while (!scd4x.readMeasurement()) {
    delay(100); // SCD40 updates ~every 5 seconds
  }
  // Record current time
  unsigned long timestamp = millis();

  //  Read from SHTC3 (synchronized to SCD-40) 
  sensors_event_t humidity, temp;
  shtc3.getEvent(&humidity, &temp);
  float sht_temp = temp.temperature;
  float sht_rh = humidity.relative_humidity;

  // Read SCD40 values 
  uint16_t co2 = scd4x.getCO2();
  float scd_temp = scd4x.getTemperature();
  float scd_rh = scd4x.getHumidity();

  // Format the data
  String dataString = String(timestamp) + "," +
                      String(sht_temp, 2) + "," +
                      String(sht_rh, 2) + "," +
                      String(scd_temp, 2) + "," +
                      String(scd_rh, 2) + "," +
                      String(co2);

  // Write to SD card 
  dataFile = SD.open("envlog.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println("Logged: " + dataString);
  } else {
    Serial.println("Error opening envlog.csv!");
  }

  // LED OFF after logging
  digitalWrite(ledPin, LOW);
  delay(5000); // LED OFF for 5 seconds
}
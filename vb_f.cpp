#include "vb_f.h"

String time_str;
int timeCurrentHourOfTheDay;
String printLocalTime(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return "Time Error";
  }
  //See http://www.cplusplus.com/reference/ctime/strftime/
  char output[80];
  // Serial.println(&timeinfo);
  strftime(output, 80, "%H", &timeinfo);
  time_str = String(output);
  timeCurrentHourOfTheDay = time_str.toInt();
  // Serial.print("timeCurrentHourOfTheDay: ");
  // Serial.println(timeCurrentHourOfTheDay);

  //strftime(output, 80, "%d-%b-%y %H:%M:%S", &timeinfo);
  strftime(output, 80, "%a %d-%b %H:%M:%S", &timeinfo);
  time_str = String(output);
  return String(output);
}

unsigned long ota_progress_millis = 0;

void onOTAStart() {
  // Log when OTA has started
  Serial.println("OTA update started!");
  // <Add your own code here>
  //display.clearDisplay();
  //display.setTextSize(1);
  //display.setTextColor(WHITE);
  //display.setCursor(0, 0);
  //display.println("OTA update started!");
  //display.display(); 
}

void onOTAProgress(size_t current, size_t final) {
  // Log every 1 second
  if (millis() - ota_progress_millis > 1000) {
    ota_progress_millis = millis();
    Serial.printf("OTA Progress Current: %u bytes, Final: %u bytes\n", current, final);
    //display.println("uploading...");
    //display.display(); 
  }
}

void onOTAEnd(bool success) {
  // Log when OTA has finished
  if (success) {
    Serial.println("OTA update finished successfully!");
    //display.println("OTA update finished successfully!");
    //display.println("rebooting...");
    //display.display(); 
  } else {
    Serial.println("There was an error during OTA update!");
  }
  // <Add your own code here>
}


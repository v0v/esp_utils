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

  String weekDay = weekDays[timeClient.getDay()];
  Serial.print("Week Day: ");
  Serial.println(weekDay); 

  //strftime(output, 80, "%d-%b-%y %H:%M:%S", &timeinfo);
  strftime(output, 80, weekDay+", "+"%d-%b %H:%M:%S", &timeinfo);
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

char* monthName(int monthNumber) {
    char* monthName = "xxx";
    switch (stamp.month) {
      case 1:
        strcpy(monthName, "Jan");
        break;
      case 2:
        strcpy(monthName, "Feb");
        break;
      case 3:
        strcpy(monthName, "Mar");
        break;
      case 4:
        strcpy(monthName, "Apr");
        break;
      case 5:
        strcpy(monthName, "May");
        break;
      case 6:
        strcpy(monthName, "Jun");
        break;
      case 7:
        strcpy(monthName, "Jul");
        break;
      case 8:
        strcpy(monthName, "Aug");
        break;
      case 9:
        strcpy(monthName, "Sep");
        break;
      case 10:
        strcpy(monthName, "Oct");
        break;
      case 11:
        strcpy(monthName, "Nov");
        break;
      case 12:
        strcpy(monthName, "Dec");
        break;
    }
}

//Week Days
String weekDays[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//Month names
String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

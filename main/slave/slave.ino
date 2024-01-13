#include <SoftwareSerial.h>
#include <SPIFFS.h>

SoftwareSerial mySerial(16, 17); // RX on pin 16, TX on pin 17

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600);

  if (!SPIFFS.begin(true)) {
    Serial.println("Error: Failed to mount SPIFFS");
    while (1) {
      delay(1000);
    }
  }
}

void loop() {
  // Wait for a request from the master
  while (!mySerial.available()) {
    delay(100);
  }

  // Read the request from the master
  String request = mySerial.readStringUntil('\n');
  Serial.println("Request from Master: " + request);

  // Check if the request is "REQ"
  if (request.startsWith("REQ")) {

    // Read the content of a file from SPIFFS
    String fileContent = readFileContent("/example.txt");

    // Respond with the file content
    mySerial.println("Data from Slave: " + fileContent);
  }

  // Add a delay before handling the next request
  delay(5000);
}

String readFileContent(const char* filePath) {
  String content = "";
  File file = SPIFFS.open(filePath, "r");
  if (file) {
    while (file.available()) {
      content += (char)file.read();
    }
    file.close();
  } else {
    Serial.println("Error opening file for reading");
  }
  return content;
}

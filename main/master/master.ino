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
  // Send request to slave
  mySerial.println("REQ example.txt");

  // Wait for response from slave
  while (!mySerial.available()) {
    delay(100);
  }

  // Read and print the response
  String response = mySerial.readStringUntil('\n');
  Serial.println("Response from Slave: " + response);

  // Save the received data into a file in SPIFFS
  saveDataToFile(response);

  // Check if the file is saved
  if (SPIFFS.exists("/received_data.txt")) {
    Serial.println("File saved in SPIFFS: received_data.txt");
  } else {
    Serial.println("Error: File not saved properly.");
  }

  printSavedFileContent();

  delay(5000); // Wait for 5 seconds before sending the next request
}

void saveDataToFile(String data) {
  // Open the file in SPIFFS for writing
  File file = SPIFFS.open("/received_data.txt", "w");

  if (!file) {
    Serial.println("Error: Unable to open file for writing");
    return;
  }

  // Write the received data to the file
  file.print(data);

  // Close the file
  file.close();
}

void printSavedFileContent() {
  // Open the file in SPIFFS for reading
  File file = SPIFFS.open("/received_data.txt", "r");

  if (!file) {
    Serial.println("Error: Unable to open file for reading");
    return;
  }

  // Read and print the content of the file
  Serial.println("Content of the saved file:");
  while (file.available()) {
    Serial.write(file.read());
  }

  // Close the file
  file.close();
}

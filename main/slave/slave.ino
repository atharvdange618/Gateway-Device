#include <SoftwareSerial.h>
#include <SPIFFS.h>

SoftwareSerial mySerial(16, 17); // RX on pin 16, TX on pin 17
#define FILE_REQUEST_CODE 'R'
#define FILE_CHUNK_SIZE 1024

void setup()
{
  Serial.begin(115200);
  mySerial.begin(9600);

  if (!SPIFFS.begin(true))
  {
    Serial.println("Error: Failed to mount SPIFFS");
    while (1)
    {
      delay(1000);
    }
  }
}

void loop()
{
  // Wait for a request from the master
  while (!mySerial.available())
  {
    delay(100);
  }

  // Read the request from the master
  String requestCommand = mySerial.readStringUntil('\n');
  Serial.println("Request from Master: " + requestCommand);

  String filename = requestCommand.substring(4);

  // Check if the request is "REQ"
  if (requestCommand.startsWith("REQ "))
  {
    Serial.println("File request received for: " + filename);

    // Get the requested file and send its content
    sendFile(filename);
  }
}

void sendFile(String filename)
{
  // Open the requested file for reading on the ESP32
  filename.trim();
  Serial.println("Sending file: " + filename);
  File file = SPIFFS.open("/" + filename, "r");

  if (!file)
  {
    Serial.println("Error opening file for reading");
    return;
  }

  // Send the start of file marker
  mySerial.println("STR" + filename);

  // Send the file content in chunks
  while (file.available())
  {
    char chunk[FILE_CHUNK_SIZE];
    int bytesRead = file.readBytes(chunk, FILE_CHUNK_SIZE);

    // Send the chunk to the master
    mySerial.write(chunk, bytesRead);

    // Add a small delay to allow the master to receive the data
    delay(5);
  }

  // Send an empty line as EOF marker
  mySerial.println();

  file.close();
  Serial.println("File sent");
}
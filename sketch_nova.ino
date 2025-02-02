#include <WiFi.h>
#include <HTTPClient.h>

// Replace with your network credentials
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

// Replace with your Express server URL
const char* serverName = "http://<your-server-ip>:3000/full-bin";

// Ultrasonic sensor pins
#define TRIG_PIN 5  // Trigger pin
#define ECHO_PIN 18 // Echo pin

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  // Wait for Wi-Fi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi");

  // Ultrasonic sensor setup
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long duration, distance;

  // Measure distance using ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 0.034) / 2;

  // Check if the bin is full (e.g., distance < 10 cm)
  if (distance < 10) {
    Serial.println("Bin is full. Sending notification...");
    sendPostRequest();
    delay(10000); // Avoid multiple alerts in a short period
  }

  delay(2000); // Delay for next measurement
}

void sendPostRequest() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Specify the URL
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    // JSON payload
    String jsonPayload = "{\"status\": \"full\"}";

    // Send the POST request
    int httpResponseCode = http.POST(jsonPayload);

    // Check the response
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Response: " + response);
    } else {
      Serial.print("Error in sending POST: ");
      Serial.println(http.errorToString(httpResponseCode).c_str());
    }

    http.end();
  } else {
    Serial.println("Wi-Fi not connected");
  }
}

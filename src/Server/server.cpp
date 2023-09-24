#include <WiFi.h>
#include <ESPAsyncWebServer.h>

#include "CommandLine/CommandLine.hpp"
#include "Program.h"

const char* ssid = "ESP32";

AsyncWebServer server(80);

void initServer() {
  // Set ESP32 as an access point
  WiFi.softAP(ssid, NULL);
  Serial.println("ESP32 AP SSID: " + String(ssid));

  // IP address of the ESP32 when acting as an AP
  IPAddress ip(192, 168, 1, 1);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.softAPConfig(ip, gateway, subnet);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String content = 
    "<!DOCTYPE html>\n"
    "<html>\n"
    "<head>\n"
    "  <title>LEDControl remote CLI</title>\n"
    "</head>\n"
    "<body>\n"
    "  <h1>Remote CLI</h1>\n"
    "  <form action=\"/run\" method=\"get\">\n"
    "    <label for=\"cmd\">Enter a command:</label>\n"
    "    <input type=\"text\" id=\"cmd\" name=\"cmd\" required>\n"
    "    <input type=\"submit\" value=\"Run Command\">\n"
    "  </form>\n"
    "</body>\n"
    "</html>\n";
    request->send(200, "text/html", content);
  });

  server.on("/run", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("cmd")) {
      String cmd = request->getParam("cmd")->value();
      // Execute the command (replace with your command execution logic)
      // For example, you can use the execCommand function here
      Serial.println("Command received: " + cmd);
      // Echo the user input
      Serial.print("# ");
      Serial.println(cmd);

      // Parse the user input into the CLI
      commandLine.parse(cmd);
      if (Program::isRecursive) {
      Program::command = cmd;
      }
    }
    request->redirect("/");
  });

  // Add more routes and actions as needed

  // Start server
  server.begin();
}

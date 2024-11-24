# ESP32 Local Network Messaging System

## Overview
The ESP32 acts as a Wi-Fi Access Point and a server that listens for incoming TCP connections on port 5000.

## Testing with TCP Client (Android)
The TCP Client (Android) app was used to test the server functionality on the ESP32. To try it yourself, follow these steps:

1. Install the **"TCP Client" app** 
2. After connecting your Android device to the ESP32's Wi-Fi network , configure the app with:
   - **IP Address**: `192.168.4.1`
   - **Port**: `5000` -> Or your settings
3. Send a message from the app, and the ESP32 will reply with an message like: "Mesage received: xxx".
# ESP32-LocalMessageServer

This project implements a local messaging server using an **ESP32**. The ESP32 acts as a TCP server, and a .NET client connects to it to send and receive messages.

## Features
- **TCP Server:** The ESP32 listens for messages on a specific port within the local network.
- **.NET Client:** A .NET application sends messages to the ESP32 server and receives responses.
- **ACK Response:** The ESP32 acknowledges each message received with a confirmation response.

## Requirements
### Hardware
- **ESP32** (with at least 4 MB flash memory).
- A Wi-Fi network for the connection.

### Software
- **Arduino IDE** (to program the ESP32).
  - Required library: `WiFi.h`
- **.NET SDK** (to run the client).
  - Language: C#.

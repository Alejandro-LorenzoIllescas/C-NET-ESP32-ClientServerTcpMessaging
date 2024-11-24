using System.Net;
using System.Net.Sockets;
using System.Text;

var esp32Ip = "192.168.4.1";  
var port = 5000;  

// Create the TCP client
var tcpClient = new TcpClient();

try
{
    // connection
    await tcpClient.ConnectAsync(esp32Ip, port);
    Console.WriteLine("Connected to ESP32!");

    // Get the network stream from the connection
    var networkStream = tcpClient.GetStream();

    var message = "Hello from .NET client!";
    byte[] messageBytes = Encoding.UTF8.GetBytes(message + "\n");

    // Send the message to server
    await networkStream.WriteAsync(messageBytes, 0, messageBytes.Length);

    // Read from server
    byte[] buffer = new byte[1024];
    int bytesRead = await networkStream.ReadAsync(buffer, 0, buffer.Length);
    string response = Encoding.UTF8.GetString(buffer, 0, bytesRead);

    Console.WriteLine("Response: " + response);
}
catch (Exception ex)
{
    Console.WriteLine("Error " + ex.Message);
}
finally
{
    tcpClient.Close();
}
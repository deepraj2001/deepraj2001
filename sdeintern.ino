#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
Adafruit_SSD1306 display(-1);
String r;
void setup()   
{                
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  

  // Clear the buffer.
  display.clearDisplay();



  // Display Text
}
void loop() {

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
 
     while (mySerial.available())
    {
        char character = mySerial.read(); // Receive a single character from the software serial port
        r.concat(character); // Add the received character to the receive buffer
        if (character == '\n')
        {
              display.print(r);        
        }
    }
 
  // Scroll full screen
  display.setCursor(0,0);
  display.setTextSize(1);
  display.display();
  display.startscrollright(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);    
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  display.clearDisplay();


}

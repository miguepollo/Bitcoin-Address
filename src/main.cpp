#include <Arduino.h>
#include <qrcode.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <Bitcoin.h>
#include <esp32_smartdisplay.h>
#define QRCODE_VERSION 5
void loop() {


}

void setup() {
Serial.begin(115200);
    // Serial.setDebugOutput(true);
    Serial.print("\n");
    generar_direcciones_derivadas_de_xpub();

}

void generar_direcciones_derivadas_de_xpub()
{
  // this is out account xpub from previous part
  HDPublicKey xpub("tpubDDEJkUr9sx6WxdwUT8Gei7P3bA2zsKuCPzmLG3WTtVEr7EJ83YDi3CCXyWWYKRhC9SFAx9zXSVPBT13uGRF8PK4WZRq3EGSujBxH1dmC4Vt");
  // deriving first 20 public keys and printing their addresses
  HDPublicKey pub;

  int btc_cursor_x = 275;
  int btc_cursor_y = 50;

  for(int i=0; i<20; i++){
    // deriving in a different manner
    pub = xpub.child(0).child(i);

    String btc_receive_address = pub.address();
    Serial.println(btc_receive_address);

    btc_cursor_y = (i*50) + 50;
    
    

}
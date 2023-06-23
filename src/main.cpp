#include <Arduino.h>
#include <qrcode.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <Bitcoin.h>
#include <esp32_smartdisplay.h>
#define QRCODE_VERSION 5


void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.print("\n");
}

void generar_direcciones_derivadas_de_xpub(){

  // this is out account xpub from previous part
  HDPublicKey xpub("tpubDDEJkUr9sx6WxdwUT8Gei7P3bA2zsKuCPzmLG3WTtVEr7EJ83YDi3CCXyWWYKRhC9SFAx9zXSVPBT13uGRF8PK4WZRq3EGSujBxH1dmC4Vt");
  // deriving first 20 public keys and printing their addresses
  HDPublicKey pub;

  int btc_cursor_x = 275;
  int btc_cursor_y = 50;

  for(int i=0; i<10; i++){
    // deriving in a different manner
    pub = xpub.child(0).child(i);

    String btc_receive_address = pub.address();
    Serial.println(btc_receive_address);

    btc_cursor_y = (i*50) + 50;
  }   
}


void codigoqrprueba() {
 Serial.begin(115200);

    // Start time
    uint32_t dt = millis();
  
    // Create the QR code
    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(3)];
    qrcode_initText(&qrcode, qrcodeData, 3, 0, "SUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU");
  
    // Delta time
    dt = millis() - dt;
    Serial.print("QR Code Generation Time: ");
    Serial.print(dt);
    Serial.print("\n");

    // Top quiet zone
    Serial.print("\n\n\n\n");

    for (uint8_t y = 0; y < qrcode.size; y++) {

        // Left quiet zone
        Serial.print("        ");

        // Each horizontal module
        for (uint8_t x = 0; x < qrcode.size; x++) {

            // Print each module (UTF-8 \u2588 is a solid block)
            Serial.print(qrcode_getModule(&qrcode, x, y) ? "\u2588\u2588": "  ");

        }

        Serial.print("\n");
    }

    // Bottom quiet zone
    Serial.print("\n\n\n\n");
}

void loop() {
generar_direcciones_derivadas_de_xpub();
delay(7000);
codigoqrprueba();
}

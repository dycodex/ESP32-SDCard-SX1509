#include <Arduino.h>
#include <FS.h>
#include <IOHAL.h>
#include <SDX.h>

// Instantiate IOHAL object with SX1509 interface
// The IOHAL class provides the digitalWrite, pinMode, digitalRead functions
// SDX library requires the pointer to object of this class to be passed to `begin` function
IOHAL io(IOHAL_SX1509);

#define SSPIN 6 // GPIO 6 on SX1509

void listDir(const char* dirname);

void setup() {
    Serial.begin(115200);

    io.begin();
    if (!SDX.begin(&io, SSPIN)) {
        Serial.println("Failed initializing SD Card!");
    } else {
        listDir("/");
    }
}

void loop() {

}

void listDir(const char * dirname){
    Serial.printf("Listing directory: %s\n", dirname);

    File root = SDX.open(dirname);
    if(!root){
        Serial.println("Failed to open directory");
        return;
    }
    if(!root.isDirectory()){
        Serial.println("Not a directory");
        return;
    }

    File file = root.openNextFile();
    while(file){
        if(file.isDirectory()){
            Serial.print("  DIR : ");
            Serial.println(file.name());
        } else {
            Serial.print("  FILE: ");
            Serial.print(file.name());
            Serial.print("  SIZE: ");
            Serial.println(file.size());
        }
        file = root.openNextFile();
    }
}


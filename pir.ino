#define DEVICE_ID "PIR_TEST"
#define PIN_PIR 5 // D1

// Timer: Auxiliary variables
//unsigned long now = millis();
//unsigned long lastTrigger = 0;
//boolean startTimer = false;

boolean movementTriggered = false;

void setup(void){
  Serial.begin(115200);
  wifiBegin();

  //callMiddleware("pir", "");

  //ESP.deepSleep(0);

  // PIR Motion Sensor mode INPUT_PULLUP
  pinMode(PIN_PIR, INPUT_PULLUP);
  // Set motionSensor pin as interrupt, assign interrupt function and set RISING mode
  attachInterrupt(digitalPinToInterrupt(PIN_PIR), detectsMovement, RISING);
}

void loop(void){
   wifiCheck();
   checkMovement(); 
}

void checkMovement() {
  if (movementTriggered) {
    callMiddleware("pir", "");
    movementTriggered = false;
  }
}

ICACHE_RAM_ATTR void detectsMovement() {
  Serial.println("MOTION DETECTED!!!");
  movementTriggered = true;
  //startTimer = true;
  //lastTrigger = millis();
}


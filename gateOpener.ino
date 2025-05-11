  #include <Servo.h>

  class GateController {
  private:
      const int TRIG_PIN = 2;
      const int ECHO_PIN = 3;
      const int RED_LED_PIN = 4;
      const int RED_GND_PIN = 8;
      const int BLUE_GND_PIN = 7;
      const int BLUE_LED_PIN = 5;
      const int SERVO_PIN = 6;
      const int BUZZER_PIN = 12;
      
      const float DETECT_RANGE = 50.0;
      const int GATE_CLOSED = 0;
      const int GATE_OPEN = 90;
      const unsigned long AUTO_CLOSE_TIME = 5000;
      
      const unsigned long BEEP_DURATION = 50;
      const unsigned long BEEP_INTERVAL = 500;
      
      Servo gateServo;
      bool gateStatus;
      unsigned long lastSeenTime;
      unsigned long lastBeep;
      bool beepState;
      
      float measureDistance() {
          digitalWrite(TRIG_PIN, LOW);
          delayMicroseconds(2);
          digitalWrite(TRIG_PIN, HIGH);
          delayMicroseconds(10);
          digitalWrite(TRIG_PIN, LOW);
          return pulseIn(ECHO_PIN, HIGH) / 20.0;
      }
      
      void updateLeds(bool open) {
          digitalWrite(RED_LED_PIN, !open);
          digitalWrite(BLUE_LED_PIN, open);
      }
      
      void operateGate(bool open) {
          gateServo.write(open ? GATE_OPEN : GATE_CLOSED);
          gateStatus = open;
          updateLeds(open);
      }

  public:
      GateController() : gateStatus(false), lastSeenTime(0), lastBeep(0), beepState(false) {}
      
      void initialize() {
          pinMode(TRIG_PIN, OUTPUT);
          pinMode(ECHO_PIN, INPUT);
          pinMode(RED_LED_PIN, OUTPUT);
          pinMode(RED_GND_PIN, OUTPUT);
          pinMode(BLUE_GND_PIN, OUTPUT);
          digitalWrite(RED_GND_PIN, LOW);
          digitalWrite(BLUE_GND_PIN, LOW);
          pinMode(BLUE_LED_PIN, OUTPUT);
          pinMode(BUZZER_PIN, OUTPUT);
          
          gateServo.attach(SERVO_PIN);
          operateGate(false);
      }
      
      void process() {
          float dist = measureDistance();
          unsigned long now = millis();
          
          if (dist < DETECT_RANGE) {
              if (!gateStatus) {
                  operateGate(true);
              }
              lastSeenTime = now;
          } else if (gateStatus && (now - lastSeenTime > AUTO_CLOSE_TIME)) {
              operateGate(false);
              digitalWrite(BUZZER_PIN, LOW);
          }
          
          if (gateStatus) {
              if (!beepState && (now - lastBeep >= BEEP_INTERVAL)) {
                  digitalWrite(BUZZER_PIN, HIGH);
                  beepState = true;
                  lastBeep = now;
              } else if (beepState && (now - lastBeep >= BEEP_DURATION)) {
                  digitalWrite(BUZZER_PIN, LOW);
                  beepState = false;
              }
          }
          delay(50);
      }
  };

  GateController controller;

  void setup() {
      controller.initialize();
  }

  void loop() {
      controller.process();
  }
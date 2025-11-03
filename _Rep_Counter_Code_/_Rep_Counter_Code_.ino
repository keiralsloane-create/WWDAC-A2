
// HC-SR04 Push-up Counter with 4-Digit TM1637 Display
// This project uses an ultrasonic distance sensor (HC-SR04) to detect push-ups
// and count repetitions on a 4-digit TM1637 display.
// A buzzer gives a short beep after each successful push-up.
// YouTube reference: https://youtu.be/u9JauTRP_cc


#include <TM1637Display.h>  // Library required for the 4-digit display

//  PIN DEFINITIONS 

// Ultrasonic sensor pins
#define echoPin  2      
#define trigPin  3      
#define resetPin 4      

// 4-digit display pins
#define CLK 11          
#define DIO 12          

// Create display object
TM1637Display display(CLK, DIO);

// VARIABLES 
float duration;          
float cm;                // Calculated distance in centimeters
boolean trigUp = false;  // Flag: true when user moves up
boolean trigDown = false;// Flag: true when user moves down
int counterPushUp = 0;   // Push-up counter
int buzzer = 7;          // Passive buzzer pin (for sound feedback)


// SETUP: Runs once when Arduino powers on or resets

void setup() {
  pinMode(buzzer, OUTPUT);       
  Serial.begin(9600);            // Start Serial Monitor for debugging
  pinMode(trigPin, OUTPUT);      
  pinMode(echoPin, INPUT);       
  pinMode(resetPin, INPUT_PULLUP); 

  // Initialize the 4-digit display
  display.setBrightness(7);      
  display.showNumberDec(0);      
}

// LOOP: Runs continuously after setup()

void loop() {

  // RESET SECTION 
  // If the reset button is pressed 
  if (digitalRead(resetPin) == 0) {
    // Reset triggers and counter
    trigUp = false;
    trigDown = false;
    counterPushUp = 0;

    // Show 0 on the display
    display.showNumberDec(counterPushUp);

    // Small delay to prevent bouncing (double reset)
    delay(500);
  }

  // ULTRASONIC MEASUREMENT 
  // Send a short pulse to trigger the HC-SR04
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure how long it takes for the pulse to return
  duration = pulseIn(echoPin, HIGH);

  // Convert time (in microseconds) to distance (in cm)
  // Sound speed = 0.034 cm per microsecond; divide by 2 for round trip
  cm = duration * 0.034 / 2.0;

  // PUSH-UP DETECTION 
  // If user moves up (away from sensor)
  if (cm > 15 && cm <= 30) {
    trigUp = true;   // Mark "up" position detected
  } 
  // If user moves down (close to sensor)
  else if (cm < 10) {
    trigDown = true; // Mark "down" position detected
  }

  // If both up and down movements have occurred → count 1 push-up
  if (trigUp == true && trigDown == true) {
    counterPushUp++;        // Increase count by 1

    // Reset triggers for the next repetition
    trigUp = false;
    trigDown = false;

    // Short beep sound for feedback
    tone(buzzer, 800, 100); // (pin, frequency, duration in ms)

    // Update the display with the new push-up count
    display.showNumberDec(counterPushUp, false);

    // Short pause to avoid double-counting fast movements
    delay(700);
  }

  // SERIAL MONITOR OUTPUT
  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.print(" cm | Count: ");
  Serial.println(counterPushUp);
}

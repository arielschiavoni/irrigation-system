
#define LED_YELLOW_PIN 12

const unsigned int interval_led_builtin = 500;
const unsigned int interval_led_yellow = 2000;
unsigned long start_time_led_yellow = 0;
unsigned long start_time_led_builtin = 0;
bool led_yellow_on = 0;
bool led_builtin_on = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
  Serial.begin(9600);      // open the serial port at 9600 bps:
}

void loop() {
  unsigned long current_time = millis();

  if (current_time - start_time_led_yellow > interval_led_yellow) {
    led_yellow_on = !led_yellow_on;
    digitalWrite(LED_YELLOW_PIN, led_yellow_on);
    start_time_led_yellow = current_time;
    Serial.print("LED_YELLOW_PIN");
    Serial.print("\t");
    Serial.println(start_time_led_yellow);
  }

  if (current_time - start_time_led_builtin > interval_led_builtin) {
    led_builtin_on = !led_builtin_on;
    digitalWrite(LED_BUILTIN, led_builtin_on);
    start_time_led_builtin = current_time;
    Serial.print("LED_BUILTIN");
    Serial.print("\t");
    Serial.println(start_time_led_builtin);
  }
}

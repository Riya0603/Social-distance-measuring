

LiquidCrystal_I2C lcd(0x27, 16,2);
const int triggerPin = 3;
const int echoPin = 2;
long duration;
int distanceCm, distanceInch;
void setup() {
  lcd.init();
  lcd.begin(16, 2); // Initializes the interface to the LCD display
  lcd.backlight();
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.0340 / 2;
  distanceInch = duration * 0.01330 / 2;
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  Serial.println(distanceCm);
  lcd.print(distanceCm);
  lcd.print(" cm");
  lcd.setCursor(0, 1);
  lcd.print("    ");
  lcd.print(distanceInch);
  lcd.print(" inch");
  delay(500);
}

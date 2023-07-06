// declaration
int read_ADC;
int turbidity;
int sensor_pin = A0;
int greenled = 7;
int yellowled = 8;
int redled = 9;

void setup() {
  Serial.begin(9600);

  pinMode(sensor_pin,INPUT);;
  pinMode(greenled,OUTPUT);
  pinMode(yellowled,OUTPUT);
  pinMode(redled,OUTPUT);
}

void loop() {

  read_ADC = analogRead(sensor_pin);
  
  if(read_ADC>208){
    read_ADC=208;
  }
  turbidity = map(read_ADC, 0, 208, 300, 0);

  if (turbidity < 20) {
    digitalWrite(greenled, HIGH);
    digitalWrite(yellowled, LOW);
    digitalWrite(redled, LOW);
  }
  else if ((turbidity >= 20) && (turbidity < 50)) {
    digitalWrite(greenled, LOW);
    digitalWrite(yellowled, HIGH);
    digitalWrite(redled, LOW);
  }
  else {
    digitalWrite(greenled, LOW);
    digitalWrite(yellowled, LOW);
    digitalWrite(redled, HIGH);
  }
  
  Serial.print("Turbidity Rate (NTU): ");
  Serial.println(turbidity);

  delay(1000);
}

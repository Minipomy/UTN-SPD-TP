#define Diplay_A 10
#define Diplay_B 11
#define Diplay_C 5
#define Diplay_D 6
#define Diplay_E 7
#define Diplay_F 9
#define Diplay_G 8

// Define los pines para los segmentos
int segmentPins[] = {Diplay_A, Diplay_B, Diplay_C, Diplay_D, Diplay_E, Diplay_F, Diplay_G};
// Define los pines para los displays
int displayPins[] = {A4, A5};
int sensorsPins[] = {0};
int ledPins[] = {12};
int motorPins[] = {3};
int photoPins[] = {A2};

void setup() {
  // Configura los pines de los segmentos salidas
  IOS_config();
  // Configura los pines de los displays como salidas
  DISPLAYS_config();
  // Configura el pin del sensor como salidas
  SENSOR_config();
  // Configura el pin del motor como salidas
  MOTOR_config();
  // Configura el pin del fotosensor como salidas
  PHOTO_config();
  
  // Testing purpose
  Serial.begin(9600);
}

void loop() {
  // Muestra el valor del contador en los displays
  showNumber(calcularCentigrados());
  delay(20);
  motorControl(calcularCentigrados());
  delay(20);
  
  //Testing purpose
  Serial.print("El valor luminico representado es: ");
  Serial.println(analogRead(photoPins[0]));
}
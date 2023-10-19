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
// Define los pines para los botones
int buttonPins[] = {2, 3};
// Pin del switch
int switchPins[] = {12};
// Variable para almacenar el valor del contador
int counter = 0;
// Variable global del estado actual del boton                     
int estado_actual = LOW;					                        


void setup() {
  // Configura los pines de los segmentos salidas
  IOS_config();
  // Configura los pines de los displays como salidas
  DISPLAYS_config();
  // Configura los pines de los botones como entradas
  BUTTONS_config();   
  // Configura el pin del switch como entrada
  SWITCH_config();
  
  // Testing purpose
  //Serial.begin(9600);
}

void loop() {
  // Funcion que maneja el control de los botones y switches
  buttonsActions();
  // Muestra el valor del contador en los displays
  showNumber(counter);
  
  // Testing purpose
  //Serial.println(digitalRead(switchPins[0]));
}
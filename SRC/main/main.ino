#define Diplay_A 10
#define Diplay_B 11
#define Diplay_C 5
#define Diplay_D 6
#define Diplay_E 7
#define Diplay_F 9
#define Diplay_G 8

int segmentPins[] = {Diplay_A, Diplay_B, Diplay_C, Diplay_D, Diplay_E, Diplay_F, Diplay_G};  // Define los pines para los segmentos
int displayPins[] = {A4, A5};                 // Define los pines para los displays
int buttonPins[] = {2, 3, 4};                 // Define los pines para los botones
int counter = 0;                              // Variable para almacenar el valor del contador

void setup() {
  IOS_config();        // Configura los pines de los segmentos salidas
  DISPLAYS_config();   // Configura los pines de los displays como salidas
  BUTTONS_config();   // Configura los pines de los botones como entradas
}

void loop() {
  buttonsActions();
  showNumber(counter);  // Muestra el valor del contador en los displays
}
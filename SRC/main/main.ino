int segmentPins[] = {5, 6, 7, 8, 9, 10, 11};  // Define los pines para los segmentos
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
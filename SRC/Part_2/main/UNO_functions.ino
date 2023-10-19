void IOS_config(){
  // Son los pines de los segmentos salidas.
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void DISPLAYS_config(){
  // Son los pines de los displays como salidas.
  for (int i = 0; i < 2; i++) {
    pinMode(displayPins[i], OUTPUT);
    digitalWrite(displayPins[i], LOW);
  }
}

void BUTTONS_config(){
  // Son los pines de los botones como esntrada.
  for (int i = 0; i < 2; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void SWITCH_config() {
  // Configura el pin del switch como entrada
  for (int i = 0; i < 1; i++) {
    pinMode(switchPins[i], INPUT);
  }
}

void showNumber(int number) {
  // Recorre una lista de 7 segmentos en Multiplexacion y por un delay.
  int digits[2] = {number / 10, number % 10};
  for (int i = 0; i < 2; i++) {
    digitalWrite(displayPins[i], HIGH);
    showDigit(digits[i]);
    delay(50);
    digitalWrite(displayPins[i], LOW);
  }
}

bool numero_primo(int numero) {
  // Retorna un booleano dependiendo si el numero es primo o no
  if (numero == 1 or numero == 0) {
    return false;
  }
  for (int i = 2; i * i <= numero; i++) {
    if (numero % i == 0)
      return false;
    }
  return true;
}

void buttonsActions(){ 
  estado_actual = digitalRead(switchPins[0]);  
  // Leer el estado de los botones
  if (digitalRead(buttonPins[0]) == LOW) { 
    // AUMENTA EL VALOR DEL CONTADOR
    // Si el primer botón está presionado, incrementar el contador
    if (estado_actual == HIGH) {
      // Si el switch esta encendido, trabaja con numeros primos
      do{counter++;}while(!numero_primo(counter));
      delay(200);
    }
    else{counter++;}
    if (counter > 99) {counter = 0;}
    delay(200);
  }
  else if (digitalRead(buttonPins[1]) == LOW) { // RESETEA EL VALOR DEL CONTADOR
    // Si el segundo botón está presionado, resetear el contador a cero
    counter = 0;
    delay(200);
  }
}

void showDigit(int digit) {
  displayClear();
   switch (digit) {
    // Enciende conjunto LED correspondiente al numero. 
  	case 0:
      digitalWrite(Diplay_A, HIGH); 
      digitalWrite(Diplay_B, HIGH); 
      digitalWrite(Diplay_C, HIGH); 
      digitalWrite(Diplay_D, HIGH); 
      digitalWrite(Diplay_E, HIGH); 
      digitalWrite(Diplay_F, HIGH); 
      break;
  	case 1: 
      digitalWrite(Diplay_B, HIGH); 
      digitalWrite(Diplay_C, HIGH); 
    	break;
    case 2: 
      digitalWrite(Diplay_A, HIGH);
    	digitalWrite(Diplay_B, HIGH); 
      digitalWrite(Diplay_G, HIGH); 
    	digitalWrite(Diplay_E, HIGH); 
    	digitalWrite(Diplay_D, HIGH); 
    	break;
    case 3: 
      digitalWrite(Diplay_A, HIGH);
    	digitalWrite(Diplay_B, HIGH); 
      digitalWrite(Diplay_G, HIGH); 
    	digitalWrite(Diplay_C, HIGH); 
    	digitalWrite(Diplay_D, HIGH); 
    	break;
    case 4: 
      digitalWrite(Diplay_F, HIGH);
    	digitalWrite(Diplay_G, HIGH); 
      digitalWrite(Diplay_B, HIGH); 
    	digitalWrite(Diplay_C, HIGH); 
    	break;
    case 5: 
      digitalWrite(Diplay_A, HIGH);
    	digitalWrite(Diplay_F, HIGH); 
      digitalWrite(Diplay_G, HIGH); 
    	digitalWrite(Diplay_C, HIGH);
    	digitalWrite(Diplay_D, HIGH);
    	break;
    case 6: 
      digitalWrite(Diplay_A, HIGH);
    	digitalWrite(Diplay_F, HIGH); 
      digitalWrite(Diplay_G, HIGH); 
    	digitalWrite(Diplay_C, HIGH);
    	digitalWrite(Diplay_E, HIGH);
    	digitalWrite(Diplay_D, HIGH);
    	break;
    case 7: 
      digitalWrite(Diplay_A, HIGH);
    	digitalWrite(Diplay_B, HIGH); 
    	digitalWrite(Diplay_C, HIGH);
    	break;
    case 8: 
      digitalWrite(Diplay_A, HIGH); 
      digitalWrite(Diplay_B, HIGH); 
      digitalWrite(Diplay_C, HIGH); 
      digitalWrite(Diplay_D, HIGH); 
      digitalWrite(Diplay_E, HIGH); 
      digitalWrite(Diplay_F, HIGH);    	
      digitalWrite(Diplay_G, HIGH);
    	break;
    case 9: 
      digitalWrite(Diplay_A, HIGH); 
      digitalWrite(Diplay_B, HIGH); 
      digitalWrite(Diplay_C, HIGH);  
      digitalWrite(Diplay_F, HIGH);
    	digitalWrite(Diplay_G, HIGH);
    	break;
  	default:
    	// Finaliza el display
    	break;
   }
}
  
void displayClear(){ // Limpia el display.
  digitalWrite(Diplay_A, LOW); 
	digitalWrite(Diplay_B, LOW); 
	digitalWrite(Diplay_C, LOW); 
	digitalWrite(Diplay_D, LOW); 
	digitalWrite(Diplay_E, LOW); 
	digitalWrite(Diplay_F, LOW); 
	digitalWrite(Diplay_G, LOW); 
}
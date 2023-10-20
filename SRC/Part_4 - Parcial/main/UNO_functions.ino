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

void SENSOR_config() {
  // Son el pin del sensor como salidas.
  for (int i = 0; i < 1; i++) {
    pinMode(sensorsPins[i],OUTPUT);
  }
}

void MOTOR_config() {
  for(int i =0; i < 1; i++) {
    pinMode(motorPins[i], OUTPUT);
  }
}

void PHOTO_config() {
  for(int i =0; i < 1; i++) {
    pinMode(photoPins[i], OUTPUT);
  }
}

int calcularCentigrados() {
  int sensor_valor = analogRead(sensorsPins[0]); // Probando con un potenciador los pines analogicos toman de 0 a 1023 valores
  //float potencia = 5.0 / 1024 * sensor_valor; // potencia
  //float temperatura = potencia * 100 - 50;
  float temperatura = map(sensor_valor, 20, 358, -40, 125);
  return(temperatura);
}

void motorControl(float temperatura) {
  if (temperatura >= 60) {
    analogWrite(motorPins[0], -500);
  }
  else if (temperatura <= 15){
    analogWrite(motorPins[0], -20);
  }
  else {
    analogWrite(motorPins[0], 200);
  }
}

void showNumber(int number) {
  // Recorre una lista de 7 segmentos en Multiplexacion y por un delay.
  if(bajoZero(number) == true){
    number *= -1;
    digitalWrite(ledPins[0], HIGH);
  }
  else {digitalWrite(ledPins[0], LOW);}
  if(number > 99){number = 99;}
  int digits[2] = {number / 10, number % 10};
  for (int i = 0; i < 2; i++) {
    digitalWrite(displayPins[i], HIGH);
    showDigit(digits[i]);
    delay(50);
    digitalWrite(displayPins[i], LOW);
  }
}

bool bajoZero(int temperatura) {
  if(temperatura < 0){
    return true;
  }
  return false;
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
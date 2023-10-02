void IOS_config(){
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void DISPLAYS_config(){
  for (int i = 0; i < 2; i++) {
    pinMode(displayPins[i], OUTPUT);
    digitalWrite(displayPins[i], LOW);
  }
}

void BUTTONS_config(){
    for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void showNumber(int number) {
   int digits[2] = {number / 10, number % 10};
   
   for (int i = 0; i < 2; i++) {
     digitalWrite(displayPins[i], HIGH);
     showDigit(digits[i]);
     delay(12);
     digitalWrite(displayPins[i], LOW);
   }
}

void buttonsActions(){
  // Leer el estado de los botones
  if (digitalRead(buttonPins[0]) == LOW) {
    // Si el primer botón está presionado, incrementar el contador
    counter++;
    if (counter > 99) {
      counter = 0;
    }
    delay(200);
  } else if (digitalRead(buttonPins[1]) == LOW) {
    // Si el segundo botón está presionado, decrementar el contador
    counter--;
    if (counter < 0) {
      counter = 99;
    }
    delay(200);
  } else if (digitalRead(buttonPins[2]) == LOW) {
    // Si el tercer botón está presionado, resetear el contador a cero
    counter = 0;
    delay(200);
  }
}

void showDigit(int digit) {
  displayClear();
   switch (digit) {
  	case 0:
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(9, HIGH); 
      digitalWrite(10, HIGH); 
      digitalWrite(11, HIGH); 
      break;
  	case 1: 
      digitalWrite(11, HIGH); 
      digitalWrite(5, HIGH); 
    	break;
    case 2: 
      digitalWrite(10, HIGH);
    	digitalWrite(11, HIGH); 
      digitalWrite(8, HIGH); 
    	digitalWrite(7, HIGH); 
    	digitalWrite(6, HIGH); 
    	break;
    case 3: 
      digitalWrite(10, HIGH);
    	digitalWrite(11, HIGH); 
      digitalWrite(8, HIGH); 
    	digitalWrite(5, HIGH); 
    	digitalWrite(6, HIGH); 
    	break;
    case 4: 
      digitalWrite(9, HIGH);
    	digitalWrite(11, HIGH); 
      digitalWrite(8, HIGH); 
    	digitalWrite(5, HIGH); 
    	break;
    case 5: 
      digitalWrite(10, HIGH);
    	digitalWrite(9, HIGH); 
      digitalWrite(8, HIGH); 
    	digitalWrite(5, HIGH);
    	digitalWrite(6, HIGH);
    	break;
    case 6: 
      digitalWrite(10, HIGH);
    	digitalWrite(9, HIGH); 
      digitalWrite(8, HIGH); 
    	digitalWrite(5, HIGH);
    	digitalWrite(7, HIGH);
    	digitalWrite(6, HIGH);
    	break;
    case 7: 
      digitalWrite(10, HIGH);
    	digitalWrite(11, HIGH); 
    	digitalWrite(5, HIGH);
    	break;
    case 8: 
      digitalWrite(10, HIGH); 
      digitalWrite(11, HIGH); 
      digitalWrite(5, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(9, HIGH);    	
      digitalWrite(8, HIGH);
    	break;
    case 9: 
      digitalWrite(10, HIGH); 
      digitalWrite(11, HIGH); 
      digitalWrite(5, HIGH);  
      digitalWrite(9, HIGH);
    	digitalWrite(8, HIGH);
    	break;
  	default:
    	// statements
    	break;
   }
}
  
void displayClear(){
  digitalWrite(5, LOW); 
	digitalWrite(6, LOW); 
	digitalWrite(7, LOW); 
	digitalWrite(8, LOW); 
	digitalWrite(9, LOW); 
	digitalWrite(10, LOW); 
	digitalWrite(11, LOW); 
}
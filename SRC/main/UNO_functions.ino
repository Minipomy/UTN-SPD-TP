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
    delay(200); // Debounce
  } else if (digitalRead(buttonPins[1]) == LOW) {
    // Si el segundo botón está presionado, decrementar el contador
    counter--;
    if (counter < 0) {
      counter = 99;
    }
    delay(200); // Debounce
  } else if (digitalRead(buttonPins[2]) == LOW) {
    // Si el tercer botón está presionado, resetear el contador a cero
    counter = 0;
    delay(200); // Debounce
  }
}

void showDigit(int digit) {
  displayClear();
   switch (digit) {
  	case 0:
      digitalWrite(5, 1); 
      digitalWrite(6, 1); 
      digitalWrite(7, 1); 
      digitalWrite(9, 1); 
      digitalWrite(10, 1); 
      digitalWrite(11, 1); 
      break;
  	case 1: 
      	digitalWrite(11, 1); 
      	digitalWrite(5, 1); 
    	break;
    case 2: 
      	digitalWrite(10, 1);
    	digitalWrite(11, 1); 
      	digitalWrite(8, 1); 
    	digitalWrite(7, 1); 
    	digitalWrite(6, 1); 
    	break;
    case 3: 
      	digitalWrite(10, 1);
    	digitalWrite(11, 1); 
      	digitalWrite(8, 1); 
    	digitalWrite(5, 1); 
    	digitalWrite(6, 1); 
    	break;
    case 4: 
      	digitalWrite(9, 1);
    	digitalWrite(11, 1); 
      	digitalWrite(8, 1); 
    	digitalWrite(5, 1); 
    	break;
    case 5: 
      	digitalWrite(10, 1);
    	digitalWrite(9, 1); 
      	digitalWrite(8, 1); 
    	digitalWrite(5, 1);
    	digitalWrite(6, 1);
    	break;
    case 6: 
      	digitalWrite(10, 1);
    	digitalWrite(9, 1); 
      	digitalWrite(8, 1); 
    	digitalWrite(5, 1);
    	digitalWrite(7, 1);
    	digitalWrite(6, 1);
    	break;
    case 7: 
      	digitalWrite(10, 1);
    	digitalWrite(11, 1); 
    	digitalWrite(5, 1);
    	break;
    case 8: 
      	digitalWrite(10, 1); 
      	digitalWrite(11, 1); 
      	digitalWrite(5, 1); 
      	digitalWrite(6, 1); 
      	digitalWrite(7, 1); 
      	digitalWrite(9, 1);    	
        digitalWrite(8, 1);
    	break;
    case 9: 
      	digitalWrite(10, 1); 
      	digitalWrite(11, 1); 
      	digitalWrite(5, 1);  
      	digitalWrite(9, 1);
    	digitalWrite(8, 1);
    	break;
  	default:
    	// statements
    	break;
   }
}
  
void displayClear(){
  	digitalWrite(5, 0); 
	digitalWrite(6, 0); 
	digitalWrite(7, 0); 
	digitalWrite(8, 0); 
	digitalWrite(9, 0); 
	digitalWrite(10, 0); 
	digitalWrite(11, 0); 
}
# Arduino Multiplexación
![Tinkercad](./IMG/ArduinoTinkercad.jpg)


## Integrantes 
- Maximiliano A. Rivera Mendes
- Hernan Robbiano
- Irina Rivas Ramirez


## Proyecto: Display 7 Segmentos y Multiplexación.
![Tinkercad](./IMG/Arduino-multiplexor.png)


## Descripción
Diseña un contador de 0 a 99 utilizando dos displays de 7 segmentos y tres botones para
controlar la cuenta. Estos botones, incrementan, decrementan o resetean el contador.

## Función principal
**FUNCION:** ___Esta funcion se encarga de enceder los LEDs de un display.___\
**USO:** ___Recorre una lista de Display de 7 segmentos en Multiplexación y por un delay, transiciona de una en otra.___\
**VARIABLES:** ___number de tipo entero, es el valor que va a imprimir en los displays.___\
**RETORNA:** ___None___

~~~ C
void showNumber(int number) {
   int digits[2] = {number / 10, number % 10};
   
   for (int i = 0; i < 2; i++) {
     digitalWrite(displayPins[i], HIGH);
     showDigit(digits[i]);
     delay(50);
     digitalWrite(displayPins[i], LOW);
   }
}
~~~

## :robot: Link al proyecto
- [Proyecto: Tinkercad](https://www.tinkercad.com/things/6XI9OxBgVjY)






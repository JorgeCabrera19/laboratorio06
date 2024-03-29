int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
int LED7 = 8;
int LED8 = 9;
int pulsador1 = 10;
int pulsador2 = 11;
int pulsador3 = 12;
int pulsador4 = 13;

bool estado1 = false;
bool estado2 = false;
bool estado3 = false;
bool estado4 = false;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(pulsador1, INPUT_PULLUP);
  pinMode(pulsador2, INPUT_PULLUP);
  pinMode(pulsador3, INPUT_PULLUP);
  pinMode(pulsador4, INPUT_PULLUP);
  Serial.begin(9600); // Inicializar la comunicación serial
}

void loop() {
  // Control de los LEDs con los pulsadores físicos
  if (digitalRead(pulsador1) == LOW) {
    estado1 = !estado1;
    digitalWrite(LED1, estado1);
    digitalWrite(LED2, estado1);
    delay(200); // Pequeña pausa para evitar el rebote del pulsador
  }

  if (digitalRead(pulsador2) == LOW) {
    estado2 = !estado2;
    digitalWrite(LED3, estado2);
    digitalWrite(LED4, estado2);
    delay(200); // Pequeña pausa para evitar el rebote del pulsador
  }

  if (digitalRead(pulsador3) == LOW) {
    estado3 = !estado3;
    digitalWrite(LED5, estado3);
    digitalWrite(LED6, estado3);
    delay(200); // Pequeña pausa para evitar el rebote del pulsador
  }

  if (digitalRead(pulsador4) == LOW) {
    estado4 = !estado4;
    digitalWrite(LED7, estado4);
    digitalWrite(LED8, estado4);
    delay(200); // Pequeña pausa para evitar el rebote del pulsador
  }

  // Control de los LEDs con comandos desde el puerto serial
  if (Serial.available() > 0) {
    char comando = Serial.read();
    if (comando == '1') {
      estado1 = !estado1;
      digitalWrite(LED1, estado1);
      digitalWrite(LED2, estado1);
    } else if (comando == '2') {
      estado2 = !estado2;
      digitalWrite(LED3, estado2);
      digitalWrite(LED4, estado2);
    } else if (comando == '3') {
      estado3 = !estado3;
      digitalWrite(LED5, estado3);
      digitalWrite(LED6, estado3);
    } else if (comando == '4') {
      estado4 = !estado4;
      digitalWrite(LED7, estado4);
      digitalWrite(LED8, estado4);
    }
    delay(50); // Breve espera para evitar la acumulación de datos en el puerto serial
  }
}









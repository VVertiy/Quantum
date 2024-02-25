#define ALONE 
#define BLUE 2
#define RED 4
#define BEEP 3

//****ПАРАМЕТРЫ ОТВЕТА
#define LEN 8 // количество знаков в ответе
byte mas[LEN] = { 12, 16, 17, 10, 17, 27, 17, 18 } ;
byte num = 0;
bool sep = false;
//****КОНЕЦ ПАРАМЕТРОВ ОТВЕТА

bool redFlag = false;
bool blueFlag = false;
byte count = 0;
int timeLed = 500;
long timerRed;
long timerBlue;
const byte P[] = {12, 11, 10, 9}; 
const byte M[] = {8, 7, 6, 5};   
const int k4x4 [4][4] = {     
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// старварс
int notes[] = {
  392, 392, 392, 311, 466, 392, 311, 466, 392,
  587, 587, 587, 622, 466, 369, 311, 466, 392,
  784, 392, 392, 784, 739, 698, 659, 622, 659,
  415, 554, 523, 493, 466, 440, 466,
  311, 369, 311, 466, 392
};
int times[] = {
  350, 350, 350, 250, 100, 350, 250, 100, 700,
  350, 350, 350, 250, 100, 350, 250, 100, 700,
  350, 250, 100, 350, 250, 100, 100, 100, 450,
  150, 350, 250, 100, 100, 100, 450,
  150, 350, 250, 100, 750
};

void setup() {

  for (int i = 0; i <= 3; i++) {  
    pinMode(P[i], OUTPUT);
    pinMode(M[i], INPUT_PULLUP);
    digitalWrite(P[i], HIGH);
  }
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BEEP, OUTPUT);
  Serial.begin(9600);
  Serial.println("begin");
}

void loop() {
  if (redFlag && millis() - timerRed > timeLed) { digitalWrite(RED, LOW); redFlag = false; }
  if (blueFlag && millis() - timerBlue > timeLed) { digitalWrite(BLUE, LOW); blueFlag = false; }

  int a = GetKey4x4();             // опрашиваем клавиатуру
  if (a != 0) {     
    Serial.print(a); 
    Serial.print(int(a));

    if (sep){
      num += int(a) - 48;
      sep = false;

      if(num == mas[count]){
        count += 1;
        digitalWrite(BLUE, HIGH);
        timerBlue = millis();
        blueFlag = true;
        num = 0;
      }
      else{
        Serial.println(num);
        digitalWrite(RED, HIGH);
        timerRed = millis();
        redFlag = true;
        StarWars();
        Serial.println("error");
        count = 0;
        num = 0;
      }

    }   
    else{
      num += (int(a)-48) * 10;
      sep = true;
    }

    if (count == LEN){
      Serial.println("YOU WON!!!");  
      RusAnthem(BEEP);
      count = 0;
      num = 0;
    }
  }
}
//
void RusAnthem(byte tonePin){
  tone(tonePin, 174, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 174, 374.999625);
    delay(416.66625);
    tone(tonePin, 195, 124.999875);
    delay(138.88875);
    tone(tonePin, 220, 499.9995);
    delay(555.555);
    tone(tonePin, 146, 249.99975);
    delay(277.7775);
    tone(tonePin, 146, 249.99975);
    delay(277.7775);
    tone(tonePin, 195, 499.9995);
    delay(555.555);
    tone(tonePin, 174, 374.999625);
    delay(416.66625);
    tone(tonePin, 155, 124.999875);
    delay(138.88875);
    tone(tonePin, 174, 499.9995);
    delay(555.555);
    tone(tonePin, 116, 249.99975);
    delay(277.7775);
    tone(tonePin, 116, 249.99975);
    delay(277.7775);
    tone(tonePin, 130, 499.9995);
    delay(555.555);
    tone(tonePin, 130, 374.999625);
    delay(416.66625);
    tone(tonePin, 146, 124.999875);
    delay(138.88875);
    tone(tonePin, 155, 499.9995);
    delay(555.555);
    tone(tonePin, 155, 374.999625);
    delay(416.66625);
    tone(tonePin, 174, 124.999875);
    delay(138.88875);
    tone(tonePin, 195, 499.9995);
    delay(555.555);
    tone(tonePin, 220, 374.999625);
    delay(416.66625);
    tone(tonePin, 233, 124.999875);
    delay(138.88875);
    tone(tonePin, 261, 749.99925);
    delay(833.3325);
    tone(tonePin, 174, 249.99975);
    delay(277.7775);
    tone(tonePin, 293, 499.9995);
    delay(555.555);
    tone(tonePin, 261, 374.999625);
    delay(416.66625);
    tone(tonePin, 233, 124.999875);
    delay(138.88875);
    tone(tonePin, 261, 499.9995);
    delay(555.555);
    tone(tonePin, 174, 249.99975);
    delay(277.7775);
    tone(tonePin, 174, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 220, 374.999625);
    delay(416.66625);
    tone(tonePin, 195, 124.999875);
    delay(138.88875);
    tone(tonePin, 220, 499.9995);
    delay(555.555);
    tone(tonePin, 146, 374.999625);
    delay(416.66625);
    tone(tonePin, 146, 124.999875);
    delay(138.88875);
    tone(tonePin, 195, 499.9995);
    delay(555.555);
    tone(tonePin, 174, 374.999625);
    delay(416.66625);
    tone(tonePin, 155, 124.999875);
    delay(138.88875);
    tone(tonePin, 174, 499.9995);
    delay(555.555);
    tone(tonePin, 116, 374.999625);
    delay(416.66625);
    tone(tonePin, 116, 124.999875);
    delay(138.88875);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 220, 374.999625);
    delay(416.66625);
    tone(tonePin, 195, 124.999875);
    delay(138.88875);
    tone(tonePin, 174, 999.999);
    delay(1111.11);
    tone(tonePin, 293, 999.999);
    delay(1111.11);
    tone(tonePin, 261, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 249.99975);
    delay(277.7775);
    tone(tonePin, 220, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 249.99975);
    delay(277.7775);
    tone(tonePin, 261, 749.99925);
    delay(833.3325);
    tone(tonePin, 174, 249.99975);
    delay(277.7775);
    tone(tonePin, 174, 999.999);
    delay(1111.11);
    tone(tonePin, 233, 999.999);
    delay(1111.11);
    tone(tonePin, 220, 249.99975);
    delay(277.7775);
    tone(tonePin, 195, 249.99975);
    delay(277.7775);
    tone(tonePin, 174, 249.99975);
    delay(277.7775);
    tone(tonePin, 195, 249.99975);
    delay(277.7775);
    tone(tonePin, 220, 749.99925);
    delay(833.3325);
    tone(tonePin, 146, 249.99975);
    delay(277.7775);
    tone(tonePin, 146, 999.999);
    delay(1111.11);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 195, 374.999625);
    delay(416.66625);
    tone(tonePin, 220, 124.999875);
    delay(138.88875);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 195, 374.999625);
    delay(416.66625);
    tone(tonePin, 220, 124.999875);
    delay(138.88875);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 195, 374.999625);
    delay(416.66625);
    tone(tonePin, 233, 124.999875);
    delay(138.88875);
    tone(tonePin, 311, 999.999);
    delay(1111.11);
    tone(tonePin, 311, 999.999);
    delay(1111.11);
    tone(tonePin, 293, 249.99975);
    delay(277.7775);
    tone(tonePin, 261, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 249.99975);
    delay(277.7775);
    tone(tonePin, 261, 249.99975);
    delay(277.7775);
    tone(tonePin, 293, 749.99925);
    delay(833.3325);
    tone(tonePin, 233, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 999.999);
    delay(1111.11);
    tone(tonePin, 261, 999.999);
    delay(1111.11);
    tone(tonePin, 233, 249.99975);
    delay(277.7775);
    tone(tonePin, 220, 249.99975);
    delay(277.7775);
    tone(tonePin, 195, 249.99975);
    delay(277.7775);
    tone(tonePin, 220, 249.99975);
    delay(277.7775);
    tone(tonePin, 233, 749.99925);
    delay(833.3325);
    tone(tonePin, 195, 249.99975);
    delay(277.7775);
    tone(tonePin, 195, 999.999);
    delay(1111.11);
    tone(tonePin, 233, 499.9995);
    delay(555.555);
    tone(tonePin, 220, 374.999625);
    delay(416.66625);
    tone(tonePin, 195, 124.999875);
    delay(138.88875);
    tone(tonePin, 174, 499.9995);
    delay(555.555);
    tone(tonePin, 116, 374.999625);
    delay(416.66625);
    tone(tonePin, 116, 124.999875);
    delay(138.88875);
    tone(tonePin, 174, 999.999);
    delay(1111.11);
    tone(tonePin, 195, 499.9995);
    delay(555.555);
    tone(tonePin, 220, 499.9995);
    delay(555.555);
    tone(tonePin, 233, 1999.998);
    delay(2222.22);
}

void StarWars(){
  for (int i = 0; i < 9; i++){ //39
        tone(BEEP, notes[i], times[i]*2);
        delay(times[i]*2);
        noTone(BEEP);
      }
}


char GetKey4x4() {
  static unsigned long timer;
  static char olda;
  char a = 0;
  if ((timer + 50) > millis()) return 0;  // пауза для опроса передает 1, сам опрос возврвщает 0 если не нажато или символ, если нажато
  for (byte p = 0; p <= 3; p++) {    // последовательно выставляем по одной строке в LOW
    digitalWrite(P[p], LOW);
    for (byte m = 0; m <= 3; m++) {  // и считываем столбцы вылавнивая где LOW происходит
      if (!digitalRead(M[m])) {
        a = k4x4[p][m];             // считываем соотвествующий символ для комбинации столбца и строки
      }
    }
    digitalWrite(P[p], HIGH);       // возвращем строку в HIGH и крутим дальше
  }
  timer = millis();
#ifdef ALONE                        // отсекаем удержание (если нужно)
  if (a == olda) return 0;
  olda = a;
#endif
  return a;
}
//Пины моторов и датчика касания
//touchsensor - датчик касания
//Моторы пронумерованы снизу вверх: 1 - самый нижний, 2 - средний, 3 - наивысший
const int touchsensor_pin = 3;
const int motor1_pin1 = 4;
const int motor1_pin2 = 5;
const int motor2_pin1 = 6;
const int motor2_pin2 = 7;
const int motor3_pin1 = 8;
const int motor3_pin2 = 9;

void setup() {
  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  pinMode(motor2_pin1, OUTPUT);
  pinMode(motor2_pin2, OUTPUT);
  pinMode(motor3_pin1, OUTPUT);
  pinMode(motor3_pin2, OUTPUT);

}
//Создание фунций для движения моторов в разные стороны

//Двигают конструкцию влево и вправо соответственно
void motor1_left() {
  digitalWrite(motor1_pin1, 1);
  digitalWrite(motor1_pin2, 0);
}
void motor1_right() {
  digitalWrite(motor1_pin2, 1);
  digitalWrite(motor1_pin1, 0);
}

//Двигают среднюю часть конструкции вверх и вниз соответственно
void motor2_up() {
  digitalWrite(motor2_pin1, 1);
  digitalWrite(motor2_pin2, 0);
}
void motor2_down() {
  digitalWrite(motor2_pin2, 1);
  digitalWrite(motor2_pin1, 0);
}

//Двигают верхнюю часть конструкции вверх и вниз соответственно
void motor3_up() {
  digitalWrite(motor3_pin1, 1);
  digitalWrite(motor3_pin2, 0);
}
void motor3_down() {
  digitalWrite(motor3_pin2, 1);
  digitalWrite(motor3_pin1, 0);
}

//Функция для остановки всех моторов
void motors_Off() {
  digitalWrite(motor1_pin1, 0);
  digitalWrite(motor1_pin2, 0);
  digitalWrite(motor2_pin1, 0);
  digitalWrite(motor2_pin2, 0);
  digitalWrite(motor3_pin1, 0);
  digitalWrite(motor3_pin2, 0);
}
void loop() {
  //Расстояние движения моторов зависит от показателя delay()
  //Единица в delay - 1 миллисекунда. 1000 = 1 секунда
  //Эта часть программы отвечает за выход из исходного положения и поднятие предмета
  motor1_left();
  delay(1000);
  motors_Off();

  motor2_down();
  delay(1500);
  motors_Off();

  motor3_down();
  delay(1000);
  motors_Off();

  motor3_up();
  delay(1000);
  motors_Off();

  motor2_up();
  delay(1500);
  motors_Off();

  //Если предмет был поднят, то есть касание зафиксировано датчиком,
  //то конструкция передвигается в нужное положение, чтобы выложить предмет
  if (digitalRead(touchsensor_pin) == HIGH) {
    motor1_right();
    delay(2000);
    motors_Off();

    motor2_down();
    delay(1500);
    motors_Off();

    motor3_down();
    delay(1000);
    motors_Off();

    motor3_up();
    delay(1000);
    motors_Off();

    motor2_up();
    delay(1500);
    motors_Off();

    motor1_left();
    delay(1000);
    motors_Off();
    
  } else {
    //Ecли же касание не было, то конструкция возвращается в исходное положение
    motor1_right();
    delay(1000);
  }
  
  
    
  

}

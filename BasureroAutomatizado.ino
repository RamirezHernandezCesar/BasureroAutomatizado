 #include<Servo.h >   //Incluimos la libreria del servo-motor
Servo mecanismo;      //Declaramos la variable que hara referencia al Servo-motor
int trig =6;          //Declaramos el pin que usaremos para enviar la señal con el sensor Ultrasonico
int echo = 5;         //Declaramos el pin que usaremos para recibir la señal con el sensor Ultrasonico
int servo =9;         //Declaramos el pin que usaremos para activar el servo-motor
int distancia;        //Declaramos una variable para almacenar la distancia 
int tiempo;           //Declaramos una variable para almacenar el tiempo
int buzzer=2;         //Declaramos el pin que usaremos para activar el buzzer

void setup() {
  Serial.begin(9600);     
  pinMode(trig, OUTPUT);      //Declaramos el pin trig como salida
  pinMode(echo, INPUT);       //Declaramos el pin echo como entrada
  pinMode(buzzer, OUTPUT);    //Declaramos el pin del buzzer como salida
  mecanismo.attach(servo);    //Declaramos el pin que usara el servo-motor
  
}
void loop() {
  mecanismo.write(0);             //Inicializamos en servo-motor en la posicion de 0 grados
  digitalWrite(trig, HIGH);       //Activamos el pulso del trig
  delay(1);                       //Esperamos un tiempó 
  digitalWrite(trig, LOW);        //Desactivamos el pulso del trig
  tiempo = pulseIn(echo, HIGH);   //Activamos el pulso del echo y lo almacenamos en la variable de tiempo
  distancia = (tiempo/2) / 29;    //Calculamos la distancia utilizando el tiempo capturado anteriormente
  
  if (distancia < 15){            //Si la distancia que se calculo es menor a 15  entraremos en la condicion
    //Serial.println(distancia);
    mecanismo.write(90);          //Activaremos el servo-motor y lo moveremos a la posicion de 90 grados
    digitalWrite(buzzer, HIGH);   //Activamos el buzzer
    delay(1200);                  //Esperamos un tiempó 
  }
  else{                           //Si la distancia que se calculo es mayor a 15 entonces se realizara lo siguiente 
    //Serial.println(distancia);
    mecanismo.write(0);           //Dejaremos activado el servo-motor a 0 grados
    digitalWrite(buzzer, LOW);    //Desactivaremos el buzzer 
  }
   delay(500);                    //Esperamos un tiempó
}

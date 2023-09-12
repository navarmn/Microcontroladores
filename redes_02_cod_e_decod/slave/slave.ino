// Termina aqui as definições
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop()
{
  String mensagem = ""; // for incoming serial data
  
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    mensagem = Serial.readString();

    // say what you got:
    Serial.println(mensagem);
  }
  
  if(mensagem == "oioavo}etmn"){
  int x = 0;
    while (x < 10){
    digitalWrite(13, HIGH);
    delay(200);
    digitalWrite(13, LOW);
    delay(200);
    x++;
    }
  }
}
 

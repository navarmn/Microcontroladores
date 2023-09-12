// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  String mensagem = ""; // for incoming serial data
  Serial.println("L");
  delay(1000);
}

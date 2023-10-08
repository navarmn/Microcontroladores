//
// Incluindo bibliotecas ================================================================
//
#include <Keypad.h>

#include <LiquidCrystal.h>

//
// Constantes e Variáveis globais =======================================================
//
const byte rows = 4; // Qtde de linhas
const byte cols = 4; // Qtde de colunas

char keys[rows][cols] = { // Código de identificação das teclas do teclado
  {'1', '2', '3', 'L'},
  {'4', '5', '6', 'R'},
  {'7', '8', '9', 'U'},
  {'O', '0', 'X', 'D'}
};

char tecla; // Para receber a tecla acionada
byte cont;  // Para contar as teclas acionadas
String texto = ""; // Para acumular as teclas acionadas
long numero; // Para receber o valor numérico do texto
byte fase; // Para indicar a fase atual


byte rowPins[rows] = {9, 8, 7, 6}; // Linhas 1, 2, 3 e 4 do teclado
byte colPins[cols] = {13, 12, 11, 10}; // Colunas 1, 2, 3 e 4 do teclado

//
// Instanciando os objetos ==============================================================
//
LiquidCrystal lcd ( 0 , 1 , 5, 4, 3, 2 ) ; // Pinos RS, EN, DB4, DB5, DB6 e DB7 do LCD 
Keypad teclado = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols ); // Objeto teclado

//
// Função setup ========================================================================= 
//
void setup() {
  lcd.begin(16, 2); // Inicializa display
  lcd.clear(); // Limpa display
  mensagem0();
  cont = 0; numero = 0; fase = 0; // Inicializa valores
  
  //Serial.begin(9600);
}

//
// Função mensagem ======================================================================
//
void mensagem0() {
  lcd.setCursor(0,1);
  lcd.print("Press 0..9/Ok/X");
  lcd.home();
}

//
// Função mensagem ======================================================================
//
void mensagem1() {
  lcd.setCursor(0,1);
  lcd.print("Press Up/Dn/X  ");
  lcd.home();
}

//
// Função executa =======================================================================
//
void executa() {
  lcd.print(tecla); // Escreve a tecla no display
  texto = texto + tecla; // Acumula a tecla no texto
  //Serial.print("Tecla: "); Serial.print(tecla);
  //Serial.print(" - Texto: "); Serial.println(texto);
  cont++; // Conta a tecla 
  delay(100);
}

//
// Função fase0 =========================================================================
//
void fase0() {
  tecla = teclado.getKey(); // Varredura e leitura da tecla acionada se houver
  if (tecla != NO_KEY) {
    switch (tecla) {
      case '0': // O que deve ocorrer se acionada a tecla "0"
        if (cont<6) {
          executa();
        }
        break;
      case '1': // O que deve ocorrer se acionada a tecla "1"
        if (cont<6) {
          executa();
        }
      break;
      case '2': // O que deve ocorrer se acionada a tecla "2"
        if (cont<6) {
          executa();
        }
        break;
      case '3': // O que deve ocorrer se acionada a tecla "3"
        if (cont<6) {
          executa();
        }
        break;
      case '4': // O que deve ocorrer se acionada a tecla "4"
        if (cont<6) {
          executa();
        }
        break;
      case '5': // O que deve ocorrer se acionada a tecla "5"
        if (cont<6) {
          executa();
        }
        break;
      case '6': // O que deve ocorrer se acionada a tecla "6"
        if (cont<6) {
          executa();
        }
        break;
      case '7': // O que deve ocorrer se acionada a tecla "7"
        if (cont<6) {
          executa();
        }
        break;
      case '8': // O que deve ocorrer se acionada a tecla "8"
        if (cont<6) {
          executa();
        }
        break;
      
      case '9': // O que deve ocorrer se acionada a tecla "9"
        if (cont<6) {
          executa();
        }
        break;
      case 'O': // O que deve ocorrer se acionada a tecla "O"
        numero = texto.toInt(); // Converte o texto para numérico
        fase = 1;
        mensagem1();
        //Serial.print("Numero: "); Serial.println(numero);
        break;
      case 'X': // O que deve ocorrer se acionada a tecla "X"
        lcd.clear();
        mensagem0();
        texto = "";
        cont = 0; numero = 0; // Inicializa valores
        break;
      default:      
        break;
      }
  }
}

// 
// Função fase1 =========================================================================
//
void fase1() {
  tecla = teclado.getKey(); // Varredura e leitura da tecla acionada se houver

  if (tecla != NO_KEY) {
    switch (tecla) {
      case 'U': // O que deve ocorrer se acionada a tecla "U"
        numero++;
        lcd.clear();
        mensagem1();
        lcd.print(numero);
        //Serial.print("Numero: "); Serial.println(numero);
        break;
      case 'D': // O que deve ocorrer se acionada a tecla "D"
        numero--;
        lcd.clear();
        mensagem1();
        lcd.print(numero);
        //Serial.print("Numero: "); Serial.println(numero);
        break;
      case 'X': // O que deve ocorrer se acionada a tecla "X"
        lcd.clear();
        mensagem0();
        texto = "";
        cont = 0; numero = 0; fase = 0; // Inicializa valores
        break;
      default:      
        break;
      }
  }  
}

//
// Função loop ==========================================================================
//
void loop() {
  
  if (fase==0) {
    fase0();    
  }
  
  if (fase==1) {
    fase1();
  }

}
  


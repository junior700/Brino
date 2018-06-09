/*---------------------------------------------------------------------------------
  Eng. Helio R. de Freitas Jr.
  junior700.eletro@gmail.com
  11.07.2017
  
  Modificado em 08.06.2018
  Utilizado a mesma terminologia do BRino
  http://brino.cc/tutoriais.php
  https://github.com/BrinoOficial/Brino
  
 ---------------------------------------------------------------------------------- 
  this library intend to translate C language keywords to Portuguese
  
  
  You can use C mixing with PT new keywords in your sketch. 
  Just include PTconverter.h in your sketch.
  
  
  modifed 11 Aug 2017
  by Eng. Helio R. Freitas Jr.
  
  
-----------------------------------------------------------------------------------------  
This software is released under an MIT license. See the attached LICENSE file for details.
-----------------------------------------------------------------------------------------
  
  
(trecho abaixo copiado do repositorio do BRduino no github)
Tipos de Dados:
Numero: valores númericos inteiros até +- 32767 (int)
NumeroDecimal: valores númericos com casas decimais (float)
NumeroLongo: valores númericos inteiros até 2147483647 (long)
NumeroLongo NumeroLongo: valores númericos até 9223372036854775807 (long long)
Palavra: sequência de caracteres (String)
Condicao: valor binário Verdadeiro ou Falso (boolean)
Modificadores
Modulo: utiliza somente o valor e ignora o sinal do número (unsigned)
Constante: indica que a variável possui valor constante, ou seja, não mudará durante a execução (const)
Funções:
Arduino
soar(Numero pino, Numero frequencia, Numero duracao): toca determinada nota no alto-falante conectado ao Pino durante o periodo definido(opcional) (tone())
pararSoar(Numero pino): interrompe a nota que está sendo tocada no pino fornecido (noTone)
esperar(Numero milis): espera "milis" milissegundos (delay())
proporcionar(): faz uma regra de três com os valores fornecidos (map())
definir: define uma constante que será utilizada durante o programa (#define)
usar: importa as dependências do programa como libraries externas (#include)
USB
USB.conectar(Numero TaxaDeTransmissao): configura a comunicação serial pela porta USB com a a taxa de transmissão fornecida como argumento. Padrão 9600. (Serial.begin(baudrate))
USB.enviar(Palavra mensagem):envia a Palavra fornecida para o monitor serial conectado (.print(String message))
USB.enviarln(Palavra mensagem):envia a Palavra fornecida para o monitor serial conectado e pula uma linha (.println(String message))
USB.disponivel():verifica se há dados disponíveis na porta serial(.available())
USB.ler():lê os dados disponíveis na porta serial(.read())
Pino
Pino.definirModo(Numero pino, Modo): define o modo da porta digital fornecida(apenas o número) para o modo fornecido (Entrada ou Saida) (pinMode(int pin, [OUTPUT ou INPUT]))
Pino.escrever(Pino, saida): escreve o valor fornecido na porta fornecida (analogWrite(int pin, int value) ou digitalWrite(int pin, [HIGH ou LOW]))
Pino.escreverAnalogico(Pino, saida): escreve o valor fornecido na porta analógica fornecida (analogWrite(int pin, int value))
Pino.ler(Pino): lê o valor da porta especificada (analogRead ou digitalRead)
Pino.lerAnalogico(Pino): lê o valor da porta analógica especificada (analogRead)
Pino.ligar(Pino): liga o pino digital (digitalWrite(int pin, HIGH))
Pino.desligar(Pino): desliga o pino digital(digitalWrite(int pin, LOW))
Pinos digitais: Digital.num ou num
Pinos analógicos: Anum, Analogico.num
Valores Digitais: Ligado ou 1,Desligado ou 0.
Libraries inclusas no IDE (devem ser declaradas com usar):
Memoria (EEPROM)
Memoria.ler(Numero endereco): lê o byte do endereço fornecido (EEPROM.read())
Memoria.escrever(Numero endereco, byte dado): escreve o byte fornecido no endereço fornecido (EEPROM.write())
Memoria.tamanho(): retorna o tamanho da memória do arduino (EEPROM.length())
Memoria.formatar(): apaga todos os dados da memória do arduino
LCD (LiquidCrystal)
LCD <nome>(Numero RS, E, D4, D5, D6, D7): cria o objeto LCD para ser utilizado (LiquidCrystal <name>())
<nome>.conectar(Numero colunas, Numero linhas): inicia a comunicação com o lcd com o número de linhas e colunas definido (<name>.begin())
<nome>.enviar(Palavra mensagem): envia a palavra para o LCD (<name>.print())
<nome>.escrever(byte b): escreve em hexadecimal o byte enviado para o LCD (<name>.write)
<nome>.posicao(Numero coluna, Numero linha): posiciona o cursor na linha e coluna definidas (<name>.setCursor())
<nome>.limpar(): apaga o que está escrito no LCD (<name>.clear)
Servo
Servo <nome>: cria o objeto servo para ser utilizado (Servo <name>)
<nome>.conectar(Pino digital): conecta o servo à porta digital (<name>.attach())
<nome>.escreverAngulo(Numero angulo): posiciona o servo no ângulo fornecido(<name>.write)
<nome>.escreverMicros(Numero micros): define a duracao em microsegundos do pulso para controlar o servo de rotação contínua (<name>.writeMicroseconds())
Servo.frente(1700): constantes de pulso para controle de servos de rotação contínua para fente.
Servo.tras(1300): constantes de pulso para controle de servos de rotação contínua para trás.
Servo.parar(1500): constantes de pulso para controle de servos de rotação contínua para parar.
I2C
I2C.conectar(Numero endereco): inicia a comunicação I2C(o endereço é opcional para o mestre)(Wire.begin())
I2C.transmitir(Numero endereco): abre uma transmissão para o escravo com o endereço fornecido(Wire.beginTranmission)
I2C.pararTransmitir(): fecha a transmissão que estava aberta(Wire.endTransmission())
I2C.escrever(msg): envia a mensagem para a transmissão aberta(apenas o mestre pode mandar, mas esse método pode ser usado pelo escravo para enviar a resposta de um pedido)(Wire.write())
I2C.disponivel():verifica quantos dados estão disponíveis para o mestre após um pedido(Wire.available())
I2C.ler():lê os dados disponíveis na transmissão ou na resposta(Wire.read())
I2C.solicitar(Numero endereco, Numero quantBytes): solicita "quantBytes" bytes de escravo no endereço fornecido(Wire.requestFrom())
I2C.solicitado(metodo): registra o método fornecido como resposta à solicitação(Wire.onRequest())
I2C.recebido(metodo): registra o método fornecido como resposta ao recebimento de dados(Wire.onReceive())
Outras palavras-chaves
Funções necessárias a um código Brino
Configuracao(){}: parte do código que será executado uma vez e que prepara o sistema para o resto do programa (void setup(){})
Principal(){}: código principal que será executado repetidas vezes (void loop(){})
Instruções de Controle
para (dado d; dado <comparador> referencia; incremento) faca{}: repete o bloco de código de acordo com as condições descritas(for(){})
se (dado <comparador> referencia) faca{}: realiza o bloco de código se o resultado da comparação for Verdadeiro (if (){})
senao faca{}: realiza o bloco de código caso o resultado do "se" relacionado seja Falso (else{})
enquanto (dado <comparador> referencia) faca{}: realiza o bloco de instruções enquanto o resultado for Verdadeiro (while(){})
Comparadores
==: igual a
<: menor que
<=: menor que ou igual
>:maior que
>=: maior que ou igual
!=: diferente de
<condicao1> e <condicao2>: retorna Verdadeiro se ambas as condições forem verdadeiras (&&)
<condicao1> ou <condicao2>: retorna Verdadeiro se uma ou outra ou ambas as condições forem verdadeiras (||)
Palavras-chaves
SemRetorno: utilizada para declarar o tipo de retorno de uma função como vazio (void)
responder <dado>: indica o dado que será retornada pela função caso não seja SemRetorno (return)
*/

//Tipos de Dados:

#define Numero  int //: valores númericos inteiros até +- 32767 (int)
#define NumeroDecima float //: valores númericos com casas decimais (float)
#define NumeroLongo: valores númericos inteiros até 2147483647 (long)
#define NumeroLongo NumeroLongo: valores númericos até 9223372036854775807 (long long)
#define Palavra: sequência de caracteres (String)
#define Condicao: valor binário Verdadeiro ou Falso (boolean)

//Modificadores

#define Modulo: utiliza somente o valor e ignora o sinal do número (unsigned)
#define Constante: indica que a variável possui valor constante, ou seja, não mudará durante a execução (const)

//Funções:
//Arduino

#define soar  tone //(Numero pino, Numero frequencia, Numero duracao): toca determinada nota no alto-falante conectado ao Pino durante o periodo definido(opcional) (tone())
#define pararSoar noTone //(Numero pino): interrompe a nota que está sendo tocada no pino fornecido (noTone)
#define esperar delay  //(Numero milis): espera "milis" milissegundos (delay())
#define proporcionar  map //(): faz uma regra de três com os valores fornecidos (map())
#define definir #define: define uma constante que será utilizada durante o programa (#define)
#define usar  #include  //: importa as dependências do programa como libraries externas (#include)

//USB
//USB.conectar(Numero TaxaDeTransmissao): configura a comunicação serial pela porta USB com a a taxa de transmissão fornecida como argumento. Padrão 9600. (Serial.begin(baudrate))

#define USB.conectar  Serial.begin
//USB.enviar  print(Palavra mensagem):envia a Palavra fornecida para o monitor serial conectado (.print(String message))
#define enviar  print
//USB.enviarln(Palavra mensagem):envia a Palavra fornecida para o monitor serial conectado e pula uma linha (.println(String message))
#define enviarln  println
//USB.disponivel():verifica se há dados disponíveis na porta serial(.available())
#define disponivel  available
//USB.ler():lê os dados disponíveis na porta serial(.read())
#define ler read    // termo vale para leitura em varias instâncias
#define escrever  write   // termo vale para escrita em varias instâncias

//Pino

#define Pino.definirModo pinMode //(Numero pino, Modo): define o modo da porta digital fornecida(apenas o número) para o modo fornecido (Entrada ou Saida) (pinMode(int pin, [OUTPUT ou INPUT]))
#define Pino.escrever digitalWrite //(Pino, saida): escreve o valor fornecido na porta fornecida (analogWrite(int pin, int value) ou digitalWrite(int pin, [HIGH ou LOW]))
#define Pino.escreverAnalogico analogWrite //(Pino, saida): escreve o valor fornecido na porta analógica fornecida (analogWrite(int pin, int value))
#define Pino.ler  digitalRead //(Pino): lê o valor da porta especificada (analogRead ou digitalRead)
#define Pino.lerAnalogico analogRead  //(Pino): lê o valor da porta analógica especificada (analogRead)
#define Pino.ligar(PINO) (digitalWrite(PINO, HIGH))  //Pino.ligar(Pino): liga o pino digital (digitalWrite(int pin, HIGH))
#define Pino.desligar(Pino)  (digitalWrite(PINO, LOW)) //Pino.desligar(Pino): desliga o pino digital(digitalWrite(int pin, LOW))
#define Pinos.Digitais   Digital.num//: Digital.num ou num
#define Pinos.analógicos   Anum//: Anum, Analogico.num
#define Valores Digitais: Ligado ou 1,Desligado ou 0.

//Libraries inclusas no IDE (devem ser declaradas com usar):

#define Memoria EEPROM
//#define Memoria.ler(Numero endereco): lê o byte do endereço fornecido (EEPROM.read())
//#define Memoria.escrever(Numero endereco, byte dado): escreve o byte fornecido no endereço fornecido (EEPROM.write())
//#define Memoria.tamanho(): retorna o tamanho da memória do arduino (EEPROM.length())
#define tamanho length
//#define Memoria.formatar(): apaga todos os dados da memória do arduino
#define formatar  erase
//#define LCD LiquidCrystal // definicao inicial com o 
#define LCD.nome(RS,En,D4,D5,D6,D7)   (LiquidCrystal nome(RS, En, D4, D5, D6, D7)) //: cria o objeto LCD para ser utilizado (LiquidCrystal <name>())
#define nome.conectar(Numero_colunas,Numero_linhas)   (nome.begin(Numero_colunas,Numero_linhas)) //<nome>.conectar(Numero colunas, Numero linhas): inicia a comunicação com o lcd com o número de linhas e colunas definido (<name>.begin())
#define nome.enviar(Palavra_mensagem)   (nome.print(Palavra_mensagem)) //<nome>.enviar(Palavra mensagem): envia a palavra para o LCD (<name>.print())
#define nome.escrever(byte_b)     (nome.write(byte_b)) //<nome>.escrever(byte b): escreve em hexadecimal o byte enviado para o LCD (<name>.write)
#define nome.posicao(Numero_coluna,Numero_linha)    (nome.setCursor(Numero_coluna,Numero linha)) //<nome>.posicao(Numero coluna, Numero linha): posiciona o cursor na linha e coluna definidas (<name>.setCursor())
#define nome.limpar nome.clear //<nome>.limpar(): apaga o que está escrito no LCD (<name>.clear)
//Servo
#define Servo.nome  Servo nome //: cria o objeto servo para ser utilizado (Servo <name>)
//#define <nome>.conectar(Pino digital): conecta o servo à porta digital (<name>.attach())
#define angulo.servo  (int anguloServo=0) // define uma variável para o angulo atual do servo, difere do BRino
#define nome.conectar(Pino_digital)   nome.attach(Pino_digital) // conecta o servo à porta digital (<name>.attach())
//#define //<nome>.escreverAngulo(Numero angulo): posiciona o servo no ângulo fornecido(<name>.write)
#define nome.escreverMicros(Numero_micros)    (nome.writeMicroseconds(Numero_micros))  //: define a duracao em microsegundos do pulso para controlar o servo de rotação contínua (<name>.writeMicroseconds())
#define Servo.frente()  (nome.writeMicroseconds(1700)) // : constantes de pulso para controle de servos de rotação contínua para fente.
#define Servo.tras()    (nome.writeMicroseconds(1300)) //: constantes de pulso para controle de servos de rotação contínua para trás.
#define Servo.parar()   (nome.writeMicroseconds(1500)) //: constantes de pulso para controle de servos de rotação contínua para parar.
#define nome.angulo(anguloServo)   (nome.write(anguloServo)) // posiciona o servo no angulo especificado, difere do BRino


//I2C

#define I2C.conectar(endereco)    (Wire.begin(endereco))       //: inicia a comunicação I2C(o endereço é opcional para o mestre)(Wire.begin())
#define I2C.transmitir(endereco)  (Wire.beginTranmission(endereco)) //: abre uma transmissão para o escravo com o endereço fornecido(Wire.beginTranmission)
#define I2C.pararTransmitir()     (Wire.endTransmission())    //: fecha a transmissão que estava aberta(Wire.endTransmission())
#define I2C.escrever(msg)         (Wire.write())            //: envia a mensagem para a transmissão aberta(apenas o mestre pode mandar, mas esse método pode ser usado pelo escravo para enviar a resposta de um pedido)(Wire.write())
#define I2C.disponivel()          (Wire.available())        //:verifica quantos dados estão disponíveis para o mestre após um pedido(Wire.available())
#define I2C.ler()   (Wire.read())          //:lê os dados disponíveis na transmissão ou na resposta(Wire.read())
#define I2C.solicitar(endereco,quantBytes)  (Wire.requestFrom(endereco,quantBytes))   //: solicita "quantBytes" bytes de escravo no endereço fornecido(Wire.requestFrom())
#define I2C.solicitado(metodo)              (Wire.onRequest(metodo))     //: registra o método fornecido como resposta à solicitação(Wire.onRequest())
#define I2C.recebido(metodo)                (Wire.onReceive(metodo))  //: registra o método fornecido como resposta ao recebimento de dados(Wire.onReceive())


//Outras palavras-chaves
//Funções necessárias a um código Brino

#define Configuracao  setup   //: parte do código que será executado uma vez e que prepara o sistema para o resto do programa (void setup(){})
#define Principal     loop     //código principal que será executado repetidas vezes (void loop(){})
//Instruções de Controle
#define para  for  //: repete o bloco de código de acordo com as condições descritas(for(){})
#define se   if  //(dado <comparador> referencia) faca{}: realiza o bloco de código se o resultado da comparação for Verdadeiro (if (){})
#define senao_faca else //: realiza o bloco de código caso o resultado do "se" relacionado seja Falso (else{})
#define enquanto   while   //(dado <comparador> referencia) faca{}: realiza o bloco de instruções enquanto o resultado for Verdadeiro (while(){})
//Comparadores
//==: igual a
//<: menor que
//<=: menor que ou igual
//>:maior que
//>=: maior que ou igual
//!=: diferente de
#define &&  e <condicao1> e <condicao2>: retorna Verdadeiro se ambas as condições forem verdadeiras (&&)
#define ||  ou <condicao1> ou <condicao2>: retorna Verdadeiro se uma ou outra ou ambas as condições forem verdadeiras (||)
#define &   E 
#define |   OU
//Palavras-chaves
#define SemRetorno  void  //: utilizada para declarar o tipo de retorno de uma função como vazio (void)
#define responder   return  //indica o dado que será retornada pela função caso não seja SemRetorno (return)

/*definições antigas, substituidas pelas listadas acima
#define para for
#define principal loop
#define enquanto while
#define se if
#define senao else
#define para for
#define maior >
#define menor <
#define igual ==
#define inteiro int
#define caracter char
#define menu switch
#define caso case
#define vazio void
#define E ||
#define OU &&
#define e |
#define ou &
#define definicao setup
#define configuraPino pinMode
#define escrevePino digitalWrite
#define lePino	digitalRead
#define retardo delay 	 
*/

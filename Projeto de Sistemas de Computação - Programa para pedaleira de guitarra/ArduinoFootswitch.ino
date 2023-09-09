/*
CONTROLADOR MIDI USB COM ARDUINO LEONARDO PARA USAR COM PLUGINS COMO O AMPLITUBE.
 5 BOTÕES PARA ACESSAR 5 DE PRESETS DO PLUGIN.
 5 LEDS, UM PRA CADA BOTÃO DE PATCH, ACENDEM DE ACORDO COM O PATCH ESCOLHIDO.
   MATERIAL NECESSÁRIO:
   1 ARDUINO LEONARDO
   5 BOTÕES
   5 LEDS
   5 RESISTORES DE 220 OHMS PARA OS LEDS
*/

#include "MIDIUSB.h" // Biblioteca MIDIUSB

//---Para adicionar mais Botões ou LEDs, basta adicionar mais pinos, estados e mensagens PC à lista.

byte ledPin[] = {A0,A1,A2,A3,A4};//-------------Lista de pinos dos LEDs, com a quantidade que desejar usar, no meu caso usei 5.
byte buttonPin[] = {2,3,4,5};//---------------Lista de pinos de botões com a quantidade de Pedais que desejar usar, no meu caso usei 5.
byte buttonState[] = {0,0,0,0};//-------------Começar com estado dos bottões em desligados.
byte lastButtonState[] = {0,0,0,0};//---------Começar com o estado dos botões já pressionados.
byte programChanges[] = {0,1,2,3};//----------Lista de mensagens PC a serem enviadas para mudança de presets.

byte channel = 0;//-----------------------------Canal MIDI

void setup() {
  for(int i =0;i< sizeof(buttonPin); i++){//----Inicializando pinos de entrada.
    pinMode(buttonPin[i], INPUT_PULLUP);//------Definindo os pinos de entrada dos botões.
    pinMode(ledPin[i], OUTPUT);//---------------Definindo os pinos de saída dos LEDs.
  }
    programChange(channel, 0);;//---------------Inicia no primeiro Patch.
    digitalWrite(A0, HIGH);//-------------------Inicia o LED do primeiro Patch aceso.
}

void ledOffAll() {//----------------------------Código dos LEDs, iniciam em off.
    for(int i = 0 ; i< sizeof(ledPin); i++){//--Inicializando pinos de saída dos LEDs..
     digitalWrite(ledPin[i], LOW);//------------Iniciando todos os LEDs apagados.
    }
}
 
void loop() {
  for(int i =0;i< sizeof(buttonPin); i++){//--------------------Verificando todos os pinos dos botões.
  buttonState[i] = digitalRead(buttonPin[i]);//-----------------Estado de todos os pinos de botões 0 , desligados.
  if(buttonState[i] == LOW && lastButtonState[i] == HIGH){//----Se determiado botão for pressionado(LOW), e o ultimo botão estiver solto(HIGH).
    ledOffAll();//----------------------------------------------Desligar todos os LEDs.
    digitalWrite(ledPin[i],HIGH);//-----------------------------Acenda o LED referente ao botão pressionado.
    programChange(channel, programChanges[i]);//----------------Envie a mensagem PC para mudança de programa do botão pressonado.
    MidiUSB.flush();//------------------------------------------Enviar mensagem MIDI imediatamente.
    delay(200);//-----------------------------------------------Tempo em milisegundos até enviar o mesmo comando novamente.
   }
   lastButtonState[i] = buttonState[i];//-----------------------Atualizando o estado do ultimo  botão pressionado.
  }
}


void programChange(byte channel, byte patch) {//----------------Ativando envio dos comandos PC.
  midiEventPacket_t event = {0x0C, 0xC0 | channel, patch};//----Onde iniciará o envio dos comandos PC.
  MidiUSB.sendMIDI(event);//------------------------------------Enviando comandos PC.
  delay(10);//--------------------------------------------------Tempo em milisegundos em que o comando é enviado.
}

void controlChange(byte channel, byte control, byte value) {//----------Código de controle dos comandos CC.
  midiEventPacket_t event = {0x0C, 0xC0 | channel, control, value};//---Onde iniciará o envio dos comandos CC.
  MidiUSB.sendMIDI(event);//--------------------------------------------Enviando comandos CC.
  delay(10);//----------------------------------------------------------Tempo em ms em que o comando é enviado.
}

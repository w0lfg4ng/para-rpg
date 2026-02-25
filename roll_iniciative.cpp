const int pinBtn = 4;

const int leds[] = {13, 12, 10, 9, 8, 7};
const int numLeds = 7;
int ledIndex = -1; 
int ultimoEstadoBotao = LOW;

//OBS 0: a variavel integer ledIndex funciona para detectar quantas vezes o botao foi apertado. ele comeca em menos 1, portanto, todos os leds estao desligados
//conforme o botao vai sendo apertado, ledIndex tem seu valor incrementado, ate que esse valor ultrapasse a quantidade de leds que tem no circuito.

void setup(){                       //NAO ESQUECER QUE NAO EH DE LOOP
  for(int i = 0; i < numLeds; i++){ //verifica todos os leds
    pinMode(leds[i],OUTPUT);        //determina os leds como saida
    digitalWrite(leds[i],LOW);
  }
  pinMode (pinBtn, INPUT);          //determina os botoes como entrada (OLHAR OBS 1)
  
}

void loop(){
  int estadoBotao = digitalRead(pinBtn);

  if(estadoBotao == HIGH && ultimoEstadoBotao == LOW){ //se o botao foi pressionado para ligar o led
    ledIndex++;                     //pule para o proximo led
    if(ledIndex >= numLeds){
      ledIndex = -1; 
    }
    attLeds();
    delay(200);                     //debug
  }
  ultimoEstadoBotao = estadoBotao;
}
//OBS 1: pinMode NAO eh uma variavel, mas sim, uma funcao do Arduino API (que nao esta sendo identificada pelo vscode)
//que configura os modos de operacao dos pinos digitais (que leem valores logicos 0 ou 1)
//nesse caso, o pin do botao eh configurado como um pin de entrada na linha 14, enquanto os pins do led sao lidos como pins de saida

void attLeds(){                   //funcao que serve para verificar e deixar os leds apagados
  for(int i = 0; i < numLeds; i++){//verifica todos os leds
    digitalWrite(leds[i], LOW);
  }
  if (ledIndex >= 0){
    digitalWrite(leds[ledIndex],HIGH); //SE o led lido (led index = valor lido atualmente) estiver acima de 0 (o que implica que ha um led ligado), entao ligue esse led
  }
}
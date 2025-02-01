# Projeto Temporizador periodico (atuação do semaforo) 🚀

Este projeto faz com que ascenda cada LED(vermeljo,verde e amarelo) periodicamente a cada 3 segundos por meio de uma interrupção.
## Hardware 🛠️

- Microcontrolador RP2040 (Raspberry Pi Pico).
- 3 LED.

## Software 💻

* **SDK do Raspberry Pi Pico:** O SDK (Software Development Kit) do Pico, que inclui as bibliotecas e ferramentas necessárias para desenvolver e compilar o código. [Instruções de instalação](https://www.raspberrypi.com/documentation/pico/getting-started/)
* **CMake:** Um sistema de construção multiplataforma usado para gerar os arquivos de construção do projeto.
* **Compilador C/C++:**  Um compilador C/C++ como o GCC (GNU Compiler Collection).
* **Git:** (Opcional) Para clonar o repositório do projeto.


### O código está dividido em vários arquivos para melhor organização:

- **`Temoprizador_periodico.C`**: Código com a função de loop principal: gera o código que faz com que alterne os leds periodicamente em um tempo definido.
- **`CMakeLists.txt`:** Define a estrutura do projeto para o CMake.
- **`diagram.json`:** projeta a simulação do semaforo.
- **`wokwi.toml`:** configuração para sicronizar o código a simulação.




## Como Compilar e Executar ⚙️

1. **Instale o SDK do Raspberry Pi Pico:** Siga as instruções no site oficial do Raspberry Pi.
2. **Clone este repositório:** `https://github.com/LuizEduardo-cyber/CEPEDI-Interrup-o-matrizLED.git`
3. **Navegue até o diretório do projeto:** `cd CEPEDI-Interrup-o-matrizLED`
4. **Compile o projeto:** `cmake -B build && cmake --build build`
5. **Copie para o Pico:** Copie o conteúdo da pasta `build` (gerada após a compilação) para o Raspberry Pi Pico. O programa iniciará automaticamente.


## Funcionamento do Loop Principal 🔄 
```
  while (true) {
     printf("Altera o sinal \n");
     sleep_ms(3000);
    }
  ```
O loop while (true) garante execução contínua. sleep_ms(3000) introdz um atraso de 3 segundos para indicar a alteração de sinal dos leds.

## Funcionamento da interrupção.
```
void LEDS(uint8_t digit){
     if(digit==2){
        gpio_put(LED_GREEN,false);
        gpio_put(LED_RED,true);
    }
    if(digit==5){
        gpio_put(LED_YELOW,true);
        gpio_put(LED_RED,false);
    }
     if(digit==8){
        gpio_put(LED_RED,false);
        gpio_put(LED_YELOW,false);
        gpio_put(LED_GREEN,true);
    }
    


}

bool repeating_timer_callback(struct repeating_timer *t){
    static uint8_t a = 0;

    printf("%d segundos \n",a+1);
    LEDS(a);
    a++;
    if(a>8){
         
        a=0;

    }
   
    return true;
}
  ```
A função void LEDS(} tem como função usar como parâmetro o contador "a" e implementar condições para o controle de liga/desliga dos Leds. bool repeating_timer_callback() é uma interrupção que tem como função imprimir o contador e chamar a função LEDS() para ligar e desligar os leds do semaforo em um tempo definido e sicronizado com o contador.
## Próximos Passos ➡️

- Fazer um semaforo que indique um tempo mais adequado para os acionamento de cada led.
- implementar condições mais complexas para que se encaixe mais na realidade..
  
 ## 🔗 Link do Vídeo de Funcionamento:
 

 ## Contribuições 🤝

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

## 📞 Contato

- 👤 **Autor**: Luiz Eduardo Soares Ferreira.
 
- 📧 **E-mail**: luizeduardosoaresferreira942@gmail.com 

--- 


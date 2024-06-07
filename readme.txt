Projeto Ocean Shield

O Ocean Shield é um projeto desenvolvido para o Desafio de "Inovação Azul" 2024, que visa incentivar estudantes, entusiastas de tecnologia, inovação e sustentabilidade a contribuir para soluções que promovam uma gestão sustentável dos oceanos. O projeto tem como objetivo alertar e informar as populações costeiras e as empresas que utilizam os mares sobre a saúde dos oceanos, especialmente monitorando as temperaturas das águas.

Funcionalidades

Monitoramento contínuo da temperatura da água do mar.
Alertas visuais e sonoros quando as temperaturas ultrapassam os limites definidos.
Exibição das temperaturas mínima, máxima e atual em um display LCD.

Requisitos

Arduino Uno ou compatível.
Sensor de temperatura DS18B20.
Buzzer.
LEDs (vermelho e verde).
Display LCD 16x2 com interface I2C.

Dependências

Biblioteca OneWire: Utilizada para comunicação com o sensor de temperatura DS18B20.
Biblioteca DallasTemperature: Utilizada para obter leituras de temperatura do sensor DS18B20.
Biblioteca LiquidCrystal_I2C: Utilizada para controlar o display LCD com interface I2C.

Instruções de Uso

Conecte o sensor de temperatura DS18B20 ao Arduino.
Conecte os LEDs (vermelho e verde) e o buzzer conforme as conexões definidas no código.
Carregue o código fornecido no Arduino IDE e faça o upload para o Arduino.
Monitore as leituras de temperatura exibidas no display LCD.
Os alertas visual e sonoro serão ativados caso a temperatura da água ultrapasse os limites definidos.

Estrutura do Código

O código está estruturado em duas funções principais:

setup(): Responsável pela inicialização do sistema, configuração dos pinos, inicialização do display LCD e início das comunicações com o sensor de temperatura. Além disso, apresenta uma mensagem de introdução com o nome e o logo do projeto.
loop(): Realiza continuamente a leitura da temperatura da água do mar, atualiza as temperaturas mínima e máxima, exibe as informações no display LCD e ativa os alertas visual e sonoro quando necessário.

Contribuição

Sinta-se à vontade para contribuir com melhorias, correções de bugs ou novas funcionalidades para o projeto Ocean Shield. Para isso, envie um pull request para o repositório do projeto.

Link Para o Repositório

https://wokwi.com/projects/399905963532365825

Autores

Julia Carolina Ferreira Silva
Heloísa Fleury Jardim
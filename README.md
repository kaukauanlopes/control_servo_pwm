# Controle de Servomotor por PWM no Raspberry Pi Pico W

## Descrição
Este projeto implementa o controle de um servomotor utilizando PWM no microcontrolador Raspberry Pi Pico W. A simulação é realizada no Wokwi, com desenvolvimento no ambiente VS Code e uso do Pico SDK.

## Requisitos
- Raspberry Pi Pico W (simulado no Wokwi)
- Servomotor micro servo padrão (simulado no Wokwi)
- VS Code com o Pico SDK configurado
- Conta no GitHub para versionamento
- Ferramenta Educacional BitDogLab para experimento adicional

## Configuração do Ambiente
1. Instale o [VS Code](https://code.visualstudio.com/).
2. Configure o [Pico SDK](https://github.com/raspberrypi/pico-sdk) seguindo a documentação oficial.
3. Integre o Wokwi ao VS Code.
4. Clone este repositório:
   sh
   git clone <https://github.com/kaukauanlopes/control_servo_pwm.git>
   
5. Compile o código:
   sh
   mkdir build && cd build
   cmake ..
   make
   

## Execução no Wokwi
1. Acesse o [Wokwi](https://wokwi.com/) e importe os arquivos do projeto.
2. Certifique-se de que a GPIO 22 está configurada para PWM.
3. Execute a simulação e observe o comportamento do servomotor.

## Funcionamento
O programa realiza as seguintes ações:
1. Define a frequência do PWM em 50Hz.
2. Ajusta o ciclo ativo para diferentes ângulos do servomotor:
   - 180 graus (2.400µs)
   - 90 graus (1.470µs)
   - 0 graus (500µs)
3. Aguarda 5 segundos em cada posição.
4. Implementa uma movimentação periódica e suave do servo entre 0 e 180 graus.
5. Realiza um experimento adicional com o LED RGB (GPIO 12) utilizando a ferramenta BitDogLab.

## Experimento com o LED RGB
- Durante a execução do código, observe o comportamento da iluminação do LED RGB e registre suas observações.

## Link do Vídeo Ensaio
[https://drive.google.com/file/d/1__X5zuVY3yWSR7kTXZmlZhGuvXmE1j-l/view?usp=drive_link)

## Autor
Este projeto foi desenvolvido como parte da atividade da disciplina ministrada pelo Prof. Dr. Ricardo Menezes Prates.

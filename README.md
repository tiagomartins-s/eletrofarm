# Sistema Automatizado de Monitoramento e Controle Ambiental

## Resumo do Projeto
Este projeto desenvolve um sistema automatizado para monitoramento e controle ambiental, utilizando diversos sensores para coletar dados sobre as condições do ambiente. Com base nas informações coletadas, o sistema pode ativar ou desativar um sistema de irrigação e alertas. Esse sistema é projetado para ser útil em ambientes como estufas, jardins automatizados ou outras áreas que requerem controle preciso sobre:

- Temperatura
- Umidade
- Luminosidade
- Nível de água
- Presença de movimento

## Funcionamento do Sistema
### 1. Sensor de Temperatura e Umidade (DHT22)
- **Objetivo**: Monitorar temperatura e umidade do ambiente.
- **Ação**: 
  - Se a temperatura ultrapassar 50°C ou a umidade relativa estiver abaixo de 50%, a irrigação é acionada para proteger as plantas de condições extremas de calor e seca.

### 2. Sensor Ultrassônico (HC-SR04)
- **Objetivo**: Monitorar o nível de água em um reservatório.
- **Ação**: 
  - Se a distância medida for maior que 100 cm (indicando baixo nível de água), a irrigação é ativada para garantir o abastecimento adequado de água para as plantas.

### 3. Sensor de Movimento (PIR)
- **Objetivo**: Detectar movimento no ambiente.
- **Ação**: 
  - Ao detectar movimento, o sistema ativa um alerta para informar o usuário, sendo útil para segurança e monitoramento de presença de pessoas ou animais.

### 4. Sensor de Luminosidade (LDR)
- **Objetivo**: Medir a intensidade de luz ambiente.
- **Ação**: 
  - Se a luminosidade for superior a 100 lux, o sistema pode ativar a irrigação, já que ambientes mais iluminados geralmente demandam mais água para manter as plantas saudáveis.

## Controle e Atualização
- **Microcontrolador**: O sistema é controlado por um microcontrolador (como Arduino ou ESP32) que coleta dados dos sensores e executa ações conforme as condições predefinidas.
- **Intervalo de Leitura**: Os sensores são lidos a cada 2 segundos, garantindo atualizações em tempo real.
- **Monitor Serial**: Todas as leituras são exibidas no monitor serial, permitindo acompanhamento contínuo dos dados e análise em tempo real.

## Benefícios e Expansão
Este sistema permite:
- Automatizar o processo de irrigação.
- Monitorar e gerenciar as condições ambientais.
- Otimizar recursos e melhorar a eficiência do processo.

Este projeto é modular e pode ser expandido para incluir novos sensores, dispositivos de alerta ou integração com sistemas de controle remoto para maior flexibilidade e personalização.

## Menu de Contexto
Este projeto conta com um menu de contexto, oferecendo opções de interação com o sistema para fácil configuração e operação.

## Requisitos
- **Hardware**: Microcontrolador (ex.: Arduino, ESP32), sensores (DHT22, HC-SR04, PIR, LDR)
- **Software**: Biblioteca para comunicação com os sensores, IDE Arduino ou similar para desenvolvimento e upload do código.

## Instalação
1. Conecte os sensores ao microcontrolador conforme o esquema de ligação.
2. Compile e carregue o código no microcontrolador utilizando a IDE.
3. Verifique o monitor serial para confirmar o funcionamento correto do sistema.

## Uso
Após a instalação, o sistema monitorará as condições ambientais continuamente e acionará a irrigação ou alertas conforme as condições predefinidas.

---

**Nota**: Este projeto é ideal para ambientes controlados e pode ser adaptado para várias aplicações agrícolas e de jardinagem.

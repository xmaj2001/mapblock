# so_long

O projeto **so_long** faz parte do currículo da Escola 42 e consiste na criação de um jogo simples, em 2D, onde o jogador deve coletar itens e encontrar a saída do mapa. O projeto utiliza a biblioteca MinilibX para a renderização gráfica e possui uma série de funcionalidades que permitem a interação com o ambiente do jogo.

## Funcionalidades

- Movimento básico do personagem usando as teclas direcionais do teclado.
- Coleta de itens no mapa para permitir a abertura da porta de saída.
- Verificação de colisão com obstáculos.
- Diferentes níveis de dificuldade através de mapas distintos.
- Interface gráfica simples usando MinilibX.

## Estrutura do Projeto

- **src/**: Contém os arquivos fonte do jogo, como a lógica de movimento, renderização e interação com o mapa.
- **maps/**: Diretório contendo os diferentes mapas do jogo.
- **assets/**: Contém imagens e sprites utilizados no jogo.
- **so_long.h**: Arquivo de cabeçalho que contém as definições e protótipos usados no projeto.

## Como Usar

### Compilação

Use o comando `make` para compilar o projeto. Isso irá gerar o executável `so_long`.

```bash
make

## Projeto

<p style="text-align: justify;">
O projeto intitulado "Mega Sena Manager" tem como objetivo gerenciar jogos da mega-sena. O mesmo utiliza uma tabela de dispersão com o objetivo de reduzir o tempo necessário para buscar, deletar e atualizar valores, visto que o tempo da operação de busca em uma tabela de dispersão é quase constante, diferente de outras estruturas, como uma lista.
<p style="text-align: justify;">

## Integrantes

- José de Barros Guerra Neto
- Jerbeson Vinycius Sousa Rodrigues

## Funcionalidades

1. Inserir Concurso.

   - O usuário pode inserir um novo concurso na tabela de dispersão.
     Cada concurso é identificado por um número único e contém a
     data do sorteio e os seis números sorteados.
   - O sistema deve garantir que não haja duplicação de números de
     concurso.

2. Buscar Concurso.

   - O usuário pode buscar um concurso especı́fico na tabela de dispersão usando o número do concurso.
   - A busca deve retornar a data do sorteio e os números sorteados.

3. Buscar Concurso.

   - O usuário pode remover um concurso da tabela de dispersão usando o número do concurso.

4. Visualizar Todos os Concursos.

   - O sistema deve permitir a visualização de todos os concursos armazenados na tabela de dispersão.
   - A visualização deve exibir o número do concurso, a data do sorteio
     e os números sorteados.

5. Carregar Concursos de um Arquivo.

   - O sistema deve carregar concursos a partir de um arquivo de dados. O arquivo deve conter resultados históricos dos sorteios da
     Mega-Sena.

6. Apresentar Estatı́sticas
   1. **Quantidade de sorteios de um número**: Mostrar a quantidade de sorteios de um número especı́fico.
   2. **Dez Números Mais Sorteados**: Mostrar os dez números que foram sorteados com maior frequência.
   3. **Dez Números Menos Sorteados**: Mostrar os dez números que foram sorteados com menor frequência.
   4. **Quantidade de concursos em um determinado ano**: Mostrar a quantidade de concursos que foram realizados em um determinado ano, bem como os seus dados.

## Requisitos

1. Tabela de Dispersão: Utilizar uma tabela de dispersão para arma-
   zenar e gerenciar concursos.

2. Tratamento de Colisões: Implementar a estratégia de encadeamento
   (chaining) para tratamento de colisões, usando listas ligadas.

3. Arquivo de Dados: Utilizar um arquivo CSV ou TSV para armazenar
   um histórico dos concursos (já fornecido). O arquivo deve ser lido e os
   dados inseridos na tabela de dispersão.

4. Estatı́sticas: Calcular e apresentar as estatı́sticas exigidas com base
   nos dados armazenados.

## Como executar o projeto

Primeiro, faz-se necessário compilar todos os arquivos do projeto. Para isso, execute:

```bash
make compile
```

Por último, execute:

```bash
make run
```

Pronto. O programa vai ser executado em sua máquina!

**Existe uma alternativa mais rápida, execute**:

```bash
make compile && make run
```

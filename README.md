# Push_swap 🔄
> Ordenação eficiente de dados em pilhas com limite de instruções. Um projeto desenvolvido na **Escola 42**.

---

## 📋 Descrição do Projeto

O **Push_swap** é um projeto de algoritmos altamente otimizado onde o objetivo é ordenar uma lista de números inteiros usando duas pilhas (`Stack A` e `Stack B`) e um conjunto restrito de operações. O desafio principal é fazer isso com a **menor quantidade de instruções possível**.

Este projeto exercita conceitos fundamentais de algoritmos, complexidade de tempo/espaço (Big O notation) e estruturas de dados em C.

---

## 🛠️ Operações Permitidas

O programa pode manipular as pilhas usando apenas as seguintes 11 instruções:

| Comando | Operação | Descrição |
| :---: | :--- | :--- |
| **`sa`** | swap a | Troca os 2 primeiros elementos do topo da pilha A. |
| **`sb`** | swap b | Troca os 2 primeiros elementos do topo da pilha B. |
| **`ss`** | swap a + b | Executa `sa` e `sb` simultaneamente. |
| **`pa`** | push a | Move o elemento do topo da pilha B para o topo da pilha A. |
| **`pb`** | push b | Move o elemento do topo da pilha A para o topo da pilha B. |
| **`ra`** | rotate a | Rotaciona todos os elementos de A para cima por 1 (o primeiro torna-se o último). |
| **`rb`** | rotate b | Rotaciona todos os elementos de B para cima por 1 (o primeiro torna-se o último). |
| **`rr`** | rotate a + b | Executa `ra` e `rb` simultaneamente. |
| **`rra`** | reverse rotate a | Rotaciona todos os elementos de A para baixo por 1 (o último torna-se o primeiro). |
| **`rrb`** | reverse rotate b | Rotaciona todos os elementos de B para baixo por 1 (o último torna-se o primeiro). |
| **`rrr`** | rev rotate a + b | Executa `rra` e `rrb` simultaneamente. |

---

## 🧠 Algoritmo Implementado

Para conjuntos maiores que 5 elementos, este projeto implementa uma variante do **Turk Algorithm** (algoritmo mecânico/guloso de custo mínimo):

1. **Fase de Preparação:** O algoritmo envia os dois primeiros elementos de A para a pilha B para começar o processo.
2. **Cálculo de Custo:** Para cada elemento restante na pilha A, ele calcula quantas rotações seriam necessárias na pilha A para colocá-lo no topo, e quantas rotações seriam necessárias na pilha B para colocá-lo no local correto de inserção (preservando a ordem decrescente na pilha B).
3. **Otimização de Rotações Combinadas:** Se ambas as pilhas precisarem rotacionar na mesma direção, o algoritmo combina essas rotações usando `rr` ou `rrr` para economizar instruções.
4. **Execução Gulosa:** O elemento com o **menor custo combinado** de movimentação é selecionado e transferido para a pilha B.
5. **Base (Caso 3):** Este processo continua até que restem apenas 3 elementos na pilha A. Esses 3 elementos são ordenados usando um resolvedor fixo ultra-eficiente de no máximo 2 instruções (`case_3`).
6. **Retorno Ordenado:** Os elementos são re-inseridos de volta de B para A de forma ordenada, calculando novamente a posição ótima com o menor custo.
7. **Alinhamento Final:** Por fim, a pilha A é rotacionada até que o menor elemento fique no topo, deixando toda a sequência perfeitamente ordenada em ordem crescente.

---

## 🚀 Como Compilar e Executar

### 🛠️ Compilação

Para compilar o executável principal e o verificador (bonus), execute:

```bash
# Compilar o push_swap
make

# Compilar o checker (bonus)
make bonus
```

Outras regras úteis do Makefile:
- `make clean`: Remove os arquivos objeto `.o`.
- `make fclean`: Remove os arquivos objeto e os binários finais (`push_swap` e `checker`).
- `make re`: Reconstrói todo o projeto do zero.

---

### 💻 Como Usar

#### Executando o push_swap
O `push_swap` recebe a lista de inteiros desordenada e imprime a sequência de operações para ordená-la:

```bash
./push_swap 2 1 3 6 5 8
```

O programa também suporta strings formatadas com espaços:
```bash
./push_swap "2 1 3 6 5 8"
```

#### Executando o Checker (Verificador)
O programa `checker` recebe a lista original de inteiros e lê as instruções da entrada padrão (stdin). Ele exibe `OK` se as instruções ordenarem corretamente a pilha, ou `KO` caso contrário:

```bash
ARG="2 1 3 6 5 8"; ./push_swap $ARG | ./checker $ARG
```

---

## 📈 Benchmarks Estimados

Este algoritmo atinge excelentes resultados nos limites exigidos pela Escola 42:

* **3 números:** máximo de 2 a 3 instruções.
* **5 números:** máximo de 12 instruções.
* **100 números:** ~500 a 600 instruções (limite de pontuação máxima: 700).
* **500 números:** ~5000 a 5300 instruções (limite de pontuação máxima: 5500).

Para rodar os testes automatizados incluídos:
```bash
bash push_swap_test_linux.sh
```

---

## 👥 Autor

* **Nd Daniel** ([NdondaDaniel2020](https://github.com/NdondaDaniel2020))

---

## 📄 Licença

Este projeto está licenciado sob a licença **MIT** - consulte o arquivo [LICENSE](file:///spot/NdDaniel/Code/42/PushSwap/LICENSE) para mais detalhes.

# Agenda de Contatos em C++
Um sistema simples e eficiente de gerenciamento de contatos via terminal, desenvolvido em C++. Este projeto demonstra a aplicação prática de manipulação de arquivos (File I/O), modularização de código e controle de fluxo usando a biblioteca padrão do C++.

## Funcionalidades
* **Adicionar contato:** Salva novos nomes diretamente no arquivo `contatos.txt`.
* **Listar contatos:** Lê e exibe todos os contatos armazenados.
* **Buscar contatos:** Pesquisa por um nome específico e retorna se ele está presente na base.
* **Excluir contato:** Remove um contato da lista reescrevendo os dados de forma segura utilizando arquivos temporários.

## Tecnologias Utilizadas

* **C++ (Standard Library):**
  * `<iostream>` para entrada e saída no terminal.
  * `<fstream>` para manipulação de arquivos (leitura/escrita).
  * `<string>` para manipulação de texto.

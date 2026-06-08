#include <iostream>
#include <fstream>
#include <string>

void Menu() {
    std::cout << "===== Agenda de Contatos =====" << std::endl;
    std::cout << "1. Adicionar contato" << std::endl;
    std::cout << "2. Listar contatos" << std::endl;
    std::cout << "3. Buscar contatos" << std::endl;
    std::cout << "4. Excluir contato" << std::endl;
    std::cout << "5. Sair" << std::endl;
    std::cout << "===============================" << std::endl;
}

void adicionarContato() {
    std::string nomeContato;

    std::cout << "Digite o nome do contato que deseja adicionar: ";
    std::cin >> nomeContato;

    std::ofstream arquivoContatos("contatos.txt", std::ios::app);
    if (arquivoContatos.is_open()) {
        arquivoContatos << nomeContato << std::endl;
        arquivoContatos.close();
    } else {
        std::cout << "Erro ao abrir o arquivo para adicionar contato." << std::endl;
    }
}

void listarContatos() {
    std::string contato;
    
    std::ifstream arquivoContatos("contatos.txt");
    if (arquivoContatos.is_open()) {
        while (std::getline(arquivoContatos, contato)) {
            std::cout << contato << std::endl;
        }
        arquivoContatos.close();
    } else {
        std::cout << "Erro ao abrir o arquivo para listar contatos." << std::endl;
    }
}

void buscarContato() {
    std::string nomeBusca;
    std::cout << "Digite o nome do contato que deseja buscar: ";
    std::cin >> nomeBusca;

    std::string contato;
    bool encontrado = false;

    std::ifstream arquivoContatos("contatos.txt");
    if (arquivoContatos.is_open()) {
        while (std::getline(arquivoContatos, contato)) {
            if (contato == nomeBusca) {
                std::cout << "Contato encontrado: " << contato << std::endl;
                encontrado = true;
                break;
            }
        }
        arquivoContatos.close();
        if (!encontrado) {
            std::cout << "Contato não encontrado." << std::endl;
        }
    } else {
        std::cout << "Erro ao abrir o arquivo para buscar contato." << std::endl;
    }
}

void excluirContato() {
    std::string nomeExcluir;
    std::cout << "Digite o nome do contato que deseja excluir: ";
    std::cin >> nomeExcluir;

    std::string contato;
    bool encontrado = false;

    std::ifstream arquivoContatos("contatos.txt");
    std::ofstream arquivoTemp("temp.txt");

    if (arquivoContatos.is_open()) {
        
        while (std::getline(arquivoContatos, contato)) {
            if (contato == nomeExcluir) {
                encontrado = true;
            } else {
                arquivoTemp << contato << std::endl;
            }
        }

        arquivoContatos.close();
        arquivoTemp.close();

        if (encontrado) {
            std::remove("contatos.txt");
            std::rename("temp.txt", "contatos.txt");
            std::cout << "Contato excluido com sucesso!" << std::endl;
        } else {
            std::remove("temp.txt"); 
            std::cout << "Contato nao encontrado." << std::endl;
        }
    } else {
        std::cout << "Erro: Arquivo de contatos nao encontrado." << std::endl;
    }
}

int main () {
    int opcao;
    do {
        Menu();
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        switch (opcao) {
            case 1:
                adicionarContato();
                break;
            case 2:
                listarContatos();
                break;
            case 3:
                buscarContato();
                break;
            case 4:
                excluirContato();
                break;
            case 5:
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
        }
    } while (opcao != 5);
    return 0;
}
//programa de gestao de encomendas futaria

#include <iostream>
//para cin e cout
#include <string>
//para usar strings
#include <fstream>
//para usar ficheiros
#include <ctime>
//para data e hora
#include <vector>
//para usar vetores


using namespace std; //para evitar usar std:: antes de cout


//struct para guardar informacoes da encomenda
struct Encomenda {

    string nomeCliente;
    string enderecoCliente;
    string descricaoProduto;
    double pesoProduto;
    double custoPorKg;
    string dataHora;
    double taxaIva = 0.06; // taxa de IVA de 6%

};

//funcao para registar uma encomenda
void registarEncomenda(Encomenda &encomenda) {

    //para garantir que o nome, endereco e descricao nao fiquem vazios
    do {

    cout << "Digita o nome do cliente: ";
    getline(cin, encomenda.nomeCliente);

    if(encomenda.nomeCliente.empty()) {
        cout << "O nome nao pode ficar vazio. Tenta outra vez.\n";
    }

} while (encomenda.nomeCliente.empty());

    do {
    cout << "Digita o endereco do cliente: ";
    getline(cin, encomenda.enderecoCliente);

    if (encomenda.enderecoCliente.empty()) {
        cout << "O endereco nao pode ficar vazio. Tenta outra vez.\n";
    }
} while (encomenda.enderecoCliente.empty());

    do {

    cout << "Digita a descricao do produto: ";
    getline(cin, encomenda.descricaoProduto);

    if (encomenda.descricaoProduto.empty()) {
        cout << "A descricao nao pode ficar vazia. Tenta outra vez.\n";
    }
} while (encomenda.descricaoProduto.empty());

    cout << "Digita o peso do produto em kg: ";
while (!(cin >> encomenda.pesoProduto) || encomenda.pesoProduto <= 0) {
    cout << "Peso invalido. Digita um numero maior que 0: ";

    cout << "Digita o custo por kg: ";
while (!(cin >> encomenda.custoPorKg) || encomenda.custoPorKg <= 0) {
    cout << "Custo invalido. Digita um numero maior que 0: ";

    //para evitar numeros negativos
   cout << "Digita o peso do produto em kg: ";
while (!(cin >> encomenda.pesoProduto) || encomenda.pesoProduto <= 0) {
    cout << "Peso invalido. Digita um numero maior que 0: ";
    cin.ignore();

}

}

cout << "Digita o custo por kg: ";
while (!(cin >> encomenda.custoPorKg) || encomenda.custoPorKg <= 0) {
    cout << "Custo invalido. Digita um numero maior que 0: ";
    cin.ignore()
}

}

}

//funcao para calcular o custo total da encomenda
double calcularCustoTotal(const Encomenda &encomenda)

{
    double custoTotal = encomenda.pesoProduto * encomenda.custoPorKg;
    cout << "Custo sem IVA: " << custoTotal << " €\n";
    cout << "IVA (6%): " << custoTotal * 0.06 << " €\n";
    return custoTotal * 1.06; //adiciona 6% de IVA
}

int main() {
    cout << "== Sistema de Gestão de Encomendas - Futaria ==\n\n";
    time_t agora = time(0);
    cout << "== Data e hora atual: == " << ctime(&agora) << "\n";
    
    vector<Encomenda> encomendas;
    
    // guarda todas as encomendas
    char continuar = 's';

    // loop para registar multiplas encomendas
    while (continuar == 's' || continuar == 'S') {
        Encomenda nova;
        registarEncomenda(nova);

        // calcula o custo total
        double custo = calcularCustoTotal(nova); 

        cout << "\nEncomenda registada com sucesso!\n";
        cout << "Custo total: " << custo << " €\n\n";

        // mostra a data e hora em que foi feita a encomenda
        time_t agora = time(0);
        cout << "Encomenda feita a: " << ctime(&agora);

        encomendas.push_back(nova);

       char resposta;
do {
    cout << "Queres registar outra encomenda? (s/n): ";
    cin >> resposta;
    resposta = tolower(resposta); // para aceitar S ou s

    if (resposta != 's' && resposta != 'n') {
        cout << "Resposta invalida! Digita s para sim ou n para nao.\n";
    }
} while (resposta != 's' && resposta != 'n');

if (resposta == 'n') {
    char confirmar;
    do {
        cout << "Tem a certeza que quer sair? (s/n): ";
        cin >> confirmar;
        confirmar = tolower(confirmar);

        if (confirmar != 's' && confirmar != 'n') {
            cout << "Resposta invalida! Digita s para sim ou n para nao.\n";
        }
    } while (confirmar != 's' && confirmar != 'n');

    if (confirmar == 's') {
        cout << "\nObrigado por usar o sistema da Futaria. Ate breve!\n";
        break; // sai do loop
    } else {
        resposta = 's'; // volta a permitir registar encomendas
    }
}
}

    // resumo das encomendas registadas
    cout << "\nTotal de encomendas registadas hoje: " << encomendas.size() << "\n";
    cout << "\n=== Resumo das encomendas registadas hoje ===\n";

    double totalFaturado = 0;
    for (int i = 0; i < encomendas.size(); i++) {
        double custo = encomendas[i].pesoProduto * encomendas[i].custoPorKg;

        totalFaturado += custo;
        cout << "- " << encomendas[i].nomeCliente << " | " << encomendas[i].descricaoProduto 
             << " | " << encomendas[i].pesoProduto << "kg | Total: " << custo << " €\n";

    }

    cout << "============================================\n";
    cout << "Total de encomendas: " << encomendas.size() << "\n";
    cout << "Valor total faturado hoje: " << totalFaturado << " €\n\n";

    // guarda as encomendas num ficheiro de texto
    ofstream ficheiro("encomendas.txt");  // nome do ficheiro

    if (ficheiro.is_open()) {
        ficheiro << "Encomendas de hoje:\n\n";

        // escreve cada encomenda no ficheiro
        for (int i = 0; i < encomendas.size(); i++) {
            double custo = encomendas[i].pesoProduto * encomendas[i].custoPorKg;
            
            ficheiro << encomendas[i].nomeCliente << " - ";
            ficheiro << encomendas[i].enderecoCliente << " - ";
            ficheiro << encomendas[i].descricaoProduto << " - ";
            ficheiro << encomendas[i].pesoProduto << " kg - ";
            ficheiro << custo << " euros\n";
            ficheiro << " - Data: " << encomendas[i].dataHora << "\n";

        }

        ficheiro << "\nTotal de encomendas: " << encomendas.size() << "\n";
        ficheiro << "Total faturado: " << totalFaturado << " euros\n";

        ficheiro.close();  // fecha o ficheiro

        cout << "As encomendas foram guardadas no ficheiro encomendas.txt\n";
    }
    else {
        
        cout << "Nao foi possivel abrir o ficheiro para guardar.\n";

    }

    cout << "Obrigado por usar o sistema da frutaria.\n";

    return 0;
}


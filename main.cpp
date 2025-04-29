#include <iostream>
#include <list>

using namespace std;

struct Tipo_Produtos {
    int codigo;
    string descricao;
};

void ler_tipo_produtos(Tipo_Produtos lista[]) {
    system("cls");
    cout << "Leitura de tipo de produtos" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Digite o codigo do produto: ";
        cin >> lista[i].codigo;
        cout << "Digite o descricao do produto: ";
        cin >> lista[i].descricao;
    }
}

struct Produtos {
    int codigo;
    string descricao;
    Tipo_Produtos tipo_produto;
    int codigo_fornecedor;
    int qtd_estoque;
    int estoque_minimo;
    int estoque_maximo;
    float valor_unitario;
};

void ler_produtos(Produtos lista[]) {
    system("cls");
    cout << "Leitura de produtos" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Codigo: ";
        cin >> lista[i].codigo;
        cout << "Descricao: ";
        cin >> lista[i].descricao;
        cout << "Tipo produto > ID: ";
        cin >> lista[i].tipo_produto.codigo;
        cout << "Tipo produto < Descricao: ";
        cin >> lista[i].tipo_produto.descricao;
    }
}

struct Cidades {
    int codigo;
    string descricao;
    char UF[2];
};

void ler_cidades(Cidades lista[]) {
    system("cls");
    cout << "Leitura de cidades" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Codigo: ";
        cin >> lista[i].codigo;
        cout << "Descricao: ";
        cin >> lista[i].descricao;
        cout << "UF: ";
        cin >> lista[i].UF;
    }
}

struct Fornecedores {
    int codigo;
    string nome;
    string endereco;
    string telefone;
    int codigo_cidade;
    string cnpj;
};

void ler_fornecedores(Fornecedores lista[]) {
    system("cls");
    cout << "Leitura de fornecedores" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Codigo: ";
        cin >> lista[i].codigo;
        cout << "Descricao: ";
        cin >> lista[i].nome;
        cout << "Endereco: ";
        cin >> lista[i].endereco;
        cout << "Telefone: ";
        cin >> lista[i].telefone;
        cout << "Codigo_cidade: ";
        cin >> lista[i].codigo_cidade;
        cout << "Cnpj: ";
        cin >> lista[i].cnpj;
    }
}

void incluir_novo_fornecedor(Fornecedores lista[]) {
    system("cls");
    Fornecedores novoFornecedor;
    cout << "Adicionar novo fornecedore" << endl;
    cout << "Codigo: ";
    cin >> novoFornecedor.codigo;
    cout << "Nome: ";
    cin >> novoFornecedor.nome;
    cout << "Endereco: ";
    cin >> novoFornecedor.endereco;
    cout << "Telefone: ";
    cin >> novoFornecedor.telefone;
    cout << "Codigo_cidade: ";
    cin >> novoFornecedor.codigo_cidade;
    cout << "Cnpj: ";
    cin >> novoFornecedor.cnpj;
}

int menu() {
    system("cls");

    int opcao = -1;
    cout << "1# -> Adicionar fornecedores" << endl;
    cin >> opcao;

    switch (opcao) {
        case 1:
            cout << "Oi";
            break;
        default: cout << "Opcao invalida";
    }

    return opcao;
}

int main() {
    int opcao = menu();
}

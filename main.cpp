#include <iostream>

using namespace std;

struct Tipo_Produtos {
    int codigo;
    string descricao;
};

void ler_tipo_produtos(Tipo_Produtos lista[]) {
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
    string UF;
};

void ler_cidades(Cidades lista[]) {
    cout << "Leitura de cidades" << endl;
    for (int i = 0; i < 5; i++) {
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

int buscar_cidade_por_codigo(int codigo, Cidades lista[]) {
    int inicio = 0, fim = 5, meio = 0;
    meio = (inicio + fim) / 2;
    while (inicio <= fim && lista[meio].codigo == codigo) {
        if (codigo != lista[meio].codigo) {
            if (codigo > lista[meio].codigo) {
                inicio = meio + 1;
                meio = (inicio + fim) / 2;
            } else if (codigo < lista[meio].codigo) {
                fim = meio - 1;
                meio = (inicio + fim) / 2;
            }
        }
    }
    cout << "Não existe cidade com esse código!" << endl;
    return meio;
}

bool validar_cnpj(string cnpj) {
    if (cnpj.length() != 14) {
        return false;
    }
    int mult1[] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2}, mult2[] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int somar1 = 0, somar2 = 0;
    for (int i = 0; i < 12; i++) {
        somar1 += (cnpj[i] - '0') * mult1[i];
    }
    int rest1 = somar1 % 11;
    int digito1 = (rest1 < 2) ? 0 : (11 - rest1);
    for (int i = 0; i < 12; i++) {
        somar2 += (cnpj[i] - '0') * mult2[i];
    }
    somar2 = digito1 * mult2[12];
    int rest2 = somar2 % 11, digito2 = (rest2 < 2) ? 0 : (11 - rest2);
    string digitoveri = to_string(digito1) + to_string(digito2);
    if (cnpj.substr(12, 2) == digitoveri) {
        return true;
    }
    return false;
}

void mesclar_fornecedores(Fornecedores listaS[], int tamanhoS, Fornecedores listaT[], int tamanhoT, Fornecedores listaF[], int *tamanhoF) {
    int s = 0, t = 0, f = 0;

    for (; s < tamanhoS && t < tamanhoT; f++) {
        if (listaS[s].codigo < listaT[t].codigo) {
            listaF[f].codigo = listaS[s].codigo;
            listaF[f].nome = listaS[s].nome;
            listaF[f].endereco = listaS[s].endereco;
            listaF[f].telefone = listaS[s].telefone;
            listaF[f].codigo_cidade = listaS[s].codigo_cidade;
            listaF[f].cnpj = listaS[s].cnpj;
            s++;
        } else {
            listaF[f].codigo = listaT[t].codigo;
            listaF[f].nome = listaT[t].nome;
            listaF[f].endereco = listaT[t].endereco;
            listaF[f].telefone = listaT[t].telefone;
            listaF[f].codigo_cidade = listaT[t].codigo_cidade;
            listaF[f].cnpj = listaT[t].cnpj;
            t++;
        }
    }

    while (s < tamanhoS) {
        listaF[f].codigo = listaS[s].codigo;
        listaF[f].nome = listaS[s].nome;
        listaF[f].endereco = listaS[s].endereco;
        listaF[f].telefone = listaS[s].telefone;
        listaF[f].codigo_cidade = listaS[s].codigo_cidade;
        listaF[f].cnpj = listaS[s].cnpj;
        s++;
        f++;
    }

    while (t < tamanhoT) {
        listaF[f].codigo = listaT[t].codigo;
        listaF[f].nome = listaT[t].nome;
        listaF[f].endereco = listaT[t].endereco;
        listaF[f].telefone = listaT[t].telefone;
        listaF[f].codigo_cidade = listaT[t].codigo_cidade;
        listaF[f].cnpj = listaT[t].cnpj;
        t++;
        f++;
    }

    *tamanhoF = f;
}

void incluir_novo_fornecedor(Fornecedores lista[], int tamanho, Cidades lista_cidades[]) {
    for (int i = 0; i < tamanho; i++) {
        Fornecedores novosFornecedores[tamanho];
        cout << "Adicionar novo fornecedore" << endl;
        cout << "Codigo: ";
        cin >> novosFornecedores[i].codigo;
        cout << "Nome: ";
        cin >> novosFornecedores[i].nome;
        cout << "Endereco: ";
        cin >> novosFornecedores[i].endereco;
        cout << "Telefone: ";
        cin >> novosFornecedores[i].telefone;
        cout << "Codigo_cidade: ";
        cin >> novosFornecedores[i].codigo_cidade;
        int indice_cidade = buscar_cidade_por_codigo(novosFornecedores[i].codigo, lista_cidades);
        cout << "Nome da cidade localizada: " << lista_cidades[indice_cidade].descricao << endl;
        cout << "UF da cidade localizada: " << lista_cidades[indice_cidade].UF << endl;

        string cnpj;
        cout << "Cnpj: ";
        cin >> cnpj;
        if (validar_cnpj(cnpj)) {
            novosFornecedores[i].cnpj = cnpj;
        }else {
        }
        while (!validar_cnpj(cnpj)) {
            cout << "CNPJ Inválido! Tente novamente..."<<endl;
            cout << "Cnpj: ";
            cin >> cnpj;
            validar_cnpj(cnpj);
        }
    }
}

int menu() {
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

}

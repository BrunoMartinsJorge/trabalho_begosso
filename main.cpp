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

int buscar_cidade_por_codigo(int codigo, Cidades lista[], int tamanho) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (codigo == lista[meio].codigo) {
            return meio;
        } else if (codigo > lista[meio].codigo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    cout << "Não existe cidade com esse código!" << endl;
    return -1;
}

/*2# e 2#.2*/
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
    somar2 += digito1 * mult2[12];
    int rest2 = somar2 % 11, digito2 = (rest2 < 2) ? 0 : (11 - rest2);
    string digitoveri = to_string(digito1) + to_string(digito2);
    if (cnpj.substr(12, 2) == digitoveri) {
        return true;
    }
    return false;
}

void mesclar_fornecedores(Fornecedores listaS[], int tamanhoS, Fornecedores listaT[], int tamanhoT,
                          Fornecedores listaF[]) {
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
}

/*2# e 2#.1*/
void incluir_novo_fornecedor(Fornecedores lista[], Cidades lista_cidades[], int tamanho) {
    Fornecedores novosFornecedores[tamanho];
    for (int i = 0; i < tamanho; i++) {
        system("cls");
        cout << "Adicionar novos fornecedores" << endl;
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
        int indice_cidade = buscar_cidade_por_codigo(novosFornecedores[i].codigo_cidade, lista_cidades, 3);
        cout << "Nome da cidade localizada: " << lista_cidades[indice_cidade].descricao << endl;
        cout << "UF da cidade localizada: " << lista_cidades[indice_cidade].UF << endl;

        string cnpj;
        cout << "Cnpj: ";
        cin >> cnpj;
        if (validar_cnpj(cnpj)) {
            novosFornecedores[i].cnpj = cnpj;
        } else {
        }
        while (!validar_cnpj(cnpj)) {
            cout << "CNPJ Inválido! Tente novamente..." << endl;
            cout << "Cnpj: ";
            cin >> cnpj;
            validar_cnpj(cnpj);
        }
    }
    Fornecedores novaLista[3 + tamanho];
    mesclar_fornecedores(lista, 3, novosFornecedores, tamanho, novaLista);
    cout << "Valores para nova lista: " << endl;
    for (int i = 0; i < tamanho + 3; i++) {
        cout << "<!---------------------------------------------------------------!>" << endl;
        cout << "Codigo: " << novaLista[i].codigo << endl;
        cout << "Nome: " << novaLista[i].nome << endl;
        cout << "Endereco: " << novaLista[i].endereco << endl;
        cout << "Telefone: " << novaLista[i].telefone << endl;
        cout << "Codigo da cidade: " << novaLista[i].codigo_cidade << endl;
        cout << "CNPJ: " << novaLista[i].cnpj << endl;
    }
}

int buscar_produto_por_codigo(Produtos lista[], int codigo_produto, int tamanho) {
    int inicio = 0, fim = tamanho, meio = 0;
    meio = (inicio + fim) / 2;
    while (inicio <= fim && lista[meio].codigo == codigo_produto) {
        if (codigo_produto != lista[meio].codigo) {
            if (codigo_produto > lista[meio].codigo) {
                inicio = meio + 1;
                meio = (inicio + fim) / 2;
            } else if (codigo_produto < lista[meio].codigo) {
                fim = meio - 1;
                meio = (inicio + fim) / 2;
            }
        }
    }
    if (meio != codigo_produto) {
        cout << "Produto não encontrado!" << endl;
        return -1;
    }
    return meio;
}

int buscar_fornecedor_por_codigo(Fornecedores lista[], int codigo_fornecedor, int tamanho) {
    int inicio = 0, fim = tamanho, meio = 0;
    meio = (inicio + fim) / 2;
    while (inicio <= fim && lista[meio].codigo == codigo_fornecedor) {
        if (codigo_fornecedor != lista[meio].codigo) {
            if (codigo_fornecedor > lista[meio].codigo) {
                inicio = meio + 1;
                meio = (inicio + fim) / 2;
            } else if (codigo_fornecedor < lista[meio].codigo) {
                fim = meio - 1;
                meio = (inicio + fim) / 2;
            }
        }
    }
    if (meio != codigo_fornecedor) {
        cout << "Fornecedor não encontrado!" << endl;
        return -1;
    }
    return meio;
}

//4#
void vender_produto(int codigo_produto, Produtos lista_produtos[], Fornecedores lista_fornecedores[]) {
    int indice_produto = buscar_produto_por_codigo(lista_produtos, codigo_produto, 3);
    if (indice_produto == -1) {
        cout << "Produto não encontrado!" << endl;
    }
    int indice_fornecedor = buscar_fornecedor_por_codigo(lista_fornecedores,
                                                         lista_produtos[indice_produto].codigo_fornecedor, 3);
    if (indice_fornecedor == -1) {
        cout << "Produto não encontrado!" << endl;
    }
    // 4#.1
    cout << "Descrição do Produto: " << endl;
    cout << "Descrição: " << lista_produtos[indice_produto].descricao << endl;
    cout << "Quantidade em estoque: " << lista_produtos[indice_produto].qtd_estoque << endl;
    cout << "Valor por unidade: " << lista_produtos[indice_produto].valor_unitario << endl;
    // 4#.2
    cout << "\nDescrição do Tipo do Produto: " << endl;
    cout << "Descrição do tipo do produto: " << lista_produtos[indice_produto].tipo_produto.descricao << endl;
    cout << "Nome do fornecedor: " << lista_fornecedores[indice_fornecedor].nome << endl;
    //4#.3
    int qtd_produtos = 0;
    cout << "Qual a quantidade de produtos que você deseja vender? ";
    cin >> qtd_produtos;
    // 4#.4
    if (qtd_produtos > lista_produtos[indice_produto].qtd_estoque) {
        cout << "A quantidade que foi solicitada para a compra é maior que a quantidade de produtos no estoque!" <<
                endl;
    }
    // 4#.5
    cout << "O valor total da venda do produto é de: " << (lista_produtos[indice_produto].valor_unitario * qtd_produtos)
            <<
            endl;
    char confirmar_venda = 'N';
    cout << "Para confirmar a venda dos produtos, por favor digite 'S', caso queira cancelar digite 'N'!";
    cin >> confirmar_venda;
    if (codigo_produto == 'S') {
        lista_produtos[indice_produto].qtd_estoque -= qtd_produtos;
        cout << "Venda confirmada! Agora o produto possui em estoque " << lista_produtos[indice_produto].qtd_estoque <<
                endl;
    } else {
        cout << "Cancelando venda dos produtos!" << endl;
    }
}

// 6#
void exibir_estoque_abaixo_minimo(Produtos lista_produtos[], Fornecedores lista_fornecedores[],
                                  int tamanho_fornecedores) {
    for (int i = 0; i < tamanho_fornecedores; i++) {
        float valor_total = 0;
        if (lista_produtos[i].qtd_estoque < lista_produtos[i].estoque_minimo) {
            cout << "Codigo produto: " << lista_produtos[i].codigo << endl;
            cout << "Descricao: " << lista_produtos[i].descricao << endl;
            cout << "Quantidade em estoque: " << lista_produtos[i].qtd_estoque << endl;
            cout << "Estoque maximo: " << lista_produtos[i].estoque_maximo << endl;
            cout << "Quantidade a ser comprada: " << 1 << endl;
            valor_total += lista_produtos[i].valor_unitario * lista_produtos[i].qtd_estoque;
            cout << "Valor da compra: " << lista_produtos[i].valor_unitario * lista_produtos[i].qtd_estoque << endl;
            int indice_fornecedor = buscar_fornecedor_por_codigo(lista_fornecedores,
                                                                 lista_produtos[i].codigo_fornecedor, 3);
            cout << "Nome do fornecedor: " << lista_fornecedores[indice_fornecedor].nome << endl;
            cout << "Telefone do fornecedor: " << lista_fornecedores[indice_fornecedor].telefone << endl;
        }
        cout << "O valor total da compra foi de: " << valor_total << endl;
    }
}

void menu(Produtos lista_produtos[], Fornecedores lista_fornecedores[], Cidades lista_cidades[],
         Tipo_Produtos lista_tipo_produtos[]) {
    int opcao = -1;
    int opcao_ler = 0;
    int qtd_fornece_adicionar = -1;
    int codigo_produto = -1;
    while (opcao == -1) {
        system("cls");
        cout << "<!--------------------* Menu *---------------------!>" << endl;
        cout << "<! Opcao #1 := Ler dados                           !>" << endl;
        cout << "<! Opcao #2 := Adicionar novo(s) fornecedor(es)    !>" << endl;
        cout << "<! Opcao #3 := Adicionar novo(s) produto(s)        !>" << endl;
        cout << "<! Opcao #4 := Vender produto(s)                   !>" << endl;
        cout << "<! Opcao #5 := Consultar produto em estoque        !>" << endl;
        cout << "<! Opcao #6 := Exibir produtos abaixo do minimo    !>" << endl;
        cout << "<! Opcao #7 := Buscar produtos palindromos         !>" << endl;
        cout << "<!-------------* Para sair digite '0' *------------!>" << endl;
        cout << "Opcao Selecionada : ";
        cin >> opcao;
    }
    switch (opcao) {
        case 1:
            cout << "<!------------------* Sub-Menu *-------------------!>" << endl;
            cout << "<! Opcao #1 := Ler dados de Produtos               !>" << endl;
            cout << "<! Opcao #2 := Ler dados de Fornecedores           !>" << endl;
            cout << "<! Opcao #3 := Ler dados de Cidades                !>" << endl;
            cout << "<! Opcao #4 := Ler dados de Tipos Produto          !>" << endl;
            cout << "<!-------------* Para sair digite '0' *------------!>" << endl;
            cout << "Opcao Selecionada : ";
            cin >> opcao_ler;
            switch (opcao_ler) {
                case 1:
                    ler_produtos(lista_produtos);
                    break;
                case 2:
                    ler_fornecedores(lista_fornecedores);
                    break;
                case 3:
                    ler_cidades(lista_cidades);
                    break;
                case 4:
                    ler_tipo_produtos(lista_tipo_produtos);
                default:
                    cout << "Opcao Selecionada invalida!" << endl;
            }
            break;
        case 2:
            while (qtd_fornece_adicionar == -1) {
                cout << "Quantos fornecedores você deseja adcionar?: ";
                cin >> qtd_fornece_adicionar;
            }
            incluir_novo_fornecedor(lista_fornecedores, lista_cidades, qtd_fornece_adicionar);
            break;
        case 3:
            // Adicionar novos produtos: Carlos
            break;
        case 4:
            for (int i = 0; i < 3; i++) {
                cout << "Nome do produto: " << lista_produtos[i].descricao << " | Codigo do produto: " << lista_produtos
                        [i].codigo << endl;
            }
            cout << "Digite o código do produto que desejá comprar: ";
            cin >> codigo_produto;
            vender_produto(codigo_produto, lista_produtos, lista_fornecedores);
            break;
        case 5:
            // Buscar dados especificos de um produto em estoque da empresa: Carlos
            break;
        case 6:
            exibir_estoque_abaixo_minimo(lista_produtos, lista_fornecedores, 3);
    }
}

int main() {
    Tipo_Produtos tipos[] = {
        {1, "Alimentos"},
        {2, "Limpeza"},
        {3, "Bebidas"}
    };

    Cidades cidades[] = {
        {1, "São Paulo", "SP"},
        {2, "Rio de Janeiro", "RJ"},
        {3, "Curitiba", "PR"}
    };

    Fornecedores fornecedores[] = {
        {1, "Fornecedor A", "Rua A, 123", "(11) 1111-1111", 1, "12345678000100"},
        {2, "Fornecedor B", "Rua B, 456", "(21) 2222-2222", 2, "98765432000199"},
        {3, "Fornecedor C", "Rua C, 789", "(41) 3333-3333", 3, "56789012000188"}
    };

    Produtos produtos[] = {
        {1, "Arroz 5kg", tipos[0], 120, 50, 200, 300, 25.50},
        {2, "Sabão em Pó 1kg", tipos[1], 80, 30, 150, 200, 9.99},
        {3, "Refrigerante 2L", tipos[2], 3, 200, 100, 300, 6.49}
    };

    menu(produtos, fornecedores, cidades, tipos);
}

#include <iostream>
#include <string>
#include <locale.h>
#include <cctype>

using namespace std;

struct Tipo_Produtos {
    int codigo;
    string descricao;
};

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


struct Fornecedores {
    int codigo;
    string nome;
    string endereco;
    string telefone;
    int codigo_cidade;
    string cnpj;
};

struct Cidades {
    int codigo;
    string descricao;
    string UF;
};

void ler_produtos(Produtos []);

void ler_tipo_produtos(Tipo_Produtos []);

void ler_fornecedores(Fornecedores []);

void ler_cidades(Cidades []);

void mostrar_produtos(Produtos []);

void mostrar_cidades(Cidades []);

void mostrar_fornecedores(Fornecedores []);

void mostrar_tipo_produtos(Tipo_Produtos []);

void incluir_novo_fornecedor(Fornecedores [], Cidades [], int);

bool validar_cnpj(string cnpj);

int buscar_produto_por_codigo(Produtos [], int, int);

int buscar_fornecedor_por_codigo(Fornecedores [], int, int);

int buscar_cidade_por_codigo(int, Cidades [], int);

void mesclar_fornecedores(Fornecedores [], int, Fornecedores [], int, Fornecedores []);

void mesclar_produtos(Produtos [], Produtos [], Produtos [], int, int);

void validar_se_palavra_for_palindromo(Produtos [], int);

void vender_produto(int, Produtos [], Fornecedores []);

void incluir_produto(Produtos [], Fornecedores [], int);

void consultar_produto(Produtos [], Fornecedores []);

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

int buscar_produto_por_codigo(Produtos lista[], int codigo_produto, int tamanho) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (lista[meio].codigo == codigo_produto) {
            return meio;
        }
        if (codigo_produto > lista[meio].codigo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    cout << "Produto não encontrado!" << endl;
    return -1;
}


int buscar_fornecedor_por_codigo(Fornecedores lista[], int codigo_fornecedor, int tamanho) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (lista[meio].codigo == codigo_fornecedor) {
            return meio;
        }
        if (codigo_fornecedor > lista[meio].codigo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    cout << "Produto não encontrado!" << endl;
    return -1;
}


// 6#
void exibir_estoque_abaixo_minimo(Produtos lista_produtos[], Fornecedores lista_fornecedores[],
                                  int tamanho_fornecedores) {
    for (int i = 0; i < tamanho_fornecedores; i++) {
        float quantidade_comprar = 0;
        if (lista_produtos[i].qtd_estoque < lista_produtos[i].estoque_minimo) {
            quantidade_comprar = lista_produtos[i].estoque_maximo - lista_produtos[i].qtd_estoque;
            cout << "<!------------------------------------------------------------------------------!>" << endl;
            cout << "Codigo produto: " << lista_produtos[i].codigo << endl;
            cout << "Descricao: " << lista_produtos[i].descricao << endl;
            cout << "Quantidade em estoque: " << lista_produtos[i].qtd_estoque << endl;
            cout << "Estoque maximo: " << lista_produtos[i].estoque_maximo << endl;
            cout << "Quantidade para ser comprada: " << quantidade_comprar << endl;
            int indice_fornecedor = buscar_fornecedor_por_codigo(lista_fornecedores,
                                                                 lista_produtos[i].codigo_fornecedor, 3);
            cout << "Nome do fornecedor 1: " << lista_fornecedores[indice_fornecedor].nome << endl;
            cout << "Telefone do fornecedor: " << lista_fornecedores[indice_fornecedor].telefone << endl;
            cout << "\nValor total a ser comprado: " << quantidade_comprar * lista_produtos[i].valor_unitario << endl;
            cout << "<!------------------------------------------------------------------------------!>" << endl;
        }
    }
}


void menu(Produtos lista_produtos[], Fornecedores lista_fornecedores[], Cidades lista_cidades[],
          Tipo_Produtos lista_tipo_produtos[]) {
    int opcao = -1;
    int opcao_ler = 0;
    int qtd_fornece_adicionar = -1;
    int codigo_produto = -1;
    Produtos novaLista[2];
    while (opcao != 0) {
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
        case 0:
            cout << "Saindo..." << endl;
            break;
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
                case 0:
                    cout << "Saindo..." << endl;
                    break;
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
                    break;
                default:
                    cout << "Opcao Selecionada invalida!" << endl;
            }
            //menu(lista_produtos, lista_fornecedores, lista_cidades, lista_tipo_produtos);
            break;
        case 2:
            while (qtd_fornece_adicionar == -1) {
                cout << "Quantos fornecedores você deseja adcionar?: ";
                cin >> qtd_fornece_adicionar;
            }
            incluir_novo_fornecedor(lista_fornecedores, lista_cidades, qtd_fornece_adicionar);
            //menu(lista_produtos, lista_fornecedores, lista_cidades, lista_tipo_produtos);
            break;
        case 3:
            incluir_produto(lista_produtos, lista_fornecedores, 3);
            //menu(lista_produtos, lista_fornecedores, lista_cidades, lista_tipo_produtos);
            break;
        case 4:
            cout << "Digite o código do produto que desejá comprar: ";
            cin >> codigo_produto;
            vender_produto(codigo_produto, lista_produtos, lista_fornecedores);
            //menu(lista_produtos, lista_fornecedores, lista_cidades, lista_tipo_produtos);
            break;
        case 5:
            consultar_produto(lista_produtos, lista_fornecedores);
            //menu(lista_produtos, lista_fornecedores, lista_cidades, lista_tipo_produtos);
            break;
        case 6:
            exibir_estoque_abaixo_minimo(lista_produtos, lista_fornecedores, 3);
            //menu(lista_produtos, lista_fornecedores, lista_cidades, lista_tipo_produtos);
            break;
        case 7:
            validar_se_palavra_for_palindromo(lista_produtos, 3);
            //menu(lista_produtos, lista_fornecedores, lista_cidades, lista_tipo_produtos);
            break;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

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
        {1, "Ovo", tipos[0], 1, 50, 10, 300, 25.50},
        {2, "Sabão em Pó 1kg", tipos[1], 2, 30, 150, 200, 9.99},
        {3, "Refrigerante 2L", tipos[2], 3, 200, 100, 300, 6.49}
    };

    menu(produtos, fornecedores, cidades, tipos);
}

// 1# Funões de Leitura:
// Ler cidades
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

// Ler tipo produtos
void ler_tipo_produtos(Tipo_Produtos lista[]) {
    cout << "Leitura de tipo de produtos" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Digite o codigo do produto: ";
        cin >> lista[i].codigo;
        cout << "Digite o descricao do produto: ";
        cin >> lista[i].descricao;
    }
}

// Ler produtos
void ler_produtos(Produtos lista[]) {
    cout << "Leitura de produtos" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Codigo: ";
        cin >> lista[i].codigo;
        cout << "Descricao: ";
        cin >> lista[i].descricao;
        cout << "Tipo produto > ID: ";
        cin >> lista[i].tipo_produto.codigo;
        cout << "Tipo produto > Descricao: ";
        cin >> lista[i].tipo_produto.descricao;
        cout << "Codigo do fornecedor: ";
        cin >> lista[i].codigo_fornecedor;
        cout << "Quantidade em estoque: ";
        cin >> lista[i].qtd_estoque;
        cout << "Estoque minimo: ";
        cin >> lista[i].estoque_minimo;
        cout << "Estoque maximo: ";
        cin >> lista[i].estoque_maximo;
    }
}

// Ler fornecedores
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

// Fim da etapa 1#

// 2# Função para incluir novo(s) fornecedor(es):
void incluir_novo_fornecedor(Fornecedores lista[], Cidades lista_cidades[], int qtd_fornecedores_adicionar) {
    Fornecedores novosFornecedores[qtd_fornecedores_adicionar];
    for (int i = 0; i < qtd_fornecedores_adicionar; i++) {
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
    Fornecedores novaLista[3 + qtd_fornecedores_adicionar];
    mesclar_fornecedores(lista, 3, novosFornecedores, qtd_fornecedores_adicionar, novaLista);
    cout << "Valores para nova lista: " << endl;
    for (int i = 0; i < qtd_fornecedores_adicionar + 3; i++) {
        cout << "<!---------------------------------------------------------------!>" << endl;
        cout << "Codigo: " << novaLista[i].codigo << endl;
        cout << "Nome: " << novaLista[i].nome << endl;
        cout << "Endereco: " << novaLista[i].endereco << endl;
        cout << "Telefone: " << novaLista[i].telefone << endl;
        cout << "Codigo da cidade: " << novaLista[i].codigo_cidade << endl;
        cout << "CNPJ: " << novaLista[i].cnpj << endl;
    }
}

// 2#1 Função para buscar a cidade por código:
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

// 2#2 Função para validar CNPJ(Só que ele espera que o CNPJ venha sem caracteres especiais)
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

// Fim da etapa 2#

// Inicio da etapa 3#
// Função para incluir novo(s) produto(s)
void incluir_produto(Produtos lista[], Fornecedores lista_fornecedor[], int tamanho) {
    int qtd_produtos = 0;
    cout << "Quantos produtos você quer adicionar? ";
    cin >> qtd_produtos;
    Produtos novoProduto[qtd_produtos];
    for (int i = 0; i < qtd_produtos; i++) {
        cout << "Digite o códgio do produto que deseja inserir: ";
        while (true) {
            cin >> novoProduto[i].codigo;
            bool codigoExiste = false;
            for (int index = 0; index < tamanho; index++) {
                if (lista[index].codigo == novoProduto[i].codigo) {
                    cout << "Código já existe! Digite outro: ";
                    codigoExiste = true;
                    break;
                }
            }
            if (!codigoExiste) {
                break;
            }
        }
        cout << "Nome do produto: ";
        cin >> novoProduto[i].descricao;
        cout << "Codigo do tipo do Produto: ";
        cin >> novoProduto[i].tipo_produto.codigo;
        cout << "Descricao do tipo do Produto: ";
        cin >> novoProduto[i].tipo_produto.descricao;
        cout << "Codigo do fornecedor: ";
        int index_fornecedor;
        while (true) {
            cin >> novoProduto[i].codigo_fornecedor;
            index_fornecedor = buscar_fornecedor_por_codigo(lista_fornecedor, novoProduto[i].codigo_fornecedor, 3);
            if (index_fornecedor == -1) {
                cout << "Fornecedor com este código não foi encontrado! Tente outro: ";
            } else {
                break;
            }
        }
        cout << "Nome do fornecedor: " << lista_fornecedor[index_fornecedor].nome << endl;
        cout << "Quantidade em estoque: ";
        cin >> novoProduto[i].qtd_estoque;
        cout << "Quantidade minima: ";
        cin >> novoProduto[i].estoque_minimo;
        cout << "Quantidade maxima: ";
        cin >> novoProduto[i].estoque_maximo;
        cout << "Valor por unidade: ";
        cin >> novoProduto[i].valor_unitario;
    }
    Produtos nova_lista[tamanho + qtd_produtos];
    mesclar_produtos(lista, novoProduto, nova_lista, tamanho, qtd_produtos);
}

void mesclar_produtos(Produtos lista_atual[], Produtos lista_adicionar[], Produtos nova_lista[], int tamanho_lista_s,
                      int tamanho_lista_add) {
    int s = 0, t = 0, f = 0;

    for (; s < tamanho_lista_s && t < tamanho_lista_add; f++) {
        if (lista_atual[s].codigo < lista_adicionar[t].codigo) {
            nova_lista[f].codigo = lista_atual[s].codigo;
            nova_lista[f].descricao = lista_atual[s].descricao;
            nova_lista[f].estoque_maximo = lista_atual[s].estoque_maximo;
            nova_lista[f].estoque_minimo = lista_atual[s].estoque_minimo;
            nova_lista[f].qtd_estoque = lista_atual[s].qtd_estoque;
            nova_lista[f].tipo_produto = lista_atual[s].tipo_produto;
            nova_lista[f].valor_unitario = lista_atual[s].valor_unitario;
            s++;
        } else {
            nova_lista[f].codigo = lista_adicionar[t].codigo;
            nova_lista[f].descricao = lista_adicionar[t].descricao;
            nova_lista[f].estoque_maximo = lista_adicionar[t].estoque_maximo;
            nova_lista[f].estoque_minimo = lista_adicionar[t].estoque_minimo;
            nova_lista[f].qtd_estoque = lista_adicionar[t].qtd_estoque;
            nova_lista[f].tipo_produto = lista_adicionar[t].tipo_produto;
            nova_lista[f].valor_unitario = lista_adicionar[t].valor_unitario;
            t++;
        }
    }

    while (s < tamanho_lista_s) {
        nova_lista[f].codigo = lista_atual[s].codigo;
        nova_lista[f].descricao = lista_atual[s].descricao;
        nova_lista[f].estoque_maximo = lista_atual[s].estoque_maximo;
        nova_lista[f].estoque_minimo = lista_atual[s].estoque_minimo;
        nova_lista[f].qtd_estoque = lista_atual[s].qtd_estoque;
        nova_lista[f].tipo_produto = lista_atual[s].tipo_produto;
        nova_lista[f].valor_unitario = lista_atual[s].valor_unitario;
        s++;
        f++;
    }

    while (t < tamanho_lista_add) {
        nova_lista[f].codigo = lista_adicionar[t].codigo;
        nova_lista[f].descricao = lista_adicionar[t].descricao;
        nova_lista[f].estoque_maximo = lista_adicionar[t].estoque_maximo;
        nova_lista[f].estoque_minimo = lista_adicionar[t].estoque_minimo;
        nova_lista[f].qtd_estoque = lista_adicionar[t].qtd_estoque;
        nova_lista[f].tipo_produto = lista_adicionar[t].tipo_produto;
        nova_lista[f].valor_unitario = lista_atual[t].valor_unitario;
        t++;
        f++;
    }
    lista_atual = nova_lista;
}

// Fim da etapa 3#

// Inicio da etapa 4#
// Função para venda de produtos
void vender_produto(int codigo_produto, Produtos lista_produtos[], Fornecedores lista_fornecedores[]) {
    int indice_produto = buscar_produto_por_codigo(lista_produtos, codigo_produto, 3);
    if (indice_produto == -1) {
        cout << "Produto não encontrado!" << endl;
    }
    int indice_fornecedor = buscar_fornecedor_por_codigo(lista_fornecedores,
                                                         lista_produtos[indice_produto].codigo_fornecedor, 3);
    if (indice_fornecedor == -1) {
        cout << "Fornecedor não encontrado!" << endl;
    }
    // 4#.1
    cout << "Descrição do Produto: " << endl;
    cout << "Descrição: " << lista_produtos[indice_produto].descricao << endl;
    cout << "Quantidade em estoque: " << lista_produtos[indice_produto].qtd_estoque << endl;
    cout << "Valor por unidade: " << lista_produtos[indice_produto].valor_unitario << endl;
    // 4#.2
    cout << "\nDescrição do Tipo do Produto: " << endl;
    cout << "Descrição do tipo do produto: " << lista_produtos[indice_produto].tipo_produto.descricao << endl;
    cout << "Nome do fornecedor 3: " << lista_fornecedores[indice_fornecedor].nome << endl;
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
    if (tolower(confirmar_venda == 's')) {
        lista_produtos[indice_produto].qtd_estoque -= qtd_produtos;
        cout << "Venda confirmada! Agora o produto possui em estoque " << lista_produtos[indice_produto].qtd_estoque <<
                endl;
    } else {
        cout << "Cancelando venda dos produtos!" << endl;
    }
}

// Fim da etapa 4#

// Inicio da etapa 5#
// Função para buscar um produto especifico
void consultar_produto(Produtos lista[], Fornecedores listaFor[]) {
    int codigo;
    cout << "Digite o código do produto que deseja consultar: ";
    cin >> codigo;

    int index_produto;
    for (int i = 0; i < 3; i++) {
        if (lista[i].codigo == codigo) {
            index_produto = i;
        }
        if (index_produto == -1) {
            cout << "Produto com código " << codigo << " não encontrado!" << endl;
            return;
        }
    }
    cout << "Codigo do produto: " << lista[index_produto].codigo << endl;
    cout << "Nome do produto: " << lista[index_produto].descricao << endl;
    cout << "Quantidade em estoque: " << lista[index_produto].qtd_estoque << endl;
    cout << "Quantidade minima: " << lista[index_produto].estoque_minimo << endl;
    cout << "Quantidade maxima: " << lista[index_produto].estoque_maximo << endl;
    cout << "Valor por unidade: " << lista[index_produto].valor_unitario << endl;
    cout << "Descricao do tipo do produto: " << lista[index_produto].tipo_produto.descricao << endl;
    int index_fornecedor = buscar_fornecedor_por_codigo(listaFor, lista[index_produto].codigo_fornecedor, 3);
    cout << "Nome do fornecedor: " << listaFor[index_fornecedor].nome << endl;
    cout << "Valor total em estoque: R$" << (lista[index_produto].qtd_estoque * lista[index_produto].valor_unitario) <<
            endl;
}

//Fim da etapa 5#

void validar_se_palavra_for_palindromo(Produtos lista[], int tamanho) {
    for (int index = 0; index < tamanho; index++) {
        if (lista[index].descricao.size() <= 1) {
            continue;
        }

        bool palavraIgualPalindromo = true;
        for (int i = 0, j = lista[index].descricao.size() - 1; i < j; i++, j--) {
            if (tolower(lista[index].descricao.at(i)) != tolower(lista[index].descricao.at(j))) {
                palavraIgualPalindromo = false;
                break;
            }
        }

        if (palavraIgualPalindromo) {
            cout << "A descrição \"" << lista[index].descricao << "\" é um palíndromo!" << endl;
        } else {
            cout << "A descrição \"" << lista[index].descricao << "\" não é um palíndromo!" << endl;
        }
    }
}

// Funções para mostrar os dados(Percibi que não precisava mais vamo lá!)
void mostrar_produtos(Produtos lista[]) {
    cout << "Produtos " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Codigo: " << lista[i].codigo << endl;
        cout << "Descricao: " << lista[i].descricao << endl;
        cout << "Tipo do produto ID: " << lista[i].tipo_produto.codigo << endl;
        cout << "Descricao do tipo do produto: " << lista[i].tipo_produto.descricao << endl;
        cout << "Codigo do fornecedor: " << lista[i].codigo_fornecedor << endl;
        cout << "Quantidade no estoque: " << lista[i].qtd_estoque;
        cout << "Estoque minimo: " << lista[i].estoque_minimo << endl;
        cout << "Estoque maximo: " << lista[i].estoque_maximo << endl;
        cout << "Valor unitário: " << lista[i].valor_unitario << endl;
    }
}

void mostrar_cidades(Cidades lista[]) {
    cout << "Cidades: ";
    for (int i = 0; i < 3; i++) {
        cout << "Código da cidade: " << lista[i].codigo << endl;
        cout << "Nome do cidade: " << lista[i].descricao << endl;
        cout << "UF: " << lista[i].UF << endl;
    }
}

void mostrar_fornecedores(Fornecedores lista[]) {
    cout << "Fornecedores: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Codigo do fornecedor: " << lista[i].codigo << endl;
        cout << "Nome do fornecedor 4: " << lista[i].nome << endl;
        cout << "Endereço: " << lista[i].endereco << endl;
        cout << "Telefone: " << lista[i].telefone << endl;
        cout << "Codigo da cidade: " << lista[i].codigo_cidade;
        cout << "CNPJ: " << lista[i].cnpj << endl;
    }
}

// Fim das funções de mostrar/imprimir

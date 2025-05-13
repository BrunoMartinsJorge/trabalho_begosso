#include <iostream>
#include <string>
#include <locale.h>
#include <cctype>
#include <vector>

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

// Questão 1#
void ler_cidades(vector<Cidades> &lista) {
    int qtd_cidades = 0;
    cout << "Quantas cidades você quer ler? ";
    cin >> qtd_cidades;
    cin.ignore();

    while (qtd_cidades <= 0) {
        cout << "Por favor digite uma quantidade válida de cidades: ";
        cin >> qtd_cidades;
        cin.ignore();
    }

    int i = 0;
    cout << "Leitura de cidades" << endl;
    for (; i < qtd_cidades; i++) {
        Cidades novaCidades;

        cout << "Código: ";
        cin >> novaCidades.codigo;
        cin.ignore();

        cout << "Descrição: ";
        getline(cin, novaCidades.descricao);

        cout << "UF: ";
        cin >> novaCidades.UF;
        cin.ignore();

        lista.push_back(novaCidades);
        cout << "<----------------------------------------->" << endl;
        cout << "Produto(s) inserido(s)" << endl;
        cout << "<----------------------------------------->" << endl;
    }
}

void ler_tipo_produtos(vector<Tipo_Produtos> &lista) {
    int qtd_tipo_produtos = 0;
    cout << "Quantos tipos de produtos você quer ler? ";
    cin >> qtd_tipo_produtos;
    cin.ignore();

    while (qtd_tipo_produtos <= 0) {
        cout << "Por favor digite uma quantidade válida de tipos de produtos para serem adicionados: ";
        cin >> qtd_tipo_produtos;
        cin.ignore();
    }

    int i = 0;
    cout << "Leitura de tipo de produtos" << endl;
    for (; i < qtd_tipo_produtos; i++) {
        Tipo_Produtos novoTipo;

        cout << "Digite o codigo do produto: ";
        cin >> novoTipo.codigo;
        cin.ignore();

        cout << "Digite o descricao do produto: ";
        cin >> novoTipo.descricao;
        cin.ignore();

        lista.push_back(novoTipo);
        cout << "<----------------------------------------->" << endl;
        cout << "Tipo(s) de produto(s) inserido(s)" << endl;
        cout << "<----------------------------------------->" << endl;
    }
}

void ler_produtos(vector<Produtos> &lista) {
    int qtd_produtos = 0;
    cout << "Quantos produtos você quer ler? ";
    cin >> qtd_produtos;
    cin.ignore();

    while (qtd_produtos <= 0) {
        cout << "Por favor digite uma quantidade válida de produtos para serem adicionados: ";
        cin >> qtd_produtos;
        cin.ignore();
    }
    int i = 0;
    cout << "Leitura de produtos" << endl;
    for (; i < qtd_produtos; i++) {
        Produtos novoProd;

        cout << "Codigo: ";
        cin >> novoProd.codigo;
        cin.ignore();

        cout << "Descricao: ";
        getline(cin, novoProd.descricao);

        cout << "Tipo produto > ID: ";
        cin >> novoProd.tipo_produto.codigo;
        cin.ignore();

        cout << "Tipo produto > Descricao: ";
        getline(cin, novoProd.tipo_produto.descricao);

        cout << "Codigo do fornecedor: ";
        cin >> novoProd.codigo_fornecedor;
        cin.ignore();

        cout << "Quantidade em estoque: ";
        cin >> novoProd.qtd_estoque;
        cin.ignore();

        cout << "Estoque minimo: ";
        cin >> novoProd.estoque_minimo;
        cin.ignore();

        cout << "Estoque maximo: ";
        cin >> novoProd.estoque_maximo;
        cin.ignore();

        cout << "Valor  unitário: ";
        cin >> novoProd.valor_unitario;
        cin.ignore();

        lista.push_back(novoProd);
        cout << "<----------------------------------------->" << endl;
        cout << "Produto(s) inserido(s)" << endl;
        cout << "<----------------------------------------->" << endl;
    }
}

bool validar_cnpj(string cnpj) {
    for (int i = 0; i < cnpj.size(); i++) {
        if (cnpj[i] == '.' || cnpj[i] == '-' || cnpj[i] == '/') {
            cnpj.erase(i, 1);
            i--;
        }
    }
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
        cout << "CNPJ Válidado!" << endl;
        return true;
    }
    return false;
}

void ler_fornecedores(vector<Fornecedores> &lista) {
    int qtd_fornecedores = 0;
    cout << "Quantos fornecedores você quer ler? ";
    cin >> qtd_fornecedores;
    cin.ignore();

    while (qtd_fornecedores <= 0) {
        cout << "Por favor digite uma quantidade válida de fornecedores para serem adicionados: ";
        cin >> qtd_fornecedores;
        cin.ignore();
    }

    cout << "Leitura de fornecedores:" << endl;
    int i = 0;
    for (; i < qtd_fornecedores; i++) {
        Fornecedores novoForneced;

        cout << "Codigo: ";
        cin >> novoForneced.codigo;
        cin.ignore();

        cout << "Nome: ";
        getline(cin, novoForneced.nome);

        cout << "Endereço: ";
        getline(cin, novoForneced.endereco);

        cout << "Telefone: ";
        getline(cin, novoForneced.telefone);

        cout << "Codigo da cidade: ";
        cin >> novoForneced.codigo_cidade;
        cin.ignore();

        cout << "Cnpj: ";
        getline(cin, novoForneced.cnpj);
        bool cnpjValido = validar_cnpj(novoForneced.cnpj);

        do {
            cout << "CNPJ Inválido, favor digite um válido: ";
            getline(cin, novoForneced.cnpj);
            cnpjValido = validar_cnpj(novoForneced.cnpj);
        } while (!cnpjValido);

        lista.push_back(novoForneced);
        cout << "<----------------------------------------->" << endl;
        cout << "Fornecedor(es) inserido(s)" << endl;
        cout << "<----------------------------------------->" << endl;
    }
}

// Questão 2#
void mesclar_fornecedores(vector<Fornecedores> &listaInicial, vector<Fornecedores> listaFinal) {
    int s = 0, t = 0;
    vector<Fornecedores> novaListaFinal;

    while (s < listaInicial.size() && t < listaFinal.size()) {
        if (listaInicial[s].codigo < listaFinal[t].codigo) {
            novaListaFinal.push_back(listaInicial[s]);
            s++;
        } else {
            novaListaFinal.push_back(listaFinal[t]);
            t++;
        }
    }

    while (s < listaInicial.size()) {
        novaListaFinal.push_back(listaInicial[s++]);
    }

    while (t < listaFinal.size()) {
        novaListaFinal.push_back(listaFinal[t++]);
    }

    listaInicial = novaListaFinal;
}

int buscar_cidade_por_codigo(int codigo, vector<Cidades> lista) {
    int inicio = 0, fim = lista.size() - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (codigo == lista[meio].codigo) {
            return meio;
        }
        if (codigo > lista[meio].codigo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    cout << "Não existe cidade com esse Código!" << endl;
    return -1;
}

void incluir_novo_fornecedor(vector<Fornecedores> &lista, vector<Cidades> lista_cidades) {
    int qtd_fornecedores = 0;
    cout << "Quantos fornecedores você quer ler? ";
    cin >> qtd_fornecedores;
    cin.ignore();

    while (qtd_fornecedores <= 0) {
        cout << "Por favor, digite uma quantidade válida de fornecedores para serem adicionados: ";
        cin >> qtd_fornecedores;
        cin.ignore();
    }

    if (lista_cidades.empty()) {
        cout << "A lista de cidades encontra-se sem registros!" << endl;
        return;
    }

    vector<Fornecedores> novosFornecedores;
    for (int i = 0; i < qtd_fornecedores; i++) {
        Fornecedores novoFornecedor;
        system("cls");
        cout << "Adicionar novo fornecedor" << endl;
        cout << "Codigo: ";
        cin >> novoFornecedor.codigo;
        cin.ignore();

        cout << "Nome: ";
        getline(cin, novoFornecedor.nome);

        cout << "Endereco: ";
        getline(cin, novoFornecedor.endereco);

        cout << "Telefone: ";
        getline(cin, novoFornecedor.telefone);

        do {
            cout << "Codigo da cidade: ";
            cin >> novoFornecedor.codigo_cidade;
            cin.ignore();

            int indice_cidade = buscar_cidade_por_codigo(novoFornecedor.codigo_cidade, lista_cidades);
            if (indice_cidade != -1) {
                cout << "Nome da cidade localizada: " << lista_cidades[indice_cidade].descricao << endl;
                cout << "UF da cidade localizada: " << lista_cidades[indice_cidade].UF << endl;
                break;
            } else {
                cout << "Código fornecido inválido ou não existente! Tente novamente." << endl;
            }
        } while (true);

        cout << "CNPJ: ";
        getline(cin, novoFornecedor.cnpj);

        while (!validar_cnpj(novoFornecedor.cnpj)) {
            cout << "CNPJ Inválido! Insira um válido: ";
            getline(cin, novoFornecedor.cnpj);
        }

        novosFornecedores.push_back(novoFornecedor);
    }

    mesclar_fornecedores(lista, novosFornecedores);
    cout << "<----------------------------------------->" << endl;
    cout << "Fornecedor(es) inserido(s)!" << endl;
    cout << "<----------------------------------------->" << endl;
}

// Questão 3#
int buscar_fornecedor_por_codigo(vector<Fornecedores> lista, int codigo_fornecedor) {
    int inicio = 0, fim = lista.size() - 1;
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
    cout << "Fornecedor não encontrado!" << endl;
    return -1;
}

void mesclar_produtos(vector<Produtos> &listaInicial, vector<Produtos> listaFinal) {
    int s = 0, t = 0;
    vector<Produtos> novaListaFinal;

    while (s < listaInicial.size() && t < listaFinal.size()) {
        if (listaInicial[s].codigo < listaFinal[t].codigo) {
            novaListaFinal.push_back(listaInicial[s]);
            s++;
        } else {
            novaListaFinal.push_back(listaFinal[t]);
            t++;
        }
    }

    while (s < listaInicial.size()) {
        novaListaFinal.push_back(listaInicial[s++]);
    }

    while (t < listaFinal.size()) {
        novaListaFinal.push_back(listaFinal[t++]);
    }

    listaInicial = novaListaFinal;
}

void incluir_produto(vector<Produtos> &lista, vector<Fornecedores> lista_fornecedor) {
    int qtd_produtos = 0;
    cout << "Quantos produtos você quer adicionar? ";
    cin >> qtd_produtos;
    cin.ignore();

    while (qtd_produtos <= 0) {
        cout << "Por favor, insira uma quantidade válida de produtos: ";
        cin >> qtd_produtos;
        cin.ignore();
    }

    vector<Produtos> novosProdutos;
    for (int i = 0; i < qtd_produtos; i++) {
        Produtos novoProduto;

        cout << "Digite o código do produto que deseja inserir: ";
        while (true) {
            cin >> novoProduto.codigo;
            cin.ignore();

            bool codigoExiste = false;
            for (int index = 0; index < lista.size(); index++) {
                if (lista[index].codigo == novoProduto.codigo) {
                    cout << "Código já existe! Digite outro: ";
                    codigoExiste = true;
                    break;
                }
            }
            if (!codigoExiste) break;
        }

        cout << "Nome do produto: ";
        getline(cin, novoProduto.descricao);

        cout << "Codigo do tipo do Produto: ";
        cin >> novoProduto.tipo_produto.codigo;
        cin.ignore();

        cout << "Descricao do tipo do Produto: ";
        getline(cin, novoProduto.tipo_produto.descricao);

        cout << "Codigo do fornecedor: ";
        int index_fornecedor;
        while (true) {
            cin >> novoProduto.codigo_fornecedor;
            cin.ignore();

            index_fornecedor = buscar_fornecedor_por_codigo(lista_fornecedor, novoProduto.codigo_fornecedor);
            if (index_fornecedor != -1) {
                break;
            } else {
                cout << "Fornecedor com este Código não foi encontrado! Tente outro: ";
            }
        }

        cout << "Nome do fornecedor: " << lista_fornecedor[index_fornecedor].nome << endl;

        cout << "Quantidade em estoque: ";
        cin >> novoProduto.qtd_estoque;

        cout << "Quantidade minima: ";
        cin >> novoProduto.estoque_minimo;

        cout << "Quantidade maxima: ";
        cin >> novoProduto.estoque_maximo;

        cout << "Valor por unidade: ";
        cin >> novoProduto.valor_unitario;
        cin.ignore();

        novosProdutos.push_back(novoProduto);
    }

    mesclar_produtos(lista, novosProdutos);
    cout << "<----------------------------------------->" << endl;
    cout << "Produto(s) inserido(s)" << endl;
    cout << "<----------------------------------------->" << endl;
}

int buscar_produto_por_codigo(vector<Produtos> lista, int codigo_produto) {
    int inicio = 0, fim = lista.size() - 1;
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
    cout << "Produto  não encontrado!" << endl;
    return -1;
}

// Questão 4#
void vender_produto(vector<Produtos> &lista_produtos, vector<Fornecedores> lista_fornecedores) {
    int codigo_produto = 0;

    cout << "Digite o Código do produto que deseja¡ comprar: ";
    cin >> codigo_produto;
    cin.ignore();

    if (lista_produtos.empty()) {
        cout << "A lista de produtos se encontra vazia! Adicione novos produtos para poder vende-los!" << endl;
    }
    int indice_produto = buscar_produto_por_codigo(lista_produtos, codigo_produto);
    while (indice_produto == -1) {
        cout << "O produto com este código não foi encontrado! Digite outro: ";
        cin >> codigo_produto;
        cin.ignore();
        indice_produto = buscar_produto_por_codigo(lista_produtos, codigo_produto);
    }
    int indice_fornecedor = buscar_fornecedor_por_codigo(lista_fornecedores,
                                                         lista_produtos[indice_produto].codigo_fornecedor);
    if (indice_fornecedor == -1) {
        cout << "Fornecedor  não encontrado!" << endl;
    }
    cout << "Descrição do Produto: " << endl;
    cout << "Descrição: " << lista_produtos[indice_produto].descricao << endl;
    cout << "Quantidade em estoque: " << lista_produtos[indice_produto].qtd_estoque << endl;
    cout << "Valor por unidade: " << lista_produtos[indice_produto].valor_unitario << endl;
    cout << "\nDescrição do Tipo do Produto: " << endl;
    cout << "Descrição do tipo do produto: " << lista_produtos[indice_produto].tipo_produto.descricao << endl;
    cout << "Nome do fornecedor: " << lista_fornecedores[indice_fornecedor].nome << endl;
    int qtd_produtos = 0;
    cout << "Qual a quantidade de produtos que você deseja vender? ";
    cin >> qtd_produtos;
    while (qtd_produtos > lista_produtos[indice_produto].qtd_estoque) {
        cout << "A quantidade que foi solicitada para a compra é maior que a quantidade de produtos no estoque!" <<
                endl;
        cout << "Escolha outra quantidade: ";
        cin >> qtd_produtos;
    }

    cout << "O valor total da venda do produto é de: " << (lista_produtos[indice_produto].valor_unitario * qtd_produtos)
            <<
            endl;
    char confirmar_venda = 'N';
    cout << "Para confirmar a venda dos produtos, por favor digite 'S', caso queira cancelar digite 'N'!";
    cin >> confirmar_venda;
    if (tolower(confirmar_venda) == 's') {
        lista_produtos[indice_produto].qtd_estoque -= qtd_produtos;
        cout << "Venda confirmada! Agora o produto possui em estoque " << lista_produtos[indice_produto].qtd_estoque <<
                endl;
    } else {
        cout << "Cancelando venda dos produtos!" << endl;
    }
}

// Questão 5#
void consultar_produto(vector<Produtos> lista, vector<Fornecedores> listaFor) {
    if (lista.empty()) {
        cout << "A lista está vázia!" << endl;
        return;
    }
    int codigo = 0;
    cout << "Digite o Código do produto que deseja consultar: ";
    cin >> codigo;
    int index_produto = buscar_produto_por_codigo(lista, codigo);
    if (codigo == -1) {
        cout << "Código não encontrado!";
        return;
    }
    cout << "Codigo do produto: " << lista[index_produto].codigo << endl;
    cout << "Nome do produto: " << lista[index_produto].descricao << endl;
    cout << "Quantidade em estoque: " << lista[index_produto].qtd_estoque << endl;
    cout << "Quantidade minima: " << lista[index_produto].estoque_minimo << endl;
    cout << "Quantidade maxima: " << lista[index_produto].estoque_maximo << endl;
    cout << "Valor por unidade: " << lista[index_produto].valor_unitario << endl;
    cout << "Descricao do tipo do produto: " << lista[index_produto].tipo_produto.descricao << endl;
    int index_fornecedor = buscar_fornecedor_por_codigo(listaFor, lista[index_produto].codigo_fornecedor);
    cout << "Nome do fornecedor: " << listaFor[index_fornecedor].nome << endl;
    cout << "Valor total em estoque: R$" << (lista[index_produto].qtd_estoque * lista[index_produto].valor_unitario) <<
            endl;
}

// Questão 6#
void exibir_estoque_abaixo_minimo(vector<Produtos> lista_produtos, vector<Fornecedores> lista_fornecedores) {
    if (lista_produtos.size() < 1) {
        cout << "A lista está vazia!" << endl;
        return;
    }
    for (int i = 0; i < lista_fornecedores.size(); i++) {
        float quantidade_comprar = 0;
        if (lista_produtos[i].qtd_estoque < lista_produtos[i].estoque_minimo) {
            quantidade_comprar = lista_produtos[i].estoque_maximo - lista_produtos[i].qtd_estoque;
            cout << "\nCodigo produto: " << lista_produtos[i].codigo << endl;
            cout << "Descricao: " << lista_produtos[i].descricao << endl;
            cout << "Quantidade em estoque: " << lista_produtos[i].qtd_estoque << endl;
            cout << "Estoque maximo: " << lista_produtos[i].estoque_maximo << endl;
            cout << "Quantidade para ser comprada: " << quantidade_comprar << endl;
            int indice_fornecedor = buscar_fornecedor_por_codigo(lista_fornecedores,
                                                                 lista_produtos[i].codigo_fornecedor);
            cout << "Nome do fornecedor 1: " << lista_fornecedores[indice_fornecedor].nome << endl;
            cout << "Telefone do fornecedor: " << lista_fornecedores[indice_fornecedor].telefone << endl;
            cout << "\nValor total a ser comprado: " << quantidade_comprar * lista_produtos[i].valor_unitario << endl;
        }
    }
}

// Questão 7#
void validar_se_palavra_for_palindromo(vector<Produtos> lista) {
    for (int index = 0; index < lista.size(); index++) {
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
            cout << "A descrição \"" << lista[index].descricao << "\" é um palindromo!" << endl;
        }
    }
}

void menu(vector<Tipo_Produtos> lista_tipo_produtos, vector<Produtos> lista_produtos,
          vector<Fornecedores> lista_fornecedores, vector<Cidades> lista_cidades) {
    int opcao = -1;
    int opcao_ler = 0;
    char continuar = 's';
    system("cls");
    while (opcao == -1) {
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
            cout << "Deseja continuar? (s/n): ";
            cin >> continuar;
            if (tolower(continuar) == 's') {
                menu(lista_tipo_produtos, lista_produtos,
                     lista_fornecedores, lista_cidades);
            }
            break;
        case 2:
            incluir_novo_fornecedor(lista_fornecedores, lista_cidades);
            cout << "Deseja continuar? (s/n): ";
            cin >> continuar;
            if (tolower(continuar) == 's') {
                menu(lista_tipo_produtos, lista_produtos,
                     lista_fornecedores, lista_cidades);
            }
            break;
        case 3:
            incluir_produto(lista_produtos, lista_fornecedores);
            cout << "Deseja continuar? (s/n): ";
            cin >> continuar;
            if (tolower(continuar) == 's') {
                menu(lista_tipo_produtos, lista_produtos,
                     lista_fornecedores, lista_cidades);
            }
            break;
        case 4:
            vender_produto(lista_produtos, lista_fornecedores);
            cout << "Deseja continuar? (s/n): ";
            cin >> continuar;
            if (tolower(continuar) == 's') {
                menu(lista_tipo_produtos, lista_produtos,
                     lista_fornecedores, lista_cidades);
            }
            break;
        case 5:
            consultar_produto(lista_produtos, lista_fornecedores);
            cout << "Deseja continuar? (s/n): ";
            cin >> continuar;
            if (tolower(continuar) == 's') {
                menu(lista_tipo_produtos, lista_produtos,
                     lista_fornecedores, lista_cidades);
            }
            break;
        case 6:
            exibir_estoque_abaixo_minimo(lista_produtos, lista_fornecedores);
            cout << "Deseja continuar? (s/n): ";
            cin >> continuar;
            if (tolower(continuar) == 's') {
                menu(lista_tipo_produtos, lista_produtos,
                     lista_fornecedores, lista_cidades);
            }
            break;
        case 7:
            validar_se_palavra_for_palindromo(lista_produtos);
            cout << "Deseja continuar? (s/n): ";
            cin >> continuar;
            if (tolower(continuar) == 's') {
                menu(lista_tipo_produtos, lista_produtos,
                     lista_fornecedores, lista_cidades);
            }
        default:
            cout << "Opcao Selecionada invalida!" << endl;
            break;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    vector<Tipo_Produtos> lista_tipos_produtos;
    vector<Produtos> lista_produtos;
    vector<Fornecedores> lista_fornecedores;
    vector<Cidades> lista_cidades;

    menu(lista_tipos_produtos, lista_produtos, lista_fornecedores, lista_cidades);
}

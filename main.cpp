#include<iostream>
#include <list>

using namespace std;

struct Tipo_Produtos{
	int codigo;
	string descricao;
};

struct Produtos{
	int codigo;
	string descricao;
	Tipo_Produtos tipo_produto;
	int codigo_fornecedor;
	int qtd_estoque;
	int estoque_minimo;
	int estoque_maximo;
	float valor_unitario;
};

struct Cidades{
	int codigo;
	string descricao;
	char UF[2];
};

struct Fornecedores{
	int codigo;
	string nome;
	string endereco;
	string telefone;
	int codigo_cidade;
	string cnpj;
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

void mostrar_produtos(Produtos lista[]){
    cout<<"Produtos "<<endl;
    for(int i=0; i<3;i++ ){
        cout<<"Codigo: "<<lista[i].codigo<<endl;
        cout<<"Descricao: "<<lista[i].descricao<<endl;
        cout<<"Tipo do produto ID: "<<lista[i].tipo_produto.codigo<<endl;
        cout<<"Descricao do tipo do produto: "<<lista[i].tipo_produto.descricao<<endl;
        cout<<"Codigo do fornecedor: "<<lista[i].codigo_fornecedor<<endl;
        cout<<"Quantidade no estoque: "<<lista[i].qtd_estoque;
        cout<<"Estoque minimo: "<<lista[i].estoque_minimo<<endl;
        cout<<"Estoque maximo: "<<lista[i].estoque_maximo<<endl;
        cout<<"Valor unitário: "<<lista[i].valor_unitario<<endl;
    }
}

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

void mostrar_cidades(Cidades lista[]){
    cout<<"Cidades: ";
    for(int i=0;i<3;i++){
        cout<<"Código da cidade: "<< lista[i].codigo<<endl;
        cout<<"Nome do cidade: "<<lista[i].descricao<<endl;
        cout<<"UF: "<<lista[i].UF<<endl;
    }
}

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

void mostrar_fornecedores(Fornecedores lista[]){
    cout<<"Fornecedores: "<<endl;
    for(int i=0; i<3; i++){
        cout<<"Codigo do fornecedor: "<<lista[i].codigo<<endl;
        cout<<"Nome do fornecedor: "<<lista[i].nome<<endl;
        cout<<"Endereço: "<<lista[i].endereco<<endl;
        cout<<"Telefone: "<<lista[i].telefone<<endl;
        cout<<"Codigo da cidade: "<<lista[i].codigo_cidade;
        cout<<"CNPJ: "<<lista[i].cnpj<<endl;
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


void incluir_produto(Produtos lista_atual[], Produtos lista_adicionar[], Fornecedores lista_fornecedor[], int tamanho){
    Produtos novo;
    int i=0,j=0,s=0,k=0;

    while(true){
        cout << "Codigo do novo produto: ";
        cin >> novo.codigo;
    
        bool codigoExiste = false;
        for(int i = 0; i < 3; i++){
            if(lista_atual[i].codigo == novo.codigo){
                cout << "Código já existe!" << endl;
                codigoExiste = true;
                break;
            }
        }
    
        if(!codigoExiste){
            break;
        }
    }
    cout<<"Descricao: ";
    cin>>novo.descricao;
    cout<<"ID Tipo do produto: ";
    cin>> novo.tipo_produto.codigo;
    cout<<"Descricao do tipo do produto: ";
    cin>> novo.tipo_produto.descricao;
    cout<<"Quantidade no estoque: ";
    cin>> novo.qtd_estoque;
    cout<<"Estoque minimo: ";
    cin>>novo.estoque_minimo;
    cout<<"Estoque maximo: ";
    cin>>novo.estoque_minimo;
    cout<<"Valor unitário: ";
    cin>>novo.valor_unitario;

    
    //ordenar
    while(j<3){
        if(novo.codigo< lista_atual[j].codigo){
            lista_adicionar[s++]=novo;
            while(j<3){
                lista_adicionar[s++] = lista_atual[j++];
            }
        }
        else{
            lista_adicionar[s++] = lista_atual[j++];
        }
        break;
        
    }
    if(k<tamanho+1){
        lista_adicionar[s] = novo;
    }


    cout<<"Produto inserido com sucesso!"<<endl;
    

    int idfornecedor;
    while(true){
        cout<<"Digite o codigo do fornecedor: ";
        cin>> idfornecedor;
        for(int i=0; i<3; i++){
            if(lista_fornecedor[i].codigo!= idfornecedor){
                cout<<"Código de fornecedor não existe!";
                return;
            }
            else{
                cout<<"Nome do fornecedor: "<<lista_fornecedor[i].codigo<<endl;
                break;
            }
        }
    }
    

}


//funcao consultar produto
void consultar_produto(Produtos lista[], Fornecedores listaFor[]){
    int codigo;
    
    while(true){
        cout<<"Digite o código do produto que deseja consultar: ";
        cin>>codigo;
        for(int i=0; i<3; i++){
            if(lista[i].codigo != codigo){
                cout<<"Código de produto não existe!";
                return;
            }
            else{
                cout<<"Produto encontrado!";
                cout<<"Descricao: "<<lista[i].descricao<<endl;
                cout<<"Tipo do produto: "<<lista[i].tipo_produto.descricao<<endl;
                for(int i=0; i<3; i++){
                    if(lista[i].codigo_fornecedor == listaFor[i].codigo){
                        cout<<"Nome do Fornecedor: "<<listaFor[i].nome<<endl;
                    }
                }
                cout<<"valor total em estoque do produto: "<<lista[i].qtd_estoque*lista[i].valor_unitario;
                break;
            }
        }
    }
}

int menu() {

    system("cls");

    int opcao = -1;
    cout << "1# -> Adicionar fornecedores" << endl;
    cout << "2# -> Adicionar novo produto" << endl;
    
    
    cin >> opcao;

    switch (opcao) {
        case 1:
            cout << "Oi";
            break;
        case 2:
            cout<<"Breno:)";
        default: cout << "Opcao invalida";
    }

    return opcao;



}

int main() {
    Produtos vet_produtoslidos[10];
    Produtos vet_listaatual[10];
    Fornecedores vet_listafornecedores[3];
    ler_produtos( vet_produtoslidos);
    int tam = 3;
    //incluir_produto(vet_produtosatuais, vet_listaatual, vet_listafornecedores);
    //tam++;
    consultar_produto(vet_listaatual, vet_listafornecedores);

    int opcao = menu();
    return 0;
}

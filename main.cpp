#include<iostream>

using namespace std;

struct Tipo_Produtos{
	int codigo;
	string descricao;
};

void ler_tipo_produtos(Tipo_Produtos lista[]){
	system("cls");
	
}

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

void ler_produtos(Produtos lista[]){
	system("cls");
	
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

struct Cidades{
	int codigo;
	string descricao;
	char UF[2];
};


void ler_cidades(Cidades lista[]){
	system("cls");
	
}

void mostrar_cidades(Cidades lista[]){
    cout<<"Cidades: ";
    for(int i=0;i<3;i++){
        cout<<"Código da cidade: "<< lista[i].codigo<<endl;
        cout<<"Nome do cidade: "<<lista[i].descricao<<endl;
        cout<<"UF: "<<lista[i].UF<<endl;
    }
}

struct Fornecedores{
	int codigo;
	string nome;
	string endereco;
	string telefone;
	int codigo_cidade;
	string cnpj;
};

void ler_fornecedores(Fornecedores lista[]){
	system("cls");
	
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

int main(){
	
}

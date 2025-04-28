#include <iostream>

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

struct Cidades{
	int codigo;
	string descricao;
	char UF[2];
};

void ler_cidades(Cidades lista[]){
	system("cls");
	
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

int main(){
	
}
#include <iostream>
using namespace std;

template <typename T>
struct node{
	T dado;
	struct node* prox;
};

template <typename T>
void adc_elemento(struct node **apontador, T elemento){
	if (*apontador == NULL){
		struct node *temp = *apontador;
		*apontador = new struct node;
		*apontador->prox = temp;
		*apontador->dado = elemento; 
	} else{
		struct node *temp = *apontador;
		
		while (temp->prox != NULL){
			temp = temp->prox;
		}

		temp->prox = new struct node;
		temp->prox->prox = NULL;
		temp->prox->dado = elemento;
	}

	
}

template <typename T>
void mos_lista(struct node *apontador){
	if (apontador == NULL){
		cout << "Vazio" << endl;
	} else{
		struct node *temp = apontador; 
		cout << temp->dado << endl;

		while (temp->prox != NULL){
			cout << temp->dado << endl;
			temp = temp->prox;
		}
		
	}
}

template <typename T>
void rem_elemento(struct node **apontador){
	if (*apontador != NULL){
		struct node *temp = *apontador;
		*apontador = *apontador->prox;
		delete temp;
	}
	
	cout << "Primeiro elemento removido" << endl;
}

template <typename T>
int main (){
	struct node *lista;
	lista = NULL;
	T entrada;
	int loop = 1; 
	int resposta;

	while (loop == 1){	
		cout << "O que voce deseja fazer?" << endl;
	        cout << "Digite 1 para adicionar elemento" << endl;
	        cout << "Digite 2 para remover elemento" << endl;
	        cout << "Digite 3 para acessar algum elemento" << endl;
		cin >> resposta;

	
		switch (resposta){
			case 1:{
				cout << "Qual elemento voce deseja adicionar?" << endl;
				cin >> entrada;
				adc_elemento(&lista, entrada);
				break;
			}

			case 2:{
				rem_elemento(&lista);				
				break;
			}

			case 3:{//mostrar
				mos_lista(lista);
				break;
			}

			default:
				cout << "Opcao invalida" << endl;			
				break;
		
		}

		cout << "Deseja realizar alguma outra acao com essa lista? Digite 1 se sim" << endl;
		cin >> loop;
	}

	return 0;
}







#include <queue>
#include <cstdlib>
#include "Balcao.h"

using namespace std;


Cliente::Cliente() {
	numPresentes = rand() %(5 - 1) + 1;
}


int Cliente::getNumPresentes() const {
	return numPresentes;
}


Balcao::Balcao(int te): tempo_embrulho(te) {
	tempo_atual = 0;
	prox_chegada = rand() %(20 - 1) + 1;
	prox_saida = 0;
	clientes_atendidos = 0;
}      


void Balcao:: proximoEvento()
{

	if(clientes.empty()){
		tempo_atual = prox_chegada;
		chegada();
		return;
	}

	if(prox_chegada <= prox_saida){
		tempo_atual = prox_chegada;
		chegada();
	} else {
		tempo_atual = prox_saida;
		saida();
	}
}


void Balcao::chegada()
{
	Cliente c;
	clientes.push(c);

	prox_chegada = rand() %(20 - 1) + 1;

	if(clientes.empty())
		prox_saida = tempo_atual + c.getNumPresentes() * tempo_embrulho;

	cout << "tempo= " << tempo_atual << "\nchegou novo cliente com " << c.getNumPresentes() << " presentes";

}   


void Balcao::saida()
{

	cout << "tempo= " << tempo_atual << endl << "saiu cliente com " << clientes.front().getNumPresentes() << " presentes\n";

	if(clientes.empty())
		throw FilaVazia();
	else
		clientes.pop();

	prox_saida = tempo_atual + clientes.front().getNumPresentes() * tempo_embrulho;

	clientes_atendidos++;

}


int Balcao::getTempoAtual() const { return tempo_atual; }


int Balcao::getProxChegada() const { return prox_chegada; }


ostream & operator << (ostream & out, const Balcao & b1)
{
	// a alterar
     return out;
}


int Balcao::getTempoEmbrulho() const {
	return tempo_embrulho;
}


int Balcao::getProxSaida() const {
	return prox_saida;
}


int Balcao::getClientesAtendidos() const {
	return clientes_atendidos;
}


Cliente & Balcao::getProxCliente() {
	if(clientes.size() > 0)
		return clientes.front();
	else
		throw FilaVazia();
}

      

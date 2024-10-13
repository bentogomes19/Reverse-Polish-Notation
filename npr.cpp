// Developer : Bento Junior Suzart Gomes
// DataStructures Reverse Polish Notation

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
 // notação polonesa reversa
// operadores -> inserir na pilha
// operando -> imprime o operando
// parentese de abertura ( -> ignorar
// parentese de fechamento ) -> descarregar a pilha
// expressão = (a+b)*c
typedef struct node {
    char operador;
    struct node *next;
} node;

struct node *aux, *topo;
// VETOR GLOBAL PARA ARMAZENAR OS OPERADORES
std::vector<char> operadores;

// PILHA DOS OPERADORES
void Push(char  a) {
    aux = new node();

    aux->operador = a;

    aux->next = topo;
    topo = aux;
}

char Pop() // FUNÇÃO QUE IRÁ RETORNAR UM OPERADOR QUE SERÁ ARMAZENADO NO VETOR "OPERADORES"
{
    if (!topo) // CASO NÃO ESTEJA CHEIA
    {
        std::cout << "Empty Stack!\n";
        return 'o';
    }
    else
    {
        // DESCARREGA A PILHA
        char operador = topo->operador;
        aux = topo;
        topo = topo->next;
        delete aux;
        return operador;
    }
}

void Clear_stack()
{
    while(topo != nullptr)
    {
        aux = topo;
        topo = topo->next;
        delete aux;
    }
}

void npr(std::string  exp)
{
    std::cout << "\n Saída : ";
    for (int i = 0; i < exp.size(); i++)
    {   // OPERADOR
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            // EMPILHAR OS OPERADORES
            Push(exp[i]);
        }
        else if (exp[i] == ')') // DESCARREGAR A PILHA
        {
            // PILHA = [FIM...TOPO]
            // PILHA = ['(', '*', '+', ')'] -> <vetor> operadores = ['+','*']
           while (topo && topo->operador != '(')
           {
                operadores.push_back(Pop()); // Armazenar os operadores no vetor
           }
           Pop(); // DESEMPILHA OS PARENTESES DE FECHAMENTO
        }
        else if (exp[i] == '(') // IGNORAR 
        {
            Push(exp[i]);
        } 
        else // SE FOR UM OPERANDO, MOSTRE NA SAÍDA
        {
            std::cout << exp[i] << " ";
        }
        
    }

    while (topo)
    {
        operadores.push_back(Pop());
    }
    // EXPRESSÃO (A+B)*C = SOMA CHAR 7
    // Exibir os operadores na ordem correta
    // ex: operadores.size() = 7 - 1 = 6

    for (int i = operadores.size() - 1; i >=0; --i)
    {
        std::cout << operadores[i] << " ";
    }

    Clear_stack(); // Limpa toda a pilha por completo
    operadores.clear(); // Limpa o vetor com os operadores para mostrar na sáida
    std::cout << std::endl;

}

int main(int argc, char *argv[])
{
    int tam;
    std::string  expressao;
    aux = nullptr;
    topo = nullptr;

    std::cout << "Notação Polonesa Reversa (NPR)\n";
    expressao = "(A+B)*C";
    std::cout << expressao << std::endl;
    expressao = "A+B";
    std::cout << expressao << std::endl;
    expressao = "A*B+((C/D)*F)+(G*H)";
    std::cout << expressao << std::endl;
    expressao = "9*2+((3*4)+8)";
    std::cout << expressao << std::endl;

    std::cout << std::endl;


    npr("(A+B)*C");
    npr("A+B");
    npr("A*B+((C/D)*F)+(G*H)");
    npr("9*2+((3*4)+8)");

    return 0;
}




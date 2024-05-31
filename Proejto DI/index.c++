#include <iostream> //Biblioteca principal para saída e entrada de dados
#include <string>   //Biblioteca Manipulção de textos
#include <cstdlib>  //Biblioteca para funções relacionadas ao sistema
#include <vector>   //Biblioteca para utilização de vetores
#include <iomanip>
using namespace std;

const double valor_nosso_app = 40;
// Custos por programador
const double programador_senior = 100;
const double programador_pleno = 60;
const double programador_back_end = 40;
const double programador_front_end = 40;

// Tempo de desenvolvimento
const int dias_semana = 5; // 5x8 = 40
const int horas_trabalhadas_diariamente = 8;
const int semanas_totais_trabalhadas = 12; // 40x24 =960 horas trabalhadas

// Cálculos Custos
double calculo_custos_programadores = (programador_senior + programador_pleno + programador_front_end + programador_back_end); // Soma do salário de todos os programadores = 240
double calculo_horas_trabalhadas = (dias_semana * horas_trabalhadas_diariamente);                                              // 40 horas trabalhadas
double calculo_horas_semanas = (calculo_horas_trabalhadas * semanas_totais_trabalhadas);                                       // 960 horas trabalhadas

// Cálculo Final Desenvolvimento
double horas_vezes_custo_programadores = (calculo_custos_programadores * calculo_horas_semanas);
// Caso haja novo cadastro de custo no sistema
double valor_soma_total = 0;

struct Despesa // Estrutura struct para armazenar valores das despesas
{
    string data;
    double valor;
    string categoria;
    string descricao;
    string metodo_pagamento;
    int pagantes;
};

void registrarDespesa(vector<Despesa> &despesas)
{
    Despesa novaDespesa;
    system("cls");
    cout << "Registrar Nova Custo" << endl;
    cout << "-----------------------" << endl;

    cout << "Valor: ";
    cin >> novaDespesa.valor;
    cin.ignore(); // Ignorar o restante da linha após a leitura do valor

    cout << "Descricao: ";
    getline(cin, novaDespesa.descricao);

    despesas.push_back(novaDespesa);
    system("cls");
    cout << "------------------------------" << endl;
    cout << "Custo registrada com sucesso!" << endl;
    cout << "------------------------------" << endl;
}

void listarCustos(const vector<Despesa> &despesas)
{

    system("cls");
    cout << "Custo com o Software:" << endl;
    cout << "-----------------" << endl;                            // colocar valor da licenca do software
    cout << "Valor: R$" << horas_vezes_custo_programadores << endl; // valor do desenvolvimento
    cout << "Descricao: Desenvolvimento" << endl;                   // descrição sobre o custo
    cout << "-----------------" << endl;

    for (size_t i = 0; i < despesas.size(); ++i)
    {
        cout << i + 1 << ". Valor: R$" << despesas[i].valor << " \nDescricao: " << despesas[i].descricao << endl;
        cout << "-----------------" << endl;
    }
}

void calcular_nossos_custos(vector<Despesa> &despesas)
{
    Despesa quantidade;
    system("cls");
    cout << "Insira a quantidade de pagantes: " << endl;
    cin >> quantidade.pagantes;

    double valor_soma_total = horas_vezes_custo_programadores;
    for (const auto &despesa : despesas)
    {
        valor_soma_total += despesa.valor;
    }
    cout << valor_soma_total << endl;
    float preco_usuario_pagante = (valor_soma_total / quantidade.pagantes); // Calcular o Preço por Usuário Pagante
    double vendas_necessarias = (valor_soma_total / valor_nosso_app);       // Número de vendas necesárias
    float porcentagem_lucro = ((quantidade.pagantes / vendas_necessarias) * 100);
    float porcentagem_prejuizo = (100 - porcentagem_lucro);
    float prejuizo_reais = (horas_vezes_custo_programadores - (valor_nosso_app * quantidade.pagantes));

    if (quantidade.pagantes < vendas_necessarias)
    {
        system("cls");
        double vendas_faltantes = (vendas_necessarias - quantidade.pagantes);
        cout << "Custo por assinantes: R$" << setprecision(2) << fixed << preco_usuario_pagante << endl;
        cout << "Quantidade necessaria de assinantes: " << setprecision(0) << fixed << vendas_necessarias << endl;
        cout << "Faltam " << vendas_faltantes << " Vendas ate o ponto de equilibrio" << endl;
        cout << "Custo de desenvolvimento: R$" << horas_vezes_custo_programadores << endl;
        cout << "Seu prejuizo foi de " << porcentagem_prejuizo << "%" << endl;
        cout << "Sua Receita foi: R$" << horas_vezes_custo_programadores - prejuizo_reais << endl;
        cout << "Valor do produto: R$" << setprecision(2) << fixed << valor_nosso_app << endl;
        cout << "---------------------------------------" << endl;
    }
    else if (quantidade.pagantes > vendas_necessarias)
    {
        system("cls");
        double lucro_total;
        lucro_total = (horas_vezes_custo_programadores - prejuizo_reais);
        cout << "Custo por assinantes: R$" << setprecision(2) << fixed << preco_usuario_pagante << endl;
        cout << "Quantidade necessaria de assinantes: " << setprecision(0) << fixed << vendas_necessarias << endl;
        cout << "Seu Lucro foi: " << porcentagem_lucro << "%" << endl;
        cout << "Custo de desenvolvimento: R$" << horas_vezes_custo_programadores << endl;
        cout << "Seu Lucro Liquido: R$" << lucro_total - horas_vezes_custo_programadores << endl;
        cout << "Seu lucro Total: R$" << lucro_total << endl;
        cout << "Valor do produto: R$" << setprecision(2) << fixed << valor_nosso_app << endl;

        cout << "---------------------------------------" << endl;
    }
    else if (quantidade.pagantes == vendas_necessarias)
    {
        system("cls");
        cout << "Custo por assinantes: R$" << setprecision(2) << fixed << preco_usuario_pagante << endl;
        cout << "Quantidade necessaria de assinantes: " << setprecision(0) << fixed << vendas_necessarias << endl;
        cout << "voce chegou no ponto de equilibrio" << endl;
        cout << "Sua Receita foi: R$" << horas_vezes_custo_programadores << endl;
        cout << "Custo de desenvolvimento: R$" << horas_vezes_custo_programadores << endl;
        cout << "Valor do produto: R$" << setprecision(2) << fixed << valor_nosso_app << endl;
        cout << "---------------------------------------" << endl;
    }
}
void excluirDespesa(vector<Despesa> &despesas)
{
    if (despesas.empty())
    {
        system("cls");
        cout << "--------------------------------" << endl;
        cout << "Nao ha despesas para excluir." << endl;
        cout << "--------------------------------" << endl;
        return;
    }

    listarCustos(despesas);

    float indice;
    cout << "Digite o numero da despesa que deseja excluir: ";
    cin >> indice;

    if (indice > 0 && indice <= despesas.size())
    {
        system("cls");
        despesas.erase(despesas.begin() + (indice - 1));
        cout << "-------------------------------" << endl;
        cout << "Despesa excluida com sucesso!" << endl;
        cout << "-------------------------------" << endl;
    }
    else
    {
        system("cls");
        cout << "------------------" << endl;
        cout << "Numero invalido!" << endl;
        cout << "------------------" << endl;
    }
}
int main() // Função Principal
{

    vector<Despesa> despesas; // Declaração de um vetor para armazenar múlitplas despesas
    system("cls");
    int opcao;
    do
    {
        cout << "Sistema de Registro de Custos" << endl;
        cout << "1. Registrar Novo Custo" << endl;
        cout << "2. Listar custos" << endl;
        cout << "3. Calcular Percentual de Lucro" << endl;
        cout << "4. Excluir Custos" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(); // Ignorar o restante da linha após a leitura da opção

        switch (opcao)
        {
        case 1:
            registrarDespesa(despesas);
            break;
        case 2:
            listarCustos(despesas);
            break;
        case 3:
            calcular_nossos_custos(despesas);
            break;
        case 4:
            excluirDespesa(despesas);
            break;
        case 5:
            cout << "Saindo do sistema..." << endl;
            break;
        default:
            system("cls");
            cout << "---------------------------------------" << endl;
            cout << "Opcaoo invalida. Tente novamente." << endl;
            cout << "---------------------------------------" << endl;
        }
    } while (opcao != 5);

    if (opcao == 5)
    {
        exit(0);
    }

    registrarDespesa(despesas);
    listarCustos(despesas);
    calcular_nossos_custos(despesas);
    excluirDespesa(despesas);

    return 0;
}
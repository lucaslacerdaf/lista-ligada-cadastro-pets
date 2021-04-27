#include <iostream>
using namespace std;
#include <string.h>
#include <time.h>

///STRUCT NO INFORMACOES E PONTEIRO
struct no
{
    char nome[50], especie[50], raca[35], sexo[1];
    float altura, peso;
    int idade, id;
    struct no *prox;
};
///FUNCAO PARA INSERIR NOVOS ANIMAIS !!
void insereANIMAIS(no **lista, int *id1)
{
    (*id1) = (*id1) + 1;
    cout << "\n  +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
    cout << "  |C| |a| |d| |a| |s| |t| |r| |o|   |d| |e|   |A| |n| |i| |m| |a| |i| |s| " << endl;
    cout << "  +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;

    time_t currentTime;
    struct tm *timeinfo;
    currentTime = time(NULL);
    timeinfo = localtime(&currentTime);
    cout << "\n Horario de Cadastramento: " << timeinfo->tm_hour;
    cout << ":" << timeinfo->tm_min;
    cout << ":" << timeinfo->tm_sec << endl;
    FILE *arq;


    no *aux;
    aux = (no *)malloc(sizeof(no));
    if (aux != NULL)
    {
        cout << " \n Informe o nome do Animal : ";
        cin.ignore();
        cin.getline(aux->nome, 50);
        cout << " \n Informe a Especie do animal : ";
        cin.getline(aux->especie, 50);
        cout << " \n Informe a Raca do animal : ";
        cin.getline(aux->raca, 35);
        cout << " \n Informe o Sexo do animal M ou F :";
        cin >> aux->sexo;
        cout << " \n Informe a Idade do animal :";
        cin >> aux->idade;
        cout << " \n Informe a Altura do animal :";
        cin >> aux->altura;
        cout << "\n Informe o Peso do animal :";
        cin >> aux->peso;
        cout << "\n O id do Animal e : " << *id1;
        aux->id = (*id1);
        aux->prox = (*lista);
        (*lista) = aux;

        cout <<"\n Gravando no arquivo !!"<<endl;
        arq = fopen("Entrada.txt", "a");
        fprintf(arq, "Nome: " "%s ", aux->nome);
        fprintf(arq,"Especie: " "%s ", aux->especie);
        fprintf(arq,"Raca: " "%s ", aux->raca);
        fprintf(arq,"Sexo: " "%s ", aux->sexo);
        fprintf(arq,"Idade: " "%d ", aux->idade);
        fprintf(arq,"Altura: " "%f ", aux->altura);
        fprintf(arq,"Id: " "%d\n",aux->id);
        fclose(arq);

        system("cls");
    }
}
///FUNCAO PARA CONTAGEM DE QUANTIDADE DE CADASTRADOS ANIMAIS!
void contagemANIMAIS(no *lista)
{
    int qtd = 0;
    while (lista != NULL)
    {
        qtd++;
        lista = lista->prox;
    }
    if (qtd != 0)
    {
        cout << " \n Quantidade de animais cadastrados : " << qtd;
    }
    else
        cout << " \n Nao a animal cadastrado ! " << endl;
}
///FUNCAO PARA BUSCAR ANIMAL PELO NOME
void buscaNOME(no *lista)
{
    cout << "\n+-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ " << endl;
    cout << "|B| |u| |s| |c| |a| |r|   |A| |n| |i| |m| |a| |l|   |p| |e| |l| |o|   |N| |o| |m| |e| " << endl;
    cout << "+-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ " << endl;

    int count = 0;
    char nome2[50];
    cout << "\n Informe  o Nome do animal a ser buscado : ";
    cin.ignore();
    cin.getline(nome2, 50);

    while (lista != NULL)
    {
        if (strcmp(nome2, lista->nome) == 0)
        {
            cout << "\n +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
            cout << " |A| |n| |i| |m| |a| |l|   |E| |n| |c| |o| |n| |t| |r| |a| |d| |o| |:|" << endl;
            cout << " +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
            cout << "\n Nome do animal : " << lista->nome;
            cout << "\n Especie do Animal :" << lista->especie;
            cout << "\n Raca do animal : " << lista->raca;
            cout << "\n Sexo do Animal : " << lista->sexo;
            cout << "\n Idade do animal :" << lista->idade;
            cout << "\n Altura do animal  :" << lista->altura;
            cout << "\n Peso do animal : " << lista->peso;
            cout << "\n ID do animal :" << lista->id;
            count++;
        }
        lista = lista->prox;
    }
    if (count == 0)
        cout << " \n Animal nao encontrado!!! " << endl;
}
///BUSCAR ANIMAL POR RAÇA E ESPECIE
void buscaANIMALESPECIERACA(no *lista)
{
    cout << "\n +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+   +-+ +-+ +-+ +-+" << endl;
    cout << " |B| |u| |s| |c| |a|   |p| |o| |r|   |e| |s| |p| |e| |c| |i| |e|   |e|   |r| |a| |c| |a|" << endl;
    cout << " +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+   +-+ +-+ +-+ +-+" << endl;

    int count = 0;
    char especie2[30], raca2[30];
    cout << " \n Informe a especie do animal a ser buscado : ";
    cin.ignore();
    cin.getline(especie2, 50);
    cout << " \n Informe a raca do animal : ";
    cin.getline(raca2, 50);

    while (lista != NULL)
    {
        if (strcmp(especie2, lista->especie) == 0 && strcmp(raca2, lista->raca) == 0)
        {
            {
                cout << "\n +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
                cout << " |A| |n| |i| |m| |a| |l|   |E| |n| |c| |o| |n| |t| |r| |a| |d| |o| |:|" << endl;
                cout << " +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
                cout << "\n Nome do animal : " << lista->nome;
                cout << "\n Especie do Animal " << lista->especie;
                cout << "\n Raca do animal : " << lista->raca;
                cout << "\n Sexo do Animal : " << lista->sexo;
                cout << "\n Idade do animal :" << lista->idade;
                cout << "\n Altura do animal  :" << lista->altura;
                cout << "\n Peso do animal : " << lista->peso;
                cout << "\n ID do animal :" << lista->id;
                count++;
            }
        }
        lista = lista->prox;
    }
    if (count == 0)
        cout << " \n Animal Nao encontrado!!!" << endl;
}
/// FUNCAO PARA BUSCAR POR ESPECIE
void buscaESPECIE(no *lista)
{
    cout << "\n  +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
    cout << "  |B| |u| |s| |c| |a| |r|   |A| |n| |i| |m| |a| |l|   |p| |o| |r|   |E| |s| |p| |e| |c| |i| |e|" << endl;
    cout << "  +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;

    int count = 0;
    char especie5[30];
    cout << " \n Informe a Especie do animal a ser buscado : ";
    cin.ignore();
    cin.getline(especie5, 30);

    while (lista != NULL)
    {
        if (strcmp(especie5, lista->especie) == 0)
        {
            cout << "\n +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
            cout << " |A| |n| |i| |m| |a| |l|   |E| |n| |c| |o| |n| |t| |r| |a| |d| |o| |:|" << endl;
            cout << " +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
            cout << "\n Nome do animal : " << lista->nome;
            cout << "\n Especie do Animal " << lista->especie;
            cout << "\n Raca do animal : " << lista->raca;
            cout << "\n Sexo do Animal : " << lista->sexo;
            cout << "\n Idade do animal :" << lista->idade;
            cout << "\n Altura do animal  :" << lista->altura;
            cout << "\n Peso do animal : " << lista->peso;
            cout << "\n ID do animal :" << lista->id;
            count++;
        }
        lista = lista->prox;
    }
    if (count == 0)
        cout << " \n Animal nao encontrado!!!" << endl;
}
///FUNCAO PARA BUSCAR POR ESPECIE RACA E SEXO
void busca(no *lista)
{
    cout << " \n +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
    cout << " |B| |u| |s| |c| |a|   |C| |o| |m| |p| |l| |e| |t| |a|" << endl;
    cout << " +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;

    int count = 0;
    char sexo2[2], especie6[30], raca5[30];
    cout << " \n Informe a Especie do Animal a ser buscado : ";
    cin.ignore();
    cin.getline(especie6, 30);
    cout << " \n Informe a Raca do Animal a ser buscado : ";
    cin.getline(raca5, 30);
    cout << " \n Informe o Sexo do Animal a ser buscado :";
    cin.getline(sexo2, 2);

    while (lista != NULL)
    {
        if (strcmp(especie6, lista->especie) == 0 && strcmp(raca5, lista->raca) == 0 && strcmp(sexo2, lista->sexo) == 0)
        {
            cout << "\n +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
            cout << " |A| |n| |i| |m| |a| |l|   |E| |n| |c| |o| |n| |t| |r| |a| |d| |o| |:|" << endl;
            cout << " +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
            cout << "\n Nome do animal : " << lista->nome;
            cout << "\n Especie do Animal :" << lista->especie;
            cout << "\n Raca do animal : " << lista->raca;
            cout << "\n Sexo do Animal : " << lista->sexo;
            cout << "\n Idade do animal :" << lista->idade;
            cout << "\n Ara do animal  :" << lista->altura;
            cout << "\n Peso do animal : " << lista->peso;
            cout << "\n ID do animal :" << lista->id;
            count++;
        }
        lista = lista->prox;
    }
    if (count == 0)
        cout << "  \n Animal nao encontrado !!! " << endl;
}
///FUNCAO PARA CONTAR QUANTIDADE DE ESPECIES
void contagemESPECIE(no *lista)
{
    int qtd = 0;
    char especie[30];

    cout << "\n Informe a especie que vc quer contar :";
    cin.ignore();
    cin.getline(especie, 30);

    while (lista != NULL)
    {
        if (strcmp(especie, lista->especie) == 0)
        {
            qtd++;
        }
        lista = lista->prox;
    }
    if (qtd != 0)
        cout << "\n Quantidade dessa especie : " << qtd;

    else
    {
        cout << "\n Nao ha animais dessa especie na lista : " << endl;
    }
}
///FUNCAO PARA APAGAR CONTATO TEMPORARIAMENTE
void apagatemporario(no **lista, no **lista3)
{
    cout << " +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
    cout << " |A| |p| |a| |g| |a| |r|   |T| |e| |m| |p| |o| |r| |i| |a| |r| |i| |a| |m| |e| |n| |t| |e| " << endl;
    cout << " +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ " << endl;

    no *aux = (*lista), *aux2, *aux3;
    int id;

    while (aux != NULL)
    {
        cout << " \n Nome do animal : " << aux->nome;
        cout << " \n Especie do Animal  : " << aux->especie;
        cout << " \n Raca do Animal : " << aux->raca;
        cout << " \n Sexo do Animal : " << aux->nome;
        cout << " \n Idade do Animal: " << aux->idade;
        cout << " \n Altura do Animal : " << aux->altura;
        cout << " \n Peso do animal : " << aux->peso;
        cout << " \n ID do animal : " << aux->id << endl;
        aux = aux->prox;
    }
    aux = (*lista);
    cout << " \n Informe Qual ID voce quer remover temporiariamente :";
    cin >> id;

    while (aux != NULL && aux->id != id)
    {
        aux2 = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        cout << "\n Nao tem animais cadastrados com esse ID para serem removido temporiariamente! " << endl;
    }

    else if (aux == (*lista))
    {
        (*lista) = aux->prox;
    }

    else
    {
        aux2->prox = aux->prox;
    }

    if (aux != NULL)
    {
        aux3 = aux;
        aux3->prox = (*lista3);
        (*lista3) = aux;
    }
}
///FUNCAO PARA REMOVER ANIMAIS
void remover(no **lista)
{
    cout << "\n+-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
    cout << "|R| |e| |m| |o| |c| |a| |o|   |d| |e|   |A| |n| |i| |m| |a| |i| |s| " << endl;
    cout << "+-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ " << endl;

    no *aux = (*lista), *aux2, *aux3 = (*lista);
    int id;

    while (aux3 != NULL)
    {
        cout << " \n Nome do animal : " << aux3->nome;
        cout << " \n Especie do Animal  : " << aux3->especie;
        cout << " \n Raca do Animal : " << aux3->raca;
        cout << " \n Sexo do Animal : " << aux3->nome;
        cout << " \n Idade do Animal: " << aux3->idade;
        cout << " \n Altura do Animal : " << aux3->altura;
        cout << " \n Peso do animal : " << aux3->peso;
        cout << " \n ID do animal : " << aux3->id << endl;
        aux3 = aux3->prox;
    }

    cout << " \n Informe o id para remocao : ";
    cin >> id;

    while (aux != NULL && aux->id != id)
    {
        aux2 = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        cout << "\n Nao tem animais cadastrados !" << endl;
    }
    else if (aux == (*lista))
    {
        (*lista) = aux->prox;
    }
    else
    {
        aux2->prox = aux->prox;
    }
    free(aux);
}
///FUNCAO PARA ADOTAR ANIMAL
void adota(no **lista, no **lista2)
{
    cout << "\n+-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+   +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
    cout << "|B| |e| |m|   |v| |i| |n| |d| |o|   |a|   |a| |d| |o| |t| |a| |c| |a| |o| " << endl;
    cout << "+-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+   +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ " << endl;

    int id;
    no *aux = (*lista);
    no *aux2;
    no *aux3;

    while (aux != NULL)
    {
        cout << " \n Nome do animal : " << aux->nome;
        cout << " \n Especie do Animal  : " << aux->especie;
        cout << " \n Raca do Animal : " << aux->raca;
        cout << " \n Sexo do Animal : " << aux->nome;
        cout << " \n Idade do Animal: " << aux->idade;
        cout << " \n Altura do Animal : " << aux->altura;
        cout << " \n Peso do animal : " << aux->peso;
        cout << " \n ID do animal : " << aux->id << endl;
        aux = aux->prox;
    }
    aux = (*lista);
    cout << " \n Informe o ID do animal que deseja adotar: ";
    cin >> id;

    while (aux != NULL && aux->id != id)
    {
        aux2 = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        cout << " \n Nao tem animais para serem adotados! " << endl;
    }
    else if (aux == (*lista))
    {
        (*lista) = aux->prox;
    }
    else
    {
        aux2->prox = aux->prox;
    }
    if (aux != NULL)
    {
        aux3 = aux;
        aux3->prox = (*lista2);
        (*lista2) = aux;
    }
}
///FUNCAO PARA ALTERAR INFORMAÇAO do Animal
void alterar(no **lista)
{
    no *aux = (*lista);
    int id3, opcao;

    cout << "\n +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ " << endl;
    cout << " |A| |l| |t| |e| |r| |a| |r|   |i| |n| |f| |o| |r| |m| |a| |c| |o| |e| |s|" << endl;
    cout << " +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;

    while (aux != NULL)
    {
        cout << " \n Nome do animal : " << aux->nome;
        cout << " \n Especie do Animal  : " << aux->especie;
        cout << " \n Raca do Animal : " << aux->raca;
        cout << " \n Sexo do Animal : " << aux->nome;
        cout << " \n Idade do Animal: " << aux->idade;
        cout << " \n Altura do Animal : " << aux->altura;
        cout << " \n Peso do animal : " << aux->peso;
        cout << " \n ID do animal : " << aux->id << endl;
        aux = aux->prox;
    }
    cout << " \n Informe qual id do Animal voce deseja alterar : ";
    cin >> id3;

    cout << " \n 1- Para alterar o nome : ";
    cout << " \n 2- Para alterar a especie :";
    cout << " \n 3- para alterar a raca :";
    cout << " \n 4- para alterar o sexo:";
    cout << " \n 5- para alterar a idade :";
    cout << " \n 6- para alterar a altura : ";
    cout << " \n 7- para alterar o peso : ";
    cout << " \n Informe sua opcao...... : ";
    cin >> opcao;
    aux = (*lista);

    switch (opcao)
    {

    case 1:
        char nome10[50];
        cout << " \n\n Informe o novo nome a ser alterado : ";
        cin.ignore();
        cin.getline(nome10, 50);

        while (aux != NULL)
        {
            if (aux->id == id3)
            {
                strcpy(aux->nome, nome10);
                break;
            }
            aux = aux->prox;
        }
        break;

    case 2:
        char especie15[50];
        cout << " \n\n Informe a nova especie  : ";
        cin.ignore();
        cin.getline(especie15, 50);

        while (aux != NULL)
        {
            if (aux->id == id3)
            {
                strcpy(aux->especie, especie15);
                break;
            }
            aux = aux->prox;
        }
        break;

    case 3:
        char raca15[45];
        cout << " \n\n Informe a nova raca  : ";
        cin.ignore();
        cin.getline(raca15, 45);

        while (aux != NULL)
        {
            if (aux->id == id3)
            {
                strcpy(aux->raca, raca15);
                break;
            }
            aux = aux->prox;
        }
        break;

    case 4:
        char sexo15[1];
        cout << " \n\n Informe o novo sexo  : ";
        cin >> sexo15;

        while (aux != NULL)
        {
            if (aux->id == id3)
            {
                strcpy(aux->sexo, sexo15);
                break;
            }
            aux = aux->prox;
        }
        break;

    case 5:
        int idade15;
        cout << " \n\n Informe a nova idade  : ";
        cin >> idade15;

        while (aux != NULL)
        {
            if (aux->id == id3)
            {
                aux->idade = idade15;
                break;
            }
            aux = aux->prox;
        }
        break;

    case 6:
        float altura15;
        cout << " \n\n Informe a nova altura  : ";
        cin >> altura15;

        while (aux != NULL)
        {
            if (aux->id == id3)
            {
                aux->altura = altura15;
                break;
            }
            aux = aux->prox;
        }
        break;

    case 7:
        float peso15;
        cout << " \n\n Informe o novo peso  : ";
        cin >> peso15;

        while (aux != NULL)
        {
            if (aux->id == id3)
            {
                aux->peso = peso15;
                break;
            }
            aux = aux->prox;
        }
        break;
    }
    system("cls");
}
///FUNCAO PARA PRINTAR TODOS ANIMAIS CADASTRADOS NA LISTA NORMAL !!
void listagem(no *lista)
{
    cout << "\n +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
    cout << " |A| |n| |i| |m| |a| |i| |s|   |C| |a| |d| |a| |s| |t| |r| |a| |d| |o| |s| |:|" << endl;
    cout << " +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;

    if (lista == NULL)
        cout << "\n Nao ha animais cadastrados no PetShop !" << endl;

    else
    {
        while (lista != NULL)
        {
            cout << " -------------------------------------------------------------- " << endl;
            cout << " \n Nome Animal : " << lista->nome << endl;
            cout << " \n Especie Animal : " << lista->especie << endl;
            cout << " \n Raca Animal : " << lista->raca << endl;
            cout << " \n Sexo do Animal : " << lista->sexo << endl;
            cout << " \n Idade Animal : " << lista->idade << endl;
            cout << " \n Altura do Animal : " << lista->altura << endl;
            cout << " \n Peso do Animal : " << lista->peso << endl;
            cout << " \n ID do animal :" << lista->id << endl;
            lista = lista->prox;
        }
    }
}
///FUNCAO PARA PRINTAR A LISTA DE ANIMAIS JA ADOTADOS
void listaAdotados(no *lista2)
{
    cout << "\n +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
    cout << " |A| |n| |i| |m| |a| |i| |s|   |j| |a|   |a| |d| |o| |t| |a| |d| |o| |s| |:| " << endl;
    cout << " +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ " << endl;

    if (lista2 == NULL)
        cout << "\n Nenhum Animal foi adotado ainda ! " << endl;

    else
    {
        while (lista2 != NULL)
        {
            cout << " -------------------------------------------------------------- " << endl;
            cout << " \n Nome Animal : " << lista2->nome << endl;
            cout << " \n Especie Animal : " << lista2->especie << endl;
            cout << " \n Raca Animal : " << lista2->raca << endl;
            cout << " \n Sexo do Animal : " << lista2->sexo << endl;
            cout << " \n Idade Animal : " << lista2->idade << endl;
            cout << " \n Altura do Animal : " << lista2->altura << endl;
            cout << " \n Peso do Animal : " << lista2->peso << endl;
            cout << " \n ID do animal :" << lista2->id << endl;
            lista2 = lista2->prox;
        }
    }
}
///FUNCAO PARA PRINTAR LISTA DE CONTATOS APAGADOS
void contatosAPAGADOS(no *lista3)
{
    cout << "+-+ +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ " << endl;
    cout << "|L| |i| |s| |t| |a|   |d| |e|   |c| |o| |n| |t| |a| |t| |o| |s|   |a| |p| |a| |g| |a| |d| |o| |s| " << endl;
    cout << "+-+ +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ " << endl;

    if (lista3 == NULL)
        cout << " \n Nao ha contatos apagados nessa lista ainda !" << endl;
    else
    {
        while (lista3 != NULL)
        {
            cout << " -------------------------------------------------------------- " << endl;
            cout << " \n Nome Animal : " << lista3->nome << endl;
            cout << " \n Especie Animal : " << lista3->especie << endl;
            cout << " \n Raca Animal : " << lista3->raca << endl;
            cout << " \n Sexo do Animal : " << lista3->sexo << endl;
            cout << " \n Idade Animal : " << lista3->idade << endl;
            cout << " \n Altura do Animal : " << lista3->altura << endl;
            cout << " \n Peso do Animal : " << lista3->peso << endl;
            cout << " \n ID do animal :" << lista3->id << endl;
            lista3 = lista3->prox;
        }
    }
}
///FUNCAO PARA RECUPERAR CONTATO APAGADO E JOGAR NO INICIO DA LISTA PRINCIPAL
void recupera(no **lista, no **lista3)
{
    cout << "\n+-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
    cout << "|R| |e| |c| |u| |p| |e| |r| |a|   |C| |o| |n| |t| |a| |t| |o| |s|   |a| |p| |a| |g| |a| |d| |o| |s|" << endl;
    cout << "+-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;

    if ((*lista3) == NULL)
    {
        cout << "\n Nao existem contatos apagados ! " << endl;
    }
    else
    {
        no *aux = (*lista3), *aux2, *aux3;
        int id;

        while (aux != NULL)
        {
            cout << " \n Nome do animal : " << aux->nome;
            cout << " \n Especie do Animal  : " << aux->especie;
            cout << " \n Raca do Animal : " << aux->raca;
            cout << " \n Sexo do Animal : " << aux->nome;
            cout << " \n Idade do Animal: " << aux->idade;
            cout << " \n Altura do Animal : " << aux->altura;
            cout << " \n Peso do animal : " << aux->peso;
            cout << " \n ID do animal : " << aux->id << endl;
            aux = aux->prox;
        }
        aux = (*lista3);
        cout << "\n Informe o ID do animal que voce quer recuperar:";
        cin >> id;

        while (aux != NULL && aux->id != id)
        {
            aux2 = aux;
            aux = aux->prox;
        }

        if (aux == NULL)
        {
            cout << " \n Esse id nao foi encontrado mano ! " << endl;
        }
        else if (aux == (*lista3))
        {
            (*lista3) = aux->prox;
        }
        else
        {
            aux2->prox = aux->prox;
        }
        if (aux != NULL)
        {
            aux3 = aux;
            aux3->prox = (*lista);
            (*lista) = aux;
        }
    }
}
///FUNCAO PARA BUSCAR ANIMAIS ADOTADOS PELO NOME
void buscaAdotados(no *lista2)
{
    char nome[10];
    int count = 0;
    cout << " \n Informe o nome do animal a ser buscado : ";
    cin.ignore();
    cin.getline(nome, 50);

    while (lista2 != NULL)
    {
        if (strcmp(nome, lista2->nome) == 0)
        {
            cout << "\n +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
            cout << " |A| |n| |i| |m| |a| |l|   |E| |n| |c| |o| |n| |t| |r| |a| |d| |o| |:|" << endl;
            cout << " +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
            cout << "\n Nome do animal : " << lista2->nome;
            cout << "\n Especie do Animal :" << lista2->especie;
            cout << "\n Raca do animal : " << lista2->raca;
            cout << "\n Sexo do Animal : " << lista2->sexo;
            cout << "\n Idade do animal :" << lista2->idade;
            cout << "\n Altura do animal  :" << lista2->altura;
            cout << "\n Peso do animal : " << lista2->peso;
            cout << "\n ID do animal :" << lista2->id;
            count++;
        }
        lista2 = lista2->prox;
    }
    if (count == 0)
        cout << " \n Nao encontramos animais adotados com esse nome ! " << endl;
}
///FUNCAO PARA INSERIR ORDENADO PELO NOME ALFABETICO
void ordenado(no **lista, int *id1)
{
    cout << "\n+-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ " << endl;
    cout << "|I| |n| |s| |e| |r| |i| |r|   |o| |r| |n| |d| |e| |a| |d| |o|   |p| |e| |l| |o|   |n| |o| |m| |e| " << endl;
    cout << "+-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ " << endl;

    time_t currentTime;
    struct tm *timeinfo;
    FILE *arq;
    currentTime = time(NULL);
    timeinfo = localtime(&currentTime);
    cout << "\n Horario de Cadastramento: " << timeinfo->tm_hour;
    cout << " " << timeinfo->tm_min;
    cout << " " << timeinfo->tm_sec << endl;

    (*id1) = (*id1) + 1;
    no *aux;
    aux = (no *)malloc(sizeof(no));
    if (aux != NULL)
    {
        cout << " \n Informe o nome do Animal : ";
        cin.ignore();
        cin.getline(aux->nome, 50);
        cout << " \n Informe a Especie do animal : ";
        cin.getline(aux->especie, 50);
        cout << " \n Informe a Raca do animal : ";
        cin.getline(aux->raca, 35);
        cout << " \n Informe o Sexo do animal M ou F :";
        cin >> aux->sexo;
        cout << " \n Informe a Idade do animal :";
        cin >> aux->idade;
        cout << " \n Informe a Altura do animal :";
        cin >> aux->altura;
        cout << "\n Informe o Peso do animal :";
        cin >> aux->peso;
        cout << "\n O id do Animal e : " << *id1;
        aux->id = (*id1);
        aux->prox = NULL;

        cout <<"\n Gravando no arquivo !!"<<endl;
        arq = fopen("Entrada.txt", "a");
        fprintf(arq, "Nome: " "%s ", aux->nome);
        fprintf(arq,"Especie: " "%s ", aux->especie);
        fprintf(arq,"Raca: " "%s ", aux->raca);
        fprintf(arq,"Sexo: " "%s ", aux->sexo);
        fprintf(arq,"Idade: " "%d ", aux->idade);
        fprintf(arq,"Altura: " "%f ", aux->altura);
        fprintf(arq,"Id: " "%d\n",aux->id);
        fclose(arq);
    }

    if ((*lista) == NULL)
    {
        aux->prox = (*lista);
        (*lista) = aux;
    }
    else
    {
        no *ant, *atual = (*lista);

        while (atual != NULL && strcmp(atual->nome, aux->nome) > 0)
        {
            ant = atual;
            atual = atual->prox;
        }
        if (atual == (*lista))
        {
            aux->prox = (*lista);
            (*lista) = aux;
        }
        else
        {
            aux->prox = ant->prox;
            ant->prox = aux;
        }
    }
    system("cls");
}
///FUNCAO PARA BUSCAR ANIMAIS ADOTADOS PELA SUA ESPECIE
void buscaADOTADOSESPECIE(no *lista2)
{
    char especie[50];
    int count = 0;
    cout << "\n Informe a especie Adotada a ser buscada ";
    cin.ignore();
    cin.getline(especie, 50);

    while (lista2 != NULL)
    {
        if (strcmp(especie, lista2->especie) == 0)
        {
            cout << "\n +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
            cout << " |A| |n| |i| |m| |a| |l|   |E| |n| |c| |o| |n| |t| |r| |a| |d| |o| |:|" << endl;
            cout << " +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
            cout << "\n Nome do animal : " << lista2->nome;
            cout << "\n Especie do Animal :" << lista2->especie;
            cout << "\n Raca do animal : " << lista2->raca;
            cout << "\n Sexo do Animal : " << lista2->sexo;
            cout << "\n Idade do animal :" << lista2->idade;
            cout << "\n Altura do animal  :" << lista2->altura;
            cout << "\n Peso do animal : " << lista2->peso;
            cout << "\n ID do animal :" << lista2->id;
            count++;
        }
        lista2 = lista2->prox;
    }
    if (count == 0)
        cout << " \n Nao foram encontrados animais adotados dessa especie!  " << endl;
}
///FUNCAO PARA BUSCAR ANIMAIS ADOTADOS POR ID
void buscaAdotadosID(no *lista2)
{
    int id, count = 0;
    cout << " \n Informe o ID do animal para ser buscado na lista de adotados: ";
    cin >> id;

    while (lista2 != NULL)
    {
        if (lista2->id == id)
        {
            cout << "\n +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
            cout << " |A| |n| |i| |m| |a| |l|   |E| |n| |c| |o| |n| |t| |r| |a| |d| |o| |:|" << endl;
            cout << " +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+ +-+" << endl;
            cout << "\n Nome do animal : " << lista2->nome;
            cout << "\n Especie do Animal :" << lista2->especie;
            cout << "\n Raca do animal : " << lista2->raca;
            cout << "\n Sexo do Animal : " << lista2->sexo;
            cout << "\n Idade do animal :" << lista2->idade;
            cout << "\n Altura do animal  :" << lista2->altura;
            cout << "\n Peso do animal : " << lista2->peso;
            cout << "\n ID do animal :" << lista2->id;
            count++;
        }
        lista2 = lista2->prox;
    }
    if (count == 0)
        cout << " \n Nao foram encontrados animais ADOTADOS  com esse id ! " << endl;
}

///CABECHALO MAIN PETSHOP
void cabechalo()
{
    cout << "\n                             ######   " << endl;
    cout << "                             #     #  ######  #    #      #    #  #  #    #  #####    ####  " << endl;
    cout << "                             #     #  #       ##  ##      #    #  #  ##   #  #    #  #    #  " << endl;
    cout << "                             ######   #####   # ## #      #    #  #  # #  #  #    #  #    #  " << endl;
    cout << "                             #     #  #       #    #      #    #  #  #  # #  #    #  #    #     " << endl;
    cout << "                             #     #  #       #    #       #  #   #  #   ##  #    #  #    #  " << endl;
    cout << "                             ######   ######  #    #        ##    #  #    #  #####    #### " << endl;
    cout << "\n\n                              ######                       ##### " << endl;
    cout << "                              #     #  ######  #####      #     #  #    #   ####   #####  " << endl;
    cout << "                              #     #  #         #        #        #    #  #    #  #    # " << endl;
    cout << "                              ######   #####     #         #####   ######  #    #  #    # " << endl;
    cout << "                              #        #         #              #  #    #  #    #  #####  " << endl;
    cout << "                              #        #         #        #     #  #    #  #    #  # " << endl;
    cout << "                              #        ######    #         #####   #    #   ####   # " << endl;
    cout << "\n\n\n\n          ( D ) ( E ) ( S ) ( E ) ( N ) ( V ) ( O ) ( L ) ( V ) ( E ) ( D ) ( O ) ( R ) ( E ) ( S )" << endl;
    cout << "\n Matheus Henry Barbosa Ra: 20068649";
    cout << "\n Lucas Lacerda Feliciano Ra: 20061859" << endl;
    cout << " \n\n Opcionais Funcionando : " << endl;
    cout << "\n 1- Recuperacao de contatos ja apagados ! ";
    cout << "\n 2- Lista de animais adotados e busca !";
    cout << "\n 3- Interface grafica e diagramacao ! ";
    cout << "\n 4- Funcao para inserir ordenado pelo nome alfabetico !";
    cout << "\n 5- Funcao para hora de cadastramento !";
    cout <<" \n 6- Funcao para gravar no arquivo!";
}

///FUNCAO MAIN
int main()
{
    char enter;
    int opcao, id1 = 0;
    no *lista = NULL;
    no *lista2 = NULL;
    no *lista3 = NULL;

    time_t currentTime;
    struct tm *timeinfo;
    currentTime = time(NULL);
    timeinfo = localtime(&currentTime);


    cabechalo();
    cout << "\n\n Deseja Entrar no Petshop S ou N ? ";
    cin >> enter;
    enter = toupper(enter);

    if (enter == 'N' || enter != 'S')
    {
        return 0;
    }
    else
    {
        system("cls");
        do
        {

            cout << "\n\n\n  +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+ " << endl;
            cout << "  |I| |n| |f| |o| |r| |m| |e|   |s| |u| |a|   |o| |p| |c| |a| |o|" << endl;
            cout << "  +-+ +-+ +-+ +-+ +-+ +-+ +-+   +-+ +-+ +-+   +-+ +-+ +-+ +-+ +-+" << endl;
            cout << " \n\n ----------------------- Menu Principal -------------------------";
            cout << " \n\n 1- Para inclusao de novos Animais ! ";
            cout << " \n 2- Para listagem completa: ";
            cout << " \n 3- Para contagem quantidade de animais: ";
            cout << " \n 4- Para fazer a Busca de um animal pelo NOME:";
            cout << " \n 5- Para fazer a Busca por ESPECIE E RACA: ";
            cout << " \n 6- Para fazer a Busca por ESPECIE:";
            cout << " \n 7- Para fazer a Busca por ESPECIE, RACA E SEXO: ";
            cout << " \n 8- Para fazer a Contagem por ESPECIE:";
            cout << " \n 9- Para Remover um Animal da lista Sem volta: ";
            cout << " \n 10- Para alterar informacao:";
            cout << " \n 11- Para escolher um Animal para Adotar:";
            cout << " \n 12- Para listagens dos Animais ja Adotados:";
            cout << " \n 13- Buscar por NOME Na lista de Animais ja Adotados ! ";
            cout << " \n 14- Buscar por ESPECIE na lista de Animais ja adotados ! ";
            cout << " \n 15- Para buscar por ID na lista de animais adotados ! ";
            cout << " \n 16- Para apager um contato temporiariamente !";
            cout << " \n 17- Para Visualizar Lista de contatos apagados temporiariamente !";
            cout << " \n 18- Para Recuperar O contato apagado ! ";
            cout << " \n 19- Para inserir Ordenado pelo NOME do Animal !";
            cout << " \n 0-  Para sair do Programa: ";
            cout << " \n Informe sua opcao:";
            cin >> opcao;

            switch (opcao)
            {
            case 1:
                insereANIMAIS(&lista, &id1);
                break;
            case 2:
                listagem(lista);
                break;
            case 3:
                contagemANIMAIS(lista);
                break;
            case 4:
                buscaNOME(lista);
                break;
            case 5:
                buscaANIMALESPECIERACA(lista);
                break;
            case 6:
                buscaESPECIE(lista);
                break;
            case 7:
                busca(lista);
                break;
            case 8:
                contagemESPECIE(lista);
                break;
            case 9:
                remover(&lista);
                break;
            case 10:
                alterar(&lista);
                break;
            case 11:
                adota(&lista, &lista2);
                break;
            case 12:
                listaAdotados(lista2);
                break;
            case 13:
                buscaAdotados(lista2);
                break;
            case 14:
                buscaADOTADOSESPECIE(lista2);
                break;
            case 15:
                buscaAdotadosID(lista2);
                break;
            case 16:
                apagatemporario(&lista, &lista3);
                break;
            case 17:
                contatosAPAGADOS(lista3);
                break;
            case 18:
                recupera(&lista, &lista3);
                break;
            case 19:
                ordenado(&lista, &id1);
                break;
            }
        } while (opcao != 0);
    }
    return 0;
}

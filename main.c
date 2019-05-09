/*=====================================================
    Nome: Anderson Simão da Silva || RA: 22.118.031-8
        Nome: Thiago Kian || RA: 22.118.165-4
=======================================================*/

#include <stdio.h>
#include <stdlib.h>
//Função para usar a sleep
#include <unistd.h>
//Função para usar acentuação no printf
#include <locale.h>
#include <string.h>

struct _user{
    char nome[50];
    char tel[20];
    char email[30];
    char rg[16];
    char cpf[20];
    char sangue[4];
    char opConv[15];
    char religiao[10];
    char cidade[20];
    char estado[3];
};

typedef struct _user User;

struct _agenda{
  User* v;
  int max;
  int n;
};

typedef struct _agenda Agenda;

Agenda criaAgenda(int n){
  Agenda a;
  a.v = malloc(sizeof(User)*n);
  a.max = n;
  a.n = 0;
  return a;
}

void destroiAgenda(Agenda* a){
  free(a->v);
}

void mainMenu(Agenda a);
void gravaTxt(Agenda a);
Agenda lerTxt();

void rmvLinha(char* str){
  int i=0;
  while(str[i] != '\0' && str[i] != '\n' )
      i++;
  str[i] = '\0';
}

void printUser(User *v){
  printf("=========================================\n");
  printf("Nome: %s\n",v->nome);
  printf("Telefone: %s\n",v->tel);
  printf("Email: %s\n",v->email);
  printf("RG: %s\n",v->rg);
  printf("CPF: %s\n",v->cpf);
  printf("Tipo Sanguineo: %s\n",v->sangue);
  printf("Operadora: %s\n",v->opConv);
  printf("Religiao: %s\n",v->religiao);
  printf("Cidade: %s\n",v->cidade);
  printf("Estado: %s\n",v->estado);
  printf("=========================================\n");
}

void cadUser(Agenda* a){
  if(a->n >= a->max){
    printf("Nao eh possivel gravar mais usuarios\n Numero maximo alcancado\n");
    return;
  }
  printf("Digite o nome:\n");
    fgets(a->v[a->n].nome, 50, stdin);
    rmvLinha(a->v[a->n].nome);
  printf("Digite o telefone:\n");
    fgets(a->v[a->n].tel, 20, stdin);
    rmvLinha(a->v[a->n].tel);
  printf("Digite o email:\n");
    fgets(a->v[a->n].email, 30, stdin);
    rmvLinha(a->v[a->n].email);
  printf("Digite o RG:\n");
    fgets(a->v[a->n].rg, 16, stdin);
    rmvLinha(a->v[a->n].rg);
  printf("Digite o CPF:\n");
    fgets(a->v[a->n].cpf, 20, stdin);
    rmvLinha(a->v[a->n].cpf);
  printf("Digite o tipo sanguíneo:\n");
    fgets(a->v[a->n].sangue, 4, stdin);
    rmvLinha(a->v[a->n].sangue);
  printf("Digite a operadora do convenio:\n");
    fgets(a->v[a->n].opConv, 15, stdin);
    rmvLinha(a->v[a->n].opConv);
  printf("Digite a religiao:\n");
    fgets(a->v[a->n].religiao, 10, stdin);
    rmvLinha(a->v[a->n].religiao);
  printf("Digite a cidade:\n");
    fgets(a->v[a->n].cidade, 20, stdin);
    rmvLinha(a->v[a->n].cidade);
  printf("Digite o estado:\n");
    fgets(a->v[a->n].estado, 3, stdin);
    rmvLinha(a->v[a->n].estado);
  a->n++;
  setbuf(stdin,NULL);
  printf("Usuario cadastrado!\n");

  int cad;

  printf("Deseja cadastrar outro usuario?\n");
  printf("1 - Sim\n");
  printf("2 - Nao\n");

  scanf("%d", &cad);
  setbuf(stdin,NULL);
  if(cad == 1){
    cadUser(a);
  }
}

void listUser(Agenda* a){
  setbuf(stdin,NULL);
  int i;
  if(a->n > 0){
    for(i=0;i< a->n;i++){
      printUser(&a->v[i]);
    }
  }
  else{
    printf("Nao ha usuarios cadastrados!\n");
  }
}

int searchUser(Agenda* a, char* cpf){
  int idx;
  for(idx=0;idx<a->n;idx++){
    if((strcmp(cpf, a->v[idx].cpf)) == 0){
      return idx;
    }
  }
  return -1;
}

void altUser(Agenda* a, int idx){
	setbuf(stdin,NULL);
  int alt = 0;
  sleep(1);
  printf("=========================================\n");
  printf("       Menu de alteração:\n");
  printf("=========================================\n");
  printf("1 - Nome\n");
  printf("2 - Telefone\n");
  printf("3 - E-mail\n");
  printf("4 - RG\n");
  printf("5 - CPF\n");
  printf("6 - Tipo Sanguineo\n");
  printf("7 - Operadora do convenio\n");
  printf("8 - Religiao\n");
  printf("9 - Cidade\n");
  printf("0 - Estado\n");
  printf("=========================================\n");
  scanf("%d", &alt);
  setbuf(stdin, NULL);

  if(alt == 1){
    char nome[50];
    printf("Digite o novo nome: \n");
    fgets(nome,sizeof(nome),stdin);
    setbuf(stdin, NULL);
    rmvLinha(nome);
    strcpy(a->v[idx].nome, nome);
    printf("Nome alterado com sucesso!\n");
  }
  else if(alt == 2){
    char tel[20];
    printf("Digite o novo telefone: \n");
    fgets(tel,sizeof(tel),stdin);
    setbuf(stdin, NULL);
    rmvLinha(tel);
    strcpy(a->v[idx].tel, tel);
    printf("Telefone alterado com sucesso!\n");
  }
  else if(alt == 3){
    char email[30];
    printf("Digite o novo e-mail: \n");
    fgets(email,sizeof(email),stdin);
    setbuf(stdin, NULL);
    rmvLinha(email);
    strcpy(a->v[idx].email, email);
    printf("E-mail alterado com sucesso!\n");
  }
  else if(alt == 4){
    char rg[16];
    printf("Digite o novo RG: \n");
    fgets(rg,sizeof(rg),stdin);
    setbuf(stdin, NULL);
    rmvLinha(rg);
    strcpy(a->v[idx].rg, rg);
    printf("RG alterado com sucesso!\n");
  }
  else if(alt == 5){
    char cpf[20];
    printf("Digite o novo CPF: \n");
    fgets(cpf,sizeof(cpf),stdin);
    setbuf(stdin, NULL);
    rmvLinha(cpf);
    strcpy(a->v[idx].cpf, cpf);
    printf("CPF alterado com sucesso!\n");
  }
  else if(alt == 6){
    char sangue[4];
    printf("Digite o novo tipo sanguíneo: \n");
    fgets(sangue,sizeof(sangue),stdin);
    setbuf(stdin, NULL);
    rmvLinha(sangue);
    strcpy(a->v[idx].sangue, sangue);
    printf("Tipo sanguineo alterado com sucesso!\n");
  }
  else if(alt == 7){
    char opConv[15];
    printf("Digite a nova operadora do convenio: \n");
    fgets(opConv,sizeof(opConv),stdin);
    setbuf(stdin, NULL);
    rmvLinha(opConv);
    strcpy(a->v[idx].opConv, opConv);
    printf("Operadora alterada com sucesso!\n");
  }
  else if(alt == 8){
    char religiao[10];
    printf("Digite a nova religiao: \n");
    fgets(religiao,sizeof(religiao),stdin);
    setbuf(stdin, NULL);
    rmvLinha(religiao);
    strcpy(a->v[idx].religiao, religiao);
    printf("Religiao alterada com sucesso!\n");
  }
  else if(alt == 9){
    char cidade[20];
    printf("Digite a nova cidade: \n");
    fgets(cidade,sizeof(cidade),stdin);
    setbuf(stdin, NULL);
    rmvLinha(cidade);
    strcpy(a->v[idx].cidade, cidade);
    printf("Cidade alterada com sucesso!\n");
  }
  else if(alt == 0){
    char estado[3];
    printf("Digite o novo estado: \n");
    fgets(estado,sizeof(estado),stdin);
    rmvLinha(estado);
    setbuf(stdin, NULL);
    strcpy(a->v[idx].estado, estado);
    printf("Estado alterado com sucesso!\n");
  }
  else{
    printf("Opcao invalida!\n Por favor, tente novamente!\n");
  }
}

void rmvUser(Agenda* a, int idx){
	setbuf(stdin,NULL);
    int rmv = 0;
    int i = 0;
    printf("Deseja realmente remover o paciente %s ?\n", a->v[idx].nome);
    printf("1 - Sim\n");
    printf("2 - N�o\n");
    scanf("%d", &rmv);
    setbuf(stdin, NULL);
    if(rmv == 1){
      for(i=0;i < (a->n)-1;i++){
        a->v[idx] = a->v[idx+1];
      }
      a->n--;
      printf("Paciente excluido com sucesso!\n");
    }
    else if(rmv == 2){
      return;
    }
    else{
      printf("Opcao invalida! Tente novamente.\n");
      rmvUser(a, idx);
    }
}

void advOpc(Agenda a){
	setbuf(stdin,NULL);
    int opc;
    sleep(1);
    printf("=========================================\n");
    printf("       Opcoes avancadas:\n");
    printf("=========================================\n");
    printf("1 - Gravar agenda em arquivo texto\n");
    printf("2 - Ler agenda de arquivo texto\n");
    printf("3 - Voltar ao menu principal\n");
    printf("=========================================\n");

    scanf("%d", &opc);
    setbuf(stdin,NULL);

    if(opc == 1){
        gravaTxt(a);
        printf("Gravacao efetuada com sucesso!\n");
        advOpc(a);
    }
    else if(opc == 2){
        Agenda a = lerTxt();
        printf("Leitura efetuada com sucesso!\n");
        advOpc(a);
    }
    else if(opc == 3){
      mainMenu(a);
    }
    else{
        printf("Opção inválida, por favor digite novamente!\n");
        sleep(1);
        advOpc(a);
    }
}

void gravaBin(Agenda* a){
	setbuf(stdin,NULL);
  FILE* arq = fopen("agenda.age", "wb");

  fwrite(&a->n, sizeof(int), 1, arq);

  fwrite(a->v, sizeof(User),a->n, arq);

  fclose(arq);
}

void leiaAgenda(Agenda *a){
  FILE* arq = fopen("agenda.age", "rb");
  int n;
  fread(&n, sizeof(n), 1, arq);
  fread(a->v, sizeof(User), n, arq);
  a->n = n;
  fclose(arq);
}

void gravaTxt(Agenda a){

  FILE* arq = fopen("agenda.txt", "w");
  User *salvar = a.v;
  int i;
  fprintf(arq, "%d\n", a.n);
  for(i=0; i<a.n; i++){
    fprintf(arq, "%s\n", a.v[i].nome);
    fprintf(arq, "%s\n", a.v[i].tel);
    fprintf(arq, "%s\n", a.v[i].email);
    fprintf(arq, "%s\n", a.v[i].rg);
    fprintf(arq, "%s\n", a.v[i].cpf);
    fprintf(arq, "%s\n", a.v[i].sangue);
    fprintf(arq, "%s\n", a.v[i].opConv);
    fprintf(arq, "%s\n", a.v[i].religiao);
    fprintf(arq, "%s\n", a.v[i].cidade);
    fprintf(arq, "%s\n", a.v[i].estado);
  }
  fclose(arq);
}

Agenda lerTxt(){
	setbuf(stdin,NULL);
  FILE* arq = fopen("agenda.txt", "r");

  int n;
  fscanf(arq, "%d", &n);
  Agenda a = criaAgenda(100);

  int i;
  for(i=0; i<n; i++){
    fgets(a.v[i].nome, 50, arq);
    rmvLinha(a.v[i].nome);
    fgets(a.v[i].tel, 20, arq);
    rmvLinha(a.v[i].tel);
    fgets(a.v[i].email, 30, arq);
    rmvLinha(a.v[i].email);
    fgets(a.v[i].rg, 16, arq);
    rmvLinha(a.v[i].rg);
    fgets(a.v[i].cpf, 20, arq);
    rmvLinha(a.v[i].cpf);
    fgets(a.v[i].sangue, 4, arq);
    rmvLinha(a.v[i].sangue);
    fgets(a.v[i].opConv, 15, arq);
    rmvLinha(a.v[i].opConv);
    fgets(a.v[i].religiao, 10, arq);
    rmvLinha(a.v[i].religiao);
    fgets(a.v[i].cidade, 20, arq);
    rmvLinha(a.v[i].cidade);
    fgets(a.v[i].estado, 3, arq);
    rmvLinha(a.v[i].estado);
  }
  a.n = n;
  fclose(arq);

  return a;
}

void boasVindas(){
	setbuf(stdin,NULL);
    printf("=========================================\n");
    printf("Bem-vindo a Agenda do Consultorio!\n");
}

void mainMenu(Agenda a){
    int menu;
    sleep(1);
    printf("=========================================\n");
    printf("       Menu de opcoes:\n");
    printf("=========================================\n");
    printf("1 - Cadastrar usuario\n");
    printf("2 - Listar usuario\n");
    printf("3 - Remover usuario\n");
    printf("4 - Alterar dados do usuario\n");
    printf("5 - Buscar usuario\n");
    printf("6 - Opcoes avancadas\n");
    printf("7 - Sair\n");
    printf("=========================================\n");

    scanf("%d", &menu);
    setbuf(stdin,NULL);

    if(menu == 1){
        cadUser(&a);
        setbuf(stdin,NULL);
        mainMenu(a);
    }

    else if(menu == 2){
        listUser(&a);
        setbuf(stdin,NULL);
        mainMenu(a);
    }

    else if(menu == 3){
      char cpf[20];
      printf("Digite o CPF do paciente:");
      scanf("%s", cpf);
      int idx = searchUser(&a, cpf);
      if(idx != -1){
        rmvUser(&a, idx);
        setbuf(stdin,NULL);
        mainMenu(a);
      }
      else{
        printf("CPF invalido ou nao encontrado!\nDigite o CPF do paciente:");
        mainMenu(a);
      }
    }

    else if(menu == 4){
      char cpf[20];
      printf("Digite o CPF do paciente:");
      scanf("%s", cpf);
      int idx = searchUser(&a, cpf);
      if(idx != -1){
        altUser(&a, idx);
        mainMenu(a);
      }
      else{
        printf("CPF invalido ou nao encontrado!\nDigite o CPF do paciente:");
        mainMenu(a);
      }
    }

    else if(menu == 5){
        char cpf[20];
        printf("Digite o CPF do paciente:");
        scanf("%s", cpf);
        int idx = searchUser(&a, cpf);
        if(idx != -1){
          printUser(&a.v[idx]);
          mainMenu(a);
          
        }
        else{
          printf("CPF invalido ou nao encontrado!\nDigite o CPF do paciente:");
          mainMenu(a);
        }
    }
    else if(menu == 6){
        advOpc(a);
    }
    else if(menu == 7){
        printf("Ate logo !\n");
        sleep(1);
        printf(";-D\n");
        sleep(1);
        gravaBin(&a);
        destroiAgenda(&a);
    }
    else{
        printf("Opcao invalida, por favor digite novamente!\n");
        sleep(1);
        mainMenu(a);
    }
}

int main (int argc, char *argv[]){
    setlocale(LC_ALL, "Portuguese");

    Agenda a = criaAgenda(100);
    leiaAgenda(&a);

    boasVindas();
    mainMenu(a);

    return 0;
}

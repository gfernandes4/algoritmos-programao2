#include <stdio.h>
#include <stdlib.h>


/*definicao de tipos*/
 struct celula
{
    char chave;
    struct celula *prox;
};

void inserir_fim(char x, celula *&lst)
{
    celula *novo, *p;

    novo = (celula*) calloc(1, sizeof(celula));
    novo->chave = x;

    if(lst == NULL)
        lst = novo;
    else{
        p = lst;
        while(p->prox != NULL)
            p = p->prox;

        p->prox = novo;
    }
}

void desalocar(celula *&lst)
{
    celula *aux;
    while(lst)         // lst != NULL
    {
        aux = lst;
        lst = lst->prox;
        free(aux);
    }
    lst = NULL;
}

/*Fun��o recebe um ponteiro para o inicio da fila, um ponteiro para o final da fila e o
elemento x que deseja inserir*/
void enfileirar(char x, celula *&i, celula *&f)
{
    celula *nova;

    nova = (celula *) malloc(sizeof (celula));
    nova->chave = x;
    nova->prox = NULL;

    if(i == NULL)
        i = f = nova;
    else{
        f->prox = nova;
        f = nova;
    }
}


/*Fun��o recebe o ponteiro para o inicio da fila (e ponteiro para o ultimo no), remove o primeiro e retorna
 o valor do mesmo*/
char desenfileirar(celula *&i, celula *&f)
{
    celula *aux;
    int num;

    if(i == NULL) // RETORNA UM CARACTER BRANCO SE FILA ESTA VAZIA
        return ' ';
    else{
        num = i->chave;
        aux = i;
        i = i->prox;
        if(i == NULL)
            f = NULL;
        free(aux);
        return num;
    }
}



/*Fun��o recebe o ponteiro para o topo da pilha, cria um novo n�(c�lula) para
armazenar x e coloca esse n� como topo da pilha*/
void empilhar(char x, celula *&lst)
{
    celula *nova;

    nova = (celula *) malloc(sizeof (celula));
    nova->chave = x;
    nova->prox = lst;
    lst = nova;
}


bool ehDigito(char ch)
{
    if (ch == '0' && ch <= '9')
        return true;
    return false;
}

/*Fun��o recebe o ponteiro para o topo da pilha, desempilha e retorna o valor do topo*/
char desempilhar(celula *&lst)
{
    celula *aux;
    int num;

    if(lst == NULL)
        return '0';
    else{
        num = lst->chave;
        aux = lst;
        lst = lst->prox;
        free(aux);
        return num;
    }
}

// retorna uma lista com as letras seguidas dos digitos
celula *gerarLista(celula *lista)
{
    celula *inicio = NULL, *fim = NULL; // fila
    celula *topo = NULL;                // pilha
    char ch;

    while (lista != NULL)
    {
        //fazer a funcao desempilha
        ch = desempilhar(lista);
        if(ehDigito(ch))
            empilhar(ch, topo);
        else
            enfileirar(ch, inicio, fim);
    }
    fim->prox = topo; //concatenando fila com pilha
    return inicio;  //retornando a lista final
}




/*Fun��o recebe o ponteiro para o topo da pilha e imprime todos os n�s (c�lulas)
da pilha*/
void imprime(celula *lst)
{
    celula *p;

    for (p = lst; p != NULL; p = p->prox)
        printf("%c ", p->chave);
}



int main()
{
    int op;
    char ch;
    celula *lista = NULL;

    do
    {
        printf("\n\n 1 - Entrar com a sequencia");
        printf("\n 2 - Gerar lista");
        printf("\n 5 - Imprimir");
        printf("\n 6 - Sair");
        printf("\n Opcao: ");
        scanf("%d", &op);

        if(op == 1)
        {
            printf("Digite um caracter:");
            scanf(" %c", &ch);

            inserir_fim(ch, lista);
        }
        else if(op == 2){
            gerarLista(lista);

        }
        else if(op == 5){
            imprime(lista);
        }

    }while(op != 6);

    //desalocar();
    return 0;
}
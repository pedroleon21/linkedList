#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int val;
    struct No * prm;
}No;

typedef struct Lista
{
    struct No* prm;
}Lista;

Lista * newLista(){
    return (Lista*) calloc(1,sizeof(Lista));
}

No * NewNo(){
    return (No*)calloc(1,sizeof(No));
}

No * newNo(int n){
    No * no = NewNo();
    no->val=n;
    return no;
}

void push(Lista * lista,int n){
    if(n <= 0 )
        return;
    No * no = newNo(n);
    no->prm = lista->prm;
    lista->prm=no;
}

void freeLista(Lista * lista){
    No *no= lista->prm;
    free(lista);
    while (no)
    {
        printf("\nliberando o valor: %d",no->val);
        No * aux = no->prm;
        free(no);
        no = aux;
    }
}
int find(Lista * lista, int n){
    No * no= lista->prm;
    while(no){
        if(no->val == n)
        return no->val;
        no = no->prm;
    }
    return 0;
}

int size(Lista *lista){
    int size = 0;
    No *no=lista->prm;
    while (no)
    {
        no = no->prm;
        size++;
    }
    return size;
}

int main(){
    Lista * lista = newLista();
    int n = 1;
    while(n){
        printf("\nDigite: ");
        scanf("%d",&n);
        push(lista,n);
    }
    printf("\nEncontre o numero: ");
    scanf("%d",&n);
    printf("Numero, %d ",n);
    if(find(lista,n))
        printf("encontrado!");
    else
        printf("não encontrado!");
    printf("\nO tamanho da Lista :%d",size(lista));
    freeLista(lista);
}
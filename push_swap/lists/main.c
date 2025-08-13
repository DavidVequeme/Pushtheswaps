#include <stdio.h>

typedef struct s_lista
{
    struct s_list *next;
    struct s_list *last;
    int n;
    char a;

} t_lista;

typedef struct s_listb
{
    struct s_list *next;
    int n;
    char a;
    struct s_list *last;
} t_listb;


int a()
{
    printf("Hello");
    return 0;
}

int b()
{
    printf("World");
    return 1;
}
int main()
{
    printf("A %lu\n", sizeof(t_lista));    
    printf("B %lu\n", sizeof(t_listb));    

    if(a() | b())
    {

    }

}






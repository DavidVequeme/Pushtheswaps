/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:33:30 by dvidal            #+#    #+#             */
/*   Updated: 2025/09/01 19:15:21 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void push_swap(t_ab antonio, t_ab benedita)
// {
//     return ;
// }

void    ft_sort_int_tab(t_var *program, int size)
{
    int    i;
    int    j;
    int    tmp;

    i = 0;
    j = 0;
    size = size - 1;
    while (i < size)
    {
        while (j < size + 1)
        {
            if (program->arr_aux[i] > program->arr_aux[j])
            {
                tmp = program->arr_aux[i];
                program->arr_aux[i] = program->arr_aux[j];
                program->arr_aux[j] = tmp;
            }
            j++;
        }
        i++;
        j = i;
    }
}

void indexlist(t_var *program)
{
    int index;
    t_list *ref;

    ref = program->a.lst;
    index = 0;
    while(index < program->lstsize)
    {
        ft_printf("Current index %d \n",  index);
        if (ref && ref->n == program->arr_aux[index])
        {
            ref->n = index;
            index = 0;
            ref = ref->next;
            ft_printf("\n");
        }
        else
            index++;
    }
}

int init(t_var *program, int ac, char **av)
{
    int i;

    i = 1;
    program->a.lst = NULL;
    program->b.lst = NULL;
    program->b.size = 0;
    ft_printf("ac: %d\n", ac - 1);
    while(i < ac)
    {
        populatelist(program, av[i]);
        i++;  
    }
    program->lstsize = lst_size(program->a.lst);
    program->a.size = program->lstsize; 
    program->arr_aux = malloc(sizeof (int) * (program->lstsize + 1));
    chunck_set(program);
    if (program->arr_aux == NULL)
        return(0);
    return(1);
}
void sortlst(t_var *program)
{
    int i;
    t_list *ref;

    ref = program->a.lst;
    i = 0;
    while (ref != NULL)
    {
        program->arr_aux[i] = ref->n;
        ref = ref->next;
        i++;
    }
    ft_sort_int_tab(program, program->lstsize);
}

int main(int ac, char **av)
{
    t_var program;

    int i;
    i = 0;
    init(&program, ac, av);
    sortlst(&program);
    ft_printf("arr aux :");
    while (i < program.lstsize)
    {
        ft_printf("[%d]", program.arr_aux[i]);
        i++;
    }
    ft_printf("\n");
    indexlist(&program);
    dbg_print_stack(program);
    moves(&program);
    dbg_print_stack(program);
    ft_printf("\n");
    lst_clear(&program.a.lst);
    lst_clear(&program.b.lst);
    free(program.arr_aux);

}

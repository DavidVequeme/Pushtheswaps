/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:33:30 by dvidal            #+#    #+#             */
/*   Updated: 2025/08/27 16:30:17 by dvidal           ###   ########.fr       */
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

    ref = program->lst_a;
    index = 0;
    while(index < program->lstsize)
    {
        if (ref && ref->n == program->arr_aux[index])
        {
            ref->n = index;
            index = 0;
            ref = ref->next;
        }
        index++;
    }
}

int init(t_var *program, int ac, char **av)
{
    int i;

    i = 1;
    program->lst_a = NULL;
    program->lst_b = NULL;
    ft_printf("ac: %d\n", ac - 1);
    while(i < ac)
    {
        populatelist(program, av[i]);
        if (i == 1)
            program->head = program->lst_a;
        i++;  
    }
    program->lstsize = lst_size(program->lst_a);
    program->arr_aux = malloc(sizeof (int) * (program->lstsize + 1));
    if (program->arr_aux == NULL)
        return(0);
    ft_printf("aux arr:\n");
    return(1);
}
void sortlst(t_var *program)
{
    int i;
    t_list *ref;

    ref = program->lst_a;
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
    t_var *program;
    t_list *lstcpy;
    int i;
    i = 0;
    program = NULL;
    program = malloc(sizeof(t_var));
    init(program, ac, av);
    lstcpy = program->lst_a;
    sortlst(program);
    while(i < program->lstsize)
    {
        ft_printf("[%d]", program->arr_aux[i]);
        i++;
    }
    indexlist(program);
    program->lst_a = program->head;
    ft_printf("\nlist: ");
    while (program->lst_a != NULL)
    {
        ft_printf("[%d]", program->lst_a->n);
        program->lst_a = program->lst_a->next;
    }
    program->lst_a = program->head;
    push_b(program);
    dbg_print_stack(*program);
    push_b(program);
    push_b(program);
    dbg_print_stack(*program);
    swap_both(program);
    dbg_print_stack(*program);
    ft_printf("\n");
}

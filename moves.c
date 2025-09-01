/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:23:04 by dvidal            #+#    #+#             */
/*   Updated: 2025/09/01 19:18:28 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_b(t_var *program)
{
    t_list *temp_a;

    temp_a = program->a.lst;
    program->a.lst = program->a.lst->next;
    if(program->a.lst  != NULL)
        program->a.lst->prev = NULL;
    temp_a->next = program->b.lst;
    if(program->b.lst != NULL)
        program->b.lst->prev = temp_a;
    program->b.lst = temp_a;
    program->b.size++;
    program->a.size--;
}

void push_a(t_var *program)
{
    t_list *temp_b;

    temp_b = program->b.lst;
    program->b.lst = program->b.lst->next;
    if(program->b.lst  != NULL)
        program->b.lst->prev = NULL;
    temp_b->next = program->a.lst;
    if(program->b.lst != NULL)
        program->a.lst->prev = temp_b;
    program->a.lst = temp_b;
    program->a.size++;
    program->b.size--;
}

void rev_rot_a(t_var *program)
{
    t_list *last;

    last = lst_last(program->a.lst);
    last->prev->next = NULL;
    last->prev =NULL;
    last->next = program->a.lst;
    program->a.lst = last;
}

void rev_rot_b(t_var *program)
{
    t_list *last;

    last = lst_last(program->b.lst);
    last->prev->next = NULL;
    last->prev = NULL;
    last->next = program->b.lst;
    program->b.lst->prev = last; 
    program->b.lst = last;
    
}

void rot_a(t_var *program)
{
    t_list *first;

    first = program->a.lst;
    program->a.lst->next->prev = NULL;
    program->a.lst = first->next;
    first->prev = lst_last(program->a.lst);
    first->prev->next = first;
    first->next = NULL;
}

void rot_b(t_var *program)
{
    t_list *first;

    first = program->b.lst;
    program->b.lst->next->prev = NULL;
    program->b.lst = first->next;
    first->prev = lst_last(program->b.lst);
    first->prev->next = first;
    first->next = NULL;
}

void swap_b(t_var *program)
{
    int  ref;

    ref = program->b.lst->n;
    program->b.lst->n = program->b.lst->next->n;
    program->b.lst->next->n = ref;

}

void swap_a(t_var *program)
{
    int  ref;

    ref = program->a.lst->n;
    program->a.lst->n = program->a.lst->next->n;
    program->a.lst->next->n = ref;

}

void swap_both(t_var *program)
{
    swap_a(program);
    swap_b(program);
}

void rot_both(t_var *program)
{
    rot_a(program);
    rot_b(program);
}

void rev_rot_both(t_var *program)
{
    rev_rot_a(program);
    rev_rot_b(program);
}

int max(t_var *program)
{
    int max;
    int i;
    t_list *ref;

    ref = program->a.lst;
    i = 0;
    max = 0;
    while (ref != NULL)
    {
        if (ref->n > max)
            max = ref->n;
        ref = ref->next;
        i++;
    }
    return(max);
}

// fazer uma funcao que checa bit a bit ate a casa binaria, a ultima casa do maior numero (bit_lng) para decidir oque fazer  

void chunck_set(t_var *program)
{
    if (program->lstsize > 400)
        program->chunck_size = 30;
    else if (program->lstsize >= 100)
        program->chunck_size = 10;
    else if (program->lstsize >= 50)
        program->chunck_size = 5;
    else if (program->lstsize >= 10)
        program->chunck_size = program->lstsize / 4;
    else
        program->chunck_size = 4;
}



void moves(t_var *program)
{
    int min;
    int max;

    ft_printf("Chunck size %d\n",program->chunck_size);
    min = program->chunck_size;
    max = min * 2;
    while (program->a.size > 3)
    {
        dbg_print_stack(*program);
        if (program->a.lst->n < max)
        {
            if (program->a.lst->n <= min)
            {
                ft_printf("Pushed min\n");
                push_b(program);
                if (program->b.size > 1)
                    rot_b(program);
            }
            else
                push_b(program);
        }
        else
            rot_a(program);
        if (program->a.size == (program->lstsize - max))
        {
            min += max;
            max += max;
            ft_printf("Chunk up\n");
        } 
        
    }
}

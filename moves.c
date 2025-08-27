/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:23:04 by dvidal            #+#    #+#             */
/*   Updated: 2025/08/27 16:42:39 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_b(t_var *program)
{
    t_list *temp_a;

    temp_a = program->lst_a;
    program->lst_a = program->lst_a->next;
    if(program->lst_a  != NULL)
        program->lst_a->prev = NULL;
    temp_a->next = program->lst_b;
    if(program->lst_b != NULL)
        program->lst_b->prev = temp_a;
    program->lst_b = temp_a;
}

void push_a(t_var *program)
{
    t_list *temp_b;

    temp_b = program->lst_b;
    program->lst_b = program->lst_b->next;
    if(program->lst_b  != NULL)
        program->lst_b->prev = NULL;
    temp_b->next = program->lst_a;
    if(program->lst_b != NULL)
        program->lst_a->prev = temp_b;
    program->lst_a = temp_b;
}

void rev_rot_a(t_var *program)
{
    t_list *last;

    last = lst_last(program->lst_a);
    last->prev->next = NULL;
    last->prev =NULL;
    last->next = program->lst_a;
    program->lst_a = last;
}

void rev_rot_b(t_var *program)
{
    t_list *last;

    last = lst_last(program->lst_b);
    last->prev->next = NULL;
    last->prev =NULL;
    last->next = program->lst_b;
    program->lst_b = last;
}

void rot_a(t_var *program)
{
    t_list *first;

    // primeiro para ultimo
    first = program->lst_a;
    program->lst_a->next->prev = NULL;
    program->lst_a = first->next;
    first->prev = lst_last(program->lst_a);
    first->prev->next = first;
    first->next = NULL;
}

void rot_b(t_var *program)
{
    t_list *first;

    // primeiro para ultimo
    first = program->lst_b;
    program->lst_b->next->prev = NULL;
    program->lst_b = first->next;
    first->prev = lst_last(program->lst_b);
    first->prev->next = first;
    first->next = NULL;
}

void swap_b(t_var *program)
{
    int  ref;

    ref = program->lst_b->n;
    program->lst_b->n = program->lst_b->next->n;
    program->lst_b->next->n = ref;

}

void swap_a(t_var *program)
{
    int  ref;

    ref = program->lst_a->n;
    program->lst_a->n = program->lst_a->next->n;
    program->lst_a->next->n = ref;

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

int biggest_bit(int n)
{
    int l;

    l = 0;
    if (n == 0)
        return(0);
    while (n > 0)
    {
        n >>= 1;
        l++;
    }
    return(l);
}

void moves(t_var *program)
{
    int i;

    i = 
}

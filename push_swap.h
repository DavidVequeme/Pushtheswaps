/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:23:53 by dvidal            #+#    #+#             */
/*   Updated: 2025/08/27 16:32:18 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "lists/list.h"
#include "printf/ft_printf.h"
#include "libft/libft.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct s_var
{
    t_list *lst_a;
    t_list *lst_b;
    t_list *head;
    int *arr_aux;
    int i;
    int lstsize;

}   t_var;
int ft_isalpha(int c);
int ft_issign(int c);
int ft_leng(char *s);
void ft_close();
char	**ft_split(char const *s, char c);
int populatelist(t_var *program, char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t ft_slen(const char *s);
void push_b(t_var *program);
void push_a(t_var *program);
void rev_rot_a(t_var *program);
void rev_rot_b(t_var *program);
void rev_rot_both(t_var *program);
void rot_a(t_var *program);
void rot_b(t_var *program);
void rot_both(t_var *program);
void swap_b(t_var *program);
void swap_a(t_var *program);
void swap_both(t_var *program);
void    dbg_print_stack(t_var program);

# endif
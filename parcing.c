/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:44:18 by dvidal            #+#    #+#             */
/*   Updated: 2025/09/01 18:53:41 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
int ft_issign(int c)
{
    if (c == '-' || c == '+')
        return(1);
    else
        return (0);
}
long ft_atol(char *str)
{
    int index;
    long sign;
    long result;

    index = 0;
    sign = 1;
    result = 0;
    while (str[index] == ' ' || (str[index] >= '\t' && str[index] <= '\r'))
        index++;
    if (str[index] == '-' || str[index] == '+')
    {
        if (str[index + 1] == '\0')
            ft_close();
        if (str[index] == '-')
            sign = -1;
        index++;
    }
    while (str[index] >= '0' && str[index] <= '9')
    {
        result = result * 10 + (str[index] - '0');
        index++;
    }
    return(sign * result);
}

int isvalid_input(char *s)
{
    int i;

    i = 0;
    if (ft_issign(s[0]))
        i++;
    while(s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return(0);
        i++;
    }
    return(1);
}
int isvalid_number(t_var *program, char *s, long *n)
{
    int i;
    t_list *temp;

    i = 0;
    *n = ft_atol(s);
    temp = program->a.lst;
    if (*n > INT_MAX || *n < INT_MIN)
        return (0);
    while(temp != NULL)
    {
        if (temp->n == *n)
            return(0);
        temp = temp->next;
    }
    return(1);
}
void freesplit(char **array)
{
    int i;

    i = 0;
    while (array[i] != NULL)
    {
        free(array[i]);
        i++;
    }
    free(array);
}
int populatelist(t_var *program, char *s)
{
    int i;
    char **array;
    long num;

    i = 0;
    num = 0;
    array = ft_split(s, ' ');
    if (!array)
        return(0);
    while (array[i])
    {
        if (!isvalid_input(array[i]))
            return(ft_printf("Error on input (%s)\n", array[i]),0);
        if (!isvalid_number(program, array[i], &num))  
            return(ft_printf("Error on number (%s)\n", array[i]),0);
        lst_add_back(&(program->a.lst), num);
        i++;
    }
    freesplit(array);
    return(1);
}
//void radix_sort(t_list **antonio, t_list **benedita, )
void ft_close()
{
    ft_printf("ERROR\n");
    exit(0);
}
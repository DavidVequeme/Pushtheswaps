

#include "push_swap.h"

static void    printcontent(t_list *lst)
{
    if (lst != NULL)
        ft_printf("%d", lst->n);
}


void	dbg_print_stack(t_var program)
{
	t_list	*a;
	t_list	*b;

	a = program.lst_a;
	b = program.lst_b;
	ft_printf("\n\nA	|	B\n");
	ft_printf("____________________________\n");
	while (a != NULL || b != NULL)
	{
		printcontent(a);
		ft_printf("	|	");
		printcontent(b);
		ft_printf("\n");
		if (a != NULL)
			a = a->next;
		if (b != NULL)
			b = b->next;
	}
	ft_printf("____________________________\n");
}


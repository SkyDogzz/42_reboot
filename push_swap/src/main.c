#include "../include/push_swap.h"

bool	is_sorted(t_dlist *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}
void	sort_three(t_dlist **inst, t_stack *stack)
{
	int	a = *(int *)stack->a->content;
	int	b = *(int *)stack->a->next->content;
	int	c = *(int *)stack->a->next->next->content;

	if (a > b && b < c && a < c)
		execsa(inst, stack); // 2 1 3
	else if (a > b && b > c)
	{
		execsa(inst, stack); // 3 2 1 → 2 3 1
		execrra(inst, stack); // → 1 2 3
	}
	else if (a > b && b < c && a > c)
		execra(inst, stack); // 3 1 2 → 1 2 3
	else if (a < b && b > c && a < c)
	{
		execsa(inst, stack); // 1 3 2 → 3 1 2
		execra(inst, stack); // → 1 2 3
	}
	else if (a < b && b > c && a > c)
		execrra(inst, stack); // 2 3 1 → 1 2 3
}
static t_dlist	*find_min(t_dlist *stack)
{
	t_dlist	*min = stack;

	while (stack)
	{
		if (*(int *)stack->content < *(int *)min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
int	get_index(t_dlist *stack, t_dlist *node)
{
	int i = 0;

	while (stack)
	{
		if (stack == node)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1); // ne devrait jamais arriver
}

void	sort_five(t_dlist **inst, t_stack *stack)
{
	t_dlist *min;

	while (ft_dlstsize(stack->a) > 3)
	{
		min = find_min(stack->a);
		// Place le minimum tout en haut pour le push vers B
		while (stack->a != min)
		{
			// Choisit la rotation la plus courte (avant ou arrière)
			if (get_index(stack->a, min) <= ft_dlstsize(stack->a) / 2)
				execra(inst, stack);
			else
				execrra(inst, stack);
		}
		execpb(inst, stack); // Push vers B
	}
	// Trie les 3 restants
	sort_three(inst, stack);

	// Remonte les 2 plus petits
	execpa(inst, stack);
	execpa(inst, stack);
}



int	main(int argc, char **argv)
{
	t_stack	stack = {0};
	t_dlist	*inst = NULL;

	if (!ft_parse_args(argc, argv, &stack) || ft_isdup(&stack.a))
		write(2, "Error\n", 6);
	else if (!is_sorted(stack.a))
	{
		if (ft_dlstsize(stack.a) < 3)
			sort_three(&inst, &stack);
		else if (ft_dlstsize(stack.a) < 5)
			sort_five(&inst, &stack);
	}

	print_instructions(inst);

	ft_dlstclear(&inst, free);
	ft_dlstclear(&stack.a, free);
	ft_dlstclear(&stack.b, free);
	return (0);
}


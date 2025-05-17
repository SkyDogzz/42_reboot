#include "../../include/push_swap.h"

void	execpa(t_dlist **inst, t_stack *stack)
{
	push(&stack->a, &stack->b);
	add_instruction(inst, "pa");
}

void	execpb(t_dlist **inst, t_stack *stack)
{
	push(&stack->b, &stack->a);
	add_instruction(inst, "pb");
}

void	execsa(t_dlist **inst, t_stack *stack)
{
	swap(&stack->a);
	add_instruction(inst, "sa");
}

void	execsb(t_dlist **inst, t_stack *stack)
{
	swap(&stack->b);
	add_instruction(inst, "sb");
}

void	execss(t_dlist **inst, t_stack *stack)
{
	swap(&stack->a);
	swap(&stack->b);
	add_instruction(inst, "ss");
}

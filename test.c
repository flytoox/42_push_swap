void	print_lst(t_stack *head)
{
	while(head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}


int	main(int argc, char *argv[])
{
	int		*tab;
	t_stack	*top_a;
	t_stack	*top_b;

	top_a = NULL;
	top_b = NULL;
	tab = malloc((argc - 1) * 4);
	while (--argc)
		add_stack_back(&top_a, ft_stack_new(ft_atoi(*(++argv))));
	printf("or : ");
	print_lst(top_a);
	sa(&top_a);
	printf("\nsa : ");
	print_lst(top_a);
	printf("\npb : (a)");
	pb(&top_a, &top_b);
	pb(&top_a, &top_b);
	pb(&top_a, &top_b);
	print_lst(top_a);
	printf("\npb : (b)");
	print_lst(top_b);
	rr(top_a, top_b);
	printf("\nrr :(a) ");
	print_lst(top_a);
	printf("\nrr :(b) ");
	print_lst(top_b);
	rrr(top_a, top_b);
	printf("\nrrr :(a) ");
	print_lst(top_a);
	printf("\nrr :(b) ");
	print_lst(top_b);
	sa(&top_a);
	printf("\nsa : ");
	print_lst(top_a);
	printf("\npa : (a)");
	pa(&top_a, &top_b);
	pa(&top_a, &top_b);
	pa(&top_a, &top_b);
	print_lst(top_a);
	printf("\npa : (b)");
	print_lst(top_b);
}	

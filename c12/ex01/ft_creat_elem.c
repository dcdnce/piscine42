#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
			return (NULL);
	(*elem).data = data;
	(*elem).next = NULL;
	return (elem);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	(*elem).next = *begin_list;// new_elem points to addr of old first elem || no if, at worst it points to NULL
	*begin_list = elem;       // *begin list points to addr of new first elem
}

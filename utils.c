#include "so_long.h"

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

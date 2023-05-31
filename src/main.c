#include <stdio.h>
#include "mlx.h"
#include "libft.h"

int	main(void)
{
	void	*mlx;
	void	*window;

	printf("~cub3d~\n");
	mlx = mlx_init();
	window = mlx_new_window(mlx, 400, 400, "cub3d");
	(void)window;
	mlx_loop(mlx);
	return (0);
}

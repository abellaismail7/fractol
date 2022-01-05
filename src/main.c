#include <math.h>
#include "mlx.h"

int main ()
{
	void *ptr = mlx_init();
	void *win = mlx_new_window(ptr, 1200, 1200, "test");
	mlx_loop(ptr);

	mlx_destroy_window(ptr,win);
	mlx_destroy_display(ptr);
	return 0;
}

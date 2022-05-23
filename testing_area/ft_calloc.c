#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	//size_t	index;
	void	*output;

	//index = 0;
	output = malloc(count * size);
	ft_bzero(output, count);
	return (output);
}

int main(void)
{
	int n;

	n = 5;

    int *A;

    // int *A = (int*)calloc(n,sizeof(int));
    // for (int i = 0; i < n; i++)
    // {
    //     // A[i] = i+1;
    //     printf("%d ", A[i]);
    // }

    A = (int*)ft_calloc(n,sizeof(int));
    for (int i = 0; i < n; i++)
    {
        // A[i] = i+1;
        printf("%d ", A[i]);
    }

	free(A);

	return (0);
}
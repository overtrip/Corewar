#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

/*
**	Comprendre pourquoi write ecrit bien dans ret comme il faut
*/

int main(int argc, const char *argv[])
{
	int	ret;
	char	tmp[400];
	int test = 543;

	if (argc == 2)
	{
		// Init tmp sur 400 octets
		bzero(tmp, 400);
		// Ecrit caca sur 4 octets
		strncpy(tmp, "caca", 4);
		// Ecrit caca sur 4 octets decale de + 20 octets
		strncpy(tmp+20, "caca", 4);
		// Ecrit caca sur 4 octets decale de + 200 octets
		strncpy(tmp+200, "caca", 4);
		ret = open(argv[1], O_WRONLY);
		// Ecrit le contenu de tmp sur 400 octets
		write(ret, tmp, 400);
		// Ecrit test (543) sur 4 octets (size of int) mais au rendu -> 1f 02
		// au lieu de 02 1f (little endian)
		// trouver comment inversser ca
		write(ret, &test, 4);
	}
	return 0;
}

/*
**	Rendu final
*/

//00000000  63 61 63 61 00 00 00 00  00 00 00 00 00 00 00 00  |caca............|
//00000010  00 00 00 00 63 61 63 61  00 00 00 00 00 00 00 00  |....caca........|
//00000020  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
//*
//000000c0  00 00 00 00 00 00 00 00  63 61 63 61 00 00 00 00  |........caca....|
//000000d0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
//*
//00000190  1f 02 00 00                                       |....|
//00000194

/*
** raising
** File description:
** Raise a number nbr to power n
** a fonction for my_getnbr
*/


/// @brief Raise a numbr nbr to n power
/// @param nbr 
/// @param n 
/// @return nbr ** n
int raising(int nbr, int n)
{
    int i = 1;
    int nb = nbr;

    if (n == 0)
        return (1);
    while (i < n)
    {
        nb *= nbr;
        i++;
    }
    return (nb);
}

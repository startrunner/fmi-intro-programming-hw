#include <cstring>

char correspondingNucleotide(char of)
{
    return(
        (of == 'A') ? 'T' :
        (of == 'T') ? 'A' :
        (of == 'C') ? 'G' :
        (of == 'G') ? 'C' :
        '\0'
    );
}

bool isReverseDNAPalindrome(char dna[1000])
{
    const size_t length = strlen(dna);
    if (length < 2)return false;

    const size_t halfLength = length / 2;
    bool isReverseDnaPalindrome = true;

    for (int i = 0; i <= halfLength && isReverseDnaPalindrome; i++)
    {
        char correspondingToIth = correspondingNucleotide(dna[i]);
        char ithFromEnd = dna[length - 1 - i];

        isReverseDnaPalindrome &= (correspondingToIth == ithFromEnd);
    }

    return isReverseDnaPalindrome;
}
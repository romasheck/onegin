#include "R1_func.h"

int swap_smth_big ( void *address_frst, void *address_scnd, int SIZE )
{
	assert ( address_frst != NULL );
    assert ( address_scnd != NULL );

	//uint64_t hui;

	for ( int i = 0; i < SIZE / 8; ++i )
	{
		uint64_t tmp_s8 = * (( unsigned long int* ) address_frst + i );
		* (( unsigned long int* ) address_frst + i) = * (( unsigned long int* ) address_scnd + i);
		* (( unsigned long int* ) address_scnd + i) = tmp_s8;
	}
	char tmp_s1;

	for ( int i = SIZE - (SIZE % 8); i < SIZE; ++i )
	{
		tmp_s1 = * ((char*) address_frst + i );
		* ((char*) address_frst + i ) = * ((char*) address_scnd + i);
		* ((char*) address_frst + i ) = tmp_s1;
	}
	return 1;
}

int swap_adr_char   ( char **adr_frst, char **adr_scnd )
{
	char* tmp = *adr_frst;
	*adr_frst = *adr_scnd;
	*adr_scnd = tmp;

	return 1;
}
#include "oneginlib.h"

int find_str_num_and_prepare_buffer (char* buffer, int size)
{
	assert (buffer != NULL);
    assert (size > 1);
	
	int str_num = 0;

	for (int i = 0; i < size - 1; ++i)
	{
		if (buffer[i] == '\n')
		{	
			buffer[i] = '\0';
			++str_num;
		} 
	}

	buffer [size - 1] = '\0';
	buffer [size] = EOF;

	return str_num + 1;
}

int make_data_index (char* buffer, const int onegin_size, const int str_num, char** Index) 
{
    assert (buffer != NULL);
    assert (str_num > 1);
    assert (Index != NULL);

	int cntr_Index = 1;
	*Index = buffer;

	for (int i = 1; i < onegin_size-1; ++i)
	{
		if (*(buffer + i) == '\0')
		{
			*(Index + cntr_Index) = buffer + i + 1;
			++cntr_Index;
		}
	}
	if (str_num != cntr_Index)
	{
		printf ("%d  %d", str_num, cntr_Index);
		//assert (str_num == cntr_Index);
	}
	return 1;
}

int print_onegin (char** Index, const int str_num, FILE* file_out_stream)
{
    assert (Index != NULL);
    assert (str_num > 1);
    assert (file_out_stream != NULL);

	for (int i = 0; i < str_num; ++i)
	{ 
		int j = 0;
		while (*(Index [i] + (char)j) != '\0')
		{
			fprintf (file_out_stream,"%c", *(Index[i] + (char)j));
			++j;
		}
		fprintf (file_out_stream,"\n");
		
		//printf("%d\n", Index [i]);
	}
	return 1;
}

int sort_onegin (char** Index, int str_num) //sSSSSSSSSSSSSSSSSSSS$$$$$$$$$$$$$$$$$$SSSshit
{
    assert (Index != NULL);
    assert (str_num > 1);
PRINT_LINE
    int middle = str_num / 2;
    int i = 0, j = str_num;

	PRINT_LINE

    while(i <= j)
    {PRINT_LINE
        while(compare_str (Index[i], Index[middle]) == S_scnd_more_frst || compare_str (Index [i], Index [middle]) == S_equal)
        {   PRINT_LINE 
			i++;
			PRINT_LINE
		}
		printf ("jopa");
		PRINT_LINE
		printf ("%c", **(Index + 2));
		printf ("jopa");
		PRINT_LINE
		s_print (Index [j]);
		printf ("%c", **(Index + j));
		s_print (Index [middle]);
		PRINT_LINE
        while(compare_str (Index[j], Index[middle]) == S_frst_more_scnd || compare_str (Index [i], Index [middle]) == S_equal)
		{
            j--; 
			PRINT_LINE
		}
		PRINT_LINE
        if(i <= j)
        {
            swap_adr_char (Index + i, Index + j);
            i++;
            j--;
        }
    }
	PRINT_LINE
    if(j > 0)
    {    
		sort_onegin (Index, j);
	}
	PRINT_LINE
    if(str_num > i)
    {    
		sort_onegin (Index + i, str_num - i);
	}
	PRINT_LINE
	return 1;
}


int sort_onegin_reverse (char** Index, int str_num) //SSSSSS$$$$$$$$$$$$$$SSSSSSSSSSSshit
{
    assert (Index != NULL);
    assert (str_num > 1);

    int middle = str_num / 2;
    int i = 0, j = str_num;

    while(i <= j)
    {
        while(compare_str_reverse (Index[i], Index[middle]) == S_scnd_more_frst)
        {    
            i++;
        }
        while(compare_str_reverse (Index[j], Index[middle]) == S_frst_more_scnd)
        {    
            j--;
        }
        if(i <= j)
        {
            swap_adr_char (Index + i, Index + j);
            i++;
            j--;
        }
    }
    if(j > 0)
	{
        sort_onegin (Index, j);
	}
    if(str_num > i)
    {    
		sort_onegin (Index + i, str_num - i);
	}
	return 1;
}

int bubble_sort_onegin (char** Index, int str_num) 
{
	for (int i = 0; i < str_num - 1; ++i)
		for (int j = 0; j < str_num - i; ++j)
			if ( compare_str (Index [j], Index [j + 1]) == S_frst_more_scnd)
				swap_adr_char (Index + j, Index + j + 1);
}

int bubble_sort_onegin_reverse (char** Index, int str_num) // ptr func compare, one bubble_sort 
{
	for (int i = 0; i < str_num - 1; ++i)
	{
		for (int j = 0; j < str_num - i - 1; ++j)
		{	if ( compare_str_reverse (Index [j], Index [j + 1]) == S_frst_more_scnd)
			{
				//PRINT_LINE
				swap_adr_char (Index + j, Index + j + 1);
			}
		}
	}
}

int copy_massive_adr_char (char** Index, char** Indexyatina, const int str_num)
{
	if (str_num < 1)
	{
		printf ("error problem with str_num");
		return 0;
	}
	if (Index == NULL)
	{
		printf ("error problem wih adress Index");
		return 0;
	}
	if (Indexyatina == NULL)
	{
		printf ("error problem with adress Indexyatina");
		return 0;
	}
	for (int i = 0; i < str_num; ++i)
	{
		Indexyatina [i] = Index [i];
	}
	return 1;
}

int fsize (FILE* file_ptr)
{
	struct stat file_size;
    fstat (fileno(file_ptr), &file_size);
	return (int)file_size.st_size;
}

int print_buffer (const char* buffer, const int size_onegin, FILE* file_out_stream)
{
	for (int i = 0; i < size_onegin; ++i)
	{
		///*
		if (*(buffer + i) == '\0')
		{
			fprintf (file_out_stream, "\n");
			//printf ("%d ", i);
		}
		else fprintf (file_out_stream,"%c", *(buffer + i));
		//*/
		//fprintf (file_out_stream, "%s\n", *(buffer+i));
	}

	return 1;
}

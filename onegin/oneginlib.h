#ifndef ONEGINLIB_H_INCLUDED
#define ONEGINLIB_H_INCLUDED

#include "s_func.h"
#include "R1_func.h"
#include <sys\stat.h>

#define PRINT_LINE printf("I am at line %d in func %s\n", __LINE__, __func__);

enum error_flag
{
    file_stream_error,
    buffer_memory_error,
    fread_error
};
/*
struct 
{
     data 
};
*/

int bubble_sort_onegin_reverse             (char** Index, int str_num); 

int bubble_sort_onegin                     (char** Index, int str_num);

int sort_onegin_reverse                    (char** Index, int str_num);

int sort_onegin                            (char** Index, int str_num);

int print_onegin                           (char** Index, const int str_num, FILE* file_out_stream);

int make_data_index                        (char* buffer, const int onegin_size, const int str_num, char** Index);

int find_str_num_and_prepare_buffer        (char* buffer, const int size);

int copy_massive_adr_char                  (char** Index, char** Indexyatina, const int str_num);

int fsize                                  (FILE* file_ptr);

int print_buffer                           (const char* buffer, const int size_onegin, FILE* file_out_stream);

#endif
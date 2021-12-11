#include "oneginlib.h"

int main ()
{
    FILE* file_in_stream = fopen ("onegIN.txt", "r");
    if (file_in_stream == NULL)
    {
        printf("File stream error!");
        return 0;
    } 
    int file_size = fsize (file_in_stream);

    char* buffer = (char*) calloc (file_size, sizeof(char));
    if (buffer == NULL)
    {
        printf("buffer memory Error");
        return 0;
    }

    int onegin_size = fread (buffer, sizeof(char), file_size , file_in_stream);
    if (onegin_size == 0)
    {
        printf("fread Error");
        return 0;
    }
    int str_number = find_str_num_and_prepare_buffer (buffer, onegin_size);

    char** Index = (char**)calloc(str_number, sizeof(char*)); 
    make_data_index (buffer, onegin_size, str_number, Index);

    FILE* file_out_stream = fopen ("onegOUT.txt", "w");
    if (file_out_stream == NULL)
    {
        printf("File stream error!");
        return 0;
    }
    //int num_symbol_in_onegOUT = fprintf (file_out_stream, "jopa");//db
    //printf ("%d\n", num_symbol_in_onegOUT);
//debug
/*
    FILE* test_file_out_stream = fopen ("testOUT.txt", "a");
    if (test_file_out_stream == NULL)
    {
        printf("File test stream error!");
        return 0;
    }
    //fprintf (test_file_out_stream, "jopa");//db
    //fprintf (file_out_stream, "jopa");//db
*/
//

    //PRINT_LINE//db
    bubble_sort_onegin  (Index, str_number - 1);
    fprintf (file_out_stream, "\n");
    print_onegin (Index, str_number, file_out_stream);
    fprintf (file_out_stream, "\n");
    //PRINT_LINE//db
    bubble_sort_onegin_reverse (Index, str_number);
    //PRINT_LINE//db
    print_onegin (Index, str_number, file_out_stream);
    //PRINT_LINE//db
    fprintf (file_out_stream, "\n");
    //PRINT_LINE//db
    //fprintf (file_out_stream, "jopa");//db

    print_buffer (buffer, onegin_size, file_out_stream);
    //PRINT_LINE
    //num_symbol_in_onegOUT = fprintf (file_out_stream, "jopa");//db
    //printf ("%d\n", num_symbol_in_onegOUT);
    free (buffer);
    free (Index);
    fclose (file_out_stream);
    fclose (file_in_stream);
    return 0;
}
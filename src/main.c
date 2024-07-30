#include <stdio.h>
#include "pitx.h"

int main(){

    Header header = {MAGIC_NUMBER, VERSION};
    Metadata metadata = {0,0};
    FILE *file = fopen("example.pitx", "wb");

    if(!file){
        perror("Error opening file\n");
        return 1;
    }
    
    if(write_header(file, &header) != 0){
        perror("Error writing header\n");
        fclose(file);
        return 1;
    }

    if(write_metadata(file, &metadata) != 0){
        perror("Error writing metadata\n");
        fclose(file);
        return 1;
    }

    return 0;
}
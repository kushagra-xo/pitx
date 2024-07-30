#include <stdio.h>
#include <string.h>
#include "pitx.h"

int main(){

    const char* text = "A beautiful sunset over the mountains.";
    unsigned int text_length = strlen(text);
    Metadata metadata = {text_length,0};
    Header header = {MAGIC_NUMBER, VERSION};
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
    
    if(write_text(file, text, text_length) != 0) {
        perror("Error writing text\n");
        fclose(file);
        return 1;
    }
    fclose(file);
    return 0;
}
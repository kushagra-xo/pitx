#include <stdio.h>
#include "pitx.h"

int write_header(FILE *file, Header *header){
    if (fwrite(header, sizeof(Header), 1, file) != 1) return -1;
    return 0;
}

int write_metadata(FILE *file, Metadata *metadata){
    if (fwrite(metadata, sizeof(Metadata), 1, file) != 1) return -1;
    return 0;
}

int write_text(FILE *file, const char *text, unsigned int length){
    if (fwrite(text, sizeof(char), length, file) != length) return -1;
    return 0;
}

int write_image(FILE *file, const void *image, unsigned int length) {
    if (fwrite(image, sizeof(char), length, file) != length) return -1;
    return 0;
}
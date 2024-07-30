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
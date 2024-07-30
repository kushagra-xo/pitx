#ifndef PITX_H
#define PITX_H

#define MAGIC_NUMBER 0x50495458 // "PITX"
#define VERSION 0x0100          // Version 1.0

typedef struct {
    unsigned int magic_number;
    unsigned int version;
} Header;

typedef struct {
    unsigned int image_length;
    unsigned int text_length;
} Metadata;

int write_header(FILE *file, Header *header);
int write_metadata(FILE *file, Metadata *metadata);

#endif // PITX_H
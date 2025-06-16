#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BitStream {
    char bit;
    struct BitStream* next;
} BitStream;

BitStream* create_bit_stream(char root_bit) {
    BitStream* bt = malloc(sizeof(BitStream));
    assert(bt != NULL);
    
    bt->bit = root_bit;
    bt->next = NULL;
    return bt; 
}

void bit_stream_append(BitStream* root, char bit) {
    BitStream* current = root;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = create_bit_stream(bit);
}

void free_bit_stream(BitStream* root) {
    BitStream* current = root;
    while (current != NULL) {
        BitStream* next = current->next;
        free(current);
        current = next;
    }
}

BitStream* gamma_encode(uint8_t num) {
    if (num == 0) {
        return NULL;
    }

    int prefix_size = (int)log2(num);
    BitStream* stream = create_bit_stream(0); 
    
    for (int i = 1; i < prefix_size; i++) {
        bit_stream_append(stream, 0);
    }

    bit_stream_append(stream, 1);

    for (int i = prefix_size - 1; i >= 0; i--) {
        bit_stream_append(stream, num >> i & 1);
    }
   

    return stream;
}

void show_bit_stream(BitStream* stream) {
    if (stream == NULL) {
        printf("Empty bit stream\n");
        return;
    }
    
    BitStream* current = stream;
    int count = 0;
    
    printf("Bit stream: ");
    while (current != NULL) {
        printf("%d", current->bit);
        current = current->next;
        count++;
    }
    printf("\nTotal bits: %d\n", count);
}

int main() {
    // Teste com o número 5 (deveria ser 00101)
    BitStream* encoded_5 = gamma_encode(5);
    show_bit_stream(encoded_5);
    free_bit_stream(encoded_5);
    
    // Teste com o número 14 (deveria ser 0001110)
    BitStream* encoded_14 = gamma_encode(14);
    show_bit_stream(encoded_14);
    free_bit_stream(encoded_14);
    
    return 0;
}

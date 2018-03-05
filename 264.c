#include <stdio.h>

typedef struct st_card{
    int color;
    int number;
}card;

#define NUM_CARDS 54 

int main(void)
{
    int K;
    int order[NUM_CARDS];
    int i, j;
    
    char color_char[5] = {'S', 'H', 'C', 'D', 'J'};
    card card_tile_main[NUM_CARDS];
    card card_tile_aux[NUM_CARDS];
    card *card_tile_current = card_tile_main;	
    card *card_tile_previous = card_tile_aux;
    
    scanf("%d\n", &K);
    
    for(i=0; i<NUM_CARDS; i++){
        scanf("%d", order+i);
    }

    for(j=0; j<NUM_CARDS; j++){
        (card_tile_current+j)->color = j/13;
        (card_tile_current+j)->number = j%13;
    }	
    
    card_tile_current = card_tile_aux;
    card_tile_previous = card_tile_main;

    for(i=0; i<K; i++){
        for(j=0; j<NUM_CARDS; j++){
            (card_tile_current+order[j]-1)->color = 
                (card_tile_previous+j)->color;
            (card_tile_current+order[j]-1)->number = 
                (card_tile_previous+j)->number;
        }	
        
        card_tile_current = 
            (card_tile_main == card_tile_current) ? 
             card_tile_aux : card_tile_main;
        card_tile_previous = 
            (card_tile_aux == card_tile_previous) ?
             card_tile_main : card_tile_aux;
    }

    for(i=0; i<NUM_CARDS-1; i++){
        
        printf("%c%d ", 
            color_char[(card_tile_previous+i)->color],
            1+(card_tile_previous+i)->number);
    }	
    
    printf("%c%d", 
        color_char[(card_tile_previous+NUM_CARDS-1)->color],
        1+(card_tile_previous+NUM_CARDS-1)->number);

    return 0;	
}

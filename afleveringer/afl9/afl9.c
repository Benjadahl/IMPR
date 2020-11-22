#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define cardsAmount 55

typedef enum {clubs, diamonds, hearts, spades, joker} cardType;
typedef enum {jack = 11, queen, king, ace} cardRank;

typedef struct card
{
  cardType type;
  cardRank rank;
} card;

void shuffle(card cards[], int amount, int types, int minRank, int maxRank);
void printCards (card cards[], int amount);
void printCard (card theCard);
int compareCards(const void* c1, const void* c2);

int main (void) {
  card cards[cardsAmount];

  srand(time(NULL));

  shuffle(cards, cardsAmount, spades, 2, ace);

  printf("Unsorted cards:\n");
  printCards(cards, cardsAmount);

  qsort(cards, cardsAmount, sizeof(card), compareCards);
  
  printf("\nSorted cards:\n");
  printCards(cards, cardsAmount);

  return 0;
}

void shuffle(card cards[], int amount, int types, int minRank, int maxRank) {
  int i = 0,
      t = 0,
      r = 2;

  for (i = 0; i < amount; i++) {
    cards[i].rank = 0;
  }

  for (t = 0; t <= types; t++) {
    for (r = minRank; r <= maxRank; r++) {
      int rndIndex = rand() % amount;
      
      while (cards[rndIndex].rank != 0) {
        rndIndex = (rndIndex + 1) % amount;
      }

      cards[rndIndex].type = t;
      cards[rndIndex].rank = r;
    }
  }

  for (i = 0; i < amount; i++) {
    if (cards[i].rank == 0) {
      cards[i].type = joker;
    }
  }
}

void printCards (card cards[], int amount) {
  int i = 0;
  
  for (i = 0; i < amount; i++) {
    printCard(cards[i]);
    printf(" ");
    if ((i + 1) % 4 == 0) {
      printf("\n");
    }
  }
  printf("\n");
}

void printCard (card theCard) {
  printf(
    "{Type: %d, Rank: %d}", 
    theCard.type, theCard.rank
  );
}

int compareCards(const void* c1, const void* c2) {
  card *card1 = (card *) c1;
  card *card2 = (card *) c2;
  int typeDiff = card1->type - card2->type;
  int rankDiff = card1->rank - card2->rank;

  if (typeDiff != 0) {
    return typeDiff;
  } else {
    return rankDiff;
  }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define cardsAmount 55
#define space 10

typedef enum {clubs, diamonds, hearts, spades, joker} cardType;
typedef enum {jack = 11, queen, king, ace} cardRank;

typedef struct card
{
  cardType type;
  cardRank rank;
} card;

void shuffle(card cards[], int amount, int types, int minRank, int maxRank);
void printCards (card cards[], int amount, int spacing);
int printCard (card theCard);
int compareCards(const void* c1, const void* c2);

int main (void) {
  card cards[cardsAmount];

  srand(time(NULL));

  shuffle(cards, cardsAmount, spades, 2, ace);

  printf("Unsorted cards:\n");
  printCards(cards, cardsAmount, space);

  qsort(cards, cardsAmount, sizeof(card), compareCards);
  
  printf("\nSorted cards:\n");
  printCards(cards, cardsAmount, space);

  return 0;
}

/* Add a deck of cards randomly to a card array */
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

/* Print an array of cards nicely formatted */
void printCards (card cards[], int amount, int spacing) {
  int i = 0,
      j = 0;
  
  for (i = 0; i < amount; i++) {
    int printed = printCard(cards[i]);
    for (j = printed; j <= spacing; j++) {
      printf(" ");
    }
    if ((i + 1) % 4 == 0) {
      printf("\n");
    }
  }
  printf("\n");
}

/* Print a card using unicode symbols */
int printCard (card theCard) {
  char* type;
  char rank[10];

  switch (theCard.type)
  {
    case clubs:
      type = "♣";
      break;

    case diamonds:
      type = "♦";
      break;

    case hearts:
      type = "♥";
      break;

    case spades:
      type = "♠";
      break;

    case joker:
      type = "J";
      return printf("%s", type) + 2;
      break;
    
    default:
      type = "Na";
      break;
  }

  switch (theCard.rank)
  {
    case 11:
      strcpy(rank, "Jack");
      break;
    
    case 12:
      strcpy(rank, "Queen");
      break;

    case 13:
      strcpy(rank,"King");
      break;

    case 14:
      strcpy(rank,"Ace");
      break;
    
    default:
      sprintf(rank, "%d", theCard.rank);
      break;
  }

  return printf(
    "%s %s", 
    type, rank
  );
}

/* Compare if one card needs to go before the next in the list */
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
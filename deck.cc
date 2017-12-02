#include "deck.h"
#include "card.h"
#include "helper.h"
#include "hand.h"

#include <string>
#include <fstream>
#include <memory>
#include <algorithm>

using namespace std;

Deck::Deck(string deckFile, shared_ptr<Player> owner){
    ifstream deck{deckFile};
    
    deck.open();
    
    string cardName;
    
    while(deck.getline(cardName)){
        addCard(createCard(cardName));
    }

    shuffle(); // always shuffle on construction
}

void Deck::shuffle(){
    int len = getCardCount();
    
    // swaps two random cards in the vector len * 3 times
    for (int i = 0; i < len * 3; ++i) {
        int randIndex1 = rand() % len;
        int randIndex2 = rand() % len;
        iter_swap(cardList.begin() + randIndex1, cardList.begin() + randIndex2); 
    }
}

void moveCardTo(int cardPosition, Hand &h) {
    if (cardPosition == -1) { // top card
        cardPosition = getCardCount() - 1;
    }
    hand.addCard(cardList.at(cardPosition));
    cardList.erase(cardList.begin() + cardPosition);
}
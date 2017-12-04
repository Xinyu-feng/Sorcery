#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <memory>
#include <utility>

class Card;
class Player;

std::shared_ptr<Card> createCard(std::string name);

#endif

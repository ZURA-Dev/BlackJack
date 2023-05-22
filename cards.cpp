#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <array>
#include <vector>
#include <algorithm>
#include "cards.h"
#include "cardDisplay.h"
// 1 = A
// 11 = Q
// 12 = J
// 13 = K
cards::cards() {}
cards::cards(string card, int cardNumber)
{
    this->card = card;
    this->cardNumber = cardNumber;
}



// cards

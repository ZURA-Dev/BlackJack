#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <array>
#include <vector>
#include <algorithm>
#include "cards.h"

#ifndef CARDFUNCTIONS_H_
#define CARDFUNCTIONS_H_

void cardShuffle(vector<cards> &player);
string cardPrint(cards selection);
void outputCard(const string *card);
int checkCardValue(cards T);

void playerStoreCardAndCount(cards selection, vector<cards>& tempPlayer, int& playerCardCount);
void dealerStoreCardAndCount(cards selection, vector<cards>& tempDealer, int& dealerCardCount);
#endif
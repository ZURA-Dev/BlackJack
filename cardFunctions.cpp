#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
#include <array>
#include <vector>
#include <algorithm>
#include <random>
#include "cardFunctions.h"
#include "cards.h"
using namespace std;

void cardShuffle(vector<cards> &player)
{
    int size = player.size();
    for (int k = 0; k < rand(); k++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            int j = rand() % (i + 1);
            // Swap player[i] with player[j]
            cards temp = player[i];
            player[i] = player[j];
            player[j] = temp;
        }
    }
}

void playerStoreCardAndCount(cards selection, vector<cards> &tempPlayer, int &playerCardCount)
{
    tempPlayer.push_back(selection);
    playerCardCount += 1;
}
void dealerStoreCardAndCount(cards selection, vector<cards> &tempDealer, int &dealerCardCount)
{
    tempDealer.push_back(selection);
    dealerCardCount += 1;
}

string cardPrint(cards selection)
{

    int number = selection.cardNumber;
    switch (number)
    {
    case 1:
        cout << "A" << endl;
        // return c.card1;
        break;
    case 2:
        cout << "2" << endl;
        // return c.card2;
        break;
    case 3:
        cout << "3" << endl;
        // return c.card3;
        break;
    case 4:
        cout << "4" << endl;
        // return c.card4;
        break;

    case 5:
        cout << "6" << endl;
        // return c.card5;
        break;
    case 6:
        cout << "7" << endl;
        // return c.card6;
        break;
    case 7:
        cout << "8" << endl;
        //  return c.card7;
        break;
    case 8:
        cout << "9" << endl;
        //  return c.card8;
        break;
    case 9:
        cout << "9" << endl;
        //  return c.card9;
        break;
    case 10:
        cout << "10" << endl;
        //  return c.card10;
        break;
    case 11:
        cout << "Q" << endl;
        //   return c.card11;
        break;
    case 12:
        cout << "J" << endl;
        //   return c.card12;
        break;
    case 13:
        cout << "K" << endl;
        //  return c.card13;
        break;
    }
}

// to print side by side

void outputCard(const string *card)
{
    const int sizeofcard = 9;
    for (int i = 0; i < sizeofcard; i++)
    {
        std::cout << card[i] << std::endl;
    }
}

int checkCardValue(cards T)
{
    int number = T.cardNumber;

    switch (number)
    {
    case 1:
        // 1 or 11
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    case 4:

        return 4;
        break;

    case 5:

        return 5;
        break;
    case 6:

        return 6;
        break;
    case 7:

        return 7;
        break;
    case 8:

        return 8;
        break;
    case 9:

        return 9;
        break;
    case 10:

        return 10;
        break;
    case 11:

        return 10;
        break;
    case 12:

        return 10;
        break;
    case 13:

        return 10;
        break;
    }
}
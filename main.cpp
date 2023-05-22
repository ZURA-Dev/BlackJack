//to dos
// add ascii art for design
// add gambling system
// add a way for user to save coins / reset coins after restart


#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <Windows.h>
#include <sstream>
#include <random>
#include <chrono>
#include "cardDisplay.h"
#include "cards.h"
#include "cardFunctions.h"
#include "misc.h"

using namespace std;

void initialDealerPull(vector<cards> &dealer, vector<cards> &tempDealer, int &dealerAmount, int &cardCount)
{
    dealerAmount += checkCardValue(dealer[0]);
    dealerStoreCardAndCount(dealer[0], tempDealer, cardCount);
    dealer.erase(dealer.begin());
    dealerAmount += checkCardValue(dealer[0]);
    dealerStoreCardAndCount(dealer[0], tempDealer, cardCount);
    dealer.erase(dealer.begin());
}
void dealerHit(vector<cards> &dealer, vector<cards> &tempDealer, int &dealerAmount, int &cardCount)
{
    dealerAmount += checkCardValue(dealer[0]);
    playerStoreCardAndCount(dealer[0], tempDealer, cardCount);
    dealer.erase(dealer.begin());
}
void checkDealerPull(vector<cards> &dealer, vector<cards> &tempDealer, int &dealerAmount, int &playerAmount, int &cardCount, bool &didplayerstand, bool &gameOver)
{
    if (dealerAmount == 21)
    {
        gameOver = true;
        return;
    }
    if (dealerAmount > 21)
    {
        gameOver = true;
        return;
    }
    if (dealerAmount > playerAmount && didplayerstand == true)
    {
        gameOver = true;
        true;
    }
    if (didplayerstand == true)
    {
        while ((dealerAmount < playerAmount) && dealerAmount <= 16)
        {
            if (dealerAmount == 21)
            {
                gameOver = true;
                return;
            }
            if (dealerAmount > 21)
            {
                gameOver = true;
                return;
            }
            if (dealerAmount > playerAmount)
            {
                gameOver = true;
                return;
            }
            dealerHit(dealer, tempDealer, dealerAmount, cardCount);
        }
    }
}

bool initialPlayerPull(vector<cards> &player, vector<cards> &tempPlayer, int &playerAmount, int &cardCount)
{
    // have player only know one of the dealer cards, put question mark next to unknown card
    // check if playerAmount busted, or is less than dealer, check player to dealer and such
    playerAmount += checkCardValue(player[0]);
    playerStoreCardAndCount(player[0], tempPlayer, cardCount);
    player.erase(player.begin());
    playerAmount += checkCardValue(player[0]);
    playerStoreCardAndCount(player[0], tempPlayer, cardCount);
    player.erase(player.begin());
    return true;
}

void playerHit(vector<cards> &player, vector<cards> &tempPlayer, int &playerAmount, int &cardCount, bool &gameOver)
{
    playerAmount += checkCardValue(player[0]);
    playerStoreCardAndCount(player[0], tempPlayer, cardCount);
    player.erase(player.begin());
    if (playerAmount > 21)
    {
        gameOver = true;
    }
}
void checkPlayer(int &playerAmount) {}
void checkGameEnd(int &playerAmount, int &dealerAmount, string &ending, bool &gameOver)
{
    if (gameOver == true)
    {
        if (playerAmount > 21)
        {
            gameOver = true;
            ending = "PLAYER BUST";
            return;
        }
        if (dealerAmount > 21)
        {
            gameOver = true;
            ending = "DEALER BUST";
            return;
        }
        if (dealerAmount == playerAmount)
        {
            gameOver = true;
            ending = "TIE";
            return;
        }
        if (playerAmount == 21)
        {
            gameOver = true;
            ending = "PLAYER BLACKJACK";
            return;
        }
        if (dealerAmount == 21)
        {
            gameOver = true;
            ending = "DEALER BLACKJACK";
            return;
        }
        if (dealerAmount > playerAmount)
        {
            gameOver = true;
            ending = "DEALER WON";
            return;
        }
        if (playerAmount > dealerAmount)
        {
            gameOver = true;
            ending = "PLAYER WON";
            return;
        }
    }
}
void playGame(const vector<cards> constdealer, const vector<cards> constperson)
{
    // TO DO if player amount >= 17 but not gameOver make dealer pull
    // TO DO pull till dealer > player
    //  todo put this into a whileloop either player exits game, or someone wins or loses
    //  to do if player amount is less than 21 he can keep hitting until he stands then the dealer pulls till greater than player.
    //  put a switch in here for player choice
    //  to do even if player pulls a 21 still have to wait for dealer to pull bc it can always be a tie.
    //  only check playerAmount logic after player and dealer turns to determine winner.

    vector<cards> dealer = constdealer; // this just grabs our deck of cards and creates a new copy of it, prob not ideal but idc.
    vector<cards> player = constperson;
    vector<cards> tempDealer; // this is just for storing card information for printing updated cards
    vector<cards> tempPlayer; // this is just for storing card information for printing updated cards
    int dealerCardCount = 0;
    int playerCardCount = 0;
    bool gameOver = false;
    bool didPlayerStand = false;
    int dealerAmount = 0;
    int playerAmount = 0;
    int dealerCardFlip = 0;
    int choice = 0;
    string ending = "";
    cardShuffle(dealer);
    cardShuffle(player);
    initialDealerPull(dealer, tempDealer, dealerAmount, dealerCardCount);
    initialPlayerPull(player, tempPlayer, playerAmount, playerCardCount); // could just change it to a void bc im just mainly checking if player stands.

    // maybe only display player and dealer in while loop past initial pull
    do
    {
        clearScreen();
        // loop through player cards + count and call print
        // display update player and dealer information
        checkDealerPull(dealer, tempDealer, dealerAmount, playerAmount, dealerCardCount, didPlayerStand, gameOver);
        checkGameEnd(playerAmount, dealerAmount, ending, gameOver);
        // only reason why im printing twice is because checkDealerPull needs to check itself again after pulling, without it the player would need to go through the switch again till it comes back to this point
        // and no im not going to create a seperate function that will do this for me, too lazy
        checkDealerPull(dealer, tempDealer, dealerAmount, playerAmount, dealerCardCount, didPlayerStand, gameOver);
        checkGameEnd(playerAmount, dealerAmount, ending, gameOver);
        if (gameOver == true)
        {
            cout << "ENDING: " << ending << endl;
        }
        cout << "DEALER ======" << endl;
        for (int i = 0; i < dealerCardCount; i++)
        {
            if (didPlayerStand == false && playerAmount <= 21)
            {
                cout << "?" << endl;
                cardPrint(tempDealer[1]);
                break;
            }
            if (playerAmount > 21 || didPlayerStand == true)
            {
                cardPrint(tempDealer[i]);
            }
        }
        // TO DO check if player stands instead of pulls;

        cout << "DEALER AMOUNT: ";
        if (didPlayerStand == false && playerAmount <= 21)
        {
            int tempValue = checkCardValue(tempDealer[0]);
            cout << dealerAmount - tempValue << endl;
        }
        if (playerAmount > 21 || didPlayerStand == true)
        {
            cout << dealerAmount << endl;
            if (dealerAmount >= 17 && dealerCardFlip == 1)
            {
                gameOver = true;
            }
        }

        cout << "PLAYER ======" << endl;
        for (int i = 0; i < playerCardCount; i++)
        {
            cardPrint(tempPlayer[i]);
        }
        cout << "PLAYER AMOUNT: " << playerAmount << endl;
        // player choice
        cout << "<1> HIT" << endl;
        cout << "<2> STAND" << endl;
        cout << "<0> RETURN TO MENU" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            return;
            break;
        case 1:
            if (didPlayerStand == false && gameOver == false)
            {
                playerHit(player, tempPlayer, playerAmount, playerCardCount, gameOver);
            }

            break;
        case 2:
            didPlayerStand = true;
            break;
        default:
            break;
        }

        // switch
        // checkGameEnd(playerAmount, dealerAmount, ending, gameOver);
    } while (choice != 3);
    return;
    // to do grab from first in deck, delete first position
    // to do destroy dynamic vector
}
int main()
{

    srand(time(0));
    intro();
    // 13 total different cards, 4 each
    // create person,dealer cards
    const int CARDSIZE = 52;
    const vector<cards> dealer = {{"A", 1}, {"A", 1}, {"A", 1}, {"A", 1}, {"2", 2}, {"2", 2}, {"2", 2}, {"2", 2}, {"3", 3}, {"3", 3}, {"3", 3}, {"3", 3}, {"4", 4}, {"4", 4}, {"4", 4}, {"4", 4}, {"5", 5}, {"5", 5}, {"5", 5}, {"5", 5}, {"6", 6}, {"6", 6}, {"6", 6}, {"6", 6}, {"7", 7}, {"7", 7}, {"7", 7}, {"7", 7}, {"8", 8}, {"8", 8}, {"8", 8}, {"8", 8}, {"9", 9}, {"9", 9}, {"9", 9}, {"9", 9}, {"10", 10}, {"10", 10}, {"10", 10}, {"10", 10}, {"Q", 11}, {"Q", 11}, {"Q", 11}, {"Q", 11}, {"J", 12}, {"J", 12}, {"J", 12}, {"J", 12}, {"K", 13}, {"K", 13}, {"K", 13}, {"K", 13}};
    const vector<cards> person = {{"A", 1}, {"A", 1}, {"A", 1}, {"A", 1}, {"2", 2}, {"2", 2}, {"2", 2}, {"2", 2}, {"3", 3}, {"3", 3}, {"3", 3}, {"3", 3}, {"4", 4}, {"4", 4}, {"4", 4}, {"4", 4}, {"5", 5}, {"5", 5}, {"5", 5}, {"5", 5}, {"6", 6}, {"6", 6}, {"6", 6}, {"6", 6}, {"7", 7}, {"7", 7}, {"7", 7}, {"7", 7}, {"8", 8}, {"8", 8}, {"8", 8}, {"8", 8}, {"9", 9}, {"9", 9}, {"9", 9}, {"9", 9}, {"10", 10}, {"10", 10}, {"10", 10}, {"10", 10}, {"Q", 11}, {"Q", 11}, {"Q", 11}, {"Q", 11}, {"J", 12}, {"J", 12}, {"J", 12}, {"J", 12}, {"K", 13}, {"K", 13}, {"K", 13}, {"K", 13}};
    int choice;
    do
    {
        clearScreen();
        cout << "<1> PLAY GAME" << endl;
        cout << "<2> QUIT" << endl;

        cout << "ENTER: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            playGame(dealer, person);
            break;
        case 2:
            // return;
            break;
        default:
            cout << "try again" << endl;
            break;
        }

    } while (choice != 2);

    cin.get();
}

/*
string operator*(const string a, const string b)
{
    const string SPACE = "  ";
    stringstream ssa(a), ssb(b);
    string result, parta, partb;
    while (getline(ssa, parta) && getline(ssb, partb))
        result += parta + SPACE + partb + '\n';
    return result;
}*/

 //cout << R"(    )" << '\n';
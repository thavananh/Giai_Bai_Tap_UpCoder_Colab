#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <ctime>
class UI
{
public:
    UI();
    UI(const UI& ui);
    ~UI();
    void renderWelcomeScreen();
    void renderGoodByeScreen();
    void renderLoginScreen();
    void renderAccountDetailScreen();
    void renderWithDrawScreen();
    void renderTransactionDetailsScreen();
    void renderChangePasswordScreen();
    void renderVAccountListScreen();
    void renderAddAccountScreen();
    void renderRemoveAccountScreen();
    void renderUnlockAccountScreen();
};
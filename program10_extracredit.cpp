/*

Program10_q

Programmer: Freese, Joshua

Course: CSC119-142 Introduction to Programming Spring 2022

Submission Date: 4/28/22

This program is an RPG battle system.
*/

/* Stat sheet is as follows, as reference for the array.
1/2/3 - DMG
0/1/2 - ACC
0/1/2 - SPD
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void playerAction(string action, int& playerHealth, int& dmgDealt, int dmg, int acc)
{
    if (action == "a")
    {
        if (rand() % 100 + 1 < 70 + (acc * 5))
        {
            int damage = (rand()%(24-16 + 1) + 8) * dmg;
            cout << "You dealt " << damage << " damage!";
            dmgDealt += damage;
        }
        else
        {
            cout << "Your attack missed!";
        }
    }
    if (action == "h")
    {
        int heal = (rand() % 50 + 25);
        cout << "You healed for " << heal << " HP.";
        playerHealth += heal;
        if (playerHealth > 1000)
        {
            playerHealth = 1000;
        }
        cout << "You now have " << playerHealth << " HP.";
    }
}

int main()
{
    int counter = 0;
    int dmgDealt = 0;
    int playerHealth = 1000;
    int stats[3];
    int dragonDamage;
    string weapon;
    string action;
    string name;
    ifstream weaponFile;
    ofstream results;
    results.open("scores.txt", ios::app);

    cout << "Weapons: \n Sword: +DMG, -SPD \n Spear: -DMG, +ACC \n Flail: +DMG, -ACC \n Daggers: -DMG, +SPD";
    cout << "\nPick your weapon: ";
    cin >> weapon;
    string weaponName = weapon + ".txt";

    weaponFile.open(weaponName);

    if (weaponFile.fail())
    {
        cout << "There is no weapon with that name!";
        weaponFile.clear();
        stats[0,1,2] = 1,1,1;
        cout << "\nYour stats have been set to default.\n";
        weaponFile.ignore();
    }

    while (!weaponFile.eof())
    {
        weaponFile >> stats[counter];
        counter++;
    }

    cout << "You are fighting a seemingly invincible dragon. Deal as much damage as you can!";
    while (playerHealth > 0)
    {
        cout << "\nHealth: " << playerHealth << "\t\t Damage Dealt: " << dmgDealt;
        cout << "\nActions: \n   a = Attack \n   h = Heal \n   s = Stats";
        for (int i = 0; i < stats[2]; i++)
        {
            cout << "\nWhat do you do? ";
            cin >> action;
            playerAction(action, playerHealth, dmgDealt, stats[0], stats[1]);
        }
        dragonDamage = (rand() % 100 + 1);
        cout << "\nThe dragon attacks! You took " << dragonDamage << " damage!";
        playerHealth -= dragonDamage;
    }
    cout << "\nYou have been defeated! Your stats will be recorded in scores.txt";
    cout << "\nWhat's your name? ";
    cin >> name;
    results << name << "\t\t Damage Dealt: " << dmgDealt << "\t\t Weapon: " << weapon << endl;

    weaponFile.close();
    results.close();
    return(0);
}

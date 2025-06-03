// midterm-project.cpp : EUCLID, a game of interdimensional adventure!

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <stdexcept>
using namespace std;

// declare our variables, including the user's name, the yes/no question, and the dice roll

string name;
string shopItem;
bool tryAgain;
bool gameStart = 1;
bool crossBridge = 0;
bool takeAmulet = 0;
bool useAmulet = 0;
bool continueAsk = 0;
bool riddleAgain = 0;
bool knockDoor = 0;
int diceRoll = 0;
int riddleGuess = 0;
int pickItem = 0;

// this bool function is what happens whenever the user encounters a game over instance. it asks the user if they want to try again
// depending on their answer, the game either just returns 0 to the command line, ending the program
// or writes "continue;" into the while loop, ending that iteration of the while loop, contained in the game logic function, starting the game over for the user.
static bool gameOver() {
    while (true) {
        cout << "GAME OVER, " << name << "\n" << endl;
        cout << "Would you like to try again? (1/0)\n" << endl;
        cin >> tryAgain;
        if (tryAgain) {
            // divider for new instance of game
            cout << endl << setfill('*') << setw(80) << "\n" << setfill(' ');
            cout << endl;
            return true;
        }
        else {
            return false;
        }
    }
}

// void function contains entire game logic, which the game logic is in a while loop inside of the function so that the while loop's continue and break functionality can be used.
static void playGame() {
    while (gameStart) {
        breakTwice:
        // introduction begins
        cout << name << ", your surroundings are greatly unfamiliar to you." << endl;
        cout << "Everything is a pale, nearly blinding white, void of any features, or life for that matter." << endl;
        cout << "As you look around you notice the vast expanse of the area you're in, as its walls and ceilings extend into infinity.\n" << endl;

        // introduce the amulet
        cout << "You find yourself at the foot of a great chasm." << endl;
        cout << "Just before the edge is a quartz pedestal holding an amulet of unknown origins." << endl;
        cout << "It has the most illustrious beauty and within its crest, holds the darkest ruby you've ever seen.\n" << endl;

        // ask if the user will take the amulet
        cout << "Do you take the amulet? (1/0)\n" << endl;
        cin >> takeAmulet;

        // introduce bridge
        cout << "Before you is a rickety bridge, which seems to extend forever." << endl;
        cout << "Despite this, you can just barely make out the structure peering over the other side.\n" << endl;

        // asks if the user will cross the bridge
        cout << "Do you dare cross the dangerous bridge? (1/0) \n" << endl;
        cin >> crossBridge;

        if (crossBridge) {
            // if the user said yes, following dialog is determined by their dice roll
            cout << "The die will determine your fate." << endl;
            srand((unsigned int)time(0)); // create seed using time(0) function
            diceRoll = rand() % 6 + 1; // dice roll
            cout << "The dice has spoken! Your number is " << diceRoll << "!\n" << endl;

            // switch statement for dice roll outcome (higher dice roll = better outcome.)
            // if the user has a dice roll of three and they use the amulet, they live.
            // if the user has a dice roll of two or four and above and has the amulet, they live.
            // if the user has a dice roll three or lower but does not have the amulet, they die.

            cout << "You confidently begin your first step onto the bridge." << endl;

            switch (diceRoll) {
            case 1:
                // dialog if user rolls a one
                cout << "The first rung of the bridge creaks loudly." << endl;
                cout << "SNAP! The bridge breaks and you are left plummeting to the bottom of the chasm.\n" << endl;

                if (takeAmulet) {
                    // dialog if user rolls a one with the amulet
                    cout << "For what feels like an eternity later, you arise." << endl;
                    cout << "You carefully get up, clutching your amulet as the surrounding walls overarch your person." << endl;
                    if (gameOver()) {
                        continue;
                    }
                    else {
                        return;
                    }
                }
                else {
                    // dialog if user rolls a one without the amulet
                    cout << "As you slowly reach the bottom, you begin to lose consciousness." << endl;
                    if (gameOver()) {
                        continue;
                    }
                    else {
                        return;
                    }
                }
                break;
            case 2:
                // dialog if user rolls a two
                cout << "You plant your feet on either side of the first rung." << endl;
                cout << "You are surprised to find that it is quite stable as you jump and shake about." << endl;
                cout << "Suddenly, a great noise from the opposite end of the bridge is heard.\n" << endl;

                if (takeAmulet) {
                    // dialog if user rolls a two with the amulet
                    cout << "The bridge begins to quake as you carefully traverse its creaking steps. You grasp the amulet tightly." << endl;
                    cout << "After hours of slow travel, you make it to the end of the bridge and immediately collapse, embracing the solid ground." << endl;
                }
                else {
                    // dialog if user rolls a two without the amulet
                    cout << "You quiver in fear as the bridge slowly falls apart, releasing you from its supports." << endl;
                    if (gameOver()) {
                        continue;
                    }
                    else {
                        return;
                    }
                }
                break;
            case 3:
                // dialog if user rolls a three
                cout << "You feel a foreboding presence around your person." << endl;
                cout << "Suddenly, a great monster with unfamiliar features jumps in front of you.\n" << endl;

                if (takeAmulet) {
                    // dialog if user rolls a three and has the amulet
                    cout << "Do you want to use your amulet on the beast? (1/0)\n" << endl;
                    cin >> useAmulet;

                    if (useAmulet) {
                        // dialog if user rolls a three and chooses to use the amulet
                        cout << "You clutch your amulet tightly, presenting it to the great beast." << endl;
                        cout << "The monster quickly subsides and allows you to continue your journey." << endl;
                    }
                    else {
                        // dialog if user rolls a three and chooses to not use the amulet
                        cout << "The creature grabs onto you and you are unable to overtake its grasp." << endl;
                        if (gameOver()) {
                            continue;
                        }
                        else {
                            return;
                        }
                    }
                }
                else {
                    // dialog if user rolls a three without the amulet
                    cout << "The creature refuses your passage along the bridge." << endl;
                    if (gameOver()) {
                        continue;
                    }
                    else {
                        return;
                    }
                }
                break;
            case 4:
                // dialog if user rolls a four
                cout << "You continue along the great bridge and find yourself making steady progress." << endl;
                cout << "Putting one foot in front of the other, you look around and find that your surroundings hold an eery beauty.\n" << endl;

                cout << "After a brief break to admire your surroundings, you continue on." << endl;
                cout << "You eventually appear at the end of the chasm, and meet the great structure before you." << endl;
                break;
            case 5:
                // dialog if user rolls a five
                cout << "You feel an overwhelming calm about you." << endl;
                cout << "You strut across the great bridge and quickly find yourself at the end.\n" << endl;

                cout << "Now standing in front of what is most likely the most daunting castle entrance you have ever come across, you cringe." << endl;
                cout << "Despite your uneasiness, you press on to begin a great journey." << endl;
                break;
            case 6:
                // dialog if user rolls a six
                cout << "Despite all odds, the bridge suddenly deconstructs and the chasm disappears." << endl;
                cout << "Ambient mechanical noises envelop your ears and you are met with a quickly approaching castle entrance.\n" << endl;

                cout << "You take a beat and find yourself at the foot of the most picturesque gothic location." << endl;
                cout << "You cower in awe of the structure in front of you and, filled with determination, approach its colossal doors." << endl;
                break;
            default:
                // dialog if criteria is not met: error
                cout << "An error has occurred! Please try again!" << endl;
                if (gameOver()) {
                    continue;
                }
                else {
                    return;
                }
                break;
            }
        }
        else {
            // if the user says no to crossing the bridge
            cout << "As your foot steps away from the first rung of the bridge, it suddenly dissolves." << endl;
            cout << "A chain reaction begins, slowly disentigrating every individual step as the bridge sinks into the ravine below.\n" << endl;
            cout << "Because of your unwillingness for adventure, you are thus doomed to perverse the rim of this chasm for eternity." << endl;
            if (gameOver()) {
                continue;
            }
            else {
                return;
            }
        }

        // ask if user would like to continue (reduce wall of text)
        cout << endl << "Would you like to continue? (1/0)\n" << endl;
        cin >> continueAsk;

        if (continueAsk) {
            // if user says yes to continue the game proceeds
            // approach the castle door
            cout << "A great castle slowly envelops your view as you approach." << endl;
            cout << "The gothic steeple demands your attention." << endl;
            cout << "You continue to gaze at the pretty architecture, slowly reaching the door." << endl;

            // meet the knight in shining armor
            cout << endl << "\t\"HALT!\"\n" << endl;

            cout << "You suddenly peer down and find stood by the castle doors is a lowly knight in shining armor." << endl;
            cout << "The knight nudges you away from the doors with his outstretched spear, making his armor clunkily ring out." << endl;

            cout << endl << "\t\"How dare you think you can just walk up on this fine manor and just walk in all willy-nilly.\"" << endl;
            cout << "\t\"To enter the compound, you must answer my riddle!\"" << endl;

            cout << endl << "The knight clears his throat very loudly.\n" << endl;

            //user attempts to answer riddle, they get only a certain amount of tries
            for (int i = 0; i < 3; i++) {
                cout << "\t\"There are seven maidens, all born two years apart.\"" << endl;
                cout << "\t\"If the youngest is seven, what would be the age of the eldest?\"\n" << endl;

                cin >> riddleGuess;
                if (riddleGuess == 19) {
                    // if the user gets the riddle right, they leave the loop and get to knock on the door
                    break;
                }
                else {
                    // if the user runs out of tries, the user gameover's.
                    if (i == 2) {
                        cout << "\t\"HALT! You have attempted my riddle one too many times. You may not enter.\"" << endl;
                        if (gameOver()) {
                            //cannot break out of nested loops with one command, so goto is used to return to the beginning of the while loop
                            goto breakTwice;
                        }
                        else {
                            return;
                        }
                        break;
                    }
                    else {
                        // if the user answers incorrectly, they are asked if they want to try again
                        cout << "\t\"You have answered incorrectly. However, I will let you try again.\"\n" << endl;
                        cout << "\t\"Would you like to try again?\" (1/0)\n" << endl;

                        // ask user if they want to try again
                        cin >> riddleAgain;
                        if (!riddleAgain) {
                            // if user does not want to retry the riddle
                            cout << "Because of your unwillingness for adventure, you are thus doomed to perverse the outside of the castle for eternity.\n" << endl;
                            if (gameOver()) {
                                //once again, cannot break out of nested loops with one command, so goto is used to return to the beginning of the while loop
                                goto breakTwice;
                            }
                            else {
                                return;
                            }
                        }
                    }
                }
            }

            // loop ends, you can now knock on the door
            cout << "Before you can even answer, the knight cuts you off.\n" << endl;
            cout << "\t\"Ah, whatever, you're no fun. I'll let you enter.\"\n" << endl;

            cout << "The knight begrudgingly raises his spear, allowing you to knock on the castle doors.\n" << endl;

            // ask the user if they want to knock on the castle door
            cout << "Do you knock? (1/0)\n" << endl;

            cin >> knockDoor;

            // only get to continue if the user agreed to knocking on the door
            if (knockDoor) {
                cout << "KNOCK" << endl << "KNOCK" << endl << "KNOCK" << endl;

                // the door opens
                cout << endl << "The door swings wide open. . ." << endl;

                // merchant shop, array defines the four possible items
                string shopsItems[4] = { "dagger", "poison apple", "shield", "longsword" };

                cout << endl << "As you make your entrance, you are led into a great, homey manor." << endl;
                cout << "You are subconsciously led to a wooden merchant stand, bearing the sign, \"Ye Olde Shop\"." << endl;
                cout << endl << "You duck to read below it's signage where there is a poorly written sign saying that the merchant is on their break." << endl;
                cout << "As you stand back up you accidentally press in a big red button on the stand's table, revealing a secret." << endl;

                // if the user previously took the amulet, the poison apple is switched out for their amulet
                if (takeAmulet) {
                    cout << endl << "Your precious amulet suddenly rises up and joins the items upon the witch's table." << endl;
                    shopsItems[1] = "amulet";
                }
                else cout << endl;

                // program prints out the items of the array, cleanly, in a list.
                cout << "All of the items upon the table begin floating around you in a circle." << endl;
                cout << "Including ";
                for (int i = 0; i < 4; i++) {
                    if (i < 3) {
                        cout << "the " << shopsItems[i] << ", ";
                    }
                    else cout << "and the " << shopsItems[i] << "." << endl;

                }

                cout << endl << "You wait for a long time before one item lowers down." << endl;

                cout << endl << "You reach out and grab it." << endl;

                //user picks item
                cout << endl << "Pick an item. (1-4)\n" << endl;
                cin >> pickItem;

                // user gets the item they picked
                // exception - try,throw,catch if chosen array index is out of bounds
                try {
                    // if chosen item does not fit within array bounds
                    if (pickItem <= 0 || pickItem >= 5) {
                        // throw out_of_range error
                        throw out_of_range("Index out of range!"); 
                    }

                    // if array is not out of bounds
                    shopItem = shopsItems[pickItem - 1];
                    cout << endl << "You now equip the " << shopItem << ".\n" << endl;
                }

                catch (out_of_range& err) {
                    // sends exception and error to the console
                    cout << "Exception: " << err.what() << endl;
                }

                // alternatively, if i would like to correct the error to prevent an exception:
                /* 
                try {
                    if (pickItem < 1 || pickItem >= 5) {
                        throw (pickItem);
                    }
                }

                catch (int pickItemFixed) {
                    pickItem = 3; // fix pickItem to random chosen index
                }

                shopItem = shopsItems[pickItem - 1];
                cout << endl << "You now equip the " << shopItem << ".\n" << endl;

                */

                // if the user picked the poison apple, they die
                if (shopItem == "poison apple") {
                    cout << "Out of curiosity, you take a bite out of the apple." << endl;
                    cout << "For a short moment you feel as if you will be alright and the apple was a dud." << endl;
                    cout << endl << "However you soon succumb to your curiosity and lose consciousness." << endl;

                    if (gameOver()) {
                        continue;
                    }
                    else {
                        return;
                    }
                }

                // GAME ENDS HERE . . . 

                if (gameOver()) {
                    continue;
                }
                else {
                    return;
                }

            }
            else {
                // if the user says no to knocking on the door
                cout << "As your hand shys away from the door, it suddenly dissolves." << endl;
                cout << "A chain reaction begins, slowly disentigrating every individual stone and board as the castle fades out of reality.\n" << endl;
                cout << "Because of your unwillingness for adventure, you are thus doomed to perverse the rim of this empty arena for eternity." << endl;
                if (gameOver()) {
                    continue;
                }
                else {
                    return;
                }
            }
        }
        else {
            // if user said no to the continue question
            cout << "Because of your unwillingness for adventure, you are thus doomed to perverse the rim of this arena for eternity." << endl;
            if (gameOver()) {
                continue;
            }
            else {
                return;
            }
        }
    }
}

// main function just asks the user for their name, otherwise all game logic is included within the gameStart function
// game over routine is included in the gameOver bool function as well.
int main()
{
    // introduce user to the program
    cout << "Welcome adventurer to EUCLID, a game of interdimensional adventure!" << endl;
    cout << "Please enter your chosen name.\n" << endl;

    // ask user for name
    getline(cin, name);

    // GAME STARTS HERE
    playGame();

    return 0;

    /* LORE:
        Game is called Euclid, you are a lone adventurer with a hazy memory.
        The find yourself being spoken to from above by somebody named Isaac.
        Isaac is an unreliable narrator.
        
        Before you is an amulet. You can choose to take it or ignore it.

        Also before you is the great chasm, which you can choose to cross.
        Those with poor luck fail to cross the bridge.
        Some may even meet the beast that lives underneath the bridge.
        The amulet wards off the beast.
        Those without the amulet are taken away.

        After crossing the bridge, you approach a great castle.
        You are stopped by the armed knight with an affinity for riddles.
        Only after getting it right can you knock on the castle doors.

        Only after knocking on the door, one can enter.

        You then walk in to discover a merchant's stand.
        While the merchant is not there, you press on.
        You push a button creating the items to spin around before one is selected.
        The item you receive determines your fate. 
    */
}

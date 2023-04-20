////////////////////////////////////////
// { PROGRAM NAME } { VERSION }
// Author: themirrazz#9986
// License: AGPLv3
// Description: Romeo and Juliet
////////////////////////////////////////

/*
* The comments in this file are here to guide you initially. Note that you shouldn't actually
* write comments that are pointless or obvious in your own code, write useful ones instead!
* See this for more details: https://ce-programming.github.io/toolchain/static/coding-guidelines.html
*
* Have fun!
*/

/* You probably want to keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <fileioc.h>
#include <tice.h>

/* Here are some standard headers. Take a look at the toolchain for more. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Put function prototypes here or in a header (.h) file */

/* Note: uint8_t is an unsigned integer that can range from 0-255. */
/* It performs faster than just an int, so try to use it (or int8_t) when possible */
void printText(const char *text, uint8_t x, uint8_t y);

void printLines(const char* pages[], int line);

int readBookmark();

void setBookmark(int line);


int length = 230;

struct { int bookmark; } file;

/* This is the entry point of your program. */
/* argc and argv can be there if you need to use arguments, see the toolchain example. */
int main(void)
{
    /* Initialize some strings */
    int line = 0;
    const char* Welcome =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* lines[] = {
        "THE TRAGEDY OF ROMEO AND",
        "JULIET",
        "By William Shakespeare",
        "Press CLEAR to exit,",
        "press Y= to go to your",
        "bookmark, and press",
        "press WINDOW save your",
        "spot to the bookmark.",
        "",
        "This copy of Romeo and",
        "Juliet is copyrighted by",
        "World Library, Inc. 1990-",
        "1993, and was provided by",
        "The Project Gutenberg.",
        "",
        "https://www.gutenberg.org/",
        "files/1112/1112.txt",
        "",
        "SCENE.--Verona; Mantua.",
        "THE PROLOUGE",
        "",
        "Enter the chorus",
        "",
        "Two households, both alike",
        "in dignity, in fair",
        "Verona, where we lay our,",
        "scene, From ancient",
        "grudge to new mutiny,",
        "Where civil blood makes",
        "civil hands unclean.",
        "From forth the fatal",
        "loins of these two foes",
        "A pair of star-cross'd",
        "lovers that take their",
        "life; Whos misadventur'd",
        "piteous overthrows",
        "Doth their death bury",
        "their parents' strife.",
        "The fearful passage of",
        "their death-mark'd love,",
        "And the continuance of",
        "their parents' rage,",
        "Which, but their",
        "children's end, naught",
        "could remove,",
        "Is now the two hours'",
        "traffic of our stage;",
        "The which if you with",
        "patient ears attend, What",
        "here shall miss, our toil",
        "shall strive to mend.",
        "",
        "(Exit.)",
        "",
        "ACT I SCENE I",
        "Verona. A public place.",
        "",
        "Enter Samspon and",
        "Gregory (with swords and",
        "bucklers) to the house of",
        "Capulet.",
        "",
        "Samp:",
        " Gregory, on my word,",
        " we'll not carry coals.",
        "Greg:",
        " No, for the we should be",
        " colliers.",
        "Samp:",
        " I mean, an we be in",
        " choler, we'll draw.",
        "Greg:",
        " Ay, while you live, draw",
        " your neck out of your",
        " collar.",
        "Samp:",
        " I strike quickly,",
        " being moved.",
        "Greg:",
        " But thou art not moved",
        " quickly to strike.",
        "Samp:",
        " A dog of the house of",
        " Montague moves me.",
        "Greg:",
        " To move is to stir,",
        " and to be valiant is",
        " to stand. Therefore,",
        " if thou art moved,",
        " thou runn'st away.",
        "Samp:",
        " A dog of that house",
        " shall move me to stand.",
        " I will take the wall of",
        " any man or maid of",
        " Montague.",
        "Greg:",
        " That shows thee a",
        " weak slave; for the",
        " weakest goes to the",
        " wall.",
        "Samp:",
        " 'Tis true; and",
        " therefore women,",
        " being the weaker",
        " vessels, are ever",
        " thrust to the wall.",
        " Therefore, I will",
        " push Montague's men from",
        " the wall and thrust his",
        " maids to the wall.",
        "Greg:",
        " The quarrel is",
        " between our masters",
        " and us their men.",
        "Samp:",
        " 'Tis all one. I will",
        " show myself a tyrant.",
        " When I have fought",
        " with the men, I",
        " will be cruel with",
        " the maids- I will",
        " cut off their heads.",
        "Greg:",
        " The heads of the maids?",
        "Samp:",
        " Aye, the heads of the",
        " maids, or their",
        " maidenheads. Take it in",
        " what sense thou wilt.",
        "Greg:",
        " They must take it in",
        " sense that feel it.",
        "Samp:",
        " Me they shall feel while",
        " I am able to stand; and",
        " 'tis known I am a pretty",
        " piece of flesh.",
        "Greg:",
        " 'Tis well thou art not",
        " fish; if thou hadst, thou",
        " hadst been poor-John.",
        " Draw thy tool! Here comes",
        " two of the house of",
        " Montagues.",
        "",
        "Enter the two other",
        "Servingmen (Abram and",
        "Balthasar).",
        "",
        "Samp:",
        " My naked weapon is out.",
        " Quarrel! I will back",
        " thee.",
        "Greg:",
        " How? turn thy back and",
        " run?",
        "Samp:",
        " Fear me not.",
        "Greg:",
        " No, marry. I fear thee!",
        "Samp:",
        " Let us take the law of",
        " our sides; let them",
        " begin.",
        "Greg:",
        " I will frown as I pass",
        " by, and let them take it",
        " as they list.",
        "Samp:",
        " Nay, as they dare. I will",
        " bite my thumb at them;",
        " which is disgrace to them,",
        " if they bear it.",
        "Abr:",
        " Do you bite your thumb",
        " at us, sir?",
        "Samp (Aside to Greg):",
        " Is the law of our side if",
        " I say ay?",
        "Greg (Aside to Samp):",
        " No.",
        "Samp:",
        " No, I do not bite my",
        " thumb at you, sir; but I",
        " bite my thumb, sir.",
        "Greg:",
        " Do you quarrel, sir?",
        "Abr:",
        " Quarrel, sir? No, sir.",
        "Samp:",
        " But if you do, sir, am",
        " for you. I serve as good",
        " a man as you.",
        "Abr:",
        " No better.",
        "Samp:",
        " Well, sir.",
        "",
        "Enter Benvolio.",
        "",
        "Greg (Aside to Samp):",
        " Say 'better.' Here comes",
        " one of my master's",
        " kinsmen.",
        "Samp:",
        " Yes, better, sir.",
        "Abr:",
        " You lie.",
        "Samp:",
        " Draw, if you be men.",
        " Gregory, remember thy",
        " slashing blow.",
        "",
        "(They fight)",
        "",
        "Ben:",
        " Part, fools!",
        " (Beats down their swords)",
        " Put up your swords! You",
        " know not what you do.",
        "",
        "Enter Tybalt.",
        "",
        "Tyb:",
        " What, art thou drawn",
        " among these heartless",
        " hinds? Turn thee",
        " Benvolio! look upon thy",
        " death."
    };

    /* Clear the homescreen */
    /* Wait for a key press */
    int key;
    printLines(lines, line);
    while (true) {
        key = os_GetCSC();
        if(key == sk_Up) {
            if(line > 0) {
                line = line - 1;
                printLines(lines, line);
            }
        } else if(key == sk_Down) {
            if(line < ((int) length) - 9) {
                line = line + 1;
                printLines(lines, line);
            }
        } else if(key == sk_Clear) {
            break;
        } else if(key == sk_Yequ) {
            readBookmark();
            if(file.bookmark != -1) {
                line = file.bookmark;
                printLines(lines, line);
            }
        } else if(key == sk_Window) {
            setBookmark(line);
            os_ClrHome();
            printText(
                ((const char*) "Saved bookmark!"),
                0, 0
            );
            sleep(1);
            printLines(lines,line);
        }
    }

    return 0;
}

/* Draw selections of the book */
void printLines(const char* pages[], int line)
{
    if(line > ((int) length) - 8) {
        return printLines(pages, ((int) length - 8));
    }
    os_ClrHome();
    int x = 0;
    printText(pages[line + x], 0, x);
    x = x + 1;
    printText(pages[line + x], 0, x);
    x = x + 1;
    printText(pages[line + x], 0, x);
    x = x + 1;
    printText(pages[line + x], 0, x);
    x = x + 1;
    printText(pages[line + x], 0, x);
    x = x + 1;
    printText(pages[line + x], 0, x);
    x = x + 1;
    printText(pages[line + x], 0, x);
    x = x + 1;
    printText(pages[line + x], 0, x);
    x = x + 1;
    printText(pages[line + x], 0, x);
    x = x + 1;
}


/* Draw text on the homescreen at the given X/Y cursor location */
void printText(const char *text, uint8_t xpos, uint8_t ypos)
{
    os_SetCursorPos(ypos, xpos);
    os_PutStrFull(text);
}


/* Read the user bookmark, as scrolling to where you left off is too slow */
int readBookmark()
{
    file.bookmark = -1;
    ti_var_t slot;
    if(slot = ti_Open(
        ((const char*) "RomjulBKM"),
        ((const char*) "r")
    )) {
        ti_Read(&file,sizeof(file),1,slot);
        ti_Close(slot);
    }
}


void setBookmark(int line)
{
    file.bookmark = line;
    ti_var_t slot;
    if(slot = ti_Open(
        ((const char*) "RomjulBKM"),
        ((const char*) "w")
    )) {
        ti_Write(&file,sizeof(file),1,slot);
        ti_Close(slot);
    }
}

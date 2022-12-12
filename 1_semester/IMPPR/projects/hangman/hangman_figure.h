#ifndef HANGMAN_FIGURE_H
#define HANGMAN_FIGURE_H

#include <stdlib.h>

#define FIGURE_STATES 8
#define FIGURE_HEIGHT 24
#define FIGURE_WIDTH 28

const char FIGURE[FIGURE_STATES][FIGURE_HEIGHT][FIGURE_WIDTH] = {
  /* state 0 */
{
"0  ___________.._______    ",
"| .__________))______|     ",
"| | / /      ||            ",
"| |/ /       ||            ",
"| | /        ||            ",
"| |/         ||            ",
"| |          ||            ",
"| |          ()            ",
"| |          /\\            ",
"| |          \\/            ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"\"\"\"\"\"\"\"\"\"\"||\"\"\"\"\"\"\"||\"\"\"|  ",
"|\"|\"\"\"\"\"\"\"|         '\"|\"|  ",
"| |                   | |  ",
": :                   : :  ",
". .                   . .  "
},
  /* state 1 */
{
"1  ___________.._______    ",
"| .__________))______|     ",
"| | / /      ||            ",
"| |/ /       ||            ",
"| | /        ||.-''.       ",
"| |/         |/  _  \\      ",
"| |          ||  `/,|      ",
"| |          (\\\\`_.'       ",
"| |           `--'         ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"\"\"\"\"\"\"\"\"\"\"||\"\"\"\"\"\"\"||\"\"\"|  ",
"|\"|\"\"\"\"\"\"\"|         '\"|\"|  ",
"| |                   | |  ",
": :                   : :  ",
". .                   . .  "
},
  /* state 2 */
{
"2  ___________.._______    ",
"| .__________))______|     ",
"| | / /      ||            ",
"| |/ /       ||            ",
"| | /        ||.-''.       ",
"| |/         |/  _  \\      ",
"| |          ||  `/,|      ",
"| |          (\\\\`_.'       ",
"| |         .-`--'.        ",
"| |         \\ . . /        ",
"| |          |   |         ",
"| |          | . |         ",
"| |          |   |         ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"\"\"\"\"\"\"\"\"\"\"||\"\"\"\"\"\"\"||\"\"\"|  ",
"|\"|\"\"\"\"\"\"\"|         '\"|\"|  ",
"| |                   | |  ",
": :                   : :  ",
". .                   . .  "
},
  /* state 3 */
{
"3  ___________.._______    ",
"| .__________))______|     ",
"| | / /      ||            ",
"| |/ /       ||            ",
"| | /        ||.-''.       ",
"| |/         |/  _  \\      ",
"| |          ||  `/,|      ",
"| |          (\\\\`_.'       ",
"| |         .-`--'.        ",
"| |        /Y . . /        ",
"| |       // |   |         ",
"| |      //  | . |         ",
"| |     ')   |   |         ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"\"\"\"\"\"\"\"\"\"\"||\"\"\"\"\"\"\"||\"\"\"|  ",
"|\"|\"\"\"\"\"\"\"|         '\"|\"|  ",
"| |                   | |  ",
": :                   : :  ",
". .                   . .  "
},
  /* state 4 */
{
"4  ___________.._______    ",
"| .__________))______|     ",
"| | / /      ||            ",
"| |/ /       ||            ",
"| | /        ||.-''.       ",
"| |/         |/  _  \\      ",
"| |          ||  `/,|      ",
"| |          (\\\\`_.'       ",
"| |         .-`--'.        ",
"| |        /Y . . Y\\       ",
"| |       // |   | \\\\      ",
"| |      //  | . |  \\\\     ",
"| |     ')   |   |   (`    ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"| |                        ",
"\"\"\"\"\"\"\"\"\"\"||\"\"\"\"\"\"\"||\"\"\"|  ",
"|\"|\"\"\"\"\"\"\"|         '\"|\"|  ",
"| |                   | |  ",
": :                   : :  ",
". .                   . .  "
},
  /* state 5 */
{
"5  ___________.._______    ",
"| .__________))______|     ",
"| | / /      ||            ",
"| |/ /       ||            ",
"| | /        ||.-''.       ",
"| |/         |/  _  \\      ",
"| |          ||  `/,|      ",
"| |          (\\\\`_.'       ",
"| |         .-`--'.        ",
"| |        /Y . . Y\\       ",
"| |       // |   | \\\\      ",
"| |      //  | . |  \\\\     ",
"| |     ')   |   |   (`    ",
"| |          ||'           ",
"| |          ||            ",
"| |          ||            ",
"| |          ||            ",
"| |         / |            ",
"\"\"\"\"\"\"\"\"\"\"||\"\"\"\"\"\"\"||\"\"\"|  ",
"|\"|\"\"\"\"\"\"\"|         '\"|\"|  ",
"| |                   | |  ",
": :                   : :  ",
". .                   . .  "
},
  /* state 6 */
{
"6  ___________.._______    ",
"| .__________))______|     ",
"| | / /      ||            ",
"| |/ /       ||            ",
"| | /        ||.-''.       ",
"| |/         |/  _  \\      ",
"| |          ||  `/,|      ",
"| |          (\\\\`_.'       ",
"| |         .-`--'.        ",
"| |        /Y . . Y\\       ",
"| |       // |   | \\\\      ",
"| |      //  | . |  \\\\     ",
"| |     ')   |   |   (`    ",
"| |          ||'||         ",
"| |          || ||         ",
"| |          || ||         ",
"| |          || ||         ",
"| |         / | | \\        ",
"\"\"\"\"\"\"\"\"\"\"||\"\"\"\"\"\"\"||\"\"\"|  ",
"|\"|\"\"\"\"\"\"\"|         '\"|\"|  ",
"| |                   | |  ",
": :                   : :  ",
". .                   . .  "
},
  /* state 7 */
{
"7  ___________.._______    ",
"| .__________))______|     ",
"| | / /      ||            ",
"| |/ /       ||            ",
"| | /        ||.-''.       ",
"| |/         |/  _  \\      ",
"| |          ||  `/,|      ",
"| |          (\\\\`_.'       ",
"| |         .-`--'.        ",
"| |        /Y . . Y\\       ",
"| |       // |   | \\\\      ",
"| |      //  | . |  \\\\     ",
"| |     ')   |   |   (`    ",
"| |          ||'||         ",
"| |          || ||         ",
"| |          || ||         ",
"| |          || ||         ",
"| |         / | | \\        ",
"\"\"\"\"\"\"\"\"\"\"|_`-' `-' |\"\"\"|  ",
"|\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|  ",
"| |        \\ \\        | |  ",
": :         \\ \\       : :  ",
". .          `'       . .  "
}
};

#endif /* HANGMAN_FIGURE_H */

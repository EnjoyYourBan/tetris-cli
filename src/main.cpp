/**
 * this is a project i started to learn c++ and the FTXUI library
*/
#include <ftxui/dom/elements.hpp> 
#include <ftxui/screen/screen.hpp>  
#include <string>   
#include <utility> 
#include <vector>   
#include <random>
#include "ftxui/component/captured_mouse.hpp" 
#include "ftxui/component/component.hpp"  
#include "ftxui/component/component_base.hpp" 
#include "ftxui/component/event.hpp"
#include "ftxui/component/mouse.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/canvas.hpp"
#include "ftxui/screen/color.hpp" 

using namespace ftxui;
struct Shape {
    int shape[4][4][4];
    int id;
    int rot=0;
};

struct Shape T_BLOCK = { { 
    {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0},
        {0}
    },
    {
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {0}
    },
    {
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {0}
    },
    {
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0}
    }
}, 1}; 
struct Shape O_BLOCK {
    {
        {
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0},
            {0}
        },
        {
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0},
            {0}
        },
        {
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0},
            {0}
        },
        {
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0},
            {0}
        }
    }, 2
};
struct Shape I_BLOCK { { 
    {
        {0},
        {1, 1, 1, 1},
        {0},
        {0}
    },
    {
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    {
        {0},
        {0},
        {1, 1, 1, 1},
        {0}
    },
    {
        {0, 1},
        {0, 1, 0, 0},
        {0, 1},
        {0, 1}
    }
}, 3};
struct Shape S_BLOCK = { {
    {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0},
        {0}
    },
    {
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0}
    },
    {
        {0},
        {0},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
    },
    {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0}
    }
}, 4};

struct Shape Z_BLOCK = { {
    {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0},
        {0}
    },
    {
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {0}
    },
    {
        {0},
        {0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
    },
    {
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {1, 0, 0, 0},
        {0}
    }
}, 5};

struct Shape L_BLOCK = { {
    {
        {0},
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0},
    },
    {
        {0, 1},
        {0, 1},
        {0, 1, 1},
        {0},
    },
    {
        {0},
        {1, 1, 1, 0},
        {1, 0, 0, 0},
        {0},
    },
    {
        {1, 1},
        {0, 1},
        {0, 1},
        {0},
    }
}, 6};
struct Shape J_BLOCK = { {
    {
        {1},
        {1, 1, 1, 0},
        {0},
        {0},
    },
    {
        {0, 1, 1},
        {0, 1},
        {0, 1},
        {0}
    },
    {
        {0},
        {1, 1, 1},
        {0, 0, 1},
        {0}
    },
    {
        {0, 1},
        {0, 1},
        {1, 1},
        {0}
    }
}, 7};

Color colors[7] = {Color::Purple, Color::Yellow1, Color::SkyBlue1, Color::Red, Color::LightGreen, Color::DarkOrange, Color::DarkBlue};
struct Shape SHAPES[7] = {T_BLOCK, I_BLOCK, S_BLOCK, O_BLOCK, Z_BLOCK, L_BLOCK, J_BLOCK};
struct Shape randomShape() {
    return SHAPES[rand() % 7];
}

class CoolCanvas : public Canvas {
    public:
        CoolCanvas(int x, int y) : Canvas(x, y)
        {

        }
        void drawGrid(int8_t sizex, int8_t sizey, int8_t x, int8_t y) {
            int xinc = sizex/x;
            for (int xAxis = 0; xAxis <= x; xAxis++) {
                DrawPointLine(xinc*xAxis, 0, xinc*xAxis, 200, Color::Gold1);
            }
            for (int yAxis = 0; yAxis <= y; yAxis++) {
                DrawPointLine(0, yAxis*10, 100, yAxis*10, Color::Red);
            }
        }

        int emptyGrids(int game[][10]) {
                int amm = 0;
                int n = sizeof(game[0]) / sizeof(game[0][0]);

                for (int y = 20; y > 1; y--) {

                    if (std::none_of(game[y], game[y]+n, [](int i) {
                        return i == 0;
                    })) {
                        for (int a = y-1; a > 2; a--) {
                            std::copy(std::begin(game[a]), std::end(game[a]), std::begin(game[a+1]));
                        }
                        y = 20;
                        amm++;
                    }
                }
                
                return amm;
        }

        void filledBlock(int x, int y, int size, Color color) {
            for (int loop = 0; loop < size; loop++)
                DrawBlockLine(x+loop, y, x+loop, y+size, color);
        }


        void drawBlocks() {
            for (int y = 0; y < 20; y++) {
                for (int x = 0; x < 10; x++) 
                    filledBlock(x*10, y*10, 8, Color::GrayDark);
            }
        }

        void drawGameBlocks(int arr[][10]) {
            for (int y = 0; y < 20; y++) {
                for (int x = 0; x < 10; x++) {
                    if (arr[y][x] != 0)
                        filledBlock(x*10, y*10, 8, colors[arr[y][x]-1]);
                }
            }
        }

        void renderPlayerPiece(struct Shape block, int origin[2]) {
            int piece_x = origin[0]*10;
            int piece_y = origin[1]*10;
            for (int x = 0; x < 4; x++) {
                for(int y = 0; y < 4; y++) {
                    if (block.shape[block.rot%4][y][x] != 0) {
                        filledBlock(piece_x+x*10, piece_y+y*10, 8, colors[block.id-1]);
                    }
                }
            }
        }


};

bool pieceHasRoom(struct Shape block, int atOrigin[2], int game[][10]) {
    int start_x = atOrigin[0];
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (atOrigin[1]+y < 0) {
                continue;
            }
            if (block.shape[block.rot%4][y][x] == 1 && (game[atOrigin[1]+y][x+start_x] != 0 || atOrigin[1]+y > 19) )
                return false;
            if (block.shape[block.rot%4][y][x] == 1 && (start_x+x > 9 || start_x+x < 0)) 
                return false;
        }
    }
    return true;
}

bool dropBlock(struct Shape block, int spot[2], int game[][10]) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (block.shape[block.rot%4][y][x] == 1) {
                if (y+spot[1] < 1) return false;
                game[y+spot[1]][x+spot[0]] = block.id;
            }
        }
    }

    return true;
}



int main() {
    int pieceLoc[2] = {5, -3};
    int gameArray[20][10] = {0};
    int frames = 0;
    int dropped = 0;
    int score = 0;
    int menu = 0;
    int gameSpeed = 30;

    struct Shape currentShape = randomShape();
    auto screen = ScreenInteractive::FitComponent();
    auto c = CoolCanvas(100, 200);

    std::vector<std::string> menu_entries = {"Tetris", "Credits"};
    std::vector<std::string> optionNames = {"Game Speed", "Colors"};

    auto radiobox = Menu(&menu_entries, &menu, MenuOption::Horizontal());
    auto credits = vbox({
        text("that sum' for loop - titty") | bold | center,
        text("holding the L - @knob") | bold | center,
        text("literally everything else - me") | bold | color(Color::Gold1) | center
    }) | size(WIDTH, EQUAL, 50);

    auto game_f = Renderer(radiobox, [&] {

        switch (menu){
            case 1:
                return credits;
        }

        if (0) { // game over
            std::fill(&gameArray[0][0], &gameArray[0][0] + sizeof(gameArray), 0);
            
            score = 0;
        }
        if (!pieceHasRoom(currentShape, pieceLoc, gameArray)) {
                // check if game should be over;
                pieceLoc[1]--;
                bool dropped = dropBlock(currentShape, pieceLoc, gameArray);
                if (!dropped) {
                    std::fill(&gameArray[0][0], &gameArray[0][0] + sizeof(gameArray), 0);
                }
                score += c.emptyGrids(gameArray) * 100;
                
                pieceLoc[0] = 5; pieceLoc[1] = -3;
                currentShape = randomShape();
                score = 0;
                frames = 0;
                
            }

        if (frames%gameSpeed == 0)
            pieceLoc[1]++;

        
        c.drawBlocks();
        c.drawGameBlocks(gameArray);

        c.renderPlayerPiece(currentShape, pieceLoc);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        frames++;
        screen.PostEvent(Event::Custom);
        return canvas(std::move(c));

    }) | CatchEvent([&](Event event) {
        if (menu != 0) return false;
        if (event == Event::ArrowDown) {
            frames=gameSpeed;
            return true;
        } else if (event == Event::ArrowLeft) {
            pieceLoc[0]--;
            if (!pieceHasRoom(currentShape, pieceLoc, gameArray))
                pieceLoc[0]++;
            return true;
        } else if (event == Event::ArrowRight) {
            pieceLoc[0]++;
            if (!pieceHasRoom(currentShape, pieceLoc, gameArray))
                pieceLoc[0]--;
            return true;
        } else if (event == Event::ArrowUp) {
            while (pieceHasRoom(currentShape, pieceLoc, gameArray))
                pieceLoc[1]++;
            pieceLoc[1]--;
            frames=gameSpeed;
        } else if (event == Event::Character('r')) {
            currentShape.rot++;
            if (!pieceHasRoom(currentShape, pieceLoc, gameArray))
            currentShape.rot--;
        }
        return false;
    });    
    
    auto component_renderer = Renderer(game_f, [&] {
        return vbox({
            separatorLight(),
            radiobox->Render()  | center,
            separatorLight() | flex,
            game_f->Render(),
        });
    });

    screen.Loop(component_renderer);
}
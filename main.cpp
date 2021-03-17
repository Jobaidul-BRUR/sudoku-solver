#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include "sudoku.h"

using namespace std;

typedef long long ll;

const int outer_box_width = 30;
const int outer_box_hight = 11;
const int inner_box_width = 8;
const int inner_box_hight = 3;
const int top_bottom_padding = 1;
const int left_right_padding = 3;
const ll maxN = 2e5+10; const ll maxB =      320; const ll  INF =     9187201950435737471; const int  INF_I =  2139062143;
const ll maxA = 1e6+10; const ll MOD  =    1e9+7; const ll mINF =    -9187201950435737472; const int mINF_I = -2139062144;



string left_margin; const int left_margin_len = 0;
signed main()
{
    //welcome_message();
    vector<string>grid = get_blank_grid();
    clear_border(grid);

    left_margin = "";
    for (int i = 0; i < left_margin_len; i++) left_margin.push_back(' ');
    //int cnt = 0;
    stack<tuple<int, int, int, vector<string>>>back_state, forward_state;
    int r, c; bool INVALID_POSITION = 0; int SOLVED = -1; bool INVALID_INPUT = 0; int STATE = 0;
    for (r = 1; r <= 9; r++)
    {
        for (c = 1; c <= 9; )
        {
            clear();
            //cout << ++cnt << endl;
            vector<string>temp_grid  = grid;
            //set_value_of_cell(temp_grid, r, c, "INS");
            activate_cell(temp_grid, r, c);
            for (auto s : temp_grid) cout << left_margin << s;
            //cout << "   #####################################################################################\n";
            cout << left_margin << "    Navigation:       (Key)            Command   : (Key)        Command        :   (Key)  \n";
            cout << left_margin << "    Up        :    up-arrow/u/U        Go back   :   <          Exit           :    e/E   \n";
            cout << left_margin << "    Down      :  down-arrow/d/D        Go forward:   >          Edit cell(" << r << ", " << c << "):   (Key)\n";
            cout << left_margin << "    Left      :  left-arrow/l/L        Solve     :  s/S         Value          :    1-9  \n";
            cout << left_margin << "    Right     : right-arrow/r/R        Reset     :  n/N         Blank          : space/0  \n";//|

            bool flag = 0;//Edit cell (" << r << ", " << c << ")
            if (SOLVED == 1)
            {
                cout << left_margin << "    Solved!\n"; flag = 1;
            }
            else if (SOLVED == 0)
            {
                cout << left_margin << "    This is not solvable!\n"; flag = 1;
            }
            if (INVALID_POSITION)
            {
                INVALID_POSITION = 0;
                cout << left_margin << "    Invalid position!\n"; flag = 1;
            }
            if (INVALID_INPUT)
            {
                INVALID_INPUT = 0;
                cout << left_margin << "    Invalid input!\n"; flag = 1;
            }
            if (STATE != 0)
            {
                if (STATE == -1) cout << left_margin << "    No back state exist!\n";
                else if (STATE == 1) cout << left_margin << "    No forward state exist!\n";
                STATE = 0; flag = 1;
            }
            if (not flag) cout << "\n";
            cout << left_margin << "    Press your choice ";
            //cout << left_margin << "   .";
            char choice = getch(); choice = tolower(choice);
            //cout << choice << " : " << (int)choice << endl;
            if (choice == -32)
            {
                choice = getch();
                if (choice == 'H') choice = 'u';
                else if (choice == 'M') choice = 'r';
                else if (choice == 'P') choice = 'd';
                else if (choice == 'K') choice = 'l';
                else choice = -32;
                //cout << choice << " : " << (int)choice << endl;
            }
            if (choice == ' ') choice = '0';
            if (choice >= '1' and choice <= '9')
            {
                if (choice-'0' != get_value_of_cell(grid, r, c))
                {
                    string str;
                    str.push_back(choice);
                    back_state.push(make_tuple(r, c, SOLVED, grid)); while (forward_state.size())forward_state.pop();
                    set_value_of_cell(grid, r, c, str); SOLVED = -1;
                }
                c++;
            }
            else if(choice == '0')
            {
                if (choice-'0' != get_value_of_cell(grid, r, c))
                {
                    back_state.push(make_tuple(r, c, SOLVED, grid)); while (forward_state.size())forward_state.pop();
                    set_value_of_cell(grid, r, c, "-"); SOLVED = -1;
                }
                c++;
            }
            else if (choice == 's')
            {
                if(SOLVED == -1)
                {
                    vector<string>prev_grid = grid;
                    SOLVED = solve(grid);
                    if (prev_grid != grid)
                    {
                        back_state.push(make_tuple(r, c, -1, prev_grid)); while (forward_state.size())forward_state.pop();
                    }
                }
            }
            else if (choice == 'u' or choice == 'd' or choice == 'l' or choice == 'r')
            {
                int x, y; tie(y, x) = tie(r, c);
                if (choice == 'u') y--;
                else if (choice == 'd') y++;
                else if (choice == 'l') x--;
                else if (choice == 'r') x++;

                if (x > 9)
                {
                    x = 1; y++;
                }
                else if (x < 1)
                {
                    x = 9; y--;
                }
                else if (y > 9)
                {
                    y = 1; x++;
                }
                else if (y < 1)
                {
                    y = 9; x--;
                }

                if (valid(y, x))
                {
                    tie(r, c) = tie(y, x);
                }
                else
                {
                    INVALID_POSITION = 1;
                }
            }
            else if (choice == 'n')
            {
                INVALID_POSITION = 0; SOLVED = -1; INVALID_INPUT = 0;
                vector<string>prev_grid = grid;
                grid = get_blank_grid(); clear_border(grid);
                if (grid != prev_grid)
                {
                    back_state.push(make_tuple(r, c, SOLVED, prev_grid)); while (forward_state.size())forward_state.pop();
                }
                r = 1; c = 1;
            }
            else if (choice == '<')
            {
                if (back_state.size())
                {
                    forward_state.push(make_tuple(r, c, SOLVED, grid));
                    tie(r, c, SOLVED, grid) = back_state.top(); back_state.pop();
                    INVALID_POSITION = 0; INVALID_INPUT = 0; STATE = 0;
                }
                else
                {
                    STATE = -1;
                    //cout << "No back grid\n";
                }
            }
            else if (choice == '>')
            {
                if (forward_state.size())
                {
                    back_state.push(make_tuple(r, c, SOLVED, grid));
                    tie(r, c, SOLVED, grid) = forward_state.top(); forward_state.pop();
                    INVALID_POSITION = 0; INVALID_INPUT = 0; STATE = 0;
                }
                else
                {
                    STATE = 1;
                    //cout << "No forward grid\n";
                }
            }
            else if (choice == 'e')
            {
                break;
            }
            else
            {
                INVALID_INPUT = 1;
            }
            //cout << left_margin << "    " << r << " - " << c << endl; getch();
            if (r == 9 and c == 10)
            {
                c = 9;
            }
        }
        if (c <= 9) break;
    }
    cout << endl << left_margin << "    closing program";
    for (int i = 0; i < 6; i++)
    {
        Sleep(300);
        cout << ".";
    }
    Sleep(2000);
    return 0;
}

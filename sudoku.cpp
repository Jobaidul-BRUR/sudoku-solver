#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
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


void clear()
{
    system("CLS");
}
void welcome_message()
{
    #define ST  250
    #define SLP Sleep(ST)
    cout << "\n\n\n";
    cout << "    W           W           W    E E E E E    L            C C C C C    O O O O O          M           M          E E E E E              T T T T T T   O O O O O\n"; SLP;
    cout << "     W         W W         W     E            L            C            O       O         M M         M M         E                           T        O       O\n"; SLP;
    cout << "      W       W   W       W      E            L            C            O       O        M   M       M   M        E                           T        O       O\n"; SLP;
    cout << "       W     W     W     W       E E E E E    L            C            O       O       M     M     M     M       E E E E E                   T        O       O\n"; SLP;
    cout << "        W   W       W   W        E            L            C            O       O      M       M   M       M      E                           T        O       O\n"; SLP;
    cout << "         W W         W W         E            L            C            O       O     M         M M         M     E                           T        O       O\n"; SLP;
    cout << "          W           W          E E E E E    L L L L L    C C C C C    O O O O O    M           M           M    E E E E E                   T        O O O O O\n"; SLP;

    cout << "\n\n\n"; SLP; SLP;
    cout << "    S S S S S    U       U    D D D       O O O O O    C C C C C    U       U              S S S S S    O O O O O    L        V           V   E E E E E    R R R R   \n"; SLP;
    cout << "    S            U       U    D     D     O       O    C            U       U              S            O       O    L         V         V    E            R      R  \n"; SLP;
    cout << "    S            U       U    D      D    O       O    C            U       U              S            O       O    L          V       V     E            R      R  \n"; SLP;
    cout << "    S S S S S    U       U    D      D    O       O    C            U       U              S S S S S    O       O    L           V     V      E E E E E    R R R R   \n"; SLP;
    cout << "            S    U       U    D      D    O       O    C            U       U                      S    O       O    L            V   V       E            R  R      \n"; SLP;
    cout << "            S    U       U    D     D     O       O    C            U       U                      S    O       O    L             V V        E            R    R    \n"; SLP;
    cout << "    S S S S S    U U U U U    D D D       O O O O O    C C C C C    U U U U U              S S S S S    O O O O O    L L L L L      V         E E E E E    R      R  \n"; SLP;

    //
    Sleep(1.5*1000);
    return ;
}
vector<string>get_blank_grid()
{
    vector<string>grid;
    grid.push_back( " _____________________________ _____________________________ _____________________________ \n");
    grid.push_back( "|   _______ _______ _______   |   _______ _______ _______   |   _______ _______ _______   |\n");
    grid.push_back( "|  |       |       |       |  |  |       |       |       |  |  |       |       |       |  |\n");
    grid.push_back( "|  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |\n");
    grid.push_back( "|  |_______|_______|_______|  |  |_______|_______|_______|  |  |_______|_______|_______|  |\n");
    grid.push_back( "|  |       |       |       |  |  |       |       |       |  |  |       |       |       |  |\n");
    grid.push_back( "|  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |\n");
    grid.push_back( "|  |_______|_______|_______|  |  |_______|_______|_______|  |  |_______|_______|_______|  |\n");
    grid.push_back( "|  |       |       |       |  |  |       |       |       |  |  |       |       |       |  |\n");
    grid.push_back( "|  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |\n");
    grid.push_back( "|  |_______|_______|_______|  |  |_______|_______|_______|  |  |_______|_______|_______|  |\n");
    grid.push_back( "|_____________________________|_____________________________|_____________________________|\n");
    grid.push_back( "|   _______ _______ _______   |   _______ _______ _______   |   _______ _______ _______   |\n");
    grid.push_back( "|  |       |       |       |  |  |       |       |       |  |  |       |       |       |  |\n");
    grid.push_back( "|  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |\n");
    grid.push_back( "|  |_______|_______|_______|  |  |_______|_______|_______|  |  |_______|_______|_______|  |\n");
    grid.push_back( "|  |       |       |       |  |  |       |       |       |  |  |       |       |       |  |\n");
    grid.push_back( "|  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |\n");
    grid.push_back( "|  |_______|_______|_______|  |  |_______|_______|_______|  |  |_______|_______|_______|  |\n");
    grid.push_back( "|  |       |       |       |  |  |       |       |       |  |  |       |       |       |  |\n");
    grid.push_back( "|  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |\n");
    grid.push_back( "|  |_______|_______|_______|  |  |_______|_______|_______|  |  |_______|_______|_______|  |\n");
    grid.push_back( "|_____________________________|_____________________________|_____________________________|\n");
    grid.push_back( "|   _______ _______ _______   |   _______ _______ _______   |   _______ _______ _______   |\n");
    grid.push_back( "|  |       |       |       |  |  |       |       |       |  |  |       |       |       |  |\n");
    grid.push_back( "|  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |\n");
    grid.push_back( "|  |_______|_______|_______|  |  |_______|_______|_______|  |  |_______|_______|_______|  |\n");
    grid.push_back( "|  |       |       |       |  |  |       |       |       |  |  |       |       |       |  |\n");
    grid.push_back( "|  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |\n");
    grid.push_back( "|  |_______|_______|_______|  |  |_______|_______|_______|  |  |_______|_______|_______|  |\n");
    grid.push_back( "|  |       |       |       |  |  |       |       |       |  |  |       |       |       |  |\n");
    grid.push_back( "|  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |  |   -   |   -   |   -   |  |\n");
    grid.push_back( "|  |_______|_______|_______|  |  |_______|_______|_______|  |  |_______|_______|_______|  |\n");
    grid.push_back( "|_____________________________|_____________________________|_____________________________|\n");

    return grid;
}
void clear_border(vector<string>&grid)
{
    for (int i = 0; i < 3*outer_box_hight+1; i++)
    {
        if (i%outer_box_hight == 0)
        {
            for (int j = 0; j < 3*outer_box_width+1; j++)
            {
                grid[i][j] = ' ';
            }
        }
        else
        {
            for (int j = 0; j < 4; j++)
            {
                grid[i][j*outer_box_width] = ' ';
            }
        }
    }
}
pair<int, int> get_pos(int r, int c)
{
    r--; c--;
    int R = r/3;
    int C = c/3;
    int y = R*outer_box_hight;
    int x = C*outer_box_width;
    y += top_bottom_padding;
    x += left_right_padding;

    r %= 3; c %= 3;

    y += inner_box_hight*r;
    x += inner_box_width*c;
    y += 2; x += 1;

    return make_pair(y, x);
}
int get_value_of_cell(vector<string>&grid, int r, int c)
{
    tie(r, c) = get_pos(r, c);

    return atoi(grid[r].substr(c, inner_box_width-1).c_str());
}
void set_value_of_cell(vector<string>&grid, int r, int c, string new_value)
{
    tie(r, c) = get_pos(r, c);

    deque<char>dq;
    for (char ch : new_value) dq.push_back(ch);
    for (int i = dq.size(); i < 7; i++)
    {
        dq.push_front(' '); i++;
        if (i > 7) break;
        dq.push_back(' ');
    }
    assert(dq.size() == inner_box_width-1);
    for (int i = 0; i < 7; i++)
    {
        grid[r][c+i] = dq[i];
    }
    return ;
}
bool valid(int y, int x)
{
    return y >= 1 and y <= 9 and x >= 1 and x <= 9;
}
void activate_cell(vector<string>& grid, int r, int c)
{
    tie(r, c) = get_pos(r, c);
    grid[r][c] = '>'; grid[r][c+1] = '>'; //grid[r-1][c] = '>'; grid[r+1][c] = '>';
    grid[r][c+6] = '<'; grid[r][c+6-1] = '<'; //grid[r-1][c+6] = '<'; grid[r+1][c+6] = '<';
    //grid[r+1][c+3] = '^';
    return ;
}

bool possible;
int sudoku[10][10];
bool row[10][10];
bool column[10][10];
bool block[3][3][10];
long long cnt;

tuple<int, int, int> pick()
{
    int r = -1, c = -1; int min_can = INF_I;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (sudoku[i][j] != 0) continue;
            int cnt = 0;
            for (int k = 1; k <= 9; k++)
            {
                if (row[i][k] == 0 and column[j][k] == 0 and block[(i-1)/3][(j-1)/3][k] == 0) cnt++;
            }
            if (cnt < min_can)
            {
                min_can = cnt; r = i; c = j;
            }
        }
    }
    return make_tuple(min_can, r, c);
}
void dfs()
{
    ++cnt;
    int r, c, can; tie(can, r, c) = pick();
    //cout << can << " (" << r << ", " << c << ")\n";
    //system("pause");
    if (possible)
    {
        cout << r << " " << c << endl;
        cout << "error\nTotal recursion: " << cnt << endl;
    }
    if (can == 0)
    {
        return;
    }
    if (r == -1 and c == -1)
    {
        possible = 1;
        return ;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (row[r][i] == 0 and column[c][i] == 0 and block[(r-1)/3][(c-1)/3][i] == 0)
        {
            row[r][i] = 1; column[c][i] = 1; block[(r-1)/3][(c-1)/3][i] = 1;
            sudoku[r][c] = i;
            dfs();
            if (possible) return;
            sudoku[r][c] = 0;
            row[r][i] = 0; column[c][i] = 0; block[(r-1)/3][(c-1)/3][i] = 0;
        }
    }
}
bool solve(vector<string>&grid)
{
    //for (string s : grid) cout << s;
    for (int r = 1; r <= 9; r++)
    {
        for (int c = 1; c <= 9; c++)
        {
            sudoku[r][c] = get_value_of_cell(grid, r, c);
            //cout << sudoku[r][c] << " \n"[ c == 9];
        }
    }
    possible = 0;
    memset(row, 0, sizeof row);
    memset(column, 0, sizeof column);
    memset(block, 0, sizeof block);
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            int x = sudoku[i][j];
            if (x >= 1 and x <= 9)
            {
                if (row[i][x] == 1 or column[j][x] == 1 or block[(i-1)/3][(j-1)/3][x] == 1) return 0;
                row[i][x] = 1; column[j][x] = 1; block[(i-1)/3][(j-1)/3][x] = 1;
            }
        }
    }
    possible = 0; cnt = 0;
    dfs();
    if (possible == 0) return 0;
    for (int r = 1; r <= 9; r++)
    {
        for (int c = 1; c <= 9; c++)
        {
            string str=""; str.push_back(sudoku[r][c]+'0');
            set_value_of_cell(grid, r, c, str);
        }
    }
    return 1;
}

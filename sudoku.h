using namespace std;

void clear();
void welcome_message();
vector<string>get_blank_grid();
void clear_border(vector<string>&grid);
pair<int, int> get_pos(int r, int c);
int get_value_of_cell(vector<string>&grid, int r, int c);
void set_value_of_cell(vector<string>&grid, int r, int c, string new_value);
bool valid(int y, int x);
void activate_cell(vector<string>& grid, int r, int c);
tuple<int, int, int> pick();
void dfs();
bool solve(vector<string>&grid);

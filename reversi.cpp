#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct num_point{
    int a;
    int b;
    num_point(int x, int y)
    {
        a = x;
        b = y;
    }
    num_point():num_point(0,0){}
};
typedef vector<num_point> vec;
class My_board{
public:
    My_board(){
        memset(m_board,0,81 * sizeof(int));
        //color = 0;
        /*int V[9][9] = {
                {0,0,0,0,0,0,0,0,0},
                {0,20, -3, 11, 8, 8, 11, -3, 20},
                {0,-3, -7, -4, 1, 1, -4, -7, -3},
                {0,11, -4, 2, 2, 2, 2, -4, 11},
                {0,8, 1, 2, -3, -3, 2, 1, 8},
                {0,8, 1, 2, -3, -3, 2, 1, 8},
                {0,11, -4, 2, 2, 2, 2, -4, 11},
                {0,-3, -7, -4, 1, 1, -4, -7, -3},
                {0,20, -3, 11, 8, 8, 11, -3, 20}
        };
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                m_weight[i][j] = V[i][j];
                //cout << V[i][j] << " ";
            }
            //cout << endl;
        }*/

    };
    void play_game();
    void show_board()
    {
        m_me = 0;
        m_other = 0;
        cout << "   a   b   c   d   e   f   g   h\n";
        cout << " +---+---+---+---+---+---+---+---\n";
        for (int i = 1; i <= 8; i++)
        {
            cout << i << "|";
            for (int j = 1; j <= 8; j++) {
                if (m_board[i][j] == 0)
                    cout << "   |";
                else if (m_board[i][j] == 1)
                {
                    cout << " O |";
                    m_me++;
                }
                else if (m_board[i][j] == 2)
                {
                    cout << " X |";
                    m_other++;
                }
            }
            cout << endl;
            cout << " +---+---+---+---+---+---+---+---\n";
        }
        cout << "I am O " << "me " << m_me << " other " << m_other << endl;
    }
private:
    int m_board[9][9]; // 1 me; 2 other; 0 empty
    int m_me, m_other;
    //m_weight[9][9];
    //int color;// 1 white; 2 black

    void update(int a, int b, vec& arr)//对ab点所在子更新
    {
        int t = m_board[a][b];// this kind
        int dir[9][2] = {{0,  0}, {-1, 0}, {-1, 1}, {0,  1}, {1,  1},
                         {1,  0}, {1,  -1}, {0,  -1}, {-1, -1}};
        for (int i = 1; i <= 8; i++) {
            int py = a, px = b, count = 0;
            while (py + dir[i][0] <= 8 && py + dir[i][0] >= 1
                   && px + dir[i][1] <= 8 && px + dir[i][1] >= 1
                   && m_board[py + dir[i][0]][px + dir[i][1]] != 0
                   && m_board[py + dir[i][0]][px + dir[i][1]] != t) {
                count++;
                py += dir[i][0];
                px += dir[i][1];
            }
            if (count && m_board[py + dir[i][0]][px + dir[i][1]] == t) //satisfy the request
            {
                py = a;
                px = b;
                while (py + dir[i][0] <= 8 && py + dir[i][0] >= 1
                       && px + dir[i][1] <= 8 && px + dir[i][1] >= 1
                       && m_board[py + dir[i][0]][px + dir[i][1]] != 0
                       && m_board[py + dir[i][0]][px + dir[i][1]] != t) {
                    py += dir[i][0];
                    px += dir[i][1];
                    m_board[py][px] = t;
                    num_point p(py,px);
                    arr.push_back(p);// note the point
                }
            }
        }
        //show_board();
    }
    void update(int a, int b)//对ab点所在子更新
    {
        int t = m_board[a][b];// this kind
        int dir[9][2] = {{0,  0}, {-1, 0}, {-1, 1}, {0,  1}, {1,  1},
                         {1,  0}, {1,  -1}, {0,  -1}, {-1, -1}};
        for (int i = 1; i <= 8; i++) {
            int py = a, px = b, count = 0;
            while (py + dir[i][0] <= 8 && py + dir[i][0] >= 1
                   && px + dir[i][1] <= 8 && px + dir[i][1] >= 1
                   && m_board[py + dir[i][0]][px + dir[i][1]] != 0
                   && m_board[py + dir[i][0]][px + dir[i][1]] != t) {
                count++;
                py += dir[i][0];
                px += dir[i][1];
            }
            if (count && m_board[py + dir[i][0]][px + dir[i][1]] == t) //satisfy the request
            {
                py = a;
                px = b;
                while (py + dir[i][0] <= 8 && py + dir[i][0] >= 1
                       && px + dir[i][1] <= 8 && px + dir[i][1] >= 1
                       && m_board[py + dir[i][0]][px + dir[i][1]] != 0
                       && m_board[py + dir[i][0]][px + dir[i][1]] != t) {
                    py += dir[i][0];
                    px += dir[i][1];
                    m_board[py][px] = t;
                    num_point p(py,px);
                    //arr.push_back(p);// note the point
                }
            }
        }
        //show_board();
    }
    void recall(int a, int b, vec & arr) {
        int t = 3 - m_board[a][b];//1 -> 2
        while (!arr.empty())
        {
            num_point p = arr.back();//只能pop一次啊！
            m_board[p.a][p.b] = t;
            arr.pop_back();
            // cout << "s";
        }
        m_board[a][b] = 0;
        //show_board();
    }//撤回操作
    int dyval()  {
        int my_tiles = 0, opp_tiles = 0, i, j, k, my_front_tiles = 0, opp_front_tiles = 0, x, y;
        double p = 0, c = 0, l = 0, f = 0, d = 0;

        int X1[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int Y1[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int V[8][8] = {{20, -3, 11, 8, 8, 11, -3, 20},
                    {-3, -7, -4, 1, 1, -4, -7, -3},
                    {11, -4, 2, 2, 2, 2, -4, 11},
                    {8, 1, 2, -3, -3, 2, 1, 8},
                    {8, 1, 2, -3, -3, 2, 1, 8},
                    {11, -4, 2, 2, 2, 2, -4, 11},
                    {-3, -7, -4, 1, 1, -4, -7, -3},
                    {20, -3, 11, 8, 8, 11, -3, 20},};
        int grid[8][8];
// Piece difference, frontier disks and disk squares
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
                grid[i][j] = m_board[i + 1][j + 1];
        }
        int my_color = 1, opp_color = 2;
        for(i=0; i<8; i++)
            for(j=0; j<8; j++)  {
                if(grid[i][j] == my_color)  {
                    d += V[i][j];
                    my_tiles++;
                } else if(grid[i][j] == opp_color)  {
                    d -= V[i][j];
                    opp_tiles++;
                }
                if(grid[i][j] != 0)   {
                    for(k=0; k<8; k++)  {
                        x = i + X1[k]; y = j + Y1[k];
                        if(x >= 0 && x < 8 && y >= 0 && y < 8 && grid[x][y] == '-') {
                            if(grid[i][j] == my_color)  my_front_tiles++;
                            else opp_front_tiles++;
                            break;
                        }
                    }
                }
            }
        if(my_tiles > opp_tiles)
            p = (100.0 * my_tiles)/(my_tiles + opp_tiles);
        else if(my_tiles < opp_tiles)
            p = -(100.0 * opp_tiles)/(my_tiles + opp_tiles);
        else p = 0;

        if(my_front_tiles > opp_front_tiles)
            f = -(100.0 * my_front_tiles)/(my_front_tiles + opp_front_tiles);
        else if(my_front_tiles < opp_front_tiles)
            f = (100.0 * opp_front_tiles)/(my_front_tiles + opp_front_tiles);
        else f = 0;

// Corner occupancy
        my_tiles = opp_tiles = 0;
        if(grid[0][0] == my_color) my_tiles++;
        else if(grid[0][0] == opp_color) opp_tiles++;
        if(grid[0][7] == my_color) my_tiles++;
        else if(grid[0][7] == opp_color) opp_tiles++;
        if(grid[7][0] == my_color) my_tiles++;
        else if(grid[7][0] == opp_color) opp_tiles++;
        if(grid[7][7] == my_color) my_tiles++;
        else if(grid[7][7] == opp_color) opp_tiles++;
        c = 25 * (my_tiles - opp_tiles);

// Corner closeness
        my_tiles = opp_tiles = 0;
        if(grid[0][0] == 0)   {
            if(grid[0][1] == my_color) my_tiles++;
            else if(grid[0][1] == opp_color) opp_tiles++;
            if(grid[1][1] == my_color) my_tiles++;
            else if(grid[1][1] == opp_color) opp_tiles++;
            if(grid[1][0] == my_color) my_tiles++;
            else if(grid[1][0] == opp_color) opp_tiles++;
        }
        if(grid[0][7] == 0)   {
            if(grid[0][6] == my_color) my_tiles++;
            else if(grid[0][6] == opp_color) opp_tiles++;
            if(grid[1][6] == my_color) my_tiles++;
            else if(grid[1][6] == opp_color) opp_tiles++;
            if(grid[1][7] == my_color) my_tiles++;
            else if(grid[1][7] == opp_color) opp_tiles++;
        }
        if(grid[7][0] == 0)   {
            if(grid[7][1] == my_color) my_tiles++;
            else if(grid[7][1] == opp_color) opp_tiles++;
            if(grid[6][1] == my_color) my_tiles++;
            else if(grid[6][1] == opp_color) opp_tiles++;
            if(grid[6][0] == my_color) my_tiles++;
            else if(grid[6][0] == opp_color) opp_tiles++;
        }
        if(grid[7][7] == 0)   {
            if(grid[6][7] == my_color) my_tiles++;
            else if(grid[6][7] == opp_color) opp_tiles++;
            if(grid[6][6] == my_color) my_tiles++;
            else if(grid[6][6] == opp_color) opp_tiles++;
            if(grid[7][6] == my_color) my_tiles++;
            else if(grid[7][6] == opp_color) opp_tiles++;
        }
        l = -12.5 * (my_tiles - opp_tiles);

/*
        my_tiles = num_valid_moves(my_color, opp_color, grid);
        opp_tiles = num_valid_moves(opp_color, my_color, grid);
        if(my_tiles > opp_tiles)
            m = (100.0 * my_tiles)/(my_tiles + opp_tiles);
        else if(my_tiles < opp_tiles)
            m = -(100.0 * opp_tiles)/(my_tiles + opp_tiles);
        else m = 0;
*/
// final weighted score
        double score = (10 * p) + (801.724 * c) + (382.026 * l) + (74.396 * f) + (10 * d);
        return (int)score;
    }
    /*
     定义极大层的下界为alpha，极小层的上界为beta，alpha-beta剪枝规则描述如下：
    （1）alpha剪枝。若任一极小值层结点的beta值不大于它任一前驱极大值层结点的alpha值，
     即alpha(前驱层) >= beta(后继层)，则可终止该极小值层中这个MIN结点以下的搜索过程。
     这个MIN结点最终的倒推值就确定为这个beta值。
    （2）beta剪枝。若任一极大值层结点的alpha值不小于它任一前驱极小值层结点的beta值，
     即alpha(后继层) >= beta(前驱层)，则可以终止该极大值层中这个MAX结点以下的搜索过程，
     这个MAX结点最终倒推值就确定为这个alpha值。
     https://blog.csdn.net/qq_27008079/article/details/60869054
     */
    int Min (int depth, int alpha, int beta)//对手turn, beta为极小层上界
    {
        int value;
        if (depth <= 0)
        {
            //return val();
            return dyval();
        }
        int a = 0, b = 0;
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                if (can_move(i,j,2))//对手可以下子
                {
                    vec arr;
                    m_board[i][j] = 2;
                    update(i,j,arr);
                    value = Max(depth - 1, alpha, beta);
                    if (value < beta)
                        beta = value;
                    recall(i,j,arr);
                    if (beta <= alpha)
                        //小于上一层（极大）之前的最大值
                        // 不用搜 因为上一层不会选这个节点了
                        return beta;
                }
                if (can_move(i,j,2))
                    b = 1;
                if (can_move(i,j,1))
                    a = 1;
            }
        }
        //************
        if (b == 0)
        {
            if (a)
                return Max(depth - 1, alpha, beta);
            else
                return dyval();
            //return val();
        }
        return beta;
    }
    int Max (int depth, int alpha, int beta)//自己turn,alpha为极大层下界
    {
        int a = 0, b = 0;
        int value;
        if (!depth)
        {
            //return val();
            return dyval();
        }
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                if (can_move(i, j, 1))//自己可以下子
                {
                    vec arr;
                    m_board[i][j] = 1;
                    update(i, j, arr);
                    value = Min(depth - 1, alpha, beta);
                    if (value > alpha)
                        alpha = value;
                    recall(i, j, arr);
                    if (alpha >= beta)
                        // alpha大于上一层的最小值，上一层不会选！
                        return alpha;
                    //为什么要return alpha?
                    //相当于return max
                }
                if (can_move(i,j,2))
                    b = 1;
                if (can_move(i,j,1))
                    a = 1;
            }
        }
        //************
        if (a == 0)
        {
            if (b)
                return Min(depth - 1, alpha, beta);
            else
                dyval();
            //return val();
        }
        return alpha;// 同
    }
    num_point MinMax(int depth){
        int ma = -999999, value;
        num_point p;
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                if (can_move(i,j,1))//自己可以下子
                {
                    vec arr;
                    m_board[i][j] = 1;
                    update(i,j,arr);
                    value = Min(depth - 1, -999999, 999999);
                    if (value > ma)
                    {
                        ma = value;
                        p.a = i; p.b = j;
                    }
                    recall(i,j,arr);
                }
            }
        }
        return p;
    }//返回一个要下的点
    int can_move(int a, int b, int side)//可以下子返回1
    {
        int dir[9][2] = {{0,0},{-1,0},{-1,1},{0,1},{1,1},
                         {1,0},{1,-1},{0,-1},{-1,-1}};
        int mark = 0, opponent = 3 - side;
        if (m_board[a][b] == 0)//don't have chess
        {
            for (int i = 1; i <= 8; i++)
            {
                int count = 0;
                int py = a, px = b;
                // 1 me; 2 other; 0 empty
                while (py + dir[i][0] <= 8 && py + dir[i][0] >= 1
                       && px + dir[i][1] <= 8 && px + dir[i][1] >= 1
                       && m_board[py + dir[i][0]][px + dir[i][1]] == opponent)
                {
                    count++;
                    py += dir[i][0]; px += dir[i][1];//更新位置
                }
                if (count){py += dir[i][0]; px += dir[i][1];}//再往前走一步
                if (px <= 8 && px >= 1 && py <= 8 && py >= 1
                    && m_board[py][px] == side)//有自己的子
                {
                    mark = 1;
                    break;
                }
            }
        }
        if (mark)
            return 1;
        else
            return 0;
    }
    //**********************
    void initialize();
    void first_round();
    void play_rounds();
    void play() {
        num_point p = MinMax(6);
        //cout << "aaaa";
        if (p.a >= 1 && p.a <= 8 && p.b >= 1 && p.b <= 8)
        {
            //cout << p.a << " " << p.b;
            m_board[p.a][p.b] = 1;// play me turn
            cout << (char)(p.b + 'a' - 1) << " " << p.a << endl;
            update(p.a,p.b);
        } else
            cout << "PASS\n";
    }

};
void My_board::initialize()
{
    char input[30] = {0};
    char a; int b;
    cin >> input;
    cin.get();
    if (strcmp(input, "START") == 0)
    {
        cin >> input;
        while (1)
        {
            if (strcmp(input,"DONE") == 0)
            {
                cin.get();
                cout << "OK\n";
                break;
            }
            else if (strcmp(input,"PLACE") == 0)
            {
                int i;
                cin >> a >> b >> i;
                cin.get();
                m_board[b][(int)a - 'a' + 1] = i;
            }
            else
                cout << "wrong ini!\n";
            cin >> input;
        }
    }
}
void My_board::first_round() {
    char input[20];
    char col;
    int row;
    cin >> input;
    if (strcmp(input,"BEGIN") == 0)//you are black (2)
    {
        cin.get();
        play();
    }
    else if (strcmp(input,"TURN") == 0)//you are white (1)
    {
        cin >> col >> row;
        cin.get();
        // 1 white; 2 black; 0 empty
        if (m_board[row][col - 'a' + 1] == 0 && (col - 'a' + 1) >= 1
            && (col - 'a' + 1) <= 8 && (row) >= 1 && (row) <= 8)
        {
            //m_board[row][col - 'a' + 1] = color;
            m_board[row][col - 'a' + 1] = 2;
            update(row, col - 'a' + 1);
            play();
        }
        /*else
            cout << "input wrong position.\n";*/
    }

}
void My_board::play_rounds() {
    char input[20];
    cin >> input;
    while(1)
    {
        if (strcmp(input,"s") == 0)
        {
            cin.get();
            show_board();
        }
        else{
            if (strcmp(input, "END") == 0)
                break;
            if (strcmp(input, "TURN") == 0) // get input
            {
                char col;
                int row;
                cin >> col >> row;
                cin.get();
                if (m_board[row][col - 'a' + 1] == 0 && (col - 'a' + 1) >= 1
                    && (col - 'a' + 1) <= 8 && (row) >= 1 && (row) <= 8)
                {
                    //m_board[row][col - 'a' + 1] = color;
                    m_board[row][col - 'a' + 1] = 2;
                    update(row, col - 'a' + 1);
                }
            }
            if (strcmp(input, "PASS") == 0)
                cin.get();
            play();
        }
        cin >> input;
    }
}
void My_board::play_game() {
    initialize();
    first_round();
    play_rounds();
}
int main()
{
    My_board board;
    board.play_game();
    return 0;
}

//Name: Micah Arndt
//File Name: p01.cpp
#include <iostream>
#include <iomanip>

typedef char Board[8][8];

//Constants
const bool BLACK = 1;
const bool WHITE = 0;
const char Black_Piece = '@';
const char White_Piece = '0';
const int BOARD_SIZE = 8;

//Function To Print the Help message
void help()
{
 std::cout << "The official rules can be found at\n"
                          << "https://en.wikipedia.org/wiki/Reversi\n"
                          << std::endl;

                std::cout << "The Othello board is set up in the following manner\n";
                std::cout << std::endl;

                std::cout << "  ABCDEFGH\n"
                          << " +--------+\n"
                          << "1|        |1\n"
                          << "2|        |2\n"
                          << "3|        |3\n"
                          << "4|   O@   |4\n"
                          << "5|   @O   |5\n"
                          << "6|        |6\n"
                          << "7|        |7\n"
                          << "8|        |8\n"
                          << " +--------+\n"
                          << "  ABCDEFGH\n"
                          << std::endl;

                std::cout << "BLACK plays @ and WHITE plays O. Players take turns in entering\n"
                          << "moves. The first player to move is BLACK. To place a @\n"
                          << "at row 6 and column E, BLACK enters E6. The result of the move\n"
                          << "is\n"
                          << std::endl;

                std::cout << "  ABCDEFGH\n"
                          << " +--------+\n"
                          << "1|        |1\n"
                          << "2|        |2\n"
                          << "3|        |3\n"
                          << "4|   O@   |4\n"
                          << "5|   @@   |5\n"
                          << "6|    @   |6\n"
                          << "7|        |7\n"
                          << "8|        |8\n"
                          << " +--------+\n"
                          << "  ABCDEFGH\n"
                          << std::endl;
                
                std::cout <<  std::endl;
                std::cout << "Note that the WHITE at E5 is now a BLACK piece.\n" << std::endl;
               
}


//Initializes the board
void init(Board &b, int &num_Spaces)
{
    num_Spaces = 0;
    //Sets Initial Values for the Board
    for (int y = 0; y < BOARD_SIZE; ++y)
    {
        for (int x = 0; x < BOARD_SIZE; ++x)
        {
            
            if ((x == 4 && y == 4) || (x == 3 && y == 3))
                b[y][x] = '0';
            
            
            else if ((x == 4 && y == 3) || (x == 3 && y == 4))
            {
                b[y][x] = '@';
            }
            else
            {
                b[y][x] = ' ';
                ++num_Spaces;
            } 
        }
    }

   
}

//prints the Board
void draw(Board b)
{
    
    std::cout << "  ABCDEFGH\n"
              << " +--------+\n"
              << "1|";
    for(int y = 0; y < 1; ++y)
    {
        for (int x = 0; x < 8; ++x)
        {
            std::cout << b[y][x];
        }
    }
    std::cout << "|1\n"
              << "2|";
    for(int y = 1; y < 2; ++y)
       {
        for (int x = 0; x < 8; ++x)
        {
            std::cout << b[y][x];
        }
       }
    std::cout << "|2\n"
              << "3|";
    for(int y = 2; y < 3; ++y)
    {
        for (int x = 0; x < 8; ++x)
        {
            std::cout << b[y][x];
        }
    }
    std::cout << "|3\n"
              << "4|";
    for(int y = 3; y < 4; ++y)
        {
            for (int x = 0; x < 8; ++x)
            {
                std::cout << b[y][x];
            }
        }
    std::cout << "|4\n"
              << "5|";
    for(int y = 4; y < 5; ++y)
        {
            for (int x = 0; x < 8; ++x)
            {
                std::cout << b[y][x];
            }
        }
    std::cout << "|5\n"
              << "6|";
    for(int y = 5; y < 6; ++y)
    {
        for (int x = 0; x < 8; ++x)
        {
            std::cout << b[y][x];
        }
    }
    std::cout << "|6\n"
              << "7|";
    for(int y = 6; y < 7; ++y)
    {
        for (int x = 0; x < 8; ++x)
        {
            std::cout << b[y][x];
        }
    }
    std::cout << "|7\n"
              << "8|";
    for(int y = 7; y < 8; ++y)
    {
        for (int x = 0; x < 8; ++x)
        {
            std::cout << b[y][x];
        }
    }
    std::cout  << "|8\n"
               << " +--------+\n"
               << "  ABCDEFGH\n"
               << std::endl;
}

//Gets the row from the input
int get_row(char command[])
{
    int row;
    row = command[1] - '1';
    return row;
}

//Gets the Col from the Input
int get_col (char command[])
{
    
    int col = command[0] - 'A';
    return col;
}

//Gets all valid positions

//Checks Vertically down one for the oppposin piece
bool row_vert_dwn(Board b, int row, int col, bool turn)
{
    bool downOk = 0;
    if (turn)
    {
        for (int i = row + 1; i < BOARD_SIZE; ++i)
        {
            if (b[i + 1][col] == White_Piece && row != 7)
            {
                downOk = 1;
            }
            if (b[i + 1][col] == White_Piece && b[i + 2][col] == ' ')
            {
                return 0;
            }
            if (b[i + 1][col] == Black_Piece && b[i][col] == White_Piece)
            {
                return 1;
                
            }
            if (b[i + 1][col] == ' ')
            {
                return 0;
            }
        }
        return 0;
    }

    else
    {
        for (int i = row + 1; i < BOARD_SIZE; ++i)
        {
            if (b[i + 1][col] == Black_Piece && row != 7)
            {
                downOk = 1;
            }
            if (b[i + 1][col] == Black_Piece && b[i + 2][col] == ' ')
            {
                return 0;
            }

            if (b[i + 1][col] == White_Piece && b[i][col] == Black_Piece)
            {
                return 1;
            }

            if (b[i + 1][col] == ' ')
            {
                return 0;
            }
        }
        return 0;
    }
    return 0;
}

//Checks Vertically up for the opposing piece
bool row_vert_up(Board b, int row, int col, bool turn)
{
    bool upOk = 0;
    if (turn)
    {
        for (int i = row; i > 0; --i)
        {
            if (b[i][col] == White_Piece && i != 0)
            {
                if (b[i - 1][col] == Black_Piece)
                {
                    return 1;
                }
                
                if (b[i-1][col] == ' ')
                {
                    return 0;
                }
            }
        }
        return 0;
    }
            
            
        
    
    else
    {
        
        for (int i = row; i > 0; --i)
        {
            if (b[i][col] == Black_Piece && i != 0)
            {
                if (b[i - 1][col] == White_Piece)
                {
                    return 1;
                }
                
                if (b[i - 1][col] == ' ')
                {
                    return 0;
                }
            }
        }
        return 0;
            
        
    }
    return 0;
}



//checks Right one for a Piece that can be captured
bool col_right(Board b, int row, int col, bool turn)
{
    bool RightOk = 0;
    if (turn)
    {
        if (b[row][col + 1] == White_Piece && col != 7)
        {
            for (int i = col; i < BOARD_SIZE; ++i)
            {               
                if (b[row][i + 1] == Black_Piece)
                {
                    return 1;
                }
                
                if (b[row][i + 1] == ' ')
                {
                    return 0;
                }
               
            }
            return 0;
        }
        return 0;
    }

    else
    {
        if (b[row][col + 1] == Black_Piece && col != 7)
        {
            for (int i = col + 1; i < BOARD_SIZE; ++i)
            {
                if (b[row][i + 1] == White_Piece)
                {
                    return 1;
                }
                
                if (b[row][i + 1] == ' ')
                {
                    return 0;
                }
                
                
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

//checks left for a piece to be captured
bool col_left(Board b, int row, int col, bool turn)
{
    bool leftOk = 0;
    if (turn)
    {
        if (b[row][col - 1] == White_Piece && col != 0)
        {
            for (int i = col; i > 0; --i)
            {
                if (b[row][i - 1] == Black_Piece)
                {
                    return 1;
                }
                
                if (b[row][i - 1] == ' ')
                {
                    return 0;
                }
            }
            return 0; 
        }
    }

    else
    {
        if (b[row][col - 1] == Black_Piece && col != 0)
        {
            for (int i = col; i > 0; --i)
            {
                if (b[row][i - 1] == White_Piece)
                {
                    return 1;
                }
                
                if (b[row][i - 1] == ' ')
                {
                    return 0;
                }
            }
            return 0;
        }
    }
    return leftOk;
}


//checks Diagonally Down and Left for a captureable piece
bool diagDLeft(Board b, int row, int col, bool turn)
{
   

    if (turn)
    {
        if (b[row + 1][col - 1] == White_Piece && row != 7 && col != 0)
        {
            for (int i = row; i < BOARD_SIZE; ++i)
            {
                if (b[i + 1][col - 1] == Black_Piece)
                {
                    return 1;
                }

                if (b[i + 1][col - 1] == ' ')
                {
                    return 0;
                }
                --col;
            }
            return 0;
            
        }
    }

    else
    {
        if (b[row + 1][col - 1] == Black_Piece && row != 7 && col != 0)
        {
            for (int i = row; i < BOARD_SIZE; ++i)
            {
                if (b[i + 1][col - 1] == White_Piece)
                {
                    return 1;
                }

                if (b[i + 1][col - 1] == ' ')
                {
                    return 0;
                }
                --col;
            }
        }
    }

    return 0;
}

bool diagDRight(Board b, int row, int col, bool turn)
{
    
    if (turn)
    {
        if (b[row + 1][col + 1] == White_Piece && row != 7 && col != 7)
        {
            for (int i = row; i < BOARD_SIZE; ++i)
            {
                if (b[i + 1][col + 1] == Black_Piece)
                {
                    return 1;
                }

                if (b[i + 1][col + 1] == ' ')
                {
                    return 0;
                }
                ++col;
            }
            return 0;
        }
    }

    else
    {
        if (b[row + 1][col + 1] == Black_Piece)
        {
            for (int i = row; i < BOARD_SIZE; ++i)
            {
                if (b[i + 1][col + 1] == White_Piece)
                {
                    return 1;
                }

                if (b[i + 1][col + 1] == ' ')
                {
                    return 0;
                }
                ++col;
            }
            return 0;
        }
    }

     return 0;
}

bool diagULeft(Board b, int row, int col, bool turn)
{
    if (turn)
    {
        if (b[row - 1][col - 1] == White_Piece && (row != 0 && col != 0))
        {
            for (int i = row; i > 0; --i)
            {
                if (b[i - 1][col - 1] == Black_Piece)
                {
                    return 1;
                }

                if (b[i - 1][col - 1] == ' ')
                {
                    return 0;
                }
                --col;
            }
        }
    }

    else
    {
        if (b[row - 1][col - 1] == Black_Piece && row != 0 && col != 0)
        {
            for (int i = row; i > 0; --i)
            {
                if (b[i - 1][col - 1] == White_Piece)
                {
                    return 1;
                }

                if (b[i - 1][col - 1] == ' ')
                {
                    return 0;
                }
                --col;
            }
            return 0;
        }
    }

    return 0;
}

bool diagURight(Board b, int row, int col, bool turn)
{
    
    if (turn)
    {
        if (b[row - 1][col + 1] == White_Piece)
        {
            for (int i = row; i > 0; --i)
            {
                if (b[i - 1][col + 1] == Black_Piece)
                {
                    return 1;
                }

                if (b[i - 1][col + 1] == ' ')
                {
                    return 0;
                }
                ++col;
            }
            return 0;
        }
    }

    else
    {
        if (b[row - 1][col + 1] == Black_Piece && row != 0 && col != 7)
        {
            for (int i = row; i > 0; --i)
            {
                if (b[i - 1][col + 1] == White_Piece)
                {
                    return 1;
                }

                if (b[i - 1][col + 1] == ' ')
                {
                    return 0;
                }
                ++col;
            }
            return 0;
        }
    }

    return 0;
}

void get_valid_position(bool whos_turn, Board b, int valid_row[], int valid_col[], int &val_length)
{
    
    val_length = 0;
    valid_row[val_length] = -1;
    valid_col[val_length] = -1;
    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        
        for (int col = 0; col < BOARD_SIZE; ++col)
        {
           
            if(b[row][col] == ' ' && (row_vert_dwn(b, row, col, whos_turn) || row_vert_up(b, row, col, whos_turn)
                                      || col_right(b, row, col, whos_turn) || col_left(b, row, col, whos_turn)
                                      || diagDLeft(b, row, col, whos_turn)
                                      || diagDRight(b, row, col, whos_turn)
                                      || diagULeft(b, row, col, whos_turn)
                                      || diagURight(b, row, col, whos_turn)))
            {
                valid_row[val_length] = row;
                valid_col[val_length] = col;
                ++val_length;
                
            }
        }
    }
    

}

//Function to handle Swapping
void swap(Board b, int row, int col, bool whos_turn, int &White_Score, int &Black_Score)
{
    int start_row = row;
    int start_col = col;
    int swap_length = 0;
     
    //For Swapping Vertically
    if (row_vert_dwn(b, start_row, start_col, whos_turn))
    {
        while (1)
        {
            if (whos_turn)
            {
                if (b[row + 2][col] == ' ' && b[row + 1][col] == White_Piece)
                {
                    swap_length = 0;
                    break;
                }
            }
            else
            {
                if (b[row + 2][col] == ' ' && b[row + 1][col] == Black_Piece)
                {
                    swap_length = 0;
                    break;
                }
            }
            if (whos_turn)
            {
                if (b[row + 1][col] == Black_Piece)
                {
                    ++swap_length;
                    break;
                }
                ++swap_length;
            }
            else
            {
                if (b[row + 1][col] == White_Piece)
                {
                    ++swap_length;
                    break;
                }
                ++swap_length;
            }
            ++row;
        }
        
        
        if(swap_length > 1)
        {
            for (int i = start_row + 1; i <= start_row + swap_length; ++i)
            {
                if(whos_turn)
                {
                    b[i][col] = Black_Piece;
                }
                
                else
                {
                    b[i][col] = White_Piece;
                }
            }
        }
    }
   
    
    row = start_row;
    col = start_col;
    swap_length = 0;
    if (row_vert_up(b, row, col, whos_turn))
    {
        while (1)
        {
            if (whos_turn)
            {
                if (b[row - 2][col] == ' ' && b[row - 1][col] == White_Piece)
                {
                    swap_length = 0;
                    break;
                }
            }

            else
            {
                if (b[row - 2][col] == ' ' && b[row - 1][col] == Black_Piece)
                {
                    swap_length = 0;
                    break;
                }
            }
            if (whos_turn)
            {
                if (b[row - 1][col] == Black_Piece)
                {
                    ++swap_length;
                    break;
                }
                ++swap_length;
            }
            else
            {
                if (b[row - 1][col] == White_Piece)
                {
                    ++swap_length;
                    break;
                }
                ++swap_length;
            }
            --row;
        }
        if (swap_length != 0)
        {
            
            for (int i = start_row -1; i >= row; --i)
            {
                if(whos_turn)
                {
                    b[i][col] = Black_Piece;
                }
                
                else
                {
                    b[i][col] = White_Piece;
                }
            
            }
        }
    }
    
    
    swap_length = 0;
    row = start_row;
    col = start_col;
    
    //For Swapping to the left
    if (col_left(b, row, col, whos_turn))
    {
        while (1)
        {
            if (b[row][col - 1] == ' ')
            {
                swap_length = 0;
                break;
            }
            if(whos_turn)
            {
                if (b[row][col - 1] == Black_Piece)
                {
                    ++swap_length;
                    break;
                }
                ++swap_length;
            }

            else if (b[row][col - 1] == White_Piece && !whos_turn)
            {
                ++swap_length;
                break;
            }
            ++swap_length;
            --col;
        }
        
        for (int i = col; i <= start_col; ++i)
        {
            if(whos_turn)
            {
                b[row][i] = Black_Piece;
            }

            else
            {
                b[row][i] = White_Piece;
            }
        }
        
    }
    
    row = start_row;
    col = start_col;
    swap_length = 0;

    //For Swapping to the right
    if (col_right(b, start_row, start_col, whos_turn))
    {
        while (1)
        {
            if (b[row][col + 1] == ' ')
            {
                swap_length = 0;
                break;
            }
            if (whos_turn)
            {
                if (b[row][col + 1] == Black_Piece)
                {
                    ++swap_length;
                    break;
                }
                ++swap_length;
            }

            else
            {
                if (b[row][col + 1] == White_Piece)
                {
                    ++swap_length;
                    break;
                }
                ++swap_length;
            }
            ++col;
        }
        for (int i = start_col; i <= col; ++i)
        {
            if(whos_turn)
            {
                b[row][i] = Black_Piece;
            }

            else
            {
                b[row][i] = White_Piece;
            }
        }
    }
   
        
    
    swap_length = 0;
    row = start_row;
    col = start_col;
   
    //For Swapping Diagonally to the right and down
    if (diagDRight(b, start_row, start_col, whos_turn))
    {
        while (1)
        {
            if (b[row + 1][col + 1] == ' ')
            {
                swap_length = 0;
                break;
            }
            if (whos_turn)
            {
                if (b[row + 1][col + 1] == Black_Piece)
                {
                    ++swap_length;
                    break;
                }
                ++swap_length;
            }

            else
            {
                if (b[row + 1][col + 1] == White_Piece)
                {
                    ++swap_length;
                    break;
                }
                ++swap_length;
            }
            ++col;
            ++row;
        }
        
        col = start_col;
        for (int i = start_row; i < start_row + swap_length; ++i)
        {
            if(whos_turn)
            {
                b[i][col] = Black_Piece;
            }

            else
            {
                b[i][col] = White_Piece;
            }
            ++col;
        }
    }
    

    swap_length = 0;
    row = start_row;
    col = start_col;
    
    //for swapping Diagonally to the left and down
    if (diagDLeft(b, start_row, start_col, whos_turn))
    {
        while (1)
        {
            if (b[row + 1][col - 1] == ' ')
            {
                swap_length = 0;
                break;
            }
            if (whos_turn)
            {
                if (b[row + 1][col - 1] == Black_Piece)
                {
                    ++swap_length;
                    break;
                }
                ++swap_length;
            }

            else
            {
                if (b[row + 1][col - 1] == White_Piece)
                {
                    ++swap_length;
                    break;
                }
                ++swap_length;
            }
            --col;
            ++row;
        }
        
        col = start_col;
        for (int i = start_row; i < start_row + swap_length; ++i)
        {
            if(whos_turn)
            {
                b[i][col] = Black_Piece;
            }

            else
            {
                b[i][col] = White_Piece;
            }
            --col;
        }
    }
   
    
     swap_length = 0;
     row = start_row;
     col = start_col;
     
    //for swapping Diagonally to the right and up
     
     if (diagURight(b, start_row, start_col, whos_turn))
     {
         while (1)
         {
             if (b[row - 1][col + 1] == ' ')
             {
                 swap_length = 0;
                 break;
             }
             if (whos_turn)
             {
                 if (b[row - 1][col + 1] == Black_Piece)
                 {
                     ++swap_length;
                     break;
                 }
                 ++swap_length;
             }
             
             else
             {
                 if (b[row - 1][col + 1] == White_Piece)
                 {
                     ++swap_length;
                     break;
                 }
                 ++swap_length;
             }
             ++col;
             --row;
         }
         
         col = start_col;
         for (int i = start_row; i > start_row - swap_length; --i)
         {
             if(whos_turn)
             {
                 b[i][col] = Black_Piece;
             }
             
             else
             {
                 b[i][col] = White_Piece;
             }
             ++col;
         }
     }
     

     swap_length = 0;
     row = start_row;
     col = start_col;
     
     //for swapping diagonnally to the left and up
      if (diagULeft(b, start_row, start_col, whos_turn))
     {
         while (1)
         {
             if (b[row - 1][col - 1] == ' ')
             {
                 swap_length = 0;
                 break;
             }
             if (whos_turn)
             {
                 if (b[row - 1][col - 1] == Black_Piece)
                 {
                     ++swap_length;
                     break;
                 }
                 ++swap_length;
             }
             
             else
             {
                 if (b[row - 1][col - 1] == White_Piece)
                 {
                     ++swap_length;
                     break;
                 }
                 ++swap_length;
             }
             --col;
             --row;
         }
         
         col = start_col;
         for (int i = start_row; i >= row; --i)
         {
             if(whos_turn)
             {
                 b[i][col] = Black_Piece;
             }
             
             else
             {
                 b[i][col] = White_Piece;
             }
             --col;
         }
     }
     

}

void declareWinner(Board b, int &White_Score, int &Black_Score)
{
    for (int y = 0; y < BOARD_SIZE; ++y)
    {
        for (int x = 0; x < BOARD_SIZE; ++x)
        {
            if (b[y][x] == Black_Piece)
            {
                ++Black_Score;
            }

            if (b[y][x] == White_Piece)
            {
                ++White_Score;
            }
        }
    }

    std::cout << "Final Score" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << std::setw(4);
    if (Black_Score > White_Score)
    {
        std::cout << Black_Score << " : " << White_Score << std::endl;
        std::cout << "Black WINS with a score of " << Black_Score << std::endl;
    }

    if (White_Score > Black_Score)
    {
        std::cout << Black_Score << " : " << White_Score << std::endl;
        std::cout << "White WINS with a score of " << White_Score << std::endl;
    }

    if (White_Score == Black_Score)
    {
        std::cout << Black_Score << " : " << White_Score << std::endl;
        std::cout << "Black and White TIE with a score of " << Black_Score << std::endl;
    }
}
//Controls Playing the game
void play()
{
    Board b;
    int row;
    int col;
    int black_score = 0;
    int white_score = 0;
    int val_row[64] = {-1};
    int val_col[64] = {-1};
    int num_Spaces = 0;
    init(b, num_Spaces);
    draw(b);
    bool whos_turn = BLACK;
    char command [100];
    bool valid_move = 0;
    int val_length = 0;
    int consecutiveTurnsSkiped = 0;
    while (1)
    {
       
        if (consecutiveTurnsSkiped == 2 || num_Spaces == 0)
        {
            std::cout << "No more valid moves can be made." << std::endl;
            std::cout << std::endl;
            break;
        }

      get_valid_position(whos_turn, b, val_row, val_col, val_length);
      
        
      if (val_length == 0)
            {
                if (whos_turn)
                {
                    whos_turn = WHITE;
                    
                }

                else
                {
                    whos_turn = BLACK;
                }
                ++consecutiveTurnsSkiped;
                continue;
            }
      
        if (whos_turn)
        {
            get_valid_position(whos_turn, b, val_row, val_col, val_length);
            valid_move = 0;
            
            while (valid_move == 0)
            {
                consecutiveTurnsSkiped = 0;
                std::cout << "BLACK's turn: ";
                std::cin >> command;
                if (command[0] == 'q' && command[1] == '\0')
                {
                    break;
                }
                row = get_row(command);
                col = get_col(command);
                
                for (int i = 0; i < val_length; ++i)
                {
                    if (val_row[i] == row && val_col[i] == col)
                    {
                        b[row][col] = Black_Piece;
                        std::cout << std::endl;
                        swap(b, row, col, whos_turn, white_score, black_score);
                        draw(b);
                        valid_move = 1;
                        whos_turn = WHITE;
                        --num_Spaces;
                        break;
                    }
                }
                
                if (valid_move == 1 && whos_turn == WHITE)
                {
                    break;
                }
                if (valid_move == 0)
                {
                    std::cout << "INVALID MOVE" <<std::endl;
                    
                }

               
            }
            if (command[0] == 'q' && command[1] == '\0')
            {
                break;
            }
            continue;
        }
        else
        {
            valid_move = 0;
            get_valid_position(whos_turn, b, val_row, val_col, val_length);
            while (valid_move == 0)
            {
                consecutiveTurnsSkiped = 0;
                std::cout << "WHITE's turn: ";
                std::cin >> command;
                if (command[0] == 'q' && command[1] == '\0')
                {
                    break;
                }
                col = get_col(command);
                row = get_row(command);
                for (int i = 0; i < val_length; ++i)
                {
                    if (val_row[i] == row && val_col[i] == col)
                    {
                        b[row][col] = White_Piece;
                        std::cout << std::endl;
                        swap(b, row, col, whos_turn, white_score, black_score);
                        draw(b);
                        valid_move = 1;
                        whos_turn = BLACK;
                        --num_Spaces;
                        break;
                    }
                }

                if (valid_move == 1)
                {
                    break;
                }
                
                if (valid_move == 0)
                {
                    std::cout << "INVALID MOVE" << std::endl;
                    
                }
            }
            if (command[0] == 'q' && command[1] == '\0')
            {
                break;
            }
        }
        continue;
        
    }
    declareWinner(b, white_score, black_score);
    std::cout << std::endl;
}
    
            
       
    






int main()
{
    Board b;
    
    while (1) 
    {    //Prints the Welcome message
        std::cout << "Welcome to Super Othello Version 0.1" << std::endl;
        std::cout << "by Micah Arndt" << std::endl;
        std::cout << std::endl;
        
        //Gives prompts for entries
        std::cout << "[?] ";
        std::cout << "  Help" << std::endl;
        
        std::cout << std::setw(5) << "[P/p]";
        std::cout << " Play a new game" << std::endl;
        
        std::cout << std::setw(5) << "[L/l]";
        std::cout << " Load a previous game" << std::endl;
        
        std::cout << std::setw(5) << "[S/s]";
        std::cout << " Set up the Board" << std::endl;
        
        std::cout << std::setw(5) << "[Q/q]";
        std::cout << " Quit" << std::endl;
        
        std::cout << "Enter Option: ";
        char entry;
        std::cin >> entry;

        //Outputs for each entry option
        
        switch (entry)
        {
            case '?':
            {
                help();
                break;
            }
            
            case 'P':
            {
                
            }
            
            case 'p':
            {
                play();
                break;
            }
            
            case 'L':
            {
                
            }
            case 'l':
            {
                std::cout << "*** L/l: TO BE IMPLEMENTED ***" << std::endl;
                break;   
            }
            
            case 'S':
            {
                
            }
            
            case 's':
            {
                std::cout << "*** S/s: TO BE IMPLEMENTED ***" << std::endl;
            break;
            }
            
            case 'Q':
            {
                
            }
            
            case 'q':
            {
                std::cout << "Thanks for playing Super Othello Version 0.1" << std::endl;
                break;
            }
            
        }
        if (entry == 'q' || entry == 'Q')
            {
                break;
            }
    }
        return 0;
}

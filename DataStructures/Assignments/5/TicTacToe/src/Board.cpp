//-------------------------------------------------------------------------------------
//
//  TicTacToe - A simple tac toe toe game
//  Copyright (C) 2009-2010 Mike Cunningham
//  Modified 2012 by Ryan Brosnahan and Jason Heid
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//-------------------------------------------------------------------------------------


#include <QtGui>
#include "Board.h"


//-------------------------------------------------------------------------------------
// Name: Board()
// Desc: Constructor
//-------------------------------------------------------------------------------------
Board::Board(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    playerSymbol = 'X';
    compSymbol = 'O';
    newGame();
}


//-------------------------------------------------------------------------------------
// Name: paintEvent()
// Desc: Draw the board
//-------------------------------------------------------------------------------------
void Board::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //painter.setRenderHint(QPainter::Antialiasing, true);

    int cellwidth = width() / 3;
    int cellheight = height() / 3;

    // Set the font to be used by the drawText() routine
    QFont font("Arial", cellwidth / 3);
    painter.setFont(font);

    // Draw the border
    painter.setPen(palette().dark().color());
    painter.drawRect(0, 0, width() - 1, height() - 1);

    // Draw the grid lines
    painter.setPen(Qt::black);
    painter.drawLine(cellwidth, 0, cellwidth, height());
    painter.drawLine(cellwidth*2, 0, cellwidth*2, height());
    painter.drawLine(0, cellheight, width(), cellheight);
    painter.drawLine(0, cellheight*2, width(), cellheight*2);

    // Draw the X's and O's
    for(int x = 0; x < 3; x++)
    {
        for(int y = 0; y < 3; y++)
        {
            if( board[x][y].isLetter() )
            {
                painter.drawText(x * cellwidth, y * cellheight, cellwidth, cellheight, Qt::AlignCenter, board[x][y]);
            }
        }
    }
}


//-------------------------------------------------------------------------------------
// Name: mousePressEvent()
// Desc: Handle mouse click events
//-------------------------------------------------------------------------------------
void Board::mousePressEvent(QMouseEvent *event)
{
    // Check if the game is running
    if( !running )
    {
        newGame(turn);
        return;
    }

    // Calculate the row/col that the user clicked
    int row = event->x() / (width() / 3);
    int col = event->y() / (height() / 3);

    // Player move
    playerMove(row, col);
}


//-------------------------------------------------------------------------------------
// Name: newGame()
// Desc: Start a new game
//-------------------------------------------------------------------------------------
void Board::newGame(bool first, bool symbol)
{
    // Clear the board
    for(int x = 0; x < 3; x++)
        for(int y = 0; y < 3; y++)
            board[x][y] = QChar();

    // If symbol is false, player is 'O'
    if (symbol == false) {
        playerSymbol = 'O';
        compSymbol = 'X';
    }
    else {
        playerSymbol = 'X';
        compSymbol = 'O';
    }

    // If first is false, computer goes first
    if (first == false)
        computerMove();

    // set the turn to persist between games
    turn = first;

    running = true;
    update();
}


//-------------------------------------------------------------------------------------
// Name: playerMove()
// Desc: Performs the player move followed by the computer move
//-------------------------------------------------------------------------------------
void Board::playerMove(int row, int col)
{

    // Check if the cell isn't empty
    if( !isCellEmpty(row, col) )
        return;

    // Player's move
    board[row][col] = playerSymbol;
    update();

    // Check if the player won
    Status status = getStatus(playerSymbol);
    if( status == Win )
    {
        QMessageBox::information(this, tr("Game Over"), tr("You won!"));
        running = false;
        return;
    }
    else if( status == Tie )
    {
        QMessageBox::information(this, tr("Game Over"), tr("It's a tie!"));
        running = false;
        return;
    }

    // Computer's turn
    computerMove();

    // Check if the computer won
    status = getStatus(compSymbol);
    if( status == Win )
    {
        QMessageBox::information(this, tr("Game Over"), tr("You lost!"));
        running = false;
        return;
    }
    else if( status == Tie )
    {
        QMessageBox::information(this, tr("Game Over"), tr("It's a tie!"));
        running = false;
        return;
    }
}


//-------------------------------------------------------------------------------------
// Name: isCellEmpty()
// Desc: Returns true if the board cell is empty
//-------------------------------------------------------------------------------------
bool Board::isCellEmpty(int row, int col)
{
    // Make sure the row and column are valid
    if( row < 0 || row > 2 || col < 0 || col > 2 )
    {
        qDebug() << tr("Invalid row/col: %1, %2").arg(row).arg(col);
        return false;
    }

    return (board[row][col].isNull());
}


//-------------------------------------------------------------------------------------
// Name: getStatus()
// Desc: Get the game status
//-------------------------------------------------------------------------------------
Board::Status Board::getStatus(const QChar &c)
{
    // Check for a completed horizontal line
    for(int x = 0; x < 3; x++)
        if( board[x][0] == c && board[x][1] == c && board[x][2] == c )
            return Win;

    // Check for a completed vertical line
    for(int y = 0; y < 3; y++)
        if( board[0][y] == c && board[1][y] == c && board[2][y] == c )
            return Win;

    // Check for a completed backward diagonal line
    if( board[0][0] == c && board[1][1] == c && board[2][2] == c )
        return Win;

    // Check for a completed forward diagonal line
    if( board[0][2] == c && board[1][1] == c && board[2][0] == c )
        return Win;

    // Check if it's a stalemate (if there are still empty cells it isn't a stalemate)
    for(int x = 0; x < 3; x++)
        for(int y = 0; y < 3; y++)
            if( isCellEmpty(x, y) )
                return None;

    // If we made it this far it's a stalemate
    return Tie;
}


//-------------------------------------------------------------------------------------
// Name: computerMove()
// Desc: Determine where to place the computer's move
//-------------------------------------------------------------------------------------
void Board::computerMove()
{
    // First check for winning moves
    QChar *cell = findMove(compSymbol);
    if( cell )
    {
        *cell = compSymbol;
        update();
        return;
    }

    // Next check for defensive moves (moves that will block a winning move by the player)
    cell = findMove(playerSymbol);
    if( cell )
    {
        *cell = compSymbol;
        update();
        return;
    }

    // Finally check for other moves (try the center cell first)
    if( isCellEmpty(1, 1) )
    {
        board[1][1] = compSymbol;
        update();
    }
    else
    {
        // Pick a random location
        // Todo: Find a better algorithm to determine the computer's move
        int x, y;
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        }
        while( !isCellEmpty(x, y) );

        board[x][y] = compSymbol;
        update();
    }
}


//-------------------------------------------------------------------------------------
// Name: findMove()
// Desc: Find a winning move or a defensive move to block the player from winning.
//       If c is O it will try to find a winning move, if c is X it will try to find
//       a defensive move. Returns a pointer to the empty cell if it finds a move or
//       returns 0 if no move was found.
//-------------------------------------------------------------------------------------
QChar* Board::findMove(const QChar &c)
{  
    //---------------------------------------------------------------------------------
    // Horizontal moves
    //---------------------------------------------------------------------------------

    // Left empty
    for(int x = 0; x < 3; x++)
    {
        if( board[x][1] == c && board[x][2] == c && isCellEmpty(x, 0) )
            return &board[x][0];
    }

    // Middle empty
    for(int x = 0; x < 3; x++)
    {
        if( board[x][0] == c && board[x][2] == c && isCellEmpty(x, 1) )
            return &board[x][1];
    }

    // Right empty
    for(int x = 0; x < 3; x++)
    {
        if( board[x][0] == c && board[x][1] == c && isCellEmpty(x, 2) )
            return &board[x][2];
    }

    //---------------------------------------------------------------------------------
    // Vertical moves
    //---------------------------------------------------------------------------------

    // Top empty
    for(int y = 0; y < 3; y++)
    {
        if( board[1][y] == c && board[2][y] == c && isCellEmpty(0, y) )
            return &board[0][y];
    }

    // Middle empty
    for(int y = 0; y < 3; y++)
    {
        if( board[0][y] == c && board[2][y] == c && isCellEmpty(1, y) )
            return &board[1][y];
    }

    // Bottom empty
    for(int y = 0; y < 3; y++)
    {
        if( board[0][y] == c && board[1][y] == c && isCellEmpty(2, y) )
            return &board[2][y];
    }

    //---------------------------------------------------------------------------------
    // Diagonal moves
    //---------------------------------------------------------------------------------

    //     x
    //   x
    // -
    if( board[0][2] == c && board[1][1] == c && isCellEmpty(2, 0) )
        return &board[2][0];

    //     x
    //   -
    // x
    else if( board[0][2] == c && board[2][0] == c && isCellEmpty(1, 1) )
        return &board[1][1];

    //     -
    //   x
    // x
    else if( board[1][1] == c && board[2][0] == c && isCellEmpty(0, 2) )
        return &board[0][2];

    // x
    //   x
    //     -
    else if( board[0][0] == c && board[1][1] == c && isCellEmpty(2, 2) )
        return &board[2][2];

    // x
    //   -
    //     x
    else if( board[0][0] == c && board[2][2] == c && isCellEmpty(1, 1) )
        return &board[1][1];

    // -
    //   x
    //     x
    else if( board[1][1] == c && board[2][2] == c && isCellEmpty(0, 0) )
        return &board[0][0];


    // No move found
    return 0;
}

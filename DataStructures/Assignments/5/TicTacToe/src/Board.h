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

#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QString>


//-------------------------------------------------------------------------------------
// Name: Board
// Desc: The tic-tac-toe board
//-------------------------------------------------------------------------------------
class Board : public QWidget
{
    Q_OBJECT

    public:
        Board(QWidget *parent = 0);

    public slots:
        void newGame(bool playerFirst = true, bool playerSymbol = true);

    protected:
        void paintEvent(QPaintEvent *event);
        void mousePressEvent(QMouseEvent *event);


    private:
        void playerMove(int row, int col);
        bool isCellEmpty(int row, int col);
        QChar* findMove(const QChar &c);
        void computerMove();

        enum Status { None, Win, Tie };
        Status getStatus(const QChar &c);

        QChar board[3][3];
        bool running;

        bool turn;
        QChar playerSymbol;
        QChar compSymbol;

};

#endif // BOARD_H

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


#include <QApplication>
#include "MainWindow.h"


//-------------------------------------------------------------------------------------
// Name: main()
// Desc: Application entry point
//-------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}

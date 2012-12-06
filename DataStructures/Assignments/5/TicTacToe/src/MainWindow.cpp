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
#include <QSettings>
#include "settingsdialog.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"


//-------------------------------------------------------------------------------------
// Name: MainWindow()
// Desc: Constructor
//-------------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    QSettings settings;
    playerFirst = settings.value("PlayerFirst", true).toBool();
    playerX = settings.value("PlayerX", true).toBool();

    ui->setupUi(this);
    setupActions();
    centerWindow();

}


//-------------------------------------------------------------------------------------
// Name: ~MainWindow()
// Desc: Destructor
//-------------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}


//-------------------------------------------------------------------------------------
// Name: setupActions()
// Desc: Setup the main window actions
//-------------------------------------------------------------------------------------
void MainWindow::setupActions()
{
    connect(ui->newAction, SIGNAL(triggered()), ui->board, SLOT(newGame()));
    connect(ui->exitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionSettings, SIGNAL(triggered()), this, SLOT(displaySettings()));
}


//-------------------------------------------------------------------------------------
// Name: about()
// Desc: Show the about window
//-------------------------------------------------------------------------------------
void MainWindow::about()
{
    QMessageBox::about(this, tr("About this program"),
                             tr("<h4>TicTacToe v1.0</h4>"
                                "<p>Copyright (C) 2009-2010 Mike Cunningham</p>"
                                "<p>Modified 2012 by Ryan Brosnahan and Jason Heid</p>"));
}


//-------------------------------------------------------------------------------------
// Name: centerWindow()
// Desc: Center the window
//-------------------------------------------------------------------------------------
void MainWindow::centerWindow()
{
    // Get the width & height of the primary desktop screen
    QDesktopWidget *desktop = QApplication::desktop();
    QRect screen = desktop->screenGeometry(desktop->primaryScreen());

    // Calculate the centered window position
    int x = (screen.width() - width()) / 2;
    int y = (screen.height() - height()) / 2;

    // Center the window
    move(x, y);
}


//-------------------------------------------------------------------------------------
// Name: displaySettings()
// Desc: Makes the dialog to get user settings
//-------------------------------------------------------------------------------------
void MainWindow::displaySettings() {
   SettingsDialog dialog(this, playerFirst, playerX);
   if (dialog.exec()) {
      // exec() returns true if the user hit okay, fetch the new settings and restart the game
      playerFirst = dialog.getPlayerFirst();
      playerX = dialog.getPlayerX();
      ui->board->newGame(playerFirst, playerX);
   }
}

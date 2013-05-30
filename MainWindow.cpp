#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SoundButton.h"

#include <QObjectList>
#include <iostream>

#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_versionDialog(new VersionDialog(this))
{
    ui->setupUi(this);
    the_tabs = this->findChild<QTabWidget*>("mainTabs");
    the_tabs->removeTab(0);
    this->setWindowTitle("Curmudgeon");
    this->setAcceptDrops(true);
    this->setUnifiedTitleAndToolBarOnMac(true);
    this->setWindowIcon(QIcon());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddSoundboard(SoundBoard *newTab)
{
    the_tabs->addTab(newTab, newTab->getName());
    soundboards << newTab;
}

#include <iostream>
void MainWindow::keyPressEvents(QKeyEvent * e)
{
    e->accept();
    SoundBoard* current = (SoundBoard*)the_tabs->currentWidget();
    if(typeid(*current)==typeid(SoundBoard))
        (current)->pressKey(QChar(e->key()));
}

void MainWindow::keyReleaseEvents(QKeyEvent * e)
{
    SoundBoard* current = (SoundBoard*)the_tabs->currentWidget();
    if(typeid(*current)==typeid(SoundBoard))
        (current)->releaseKey(QChar(e->key()));
}

void MainWindow::newSoundboard()
{
    AddSoundboard(new SoundBoard("New Soundboard"));
}

void MainWindow::openSoundboard()
{
}
void MainWindow::closeSoundboard()
{
}

#include <QMessageBox>

void MainWindow::showAbout()
{
    QString title = tr("About Curmudgeon ");
    title.append(APP_VERSION);
    //QMessageBox::about(NULL, title, "BLAAAAAAH");

    if (!m_versionDialog) {
        m_versionDialog = new VersionDialog(this);
        connect(m_versionDialog, SIGNAL(finished(int)),
                this, SLOT(destroyVersionDialog()));
    }
    m_versionDialog->show();
    //*/
}

/*TODO:
 *  -SoundButon:
 *      -"Set Label"
 *      -"Change Sound"
 *      -"Remove"
 *      -Volume Slider
 *      -"Stop when done" vs "Loop when done"
 *      -"Stop when released" vs "Continue when released"
 *      -"Restart when re-pressed" vs "Stop when re-pressed"
 *
 *  -SoundBoard:
 *      -Close
 *          -"Are you sure you want to close?
 *      -Save to file
 *
 *  -Menu:
 *      -File
 *          -Open Soundboard
 *          -Save Soundboard
 *      -View
 *          -Next Soundboard
 *          -Previous Soundboard
 *      -Open
 *      -Dock menu?
 *          -qt_mac_set_dock_menu(QMenu *)
 *
 *  -Window: resize
 */

/*Tabs for each different soundboard
 *  -What happens when change tabs? do sounds keep playing?
 *
 *FOR EACH BUTTON
 *  If it is not set:
 *  (1) Press to browse
 *  (2) Dragndrop
 *  ~(3) Record?
 *  If it is set:
 *  (1) Play/Pause
 *
 *  _____________
 * | NAME      / |
 * |           / |  <- volume
 * |             |
 * | time     ID |
 * _______________
 *
 *CONFIG:
 *  -Duck
 *      -%
 *      -Duration
 *  -Should sounds...
 *      -Loop?
 *      -Only play when depressed?
 *      -Stop or restart when re-pressed?
 *  -Fade Out
 *
 *
 *MAIN WINDOW:
 *  -Duck
 *  -Play/Pause
 *  -Main Volume
 *  -Balance
 *
 *~Android Remote
*/
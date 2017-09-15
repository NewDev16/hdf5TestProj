#include "MainWindow.h"

#include "GoogleRequester.h"
#include <QWidget>

MainWindow::MainWindow(QWidget* parent)
    :QMainWindow(parent)
{
    GoogleRequester requester;
    requester.sendRequest();
}

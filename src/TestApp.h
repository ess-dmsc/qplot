#pragma once

#include <QMainWindow>

namespace Ui {
class TestApp;
}

class TestApp : public QMainWindow
{
  Q_OBJECT

public:
  explicit TestApp(QWidget *parent = 0);
  ~TestApp();

protected:
  void closeEvent(QCloseEvent*);

private slots:
  void saveSettings();
  void loadSettings();

private:
  Ui::TestApp *ui;
};


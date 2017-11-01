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

  void init2d(uint32_t nx, uint32_t ny);
};


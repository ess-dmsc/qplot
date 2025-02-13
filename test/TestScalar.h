#pragma once

#include <QPlot/KnightRiderWidget.h>
#include <QPlot/GradientSelector.h>
#include <QThread>
#include <QMutex>
#include <QElapsedTimer>

#include <atomic>

namespace Ui
{
class TestScalar;
}

class OscillatorThread : public QThread
{
 Q_OBJECT
 public:
  explicit OscillatorThread(QObject *parent = 0)
      : QThread(parent)
  {}

  void oscillate(double min, double max)
  {
    QMutexLocker locker(&mutex_);
    terminate_helper();
    terminating_.store(false);
    min_ = min;
    max_ = max;
    if (!isRunning())
      start(HighPriority);
  }

  void terminate_wait()
  {
    QMutexLocker locker(&mutex_);
    terminate_helper();
  }

  void set_wait_time(uint16_t time)
  {
    wait_ms_.store(time);
  }

  void set_period(double period)
  {
    period_.store(period);
  }

 signals:
  void val_update(double val);

 protected:
  void run() {
    QElapsedTimer myTimer;
    myTimer.start();

    while (!terminating_.load())
    {
      int nMilliseconds = myTimer.elapsed();
      double periods = double(nMilliseconds) / period_;
      double sinval = std::sin(periods * M_2_PI);
      double val = (max_ - min_) * (1. + sinval) / 2. + min_;
      emit val_update(val);
      if (!terminating_.load())
        QThread::msleep(wait_ms_.load());
    }
  }

 private:
  QMutex mutex_;
  std::atomic<bool> terminating_ {false};
  std::atomic<uint16_t> wait_ms_ {50};
  double min_ {0.};
  double max_ {100.};
  std::atomic<double> period_ {1000.0};

  void terminate_helper()
  {
    terminating_.store(true);
    wait();
  }
};


class TestScalar : public QWidget
{
 Q_OBJECT

 public:
  TestScalar(QWidget* parent = 0);

 protected:
  void closeEvent(QCloseEvent*);

 private slots:
  void update();

  void on_pushGradientSelector_clicked();

  void on_pushStart_clicked();
  void on_pushStop_clicked();

  void on_doublePeriod_valueChanged(double);
  void on_spinUpdateFrequency_valueChanged(int);

  void val_update(double val);

 private:
  Ui::TestScalar* ui;
  QPlot::Gradients g;
  OscillatorThread oscillator_;

};

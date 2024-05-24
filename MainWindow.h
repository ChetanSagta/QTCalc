#include <QGridLayout>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QSlider>
#include <QWidget>
#include <qpushbutton.h>
class MainWindow : public QWidget {
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = 0);

public slots:
  void digitPressed();
  void symbolPressed();
  void calculate();

private:

  float m_display_value=0;
  float m_result=0;

  enum Operation{
    ADD,
    MINUS,
    MULTIPLY,
    DIVIDE,
    None
  };

  QHBoxLayout *m_hbox_layout;
  QVBoxLayout *m_vbox_layout;
  QGridLayout *m_grid_layout;

  QLineEdit *m_line_edit;
  QPushButton *m_one_button;
  QPushButton *m_two_button;
  QPushButton *m_three_button;
  QPushButton *m_four_button;
  QPushButton *m_five_button;
  QPushButton *m_six_button;
  QPushButton *m_seven_button;
  QPushButton *m_eight_button;
  QPushButton *m_nine_button;
  QPushButton *m_zero_button;

  QPushButton *m_point_button;
  QPushButton *m_plus_button;
  QPushButton *m_minus_button;
  QPushButton *m_mult_button;
  QPushButton *m_div_button;
  QPushButton *m_equal_button;

  Operation m_operation;

};

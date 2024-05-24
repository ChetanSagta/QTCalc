#include "MainWindow.h"
#include <QApplication>
#include <iostream>
#include <qapplication.h>
#include <qboxlayout.h>
#include <qgridlayout.h>
#include <qlineedit.h>
#include <qmap.h>
#include <qnamespace.h>
#include <qobjectdefs.h>
#include <qprogressbar.h>
#include <qpushbutton.h>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

  m_line_edit = new QLineEdit();
  m_operation = Operation::None;
  m_display_value = 0;

  m_one_button = new QPushButton("1");
  m_two_button = new QPushButton("2");
  m_three_button = new QPushButton("3");
  m_four_button = new QPushButton("4");
  m_five_button = new QPushButton("5");
  m_six_button = new QPushButton("6");
  m_seven_button = new QPushButton("7");
  m_eight_button = new QPushButton("8");
  m_nine_button = new QPushButton("9");
  m_zero_button = new QPushButton("0");

  m_equal_button = new QPushButton("=");
  m_point_button = new QPushButton(".");
  m_plus_button = new QPushButton("+");
  m_minus_button = new QPushButton("-");
  m_mult_button = new QPushButton("*");
  m_div_button = new QPushButton("/");

  m_hbox_layout = new QHBoxLayout();
  m_hbox_layout->addWidget(m_line_edit);

  m_vbox_layout = new QVBoxLayout();

  m_grid_layout = new QGridLayout();
  m_grid_layout->addWidget(m_one_button, 0, 0);
  m_grid_layout->addWidget(m_two_button, 0, 1);
  m_grid_layout->addWidget(m_three_button, 0, 2);
  m_grid_layout->addWidget(m_mult_button, 0, 3);
  m_grid_layout->addWidget(m_four_button, 1, 0);
  m_grid_layout->addWidget(m_five_button, 1, 1);
  m_grid_layout->addWidget(m_six_button, 1, 2);
  m_grid_layout->addWidget(m_div_button, 1, 3);
  m_grid_layout->addWidget(m_seven_button, 2, 0);
  m_grid_layout->addWidget(m_eight_button, 2, 1);
  m_grid_layout->addWidget(m_nine_button, 2, 2);
  m_grid_layout->addWidget(m_minus_button, 2, 3);
  m_grid_layout->addWidget(m_zero_button, 3, 0);
  m_grid_layout->addWidget(m_point_button, 3, 1);
  m_grid_layout->addWidget(m_equal_button, 3, 2);
  m_grid_layout->addWidget(m_plus_button, 3, 3);

  m_vbox_layout->addLayout(m_hbox_layout);
  m_vbox_layout->addLayout(m_grid_layout);
  this->setLayout(m_vbox_layout);

  connect(m_one_button, SIGNAL(clicked()), this, SLOT(digitPressed()));

  connect(m_two_button, SIGNAL(clicked()), this, SLOT(digitPressed()));

  connect(m_three_button, SIGNAL(clicked()), this, SLOT(digitPressed()));

  connect(m_four_button, SIGNAL(clicked()), this, SLOT(digitPressed()));

  connect(m_five_button, SIGNAL(clicked()), this, SLOT(digitPressed()));

  connect(m_six_button, SIGNAL(clicked()), this, SLOT(digitPressed()));

  connect(m_seven_button, SIGNAL(clicked()), this, SLOT(digitPressed()));

  connect(m_eight_button, SIGNAL(clicked()), this, SLOT(digitPressed()));

  connect(m_nine_button, SIGNAL(clicked()), this, SLOT(digitPressed()));

  connect(m_zero_button, SIGNAL(clicked()), this, SLOT(digitPressed()));

  connect(m_plus_button, SIGNAL(clicked()), this, SLOT(symbolPressed()));

  connect(m_minus_button, SIGNAL(clicked()), this, SLOT(symbolPressed()));

  connect(m_mult_button, SIGNAL(clicked()), this, SLOT(symbolPressed()));

  connect(m_div_button, SIGNAL(clicked()), this, SLOT(symbolPressed()));

  connect(m_equal_button, SIGNAL(clicked()), this, SLOT(calculate()));

}

void MainWindow::digitPressed() {
  QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
  m_display_value= m_display_value* 10 + clickedButton->text().toInt();
  m_line_edit->setText(QString::number(m_display_value));
}

void MainWindow::symbolPressed() {
  m_line_edit->clear();
  m_result = m_display_value;
  m_display_value = 0;
  QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
  std::string curr_symbol = clickedButton->text().toStdString();
  if (curr_symbol.compare("+") == 0) {
    m_operation = Operation::ADD;
  } else if (curr_symbol.compare("-") == 0) {
    m_operation = Operation::MINUS;
  } else if (curr_symbol.compare("*") == 0) {
    m_operation = Operation::MULTIPLY;
  } else if (curr_symbol.compare("/") == 0) {
    m_operation = Operation::DIVIDE;
  }
}

void MainWindow::calculate(){

  if (m_operation == Operation::ADD) {
    m_result += m_display_value;
  }
  else if (m_operation == Operation::MINUS) {
    m_result -= m_display_value;
  }
  else if (m_operation == Operation::MULTIPLY) {
    m_result *= m_display_value;
  }
  else if (m_operation == Operation::DIVIDE) {
    m_result /= m_display_value;
  }
  m_line_edit->setText(QString::number(m_result));
  m_display_value = m_result;
}

#ifndef UDP_H
#define UDP_H

#include <QMainWindow>
#include <QUdpSocket>
#include <iostream>

namespace Ui {
class udp;
}

class udp : public QMainWindow
{
    Q_OBJECT

public:
    explicit udp(QWidget *parent = 0);
    ~udp();

private slots:
    void on_SendBtn_clicked();
    void receive();

private:
    QUdpSocket *uSocket;
    Ui::udp *ui;
};

#endif // UDP_H

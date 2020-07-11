#include "udp.h"
#include "ui_udp.h"
#include <QMessageBox>

udp::udp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::udp)
{
    ui->setupUi(this);
    uSocket = new QUdpSocket(this);
    connect(uSocket, SIGNAL(readyRead()), this, SLOT(receive()));
    //bool result=uSocket->bind(QHostAddress("192.168.122.2"), 8082);
    bool result=uSocket->bind(8082, QUdpSocket::ShareAddress);
    ui->TextEdit->setText("--- Recevier ---" );
    connect(ui->exitBtn,SIGNAL(clicked()),this,SLOT(close()));
    if(!result)     //udpsocket进行绑定和server一样的端口
    {
     QMessageBox::information(this,"error","bind fail"); //绑定失败弹出信息对话框
    }
}
void udp::receive()
{
    QByteArray ba;
    while(uSocket->hasPendingDatagrams())
    {
        ba.resize(uSocket->pendingDatagramSize());
        uSocket->readDatagram(ba.data(), ba.size());
        QString message = ba.data();
        ui->TextEdit->append(message);
    }
}
udp::~udp()
{
    delete ui;
    delete uSocket;
}

void udp::on_SendBtn_clicked()
{
    QUdpSocket qus;
   //qus.bind(QHostAddress("192.168.0.2"), 8070);
    QString ip = ui->lineEditip->text();    //获取对方的端口号和ip
    quint16 port = ui->lineEditport->text().toInt();
    QByteArray msg = "11";
    for(int i=0; i<100; ++i)
        //qus.writeDatagram(msg, QHostAddress("192.168.122.2"), 8080);
        qus.writeDatagram(msg.data(),msg.size(), (QHostAddress)ip, port);

}



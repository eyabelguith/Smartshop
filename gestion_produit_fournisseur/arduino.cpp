#include "arduino.h"
#include <QDebug>

Arduino::Arduino()
{
  data = "";
  arduino_port_name="";
  arduino_is_available=false;
  serial= new QSerialPort;

}

int Arduino::connect_arduino()
{
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
            if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
                if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id && serialPortInfo.productIdentifier()
                        == arduino_uno_product_id){
                        arduino_port_name = serialPortInfo.portName();
                        arduino_is_available = true;
                    }

            }
        }
        qDebug()<< "arduino proort name is"<<arduino_port_name << arduino_is_available;
        if(arduino_is_available){
            // open and configure the serialport
            serial->setPortName(arduino_port_name);
            serial->open(QSerialPort::ReadWrite);
            serial->setBaudRate(QSerialPort::Baud115200);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;

    }
        return 1;
}

int Arduino::close_arduino()
{if (serial->isOpen()){serial->close(); return 0;}
    return 0;

}


QByteArray Arduino::read_from_arduino()
{
    if (serial->isReadable()){
        data=serial->readAll();
        return data;}

}

QSerialPort *Arduino::getserial()
{
    return serial;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

void  Arduino::write_arduino(QByteArray d)
{
    if(serial->isReadable()){serial->write(d);
    }
    else {qDebug() <<"couldnt open";}


}

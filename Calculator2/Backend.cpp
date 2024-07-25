#include "Backend.h"

Backend::Backend(QObject *parent)
{
}

QString Backend::digits()
{
    return QString(m_digitsStr);
}

void Backend::setDigits(QString inputDigits)
{
    m_digitsStr = inputDigits;
    qDebug()<< m_digitsStr <<"Called setDigits"<<inputDigits;
    emit digitsChanged(m_digitsStr);
}

QString Backend::calculate()
{
    qDebug()<<"Called calculate";
    switch(m_operChar)
    {
    case 1:{
        float result = (m_op1.toFloat() + (m_digitsStr.toFloat()));
        QString str = QString::number(result);
        m_digitsStr = str;
        setDigits(m_digitsStr);
    }
        break;
    case 2:{
        float result = (m_op1.toFloat() - (m_digitsStr.toFloat()));
        QString str = QString::number(result);
        m_digitsStr = str;
        setDigits(m_digitsStr);
    }
        break;
    case 3: {
        float result = (m_op1.toFloat() * (m_digitsStr.toFloat()));
        QString str = QString::number(result);
        m_digitsStr = str;
        setDigits(m_digitsStr);
    }
        break;
    case 4: {
        float result = 0;
        if(m_digitsStr.toFloat()!=0)
            result = (m_op1.toFloat() / (m_digitsStr.toFloat()));
        QString str = QString::number(result);
        m_digitsStr = str;
        setDigits(m_digitsStr);
    }
        break;
    }

    return QString("");
}

void Backend::clear()
{
    qDebug()<<"Called clear";
    m_digitsStr="";
    setDigits("");
}

Backend::~Backend()
{

}

void Backend::append(QString strPiece)
{
    m_digitsStr = m_digitsStr + strPiece;
    setDigits(m_digitsStr);
}

void Backend::operSet(int ch)
{
    m_op1 = m_digitsStr;
    m_digitsStr = "";
    m_operChar = ch;
}

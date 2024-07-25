#ifndef Backend_H
#define Backend_H

#include <QObject>
#include <QQuickItem>
#include <QString>
#include <qqml.h>

class Backend: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString digits READ digits WRITE setDigits NOTIFY digitsChanged)
public:
    explicit Backend(QObject *parent = nullptr);
    QString digits();
    Q_INVOKABLE void setDigits(QString inputDigits);
    Q_INVOKABLE QString calculate();
    Q_INVOKABLE void clear();
    Q_INVOKABLE void append(QString strPiece);
    Q_INVOKABLE void operSet(int ch);
    ~Backend();

signals:
    void digitsChanged(QString digit);
private:
    QString m_digitsStr;
    QString m_op1;
    int m_operChar;
};
Q_DECLARE_METATYPE(Backend)
#endif // Backend_H

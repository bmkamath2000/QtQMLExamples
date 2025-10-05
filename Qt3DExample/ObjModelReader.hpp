#ifndef OBJMODELREADER_HPP
#define OBJMODELREADER_HPP
#include<QObject>
#include<QDebug>
#include<QVariant>
#include<QVariantList>
#include<QVector3D>
#include<Triangles.hpp>
class ObjModelReader :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList pl READ pl WRITE setPl NOTIFY plChanged)

public:

    QVariantList pl(){
        return myPl;
    }
    void setPl(QVariantList ppl){
        myPl = ppl;
        emit plChanged(myPl);
    }
    Q_INVOKABLE int sizePl(){
        return myPl.size();
    }

signals:
    void plChanged(QVariantList);

private:
    QVariantList myPl;    // my point list

    static const int MAX_VERTICES=1000000;
    static const int MAX_FACES=1000000;
    static const int MAX_NORMALS=1000000;
    int usesnormals=0;
    int vertex_count=0;
    int face_count=0;
    int normal_count=0;
    double minx=-1,maxx=1,miny=-1,maxy=1,minz=-1,maxz=1;
public:
    QVector<QVector3D> _vertices;
    QVector<Triangles> _faces;
    QVector<QVector3D> _normals;
    void emitVertex(double x,double y,double z);
    void emitNormal(double vx,double vy,double vz);

    void emitFace1(QString s1,QString s2,QString s3);
    void emitFace2(QString s1,QString s2,QString s3,QString s4);

    void loadObj(void);
};

#endif // OBJMODELREADERHPP

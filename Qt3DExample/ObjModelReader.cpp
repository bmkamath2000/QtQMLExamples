#include<ObjModelReader.hpp>
#include<ModelController.hpp>
#include<QFile>
#include<QDir>
#include<QVector3D>
void ObjModelReader::emitVertex(double x,double y,double z)
{
    _vertices.append(QVector3D(x,y,z));
}
void ObjModelReader::emitNormal(double vx,double vy,double vz)
{
    _normals.append(QVector3D(vx,vy,vz));
}

void ObjModelReader::emitFace1(QString s1,QString s2,QString s3)
{
    int num1,num2,num3,num4,num5,num6;
    QStringList split1,split2,split3;

    split1=s1.split('/');
    split2=s2.split('/');
    split3=s3.split('/');
    num1=split1.count();
    num2=split2.count();
    num3=split3.count();
    if(num1>1) usesnormals=1;   //assuming two or more items in split means has texture coords and vn
    if(num1==1)
    {
        num1=split1[0].toInt();
        num2=split2[0].toInt();
        num3=split3[0].toInt();
        // printf("%d %d %d\n",num1,num2,num3);
        Triangles t=Triangles();
        t.vertexIndex1=num1-1;t.vertexIndex2=num2-1;t.vertexIndex3=num3-1;
        _faces.append(t);
        usesnormals=0;
    }
    else{
        num1=split1[0].toInt();
        num2=split2[0].toInt();
        num3=split3[0].toInt();
        num4=split1[2].toInt();// these are normal indices
        num5=split2[2].toInt();
        num6=split3[2].toInt();
        //  a face with vertex normals
        Triangles t=Triangles();
        t.vertexIndex1=num1-1;t.vertexIndex2=num2-1;t.vertexIndex3=num3-1;
        _faces.append(t);
        _normals.append(QVector3D(num4-1,num5-1,num6-1));
    }
}
void ObjModelReader::emitFace2(QString s1,QString s2,QString s3,QString s4)
{
    int num1,num2,num3,num4,num5,num6,num7,num8;
    QStringList split1,split2,split3,split4;

    split1=s1.split('/');
    split2=s2.split('/');
    split3=s3.split('/');
    split4=s4.split('/');
    num1=split1.count();
    if(num1>1) usesnormals=1;
    if(num1>1)
    {
        usesnormals=1;
        num1=split1[0].toInt();
        num2=split2[0].toInt();
        num3=split3[0].toInt();
        num4=split4[0].toInt();

        num5=split1[2].toInt();
        num6=split2[2].toInt();
        num7=split3[2].toInt();
        num8=split4[2].toInt();
        Triangles t1=Triangles();
        t1.vertexIndex1=num1-1;t1.vertexIndex2=num2-1;t1.vertexIndex3=num3-1;
        _faces.append(t1);
        _normals.append(QVector3D(num5-1,num6-1,num7-1));
        Triangles t2=Triangles();
        t2.vertexIndex1=num1-1;t2.vertexIndex2=num4-1;t2.vertexIndex3=num3-1;
        _faces.append(t2);
        _normals.append(QVector3D(num5-1,num8-1,num7-1));
    }
    else if(num1==1)
    {
        usesnormals=0;
        num1=split1[0].toInt();
        num2=split2[0].toInt();
        num3=split3[0].toInt();
        num4=split4[0].toInt();

        Triangles t1=Triangles();
        t1.vertexIndex1=num1-1;t1.vertexIndex2=num2-1;t1.vertexIndex3=num3-1;
        _faces.append(t1);
        Triangles t2=Triangles();
        t2.vertexIndex1=num1-1;t2.vertexIndex2=num4-1;t2.vertexIndex3=num3-1;
        _faces.append(t2);
    }
}

void ObjModelReader::loadObj()
{
    //   FILE *fp;
    int num1,offset=0;
    double x, y, z,vnx,vny,vnz;
    //char ch; /**/
    const char* fname = "..\\Qt3DExample\\12-elefante\\elefante.obj";
    std::string linestr;
    QString s1,s2,s3,s4;
    QStringList split1;
    QFile inputFile(fname);

    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();

            split1=line.split(' ');
            num1=split1.count();
            if(num1==0)
            {     /*Ignore if single word*/
            }
            else if(!split1[0].compare("o"))
            {
                //  qDebug()<<"Ignored"<<split1;
            }
            else if(!split1[0].compare("#")||!split1[0].compare("o")||!split1[0].compare("vt")||!split1[0].compare("l")||!split1[0].compare("g"))
            {
                //ignore comments and mesh statements, texture vertex etc
                //qDebug()<<"ignored"<< split1;
            }
            else if(!split1[0].compare("v"))
            {
                if(num1==5)
                {
                    offset=1;
                }
                else offset=0;
                x=split1[1+offset].toDouble();
                y=split1[2+offset].toDouble();
                z=split1[3+offset].toDouble();
                if(x<minx) minx=x;
                if(x>maxx) maxx=x;
                if(y<miny) miny=y;
                if(y>maxy) maxy=y;
                if(z<minz) minz=z;
                if(z>maxz) maxz=z;
                emitVertex(x,y,z);
            }
            else if(!split1[0].compare("vn"))
            {
                if(num1==5)
                {
                    offset=1;
                }
                else offset=0;
                vnx=split1[1+offset].toDouble();
                vny=split1[2+offset].toDouble();
                vnz=split1[3+offset].toDouble();
                emitNormal(vnx,vny,vnz);
            }
            else if(!split1[0].compare("s"))
            {
                //consume off in statement s off

            }
            else if(!split1[0].compare("f"))
            {
                s1=split1[1];
                s2=split1[2];
                s3=split1[3];
                if(num1==5)
                {
                    s4=split1[4];
                    emitFace2(s1,s2,s3,s4);
                }
                else
                {
                    emitFace1(s1,s2,s3);
                }
            }
        }
        inputFile.close();
    }
    else {
        qDebug()<<"Can't Open file";
    }
}

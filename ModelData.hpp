#ifndef MODELDATA_HPP
#define MODELDATA_HPP
#include<QObject>
#include<ObjModelReader.hpp>
#include<Triangles.hpp>
class ModelData : public QObject
{
Q_OBJECT
public:
    ModelData() {}
    virtual ~ModelData(){}
   Q_INVOKABLE void createModel(ObjModelReader *omr)
    {
        omr->loadObj();
        _vertices=omr->_vertices;
        _normals=omr->_normals;
        _faces=omr->_faces;
    }
    QVector<QVector3D> _vertices;
    QVector<QVector3D> _normals;
    QVector<Triangles> _faces;
};

#endif // MODELDATA_HPP

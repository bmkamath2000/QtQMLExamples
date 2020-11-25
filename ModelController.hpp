#ifndef MODELCONTROLLER_HPP
#define MODELCONTROLLER_HPP
#include<QObject>

#include<ModelGeometry.hpp>
#include<ModelData.hpp>
class ModelController : public QObject
{
    Q_OBJECT
public:
    ModelController() {}
    virtual ~ModelController() {}
//    static QString AbsolutePath;
public slots:
    ModelGeometry* createGeometry(ModelData* data,Qt3DCore::QNode *node = nullptr);
};
#endif // MODELCONTROLLER_HPP

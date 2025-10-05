#include<ModelController.hpp>
#include<Qt3DCore/QGeometry>
QString ModelController::AbsolutePath=QDir::currentPath();
ModelGeometry* ModelController::createGeometry(ModelData *data,Qt3DCore::QNode *node)
{
    return new ModelGeometry(data,node);
}

#include<ModelController.hpp>
#include<Qt3DRender/QGeometry>

ModelGeometry* ModelController::createGeometry(ModelData *data,Qt3DCore::QNode *node)
{
 //   ModelController::AbsolutePath="E:\\Qt\\workspace\\Qt3DExample\\12-elefante";
    return new ModelGeometry(data,node);
}

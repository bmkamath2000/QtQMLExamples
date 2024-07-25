#ifndef MODELGEOMETRY_HPP
#define MODELGEOMETRY_HPP
#include<Qt3DRender/QGeometry>
#include<Qt3DRender/QAttribute>
#include<ModelData.hpp>
#include<RenderAttributes.hpp>
class ModelGeometry : public Qt3DRender::QGeometry
{
public:
    ModelGeometry(){

    }
    ModelGeometry(ModelData *data,Qt3DCore::QNode *parent=nullptr)
        :Qt3DRender::QGeometry(parent)
    {
        omr=new ObjModelReader();

        data->createModel(omr);

        auto attr1=RenderAttributes::create(data->_vertices,Qt3DRender::QAttribute::defaultPositionAttributeName(),this);
        this->addAttribute(attr1);
        this->setBoundingVolumePositionAttribute(attr1);

        auto attr2=RenderAttributes::create(data->_normals,Qt3DRender::QAttribute::defaultNormalAttributeName(),this);
        this->addAttribute(attr2);

        auto attr3=RenderAttributes::create(data->_faces,this);
        this->addAttribute(attr3);
    }

    private:
    ObjModelReader *omr;

};
Q_DECLARE_METATYPE(ModelGeometry*);
#endif // MODELGEOMETRY_HPP

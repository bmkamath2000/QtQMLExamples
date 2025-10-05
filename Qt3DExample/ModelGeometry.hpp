#ifndef MODELGEOMETRY_HPP
#define MODELGEOMETRY_HPP
#include<Qt3DCore/QGeometry>
#include<Qt3DCore/QAttribute>
#include<ModelData.hpp>
#include<RenderAttributes.hpp>
class ModelGeometry : public Qt3DCore::QGeometry
{
public:
    ModelGeometry(){

    }
    ModelGeometry(ModelData *data,Qt3DCore::QNode *parent=nullptr)
        :Qt3DCore::QGeometry(parent)
    {
        omr=new ObjModelReader();

        data->createModel(omr);

        auto attr1=RenderAttributes::create(data->_vertices,Qt3DCore::QAttribute::defaultPositionAttributeName(),this);
        this->addAttribute(attr1);
        this->setBoundingVolumePositionAttribute(attr1);

        auto attr2=RenderAttributes::create(data->_normals,Qt3DCore::QAttribute::defaultNormalAttributeName(),this);
        this->addAttribute(attr2);

        auto attr3=RenderAttributes::create(data->_faces,this);
        this->addAttribute(attr3);
    }

    private:
    ObjModelReader *omr;

};
Q_DECLARE_METATYPE(ModelGeometry*);
#endif // MODELGEOMETRY_HPP

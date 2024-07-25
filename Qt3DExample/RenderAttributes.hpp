#ifndef RENDERATTRIBUTES_HPP
#define RENDERATTRIBUTES_HPP
#include<Triangles.hpp>
#include<Qt3DRender/QAttribute>
#include<Qt3DRender/QGeometry>
#include<QVector3D>
namespace RenderAttributes
{
Qt3DRender::QAttribute *create(const QVector<Triangles> &triangles, Qt3DRender::QGeometry *parent);

Qt3DRender::QAttribute *create(const QVector<QVector3D> &vertices, const QString &name, Qt3DRender::QGeometry *parent);

//Qt3DRender::QAttribute *create(const QVector<QVector4D> &vertices, const QString &name, Qt3DRender::QGeometry *parent);

//Qt3DRender::QAttribute *create(const QVector<float> &values, const QString &name, Qt3DRender::QGeometry *parent);

Qt3DRender::QAttribute *clone(Qt3DRender::QAttribute *from, Qt3DRender::QGeometry *parent);

};
#endif // RENDERATTRIBUTES_HPP

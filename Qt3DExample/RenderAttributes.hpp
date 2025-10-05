#ifndef RENDERATTRIBUTES_HPP
#define RENDERATTRIBUTES_HPP
#include<Triangles.hpp>
#include<Qt3DCore/QAttribute>
#include<Qt3DCore/QGeometry>
#include<QVector3D>
namespace RenderAttributes
{
Qt3DCore::QAttribute *create(const QVector<Triangles> &triangles, Qt3DCore::QGeometry *parent);

Qt3DCore::QAttribute *create(const QVector<QVector3D> &vertices, const QString &name, Qt3DCore::QGeometry *parent);

Qt3DCore::QAttribute *clone(Qt3DCore::QAttribute *from, Qt3DCore::QGeometry *parent);

};
#endif // RENDERATTRIBUTES_HPP

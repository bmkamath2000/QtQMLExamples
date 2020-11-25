#include<RenderAttributes.hpp>
#include<Triangles.hpp>
#include<Qt3DRender/QBuffer>

Qt3DRender::QAttribute *RenderAttributes::create(const QVector<Triangles> &triangles, Qt3DRender::QGeometry *parent)
{
    auto attribute = new Qt3DRender::QAttribute(parent);

    QVector<uint> indices;
    indices.reserve(triangles.size() * 3);

    for (const Triangles &triangle : triangles) {
        indices << static_cast<uint>(triangle.vertexIndex1)
                << static_cast<uint>(triangle.vertexIndex2)
                << static_cast<uint>(triangle.vertexIndex3);
    }

    Qt3DRender::QBuffer *dataBuffer = new Qt3DRender::QBuffer(attribute);
    const int rawSize = indices.size() * static_cast<int>(sizeof(uint));
    auto rawData = QByteArray::fromRawData(reinterpret_cast<const char*>(indices.constData()), rawSize);
    rawData.detach();
    dataBuffer->setData(rawData);

    attribute->setAttributeType(Qt3DRender::QAttribute::IndexAttribute);
    attribute->setBuffer(dataBuffer);
    attribute->setVertexBaseType(Qt3DRender::QAttribute::UnsignedInt);
    attribute->setVertexSize(1);
    attribute->setByteOffset(0);
    attribute->setByteStride(sizeof(uint));
    attribute->setCount(static_cast<uint>(indices.size()));

    return attribute;
}
Qt3DRender::QAttribute *RenderAttributes::create(const QVector<QVector3D> &vertices, const QString &name, Qt3DRender::QGeometry *parent)
{
    auto attribute = new Qt3DRender::QAttribute(parent);

    QVector<float> values;
    values.reserve(vertices.size() * 3);

    for (const QVector3D &v : vertices) {
        values << v.x() << v.y() << v.z();
    }

    Qt3DRender::QBuffer *dataBuffer = new Qt3DRender::QBuffer(attribute);
    const int rawSize = values.size() * static_cast<int>(sizeof(float));
    auto rawData = QByteArray::fromRawData(reinterpret_cast<const char*>(values.constData()), rawSize);
    rawData.detach();
    dataBuffer->setData(rawData);

    attribute->setAttributeType(Qt3DRender::QAttribute::VertexAttribute);
    attribute->setBuffer(dataBuffer);
    attribute->setVertexBaseType(Qt3DRender::QAttribute::Float);
    attribute->setVertexSize(3);
    attribute->setByteOffset(0);
    attribute->setByteStride(3 * sizeof(float));
    attribute->setName(name);
    attribute->setCount(static_cast<uint>(vertices.size()));

    return attribute;
}
Qt3DRender::QAttribute *RenderAttributes::clone(Qt3DRender::QAttribute *from, Qt3DRender::QGeometry *parent)
{
    auto attribute = new Qt3DRender::QAttribute(parent);

    Qt3DRender::QBuffer *dataBuffer = new Qt3DRender::QBuffer(attribute);
    auto dataCopy = from->buffer()->data();
    dataCopy.detach();
    dataBuffer->setData(dataCopy);

    attribute->setAttributeType(from->attributeType());
    attribute->setBuffer(dataBuffer);
    attribute->setVertexBaseType(from->vertexBaseType());
    attribute->setVertexSize(from->vertexSize());
    attribute->setByteOffset(from->byteOffset());
    attribute->setByteStride(from->byteStride());
    attribute->setName(from->name());
    attribute->setCount(from->count());

    return attribute;
}

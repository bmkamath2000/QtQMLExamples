#include "qwaveformhistorypanel.h"
#include <QSGGeometryNode>
#include<QSGGeometry>
#include <QSGFlatColorMaterial>
#include<QDebug>

class QWaveformHistoryPanelData : public QSharedData
{
public:

};

QWaveformHistoryPanel::QWaveformHistoryPanel(QQuickItem *parent) :
      QQuickItem(parent)
    , data(new QWaveformHistoryPanelData)
    , m_segmentCount(32)
{
    setFlag(ItemHasContents, true);
}

QWaveformHistoryPanel::QWaveformHistoryPanel(const QWaveformHistoryPanel &rhs)
    : data{rhs.data}
{

}

QWaveformHistoryPanel &QWaveformHistoryPanel::operator=(const QWaveformHistoryPanel &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

QWaveformHistoryPanel::~QWaveformHistoryPanel()
{

}

QSGNode *QWaveformHistoryPanel::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    QSGGeometryNode *node = nullptr;
    QSGGeometry *geometry = nullptr;

    if (!oldNode) {
        node = new QSGGeometryNode;
        geometry = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), m_segmentCount);
        geometry->setLineWidth(2);
        geometry->setDrawingMode(QSGGeometry::DrawLineStrip);
        node->setGeometry(geometry);
        node->setFlag(QSGNode::OwnsGeometry);
        auto *material = new QSGFlatColorMaterial;
        material->setColor(QColor(255, 0, 0));
        node->setMaterial(material);
        node->setFlag(QSGNode::OwnsMaterial);
    } else {
        node = static_cast<QSGGeometryNode *>(oldNode);
        geometry = node->geometry();
        geometry->allocate(m_segmentCount);
    }
    QSizeF itemSize = size();
    QSGGeometry::Point2D *vertices = geometry->vertexDataAsPoint2D();
    for (int i = 0; i < m_segmentCount; ++i) {
        qreal t = i / qreal(m_segmentCount - 1);

        float pos_x = t;
        float pos_y = 0.5f;

        float x = pos_x * itemSize.width();
        float y = pos_y * itemSize.height();

        vertices[i].set(x, y);
        //qDebug() << "x=" << x << "y=" << y;
    }
    node->markDirty(QSGNode::DirtyGeometry);
    return node;

}

void QWaveformHistoryPanel::setSegmentCount(int count)
{

}

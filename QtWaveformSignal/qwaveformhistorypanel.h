#ifndef QWAVEFORMHISTORYPANEL_H
#define QWAVEFORMHISTORYPANEL_H

#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>

class QWaveformHistoryPanelData;

class QWaveformHistoryPanel : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(int segmentCount READ segmentCount WRITE setSegmentCount NOTIFY segmentCountChanged)
    QML_ELEMENT
public:
    QWaveformHistoryPanel(QQuickItem *parent = nullptr);
    QWaveformHistoryPanel(const QWaveformHistoryPanel &);
    QWaveformHistoryPanel &operator=(const QWaveformHistoryPanel &);
    ~QWaveformHistoryPanel();

    QSGNode *updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *) override;

    int segmentCount() const { return m_segmentCount; }

    void setSegmentCount(int count);
signals:
    void p1Changed(const QPointF &p);
    void p2Changed(const QPointF &p);
    void p3Changed(const QPointF &p);
    void p4Changed(const QPointF &p);

    void segmentCountChanged(int count);
private:
    QSharedDataPointer<QWaveformHistoryPanelData> data;

    int m_segmentCount;
};

#endif // QWAVEFORMHISTORYPANEL_H

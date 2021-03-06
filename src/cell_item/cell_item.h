#pragma once

#include <QPainter>
#include <QGraphicsItem>

#include "../defs/defs.h"

namespace cell
{

class CellItem final : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit CellItem(const QSize& size, const QPoint& coordinates, const defs::Color& color, QObject* parent = Q_NULLPTR);
    ~CellItem() = default;

    void Reset();
    void SetType(const defs::CellType& type);

    defs::Color GetColor() const;
    QSize GetSize() const;
    QPoint GetCoordinates() const;

signals:
    void SendMetadata(const defs::CellType& type, const QPoint& coordinates);

private:
    QSize size_;
    QPoint coordinates_;

    defs::CellType type_;
    defs::Color    color_;
    defs::Colors   colors_;

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

};

} // cell
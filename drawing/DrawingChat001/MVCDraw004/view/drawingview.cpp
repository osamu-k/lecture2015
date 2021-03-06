#include "drawingview.h"

#include <QDebug>

DrawingView::DrawingView()
    : m_scale(1.0)
{
    setAutoFillBackground(true);
    setPalette(Qt::white);

    m_shapeSpace = ShapeSpace::instance();
    connect(m_shapeSpace, SIGNAL(changed()),this,SLOT(update()));
}

DrawingView::~DrawingView()
{

}

void DrawingView::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.scale(m_scale,m_scale);
    DrawVisitor visitor(painter);
    for( int i = 0; i < m_shapeSpace->shapeCount(); i++ ){
        Shape *shape = m_shapeSpace->shape(i);
        qDebug() << "DrawingView::paintEvent shape->type() = " << shape->type();
        shape->accept(&visitor);
    }
}

void DrawingView::setOriginalSize(QSize size)
{
    m_originalSize = size;
    int w = m_originalSize.width() * m_scale;
    int h = m_originalSize.height() * m_scale;
    setFixedSize( w, h );
    update();
}

void DrawingView::setScale( qreal scale )
{
    m_scale = scale;
    int w = m_originalSize.width() * m_scale;
    int h = m_originalSize.height() * m_scale;
    setFixedSize( w, h );
    update();
}

QPoint DrawingView::logicalPoint( QPoint p )
{
    return QPoint( (p.x() / m_scale),
                   (p.y() / m_scale) );
}

QPointF DrawingView::logicalPoint( QPointF p )
{
    return QPointF( (p.x() / m_scale),
                    (p.y() / m_scale) );
}

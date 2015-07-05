/*
* The MIT License (MIT)
*
* Copyright (c) 20014 Moukhlynin Ruslan <me@ruslan.pw>
*
* paintschemepoint.cpp
* This file is part of the QSimpleSpatial.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "paintschemepoint.h"

#include "pointfeature.h"
#include "maptranslator.h"

#include <QPainter>
#include <QDebug>

PaintSchemePoint::PaintSchemePoint() :
    PaintScheme(),
    p_type(PointTypeUndefined)
{
}

PaintSchemePoint::PaintSchemePoint(const QPen &pen, const QBrush brush,int size) :
    PaintScheme(pen,brush),
    p_size(size),
    p_type(PointTypeCircle)
{
}

PaintSchemePoint::PaintSchemePoint(const QPen &pen, const QBrush brush,const QPolygon &polygon) :
    PaintScheme(pen,brush),
    p_polygon(polygon),
    p_type(PointTypePolygon)
{
}

PaintSchemePoint::PaintSchemePoint(const QPixmap &pixmap) :
    PaintScheme(),
    p_pixmap(pixmap),
    p_type(PointTypePixmap)
{
}

QSimpleSpatial::ShapeTypes PaintSchemePoint::getShapeType()
{
    return QSimpleSpatial::Point;
}

int PaintSchemePoint::GetSize()
{
    return p_size;
}

PaintSchemePoint::PointType PaintSchemePoint::getType()
{
    return p_type;
}

void PaintSchemePoint::Draw(MapTranslator *renderer, Feature *feature, QPainter *painter, int idFeature)
{
    PointFeature * pf = static_cast<PointFeature *>(feature);
    if(pf) {

        QSimpleSpatial::SimplePoint point = pf->getPoint();
        QSimpleSpatial::SimplePoint pointPx = renderer->Coord2Screen(point.X, point.Y);

        qDebug() << "in point scheme";

        itemPoint->push_back(new MapGraphicsPointItem(pointPx.X, pointPx.Y, itemPoint->size(), idFeature, p_size, &p_pen, &p_brush));

    }
}

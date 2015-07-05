/*
* The MIT License (MIT)
*
* Copyright (c) 20014 Moukhlynin Ruslan <me@ruslan.pw>
*
* shapemapreader.h
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

#include "shapemapreader.h"

#include "pointfeature.h"
#include "polygonfeature.h"
#include "polylinefeature.h"
#include "projection.h"
#include "layer.h"

#include "variableview.h"

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QtEndian>
#include <QDebug>
#include <QDataStream>
#include <QTableWidget>


ShapeMapReader::ShapeMapReader(VariableView *vv, QObject *parent) :
    vv(vv), MapReader(parent)
{
}

Layer *ShapeMapReader::ReadFile(QString path, Projection *projection)
{
    QFile file(path);
    //QTableWidget *tablewidget = vv->getSpreadsheetTable();

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Error. Cannot open SHAPE file " << path;
        return NULL;
    }
    file.seek(0);
    QDataStream stream(&file);
    stream.setByteOrder(QDataStream::BigEndian);
    stream >> fileHeader.FileCode;
    stream >> fileHeader.Unused1;
    stream >> fileHeader.Unused2;
    stream >> fileHeader.Unused3;
    stream >> fileHeader.Unused4;
    stream >> fileHeader.Unused5;
    stream >> fileHeader.FileLength;
    stream.setByteOrder(QDataStream::LittleEndian);
    stream >> fileHeader.Version;
    stream >> fileHeader.ShapeType;
    stream >> fileHeader.Xmin;
    stream >> fileHeader.Ymin;
    stream >> fileHeader.Xmax;
    stream >> fileHeader.Ymax;
    stream >> fileHeader.Zmin;
    stream >> fileHeader.Zmax;
    stream >> fileHeader.Mmin;
    stream >> fileHeader.Mmax;
    qint32 pos = 50;
    ShapeFileRecordHeader recordHeader;
    Layer *fset = new Layer();
    fileHeader.Xmin = projection->toCartesianLon(fileHeader.Xmin);
    fileHeader.Ymin = projection->toCartesianLat(fileHeader.Ymin);
    fileHeader.Xmax = projection->toCartesianLon(fileHeader.Xmax);
    fileHeader.Ymax = projection->toCartesianLat(fileHeader.Ymax);
    fset->SetExtent(QSimpleSpatial::Extent(fileHeader.Xmin,
                                           fileHeader.Ymin,
                                           fileHeader.Xmax,
                                           fileHeader.Ymax));
    fset->SetShapeType((QSimpleSpatial::ShapeTypes)fileHeader.ShapeType);
    qint32 shapeType;
    Feature *feature;
    int count = 0 ;
    while(pos < fileHeader.FileLength && !stream.atEnd()) {
        stream.setByteOrder(QDataStream::BigEndian);
        stream >> recordHeader.RecordNumber;
        stream >> recordHeader.ContentLength;
        pos += 4;
        stream.setByteOrder(QDataStream::LittleEndian);
        stream  >> shapeType;
        feature = NULL;
        switch(shapeType) {
        case QSimpleSpatial::Point:
            double X,Y;
            stream  >> X;
            stream  >> Y;
            feature = fset->AddFeature(new PointFeature(fset,projection->toCartesian(X,Y)));
            break;

        case QSimpleSpatial::Polygon:
        case QSimpleSpatial::PolyLine:
            {
            if(shapeType == QSimpleSpatial::Polygon)
                feature = new PolygonFeature(fset);
            else if(shapeType == QSimpleSpatial::PolyLine)
                feature = new PolylineFeature(fset);
            double x1,y1,x2,y2;
            qint32 numParts,numPoints;
            stream  >> x1;
            stream  >> y1;
            stream  >> x2;
            stream  >> y2;
            feature->setExtent(projection->toCartesian(x1,y1),
                               projection->toCartesian(x2,y2));
            stream  >> numParts;
            stream  >> numPoints;
            double d1,d2;
            int i;
            int *parts = new int[numParts];
            for(i = 0;i < numParts;i ++) stream >> parts[i];
            int pos;
            for(i = 0;i < numParts;i ++) {
                int start = parts[i];
                int end;
                if(i < (numParts - 1)) end = parts[i + 1] - 1;
                else end = (numPoints - 1);
                int count = end - start + 1;
                Points *points = new Points;
                points->count = count;
                points->x = new double[count];
                points->y = new double[count];
                pos = 0;
                for(int j = start;j <= end;j ++) {
                    stream >> d1;
                    stream >> d2;
                    points->x[pos] = d1;
                    points->y[pos] = d2;
                    pos ++;
                }
                if(shapeType == QSimpleSpatial::Polygon)
                {
                    double sum = 0.0;
                    for(int j = 0;j < count - 1;j ++)
                        sum += (points->x[j + 1] - points->x[j]) * (points->y[j + 1] + points->y[j]);
                    points->cw = (sum >= 0.0);
                }
                projection->toCartesian(points->count,points->x,points->y);
                feature->AddPoints(points);

            }
            feature = fset->AddFeature(feature);
            }
            break;

        case QSimpleSpatial::PolygonZ:
        case QSimpleSpatial::PolyLineZ:
            {
            if(shapeType == QSimpleSpatial::PolygonZ){
                fset->SetShapeType(QSimpleSpatial::Polygon);
                feature = new PolygonFeature(fset);
            }
            else if(shapeType == QSimpleSpatial::PolyLineZ){
                fset->SetShapeType(QSimpleSpatial::PolyLine);
                feature = new PolylineFeature(fset);
            }
            double x1,y1,x2,y2;
            qint32 numParts,numPoints;
            stream  >> x1;
            stream  >> y1;
            stream  >> x2;
            stream  >> y2;
            feature->setExtent(projection->toCartesian(x1,y1),
                               projection->toCartesian(x2,y2));
            stream  >> numParts;
            stream  >> numPoints;
            double d1,d2;
            double d3,d4;
            double z1,z2;
            double m1,m2;
            int i;
            int *parts = new int[numParts];
            for(i = 0;i < numParts;i ++) stream >> parts[i];
            int pos;
            for(i = 0;i < numParts;i ++) {
                int start = parts[i];
                int end;
                if(i < (numParts - 1)) end = parts[i + 1] - 1;
                else end = (numPoints - 1);
                int count = end - start + 1;
                Points *points = new Points;
                points->count = count;
                points->x = new double[count];
                points->y = new double[count];
                pos = 0;
                for(int j = start;j <= end;j ++) {
                    stream >> d1;
                    stream >> d2;
                    points->x[pos] = d1;
                    points->y[pos] = d2;
                    pos ++;
                }
                if(shapeType == QSimpleSpatial::PolygonZ)
                {
                    double sum = 0.0;
                    for(int j = 0;j < count - 1;j ++)
                        sum += (points->x[j + 1] - points->x[j]) * (points->y[j + 1] + points->y[j]);
                    points->cw = (sum >= 0.0);
                }
                projection->toCartesian(points->count,points->x,points->y);
                feature->AddPoints(points);
            }

            stream >> z1;
            stream >> z2;

            for(i = 0;i < numParts;i ++) {
                int start = parts[i];
                int end;
                if(i < (numParts - 1)) end = parts[i + 1] - 1;
                else end = (numPoints - 1);
                int count = end - start + 1;
                double *z = new double[count];
                pos = 0;
                for(int j = start;j <= end;j ++) {
                    stream >> d3;
                    z[pos] = d3;
                    pos ++;
                }
            }

            stream >> m1;
            stream >> m2;

            for(i = 0;i < numParts;i ++) {
                int start = parts[i];
                int end;
                if(i < (numParts - 1)) end = parts[i + 1] - 1;
                else end = (numPoints - 1);
                int count = end - start + 1;
                double *m = new double[count];
                pos = 0;
                for(int j = start;j <= end;j ++) {
                    stream >> d4;
                    m[pos] = d4;
                    pos ++;
                }
            }

            feature = fset->AddFeature(feature);
            }
            break;
        }

        //for(int i=0; i < tablewidget->columnCount(); i++)
        //    feature->AddField(tablewidget->horizontalHeaderItem(i)->text(),tablewidget->item(count,i)->text().trimmed());

        feature->setIdFeature(count+1); //kalo id mau mulai dari 1 jangan dirubah count-nya, tapi +1 aja
        count++;
        pos += recordHeader.ContentLength;
    }
    return fset;
}

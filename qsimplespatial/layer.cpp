/*
* The MIT License (MIT)
*
* Copyright (c) 20014 Moukhlynin Ruslan <me@ruslan.pw>
*
* layer.cpp
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

#include "layer.h"

#include "maptranslator.h"
#include "mapgraphicspolygonitem.h"
#include "mapgraphicslineitem.h"
#include "mapgraphicspointitem.h"

#include <QDebug>
#include "polygonfeature.h"


Layer::Layer(QObject *parent) :
    QObject(parent),
    p_visible(true),
    p_shapeType(QSimpleSpatial::NullShape),
    p_minZoom(-1),
    p_maxZoom(-1),
    p_min_zoom_filter_func(NULL),
    p_max_zoom_filter_func(NULL)
{
}

Layer::~Layer()
{
    qDeleteAll(p_list);
    p_list.clear();
    qDeleteAll(p_schemes);
    p_schemes.clear();
    qDeleteAll(p_labelSchemes);
    p_labelSchemes.clear();
}

Layer::Layer(QSimpleSpatial::ShapeTypes shapeType, QObject *parent)
{
    p_shapeType = shapeType;
}

Layer::Layer(PaintScheme *scheme, QObject *parent)
{
    p_schemes.append(scheme);
}

Feature *Layer::AddFeature(Feature *feature)
{
    p_list.append(feature);
    p_extent.correctSize(feature->GetExtent());
    setSchemeForFeature(feature);
    setLabelSchemeForFeature(feature);
    return feature;
}

Feature *Layer::getFeature(int index)
{
    return p_list.at(index);
}

qint32 Layer::Count()
{
    return p_list.count();
}

const QList<Feature *> &Layer::getFeatures()
{
    return p_list;
}

void Layer::AddScheme(PaintScheme *scheme)
{
    if(GetShapeType() == scheme->getShapeType()) {
        p_schemes.append(scheme);
        setSchemeForFeatures();
    }
    else
        qWarning() << "Wrong shape type";
}

void Layer::AddLabelScheme(LabelScheme *scheme)
{
    p_labelSchemes.append(scheme);
    setLabelSchemeForFeatures();
}

bool Layer::isVisible()
{
    return p_visible;
}

void Layer::setVisible(bool visible)
{
    p_visible = visible;
}

QString Layer::getName() const
{
    return p_name;
}

void Layer::setName(const QString &name)
{
    p_name = name;
}

void Layer::SetExtent(const QSimpleSpatial::Extent &extent)
{
    p_extent = extent;
}

QString Layer::getSource() const
{
    return p_source;
}

void Layer::setSource(const QString &source)
{
    p_source = source;
}

QSimpleSpatial::Extent Layer::GetExtent()
{
    return p_extent;
}

QSimpleSpatial::ShapeTypes Layer::GetShapeType()
{
    return p_shapeType;
}

void Layer::SetShapeType(QSimpleSpatial::ShapeTypes shapeType)
{
    p_shapeType = shapeType;
}

double Layer::GetMaxZoom(Feature *feature)
{
    if(p_max_zoom_filter_func)
        return p_max_zoom_filter_func(feature);
    return (-1);
}

void Layer::setMaxZoom(double zoom)
{
    p_maxZoom = zoom;
}

double Layer::GetMinZoom(Feature *feature)
{
    if(p_min_zoom_filter_func)
        return p_min_zoom_filter_func(feature);
    return (-1);
}

void Layer::setMinZoom(double zoom)
{
    p_minZoom = zoom;
}

void Layer::SetMinZoomFilter(double (*min_zoom_filter_func)(Feature *))
{
    p_min_zoom_filter_func = min_zoom_filter_func;
    setMinZoomForFeatures();
}

void Layer::SetMaxZoomFilter(double (*max_zoom_filter_func)(Feature *))
{
    p_max_zoom_filter_func = max_zoom_filter_func;
    setMaxZoomForFeatures();
}

void Layer::DrawItemRegion(MapTranslator *renderer, QPainter *painter, QList<MapGraphicsPolygonItem*> *itemRegion)
{
    double currentZoom = renderer->getZoom();
    if(p_maxZoom != (-1) && p_maxZoom < currentZoom)
        return;
    if(p_minZoom != (-1) && p_minZoom > currentZoom)
        return;
    for(int i = 0;i < p_list.count();i ++) {
        Feature *feature = p_list[i];
        qDebug() << "scheme";
        QSimpleSpatial::Extent extent = feature->GetExtent();
        qDebug() << QString("%1,%2 - %3,%4").arg(extent.p1().X).arg(extent.p1().Y).arg(extent.p2().X).arg(extent.p2().Y);
        qDebug() << QString("%1,%2 - %3,%4").arg(renderer->getViewport().p1().X).arg(renderer->getViewport().p1().Y).arg(renderer->getViewport().p2().X).arg(renderer->getViewport().p2().Y);
        qDebug() << QString("%1,%2 - %3,%4")
                    .arg(renderer->getCurrentExtent().p1().X)
                    .arg(renderer->getCurrentExtent().p1().Y)
                    .arg(renderer->getCurrentExtent().p2().X)
                    .arg(renderer->getCurrentExtent().p2().Y);
        qDebug() << QString("%1").arg(renderer->getScaleFactor());

        if(renderer->getViewport().IsIntersect(extent)) {
            qDebug() << "scheme2";
            if(feature->getMaxZoom() != (-1) && feature->getMaxZoom() < currentZoom)
                continue;
            if(feature->getMinZoom() != (-1) && feature->getMinZoom() > currentZoom)
                continue;
            PaintScheme *scheme = feature->getScheme();
            if(scheme){
                qDebug() << "before scheme3";
                scheme->setItemRegion(itemRegion);
                scheme->Draw(renderer,feature,painter,i+1);
                qDebug() << "scheme3";
            }
        }
    }
}

void Layer::DrawItemLine(MapTranslator *renderer, QPainter *painter, QList<MapGraphicsLineItem *> *itemLine)
{
    double currentZoom = renderer->getZoom();
    if(p_maxZoom != (-1) && p_maxZoom < currentZoom)
        return;
    if(p_minZoom != (-1) && p_minZoom > currentZoom)
        return;
    for(int i = 0;i < p_list.count();i ++) {

        Feature *feature = p_list[i];
        QSimpleSpatial::Extent extent = feature->GetExtent();

        if(renderer->getViewport().IsIntersect(extent)) {
            if(feature->getMaxZoom() != (-1) && feature->getMaxZoom() < currentZoom)
                continue;
            if(feature->getMinZoom() != (-1) && feature->getMinZoom() > currentZoom)
                continue;
            PaintScheme *scheme = feature->getScheme();
            if(scheme){
                scheme->setItemLine(itemLine);
                scheme->Draw(renderer,feature,painter,i);
            }
        }
    }
}

void Layer::DrawItemPoint(MapTranslator *renderer, QPainter *painter, QList<MapGraphicsPointItem *> *itemPoint)
{
    double currentZoom = renderer->getZoom();
    if(p_maxZoom != (-1) && p_maxZoom < currentZoom)
        return;
    if(p_minZoom != (-1) && p_minZoom > currentZoom)
        return;
    for(int i = 0;i < p_list.count();i ++) {

        Feature *feature = p_list[i];
        QSimpleSpatial::Extent extent = feature->GetExtent();

        if(renderer->getViewport().IsIntersect(extent)) {
            if(feature->getMaxZoom() != (-1) && feature->getMaxZoom() < currentZoom)
                continue;
            if(feature->getMinZoom() != (-1) && feature->getMinZoom() > currentZoom)
                continue;
            PaintScheme *scheme = feature->getScheme();
            if(scheme){
                scheme->setItemPoint(itemPoint);
                scheme->Draw(renderer,feature,painter,i);
            }
        }
    }
}

void Layer::DrawLabel(MapTranslator *renderer, QPainter *painter, QList<MapGraphicsLabelItem*> *itemLabel)
{
    double currentZoom = renderer->getZoom();
    if(p_maxZoom != (-1) && p_maxZoom < currentZoom)
        return;
    if(p_minZoom != (-1) && p_minZoom > currentZoom)
        return;
    for(int i = 0;i < p_list.count();i ++) {
        Feature *feature = p_list[i];
        QSimpleSpatial::Extent extent = feature->GetExtent();
        if(renderer->getViewport().IsIntersect(extent)) {
            if(feature->getMaxZoom() != (-1) && feature->getMaxZoom() < currentZoom)
                continue;
            if(feature->getMinZoom() != (-1) && feature->getMinZoom() > currentZoom)
                continue;
            LabelScheme *scheme = feature->getLabelScheme();
            if(scheme){
                scheme->setItemLabel(itemLabel);
                scheme->Draw(renderer,feature,painter); //change to itemLabel

            }
        }
    }
}


void Layer::setMaxZoomForFeatures()
{
    foreach(Feature *feature,p_list)
        feature->setMaxZoom(p_max_zoom_filter_func(feature));
}

void Layer::setMinZoomForFeatures()
{
    foreach(Feature *feature,p_list)
        feature->setMinZoom(p_min_zoom_filter_func(feature));
}

void Layer::setSchemeForFeatures()
{
    foreach(Feature *feature,p_list) {
        setSchemeForFeature(feature);
    }
}

void Layer::setLabelSchemeForFeatures()
{
    foreach(Feature *feature,p_list) {
        setLabelSchemeForFeature(feature);
    }
}

void Layer::setSchemeForFeature(Feature *feature)
{
    PaintScheme *defaultScheme = 0;
    bool setDefault = true;
    for(int i = 0;i < p_schemes.count();i ++) {
        if(p_schemes[i]->IsDefault())
            defaultScheme = p_schemes[i];
        else if(p_schemes[i]->TestFilter(feature)) {
            feature->SetScheme(p_schemes[i]);
            setDefault = false;
        }
    }
    if(setDefault)
        feature->SetScheme(defaultScheme);
}

void Layer::setLabelSchemeForFeature(Feature *feature)
{
    LabelScheme *defaultScheme = 0;
    bool setDefault = true;
    for(int i = 0;i < p_labelSchemes.count();i ++) {
        if(p_labelSchemes[i]->isDefault())
            defaultScheme = p_labelSchemes[i];
        else if(p_labelSchemes[i]->TestFilter(feature))
        {
            feature->SetLabelScheme(p_labelSchemes[i]);
            setDefault = false;
        }
    }
    if(setDefault)
        feature->SetLabelScheme(defaultScheme);
}


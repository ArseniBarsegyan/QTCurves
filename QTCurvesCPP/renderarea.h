#pragma once

#include <QWidget>
#include <QColor>
#include <QPen>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    enum ShapeType {
        Astroid, Cycloid, HuygensCycloid, HypoCycloid, Line, Circle, Ellipse, Fancy, Starfish, Cloud, InvertedCloud
    };

    void setBackgroundColor(QColor color) {mBackgroundColor = color;}
    QColor getBackgroundColor() const {return mBackgroundColor;}
    void setShape(ShapeType shapes) { this->mShape = shapes; on_shape_change(); }
    ShapeType getShape() const {return this->mShape;}
    void setScale(float scale) {mScale = scale; repaint();}
    float getScale() const {return mScale;}
    void setInterval(float interval) {mIntervalLength = interval; repaint(); }
    float getInterval() const {return mIntervalLength;}
    void setStepCount(int stepCount) {mStepCount = stepCount; repaint();}
    int getStepCount() {return mStepCount;}

    void setShapeColor(QColor color) {mPen.setColor(color);}
    QColor getShapeColor() const {return mPen.color();}
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QColor mBackgroundColor;
    ShapeType mShape;

    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_hypoCycloid(float t);
    QPointF compute_huygenCycloid(float t);
    QPointF compute_line(float t);
    QPointF compute_circle(float t);
    QPointF compute_ellipse(float t);
    QPointF compute_fancy(float t);
    QPointF compute_starfish(float t);
    QPointF compute(float t);
    QPointF compute_cloud(float f, bool inverted);
    void on_shape_change();

    float mIntervalLength;
    float mScale;
    int mStepCount;
    QPen mPen;
};

#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QLabel>
#include <QToolButton>

class WidgetPar : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetPar(QWidget *parent=0);

signals:

public slots:

};

class titlebar : public QWidget
{
    Q_OBJECT
public:
    explicit titlebar(QWidget *parent=0);

signals:

public slots:
    void on_tiBar_clicked();

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual bool eventFilter(QObject *obj, QEvent *e);

    QTimer *m_titleRollTimer;
private:
    void updateMaximize();

    QLabel *TiBar_pIconLabel;               //左上角图标label
    QLabel *TiBar_pTitleLabel;              //中间标题栏label

    QToolButton *TiBar_pMinimizeBtn;        //右上角缩小到底部任务栏按钮,最小化
    QToolButton *TiBar_pMaximizeBtn;        //右上角放大缩小按钮
    QToolButton *TiBar_pCloseBtn;           //右上角关闭按钮

};

#endif // TITLEBAR_H

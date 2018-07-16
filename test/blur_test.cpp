#include "widget.h"
#include "QDebug"
#include "QHBoxLayout"
#include "QImage"
#include "QApplication"
#include "QLabel"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    auto layout=new QHBoxLayout{this};
    this->setLayout(layout);
    this->setAutoFillBackground(false);
    layout->setMargin(0);
    layout->setSpacing(0);

    auto dir=QApplication::applicationDirPath();
    auto pix=QPixmap(dir+"/2.jpg");

    auto blur=[](QPixmap* pix)->QPixmap{
        auto image=pix->toImage();
        int xx[]={-4,-4,-3,-2,-1,0,1,2,3,4,4,4,3,2,1,0,-1,-2,-3,-4};
        int yy[]={0,1,2,3,4,4,4,3,2,1,0,-1,-2,-3,-4,-4,-4,-3,-2,-1};
        auto mixed=[&](int i,int j)->int{
            auto r=0;
            auto g=0;
            auto b=0;
            auto count=0;
            //deep=2,4,6,8
            for(auto deep=1;deep<=4;deep++){
                for(auto k=0;k<20;k++){
                    auto tx=i+xx[k]*deep;
                    auto ty=j+yy[k]*deep;
                    if(tx<0||tx>=image.width())continue;
                    if(ty<0||ty>=image.height())continue;
                    count++;
                    r+=image.pixelColor(tx,ty).red();
                    g+=image.pixelColor(tx,ty).green();
                    b+=image.pixelColor(tx,ty).blue();
                }
            }
            count+=1;
            r+=image.pixelColor(i,j).red();
            g+=image.pixelColor(i,j).green();
            b+=image.pixelColor(i,j).blue();
            auto result=(r/count)<<16|(g/count)<<8|(b/count);
            return result;
        };
        QImage res(image.width(),image.height(),QImage::Format_RGB32);
        for(auto i=0;i<image.width();i++){
            for(auto j=0;j<image.height();j++){
                auto r=mixed(i,j);
                res.setPixelColor(i,j,QColor(r>>16&255,r>>8&255,r&255));
            }
        }
        return QPixmap::fromImage(res);
    };

    auto b1=blur(&pix);
    auto b2=blur(&b1);
    auto b3=blur(&b2);

    auto origin=new QLabel;
    layout->addWidget(origin);
    origin->setPixmap(pix);

    auto target=new QLabel;
    layout->addWidget(target);
    target->setPixmap(b1);

    auto target2=new QLabel;
    layout->addWidget(target2);
    target2->setPixmap(b2);

    auto target3=new QLabel;
    layout->addWidget(target3);
    target3->setPixmap(b3);

}

Widget::~Widget()
{

}

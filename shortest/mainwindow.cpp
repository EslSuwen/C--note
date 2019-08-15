#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include <QPainter>
#include<QTime>

void sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->shortes=new shortestpath;
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            colors[i][j]="lightGray";
        }
    }
    this->shortes->StortPath1(this->shortes->G,this->shortes->P1,this->distance1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter pbk(this);
    //pbk.drawPixmap(30,10,881,701,QPixmap("D:\\Download\\QT-master\\shortest\\map.jpg"));
    pbk.drawPixmap(30,10,881,701,QPixmap(":/map.jpg"));

    QPen bj_tj_pen;
    QPainter bj_tj_painter(this);
    bj_tj_pen.setWidth(5);
    bj_tj_pen.setColor(QColor(colors[14][15]));
    bj_tj_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    bj_tj_painter.setPen(bj_tj_pen);
    bj_tj_painter.drawLine(QPointF(ui->btn_beijing->x()+7,ui->btn_beijing->y()+7), QPointF(ui->btn_tianjing->x()+7, ui->btn_tianjing->y()+7));// 绘制直线

    QPen cd_km_pen;
    QPainter cd_km_painter(this);
    cd_km_pen.setWidth(5);
    cd_km_pen.setColor(QColor(colors[0][1]));
    cd_km_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    cd_km_painter.setPen(cd_km_pen);
    cd_km_painter.drawLine(QPointF(ui->btn_chengdu->x()+7,ui->btn_chengdu->y()+7), QPointF(ui->btn_kunming->x()+7, ui->btn_kunming->y()+7));// 绘制直线

 /*   QPen cd_xa_pen;
    QPainter cd_xa_painter(this);
    cd_xa_pen.setWidth(5);
    cd_xa_pen.setColor(QColor(colors[0][20]));
    cd_xa_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    cd_xa_painter.setPen(cd_xa_pen);
    cd_xa_painter.drawLine(QPointF(ui->btn_chengdu->x()+7,ui->btn_chengdu->y()+7), QPointF(ui->btn_xian->x()+7, ui->btn_xian->y()+7));// 绘制直线
*/
    QPen cd_gy_pen;
    QPainter cd_gy_painter(this);
    cd_gy_pen.setWidth(5);
    cd_gy_pen.setColor(QColor(colors[0][2]));
    cd_gy_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    cd_gy_painter.setPen(cd_gy_pen);
    cd_gy_painter.drawLine(QPointF(ui->btn_chengdu->x()+7,ui->btn_chengdu->y()+7), QPointF(ui->btn_guiyang->x()+7, ui->btn_guiyang->y()+7));// 绘制直线

    QPen km_gy_pen;
    QPainter km_gy_painter(this);
    km_gy_pen.setWidth(5);
    km_gy_pen.setColor(QColor(colors[1][2]));
    km_gy_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    km_gy_painter.setPen(km_gy_pen);
    km_gy_painter.drawLine(QPointF(ui->btn_guiyang->x()+7,ui->btn_guiyang->y()+7), QPointF(ui->btn_kunming->x()+7, ui->btn_kunming->y()+7));// 绘制直线


   /* QPen gy_lz_pen;
    QPainter gy_lz_painter(this);
    gy_lz_pen.setWidth(5);
    gy_lz_pen.setColor(QColor(colors[2][3]));
    gy_lz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    gy_lz_painter.setPen(gy_lz_pen);
    gy_lz_painter.drawLine(QPointF(ui->btn_guiyang->x()+7,ui->btn_guiyang->y()+7), QPointF(ui->btn_liuzhou->x()+7, ui->btn_liuzhou->y()+7));// 绘制直线
*/
    QPen lz_nn_pen;
    QPainter lz_nn_painter(this);
    lz_nn_pen.setWidth(5);
    lz_nn_pen.setColor(QColor(colors[3][4]));
    lz_nn_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    lz_nn_painter.setPen(lz_nn_pen);
    lz_nn_painter.drawLine(QPointF(ui->btn_nanning->x()+7,ui->btn_nanning->y()+7), QPointF(ui->btn_liuzhou->x()+7, ui->btn_liuzhou->y()+7));// 绘制直线

    QPen lz_zz_pen;
    QPainter lz_zz_painter(this);
    lz_zz_pen.setWidth(5);
    lz_zz_pen.setColor(QColor(colors[3][5]));
    lz_zz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    lz_zz_painter.setPen(lz_zz_pen);
    lz_zz_painter.drawLine(QPointF(ui->btn_zhuzhou->x()+7,ui->btn_zhuzhou->y()+7), QPointF(ui->btn_liuzhou->x()+7, ui->btn_liuzhou->y()+7));// 绘制直线

    QPen gy_zz_pen;
    QPainter gy_zz_painter(this);
    gy_zz_pen.setWidth(5);
    gy_zz_pen.setColor(QColor(colors[2][5]));
    gy_zz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    gy_zz_painter.setPen(gy_zz_pen);
    gy_zz_painter.drawLine(QPointF(ui->btn_zhuzhou->x()+7,ui->btn_zhuzhou->y()+7), QPointF(ui->btn_guiyang->x()+7, ui->btn_guiyang->y()+7));// 绘制直线

    QPen zz_gz_pen;
    QPainter zz_gz_painter(this);
    zz_gz_pen.setWidth(5);
    zz_gz_pen.setColor(QColor(colors[5][6]));
    zz_gz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    zz_gz_painter.setPen(zz_gz_pen);
    zz_gz_painter.drawLine(QPointF(ui->btn_zhuzhou->x()+7,ui->btn_zhuzhou->y()+7), QPointF(ui->btn_guangzhou->x()+7, ui->btn_guangzhou->y()+7));// 绘制直线

  /*  QPen gz_sz_pen;
    QPainter gz_sz_painter(this);
    gz_sz_pen.setWidth(5);
    gz_sz_pen.setColor(QColor(colors[6][7]));
    gz_sz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    gz_sz_painter.setPen(gz_sz_pen);
    gz_sz_painter.drawLine(QPointF(ui->btn_guangzhou->x()+7,ui->btn_guangzhou->y()+7), QPointF(ui->btn_shenzhen->x()+7, ui->btn_shenzhen->y()+7));// 绘制直线
*/
/*    QPen zz_nc_pen;
    QPainter zz_nc_painter(this);
    zz_nc_pen.setWidth(5);
    zz_nc_pen.setColor(QColor(colors[5][8]));
    zz_nc_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    zz_nc_painter.setPen(zz_nc_pen);
    zz_nc_painter.drawLine(QPointF(ui->btn_zhuzhou->x()+7,ui->btn_zhuzhou->y()+7), QPointF(ui->btn_nanchang->x()+7, ui->btn_nanchang->y()+7));
*/
    QPen nc_fz_pen;
    QPainter nc_fz_painter(this);
    nc_fz_pen.setWidth(5);
    nc_fz_pen.setColor(QColor(colors[8][9]));
    nc_fz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    nc_fz_painter.setPen(nc_fz_pen);
    nc_fz_painter.drawLine(QPointF(ui->btn_fuzhou->x()+7,ui->btn_fuzhou->y()+7), QPointF(ui->btn_nanchang->x()+7, ui->btn_nanchang->y()+7));

    QPen nc_sh_pen;
    QPainter nc_sh_painter(this);
    nc_sh_pen.setWidth(5);
    nc_sh_pen.setColor(QColor(colors[8][10]));
    nc_sh_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    nc_sh_painter.setPen(nc_sh_pen);
    nc_sh_painter.drawLine(QPointF(ui->btn_shanghai->x()+7,ui->btn_shanghai->y()+7), QPointF(ui->btn_nanchang->x()+7, ui->btn_nanchang->y()+7));

    QPen zz_wh_pen;
    QPainter zz_wh_painter(this);
    zz_wh_pen.setWidth(5);
    zz_wh_pen.setColor(QColor(colors[5][11]));
    zz_wh_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    zz_wh_painter.setPen(zz_wh_pen);
    zz_wh_painter.drawLine(QPointF(ui->btn_zhuzhou->x()+7,ui->btn_zhuzhou->y()+7), QPointF(ui->btn_wuhan->x()+7, ui->btn_wuhan->y()+7));

    QPen wh_zz_pen;
    QPainter wh_zz_painter(this);
    wh_zz_pen.setWidth(5);
    wh_zz_pen.setColor(QColor(colors[11][13]));
    wh_zz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    wh_zz_painter.setPen(wh_zz_pen);
    wh_zz_painter.drawLine(QPointF(ui->btn_zhengzhou->x()+7,ui->btn_zhengzhou->y()+7), QPointF(ui->btn_wuhan->x()+7, ui->btn_wuhan->y()+7));

    QPen zz_xz_pen;
    QPainter zz_xz_painter(this);
    zz_xz_pen.setWidth(5);
    zz_xz_pen.setColor(QColor(colors[12][13]));
    zz_xz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    zz_xz_painter.setPen(zz_xz_pen);
    zz_xz_painter.drawLine(QPointF(ui->btn_zhengzhou->x()+7,ui->btn_zhengzhou->y()+7), QPointF(ui->btn_xuzhou->x()+7, ui->btn_xuzhou->y()+7));

    QPen sh_xz_pen;
    QPainter sh_xz_painter(this);
    sh_xz_pen.setWidth(5);
    sh_xz_pen.setColor(QColor(colors[10][12]));
    sh_xz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    sh_xz_painter.setPen(sh_xz_pen);
    sh_xz_painter.drawLine(QPointF(ui->btn_shanghai->x()+7,ui->btn_shanghai->y()+7), QPointF(ui->btn_xuzhou->x()+7, ui->btn_xuzhou->y()+7));

    QPen zz_bj_pen;
    QPainter zz_bj_painter(this);
    zz_bj_pen.setWidth(5);
    zz_bj_pen.setColor(QColor(colors[13][15]));
    zz_bj_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    zz_bj_painter.setPen(zz_bj_pen);
    zz_bj_painter.drawLine(QPointF(ui->btn_zhengzhou->x()+7,ui->btn_zhengzhou->y()+7), QPointF(ui->btn_beijing->x()+7, ui->btn_beijing->y()+7));

  /*  QPen xz_tj_pen;
    QPainter xz_tj_painter(this);
    xz_tj_pen.setWidth(5);
    xz_tj_pen.setColor(QColor(colors[12][14]));
    xz_tj_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    xz_tj_painter.setPen(xz_tj_pen);
    xz_tj_painter.drawLine(QPointF(ui->btn_xuzhou->x()+7,ui->btn_xuzhou->y()+7), QPointF(ui->btn_tianjing->x()+7, ui->btn_tianjing->y()+7));
*/
    QPen tj_sy_pen;
    QPainter tj_sy_painter(this);
    tj_sy_pen.setWidth(5);
    tj_sy_pen.setColor(QColor(colors[14][16]));
    tj_sy_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    tj_sy_painter.setPen(tj_sy_pen);
    tj_sy_painter.drawLine(QPointF(ui->btn_shenyang->x()+7,ui->btn_shenyang->y()+7), QPointF(ui->btn_tianjing->x()+7, ui->btn_tianjing->y()+7));

    QPen sy_dl_pen;
    QPainter sy_dl_painter(this);
    sy_dl_pen.setWidth(5);
    sy_dl_pen.setColor(QColor(colors[16][17]));
    sy_dl_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    sy_dl_painter.setPen(sy_dl_pen);
    sy_dl_painter.drawLine(QPointF(ui->btn_shenyang->x()+7,ui->btn_shenyang->y()+7), QPointF(ui->btn_dalian->x()+7, ui->btn_dalian->y()+7));

    QPen sy_cc_pen;
    QPainter sy_cc_painter(this);
    sy_cc_pen.setWidth(5);
    sy_cc_pen.setColor(QColor(colors[16][18]));
    sy_cc_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    sy_cc_painter.setPen(sy_cc_pen);
    sy_cc_painter.drawLine(QPointF(ui->btn_shenyang->x()+7,ui->btn_shenyang->y()+7), QPointF(ui->btn_changchun->x()+7, ui->btn_changchun->y()+7));

    QPen cc_heb_pen;
    QPainter cc_heb_painter(this);
    cc_heb_pen.setWidth(5);
    cc_heb_pen.setColor(QColor(colors[18][19]));
    cc_heb_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    cc_heb_painter.setPen(cc_heb_pen);
    cc_heb_painter.drawLine(QPointF(ui->btn_haerbin->x()+7,ui->btn_haerbin->y()+7), QPointF(ui->btn_changchun->x()+7, ui->btn_changchun->y()+7));

    QPen zz_xa_pen;
    QPainter zz_xa_painter(this);
    zz_xa_pen.setWidth(5);
    zz_xa_pen.setColor(QColor(colors[13][20]));
    zz_xa_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    zz_xa_painter.setPen(zz_xa_pen);
    zz_xa_painter.drawLine(QPointF(ui->btn_zhengzhou->x()+7,ui->btn_zhengzhou->y()+7), QPointF(ui->btn_xian->x()+7, ui->btn_xian->y()+7));

/*    QPen xa_lz_pen;
    QPainter xa_lz_painter(this);
    xa_lz_pen.setWidth(5);
    xa_lz_pen.setColor(QColor(colors[20][22]));
    xa_lz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    xa_lz_painter.setPen(xa_lz_pen);
    xa_lz_painter.drawLine(QPointF(ui->btn_lanzhou->x()+7,ui->btn_lanzhou->y()+7), QPointF(ui->btn_xian->x()+7, ui->btn_xian->y()+7));
*/
 /*   QPen hhht_lz_pen;
    QPainter hhht_lz_painter(this);
    hhht_lz_pen.setWidth(5);
    hhht_lz_pen.setColor(QColor(colors[21][22]));
    hhht_lz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    hhht_lz_painter.setPen(hhht_lz_pen);
    hhht_lz_painter.drawLine(QPointF(ui->btn_lanzhou->x()+7,ui->btn_lanzhou->y()+7), QPointF(ui->btn_huhehaote->x()+7, ui->btn_huhehaote->y()+7));
*/
    QPen bj_hhht_pen;
    QPainter bj_hhht_painter(this);
    bj_hhht_pen.setWidth(5);
    bj_hhht_pen.setColor(QColor(colors[15][21]));
    bj_hhht_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    bj_hhht_painter.setPen(bj_hhht_pen);
    bj_hhht_painter.drawLine(QPointF(ui->btn_beijing->x()+7,ui->btn_beijing->y()+7), QPointF(ui->btn_huhehaote->x()+7, ui->btn_huhehaote->y()+7));

    QPen lz_xl_pen;
    QPainter lz_xl_painter(this);
    lz_xl_pen.setWidth(5);
    lz_xl_pen.setColor(QColor(colors[22][23]));
    lz_xl_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    lz_xl_painter.setPen(lz_xl_pen);
    lz_xl_painter.drawLine(QPointF(ui->btn_lanzhou->x()+7,ui->btn_lanzhou->y()+7), QPointF(ui->btn_xining->x()+7, ui->btn_xining->y()+7));

    QPen lz_wlmq_pen;
    QPainter lz_wlmq_painter(this);
    lz_wlmq_pen.setWidth(5);
    lz_wlmq_pen.setColor(QColor(colors[22][24]));
    lz_wlmq_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    lz_wlmq_painter.setPen(lz_wlmq_pen);
    lz_wlmq_painter.drawLine(QPointF(ui->btn_lanzhou->x()+7,ui->btn_lanzhou->y()+7), QPointF(ui->btn_wulumuqi->x()+7, ui->btn_wulumuqi->y()+7));

    QPen nn_xa_pen;
    QPainter nn_xa_painter(this);
    nn_xa_pen.setWidth(5);
    nn_xa_pen.setColor(QColor(colors[4][20]));
    nn_xa_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    nn_xa_painter.setPen(nn_xa_pen);
    nn_xa_painter.drawLine(QPointF(ui->btn_nanning->x()+7,ui->btn_nanning->y()+7), QPointF(ui->btn_xian->x()+7, ui->btn_xian->y()+7));

    QPen sz_fz_pen;
    QPainter sz_fz_painter(this);
    sz_fz_pen.setWidth(5);
    sz_fz_pen.setColor(QColor(colors[7][9]));
    sz_fz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    sz_fz_painter.setPen(sz_fz_pen);
    sz_fz_painter.drawLine(QPointF(ui->btn_shenzhen->x()+7,ui->btn_shenzhen->y()+7), QPointF(ui->btn_fuzhou->x()+7, ui->btn_fuzhou->y()+7));

    QPen fz_sh_pen;
    QPainter fz_sh_painter(this);
    fz_sh_pen.setWidth(5);
    fz_sh_pen.setColor(QColor(colors[9][10]));
    fz_sh_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    fz_sh_painter.setPen(fz_sh_pen);
    fz_sh_painter.drawLine(QPointF(ui->btn_fuzhou->x()+7,ui->btn_fuzhou->y()+7), QPointF(ui->btn_shanghai->x()+7, ui->btn_shanghai->y()+7));

    QPen xz_bj_pen;
    QPainter xz_bj_painter(this);
    xz_bj_pen.setWidth(5);
    xz_bj_pen.setColor(QColor(colors[12][15]));
    xz_bj_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    xz_bj_painter.setPen(xz_bj_pen);
    xz_bj_painter.drawLine(QPointF(ui->btn_xuzhou->x()+7,ui->btn_xuzhou->y()+7), QPointF(ui->btn_beijing->x()+7, ui->btn_beijing->y()+7));

    QPen gz_nc_pen;
    QPainter gz_nc_painter(this);
    gz_nc_pen.setWidth(5);
    gz_nc_pen.setColor(QColor(colors[6][8]));
    gz_nc_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    gz_nc_painter.setPen(gz_nc_pen);
    gz_nc_painter.drawLine(QPointF(ui->btn_guangzhou->x()+7,ui->btn_guangzhou->y()+7), QPointF(ui->btn_nanchang->x()+7, ui->btn_nanchang->y()+7));

    QPen nc_wh_pen;
    QPainter nc_wh_painter(this);
    nc_wh_pen.setWidth(5);
    nc_wh_pen.setColor(QColor(colors[8][11]));
    nc_wh_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    nc_wh_painter.setPen(nc_wh_pen);
    nc_wh_painter.drawLine(QPointF(ui->btn_nanchang->x()+7,ui->btn_nanchang->y()+7), QPointF(ui->btn_wuhan->x()+7, ui->btn_wuhan->y()+7));

    QPen xn_wumq_pen;
    QPainter xn_wumq_painter(this);
    xn_wumq_pen.setWidth(5);
    xn_wumq_pen.setColor(QColor(colors[23][24]));
    xn_wumq_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    xn_wumq_painter.setPen(xn_wumq_pen);
    xn_wumq_painter.drawLine(QPointF(ui->btn_xining->x()+7,ui->btn_xining->y()+7), QPointF(ui->btn_wulumuqi->x()+7, ui->btn_wulumuqi->y()+7));

    QPen cd_xn_pen;
    QPainter cd_xn_painter(this);
    cd_xn_pen.setWidth(5);
    cd_xn_pen.setColor(QColor(colors[0][23]));
    cd_xn_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    cd_xn_painter.setPen(cd_xn_pen);
    cd_xn_painter.drawLine(QPointF(ui->btn_chengdu->x()+7,ui->btn_chengdu->y()+7), QPointF(ui->btn_xining->x()+7, ui->btn_xining->y()+7));

    QPen gy_lz1_pen;
    QPainter gy_lz1_painter(this);
    gy_lz1_pen.setWidth(5);
    gy_lz1_pen.setColor(QColor(colors[2][22]));
    gy_lz1_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    gy_lz1_painter.setPen(gy_lz1_pen);
    gy_lz1_painter.drawLine(QPointF(ui->btn_guiyang->x()+7,ui->btn_guiyang->y()+7), QPointF(ui->btn_lanzhou->x()+7, ui->btn_lanzhou->y()+7));

    QPen nc_lz_pen;
    QPainter nc_lz_painter(this);
    nc_lz_pen.setWidth(5);
    nc_lz_pen.setColor(QColor(colors[3][22]));
    nc_lz_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    nc_lz_painter.setPen(nc_lz_pen);
    nc_lz_painter.drawLine(QPointF(ui->btn_liuzhou->x()+7,ui->btn_liuzhou->y()+7), QPointF(ui->btn_lanzhou->x()+7, ui->btn_lanzhou->y()+7));

    QPen xa_hhht_pen;
    QPainter xa_hhht_painter(this);
    xa_hhht_pen.setWidth(5);
    xa_hhht_pen.setColor(QColor(colors[20][21]));
    xa_hhht_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    xa_hhht_painter.setPen(xa_hhht_pen);
    xa_hhht_painter.drawLine(QPointF(ui->btn_xian->x()+7,ui->btn_xian->y()+7), QPointF(ui->btn_huhehaote->x()+7, ui->btn_huhehaote->y()+7));

    QPen he_hhht_pen;
    QPainter he_hhht_painter(this);
    he_hhht_pen.setWidth(5);
    he_hhht_pen.setColor(QColor(colors[19][21]));
    he_hhht_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    he_hhht_painter.setPen(he_hhht_pen);
    he_hhht_painter.drawLine(QPointF(ui->btn_haerbin->x()+7,ui->btn_haerbin->y()+7), QPointF(ui->btn_huhehaote->x()+7, ui->btn_huhehaote->y()+7));

    QPen tj_dl_pen;
    QPainter tj_dl_painter(this);
    tj_dl_pen.setWidth(5);
    tj_dl_pen.setColor(QColor(colors[14][17]));
    tj_dl_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    tj_dl_painter.setPen(tj_dl_pen);
    tj_dl_painter.drawLine(QPointF(ui->btn_tianjing->x()+7,ui->btn_tianjing->y()+7), QPointF(ui->btn_dalian->x()+7, ui->btn_dalian->y()+7));

    QPen tj_hhht_pen;
    QPainter tj_hhht_painter(this);
    tj_hhht_pen.setWidth(5);
    tj_hhht_pen.setColor(QColor(colors[14][21]));
    tj_hhht_painter.setRenderHint(QPainter::Antialiasing, true); // 反走样
    tj_hhht_painter.setPen(tj_hhht_pen);
    tj_hhht_painter.drawLine(QPointF(ui->btn_tianjing->x()+7,ui->btn_tianjing->y()+7), QPointF(ui->btn_huhehaote->x()+7, ui->btn_huhehaote->y()+7));
}
void MainWindow::on_btn_chengdu_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_chengdu->text());
        this->shortes->starcity="jiangjin";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else
    {
       this->ui->label_over->setText(this->ui->btn_chengdu->text());
        this->shortes->overcity="jiangjin";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="jiangjin")
                {
                    t=i;
                    display="两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }

            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_kunming_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_kunming->text());
        this->shortes->starcity="qijiang";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_kunming->text());
        this->shortes->overcity="qijiang";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="qijiang")
                {
                    t=i;
                    display="两地最短距离为"+ QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }

            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_guiyang_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_guiyang->text());
        this->shortes->starcity="nanchuan";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_guiyang->text());
        this->shortes->overcity="nanchuan";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="nanchuan")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_guangzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_guangzhou->text());
        this->shortes->starcity="wulong";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_guangzhou->text());
        this->shortes->overcity="wulong";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="wulong")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }

            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_nanning_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_nanning->text());
        this->shortes->starcity="dianjiang";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_nanning->text());
        this->shortes->overcity="dianjiang";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="dianjiang")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_liuzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_liuzhou->text());
        this->shortes->starcity="changshou";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_liuzhou->text());
        this->shortes->overcity="changshou";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="changshou")
                {
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                    t=i;
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_zhuzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_zhuzhou->text());
        this->shortes->starcity="fuling";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_zhuzhou->text());
        this->shortes->overcity="fuling";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="fuling")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_haerbin_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_haerbin->text());
        this->shortes->starcity="chengkou";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_haerbin->text());
        this->shortes->overcity="chengkou";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="chengkou")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_shenzhen_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_shenzhen->text());
        this->shortes->starcity="xiushan";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_shenzhen->text());
        this->shortes->overcity="xiushan";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="xiushan")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_fuzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_fuzhou->text());
        this->shortes->starcity="youyang";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_fuzhou->text());
        this->shortes->overcity="youyang";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="youyang")
                {
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                    t=i;
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_nanchang_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_nanchang->text());
        this->shortes->starcity="penshui";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_nanchang->text());
        this->shortes->overcity="penshui";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="penshui")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_shanghai_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_shanghai->text());
        this->shortes->starcity="qianjiang";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_shanghai->text());
        this->shortes->overcity="qianjiang";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="qianjiang")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_wuhan_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_wuhan->text());
        this->shortes->starcity="fengdu";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_wuhan->text());
        this->shortes->overcity="fengdu";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="fengdu")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_xuzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_xuzhou->text());
        this->shortes->starcity="shizhu";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_xuzhou->text());
        this->shortes->overcity="shizhu";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="shizhu")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_zhengzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_zhengzhou->text());
        this->shortes->starcity="zhongxian";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_zhengzhou->text());
        this->shortes->overcity="zhongxian";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="zhongxian")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_xian_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_xian->text());
        this->shortes->starcity="liangping";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_xian->text());
        this->shortes->overcity="liangping";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="liangping")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_tianjing_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_tianjing->text());
        this->shortes->starcity="yunyang";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_tianjing->text());
        this->shortes->overcity="yunyang";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="yunyang")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_dalian_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_dalian->text());
        this->shortes->starcity="fengjie";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_dalian->text());
        this->shortes->overcity="fengjie";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="fengjie")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_shenyang_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_shenyang->text());
        this->shortes->starcity="wushan";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_shenyang->text());
        this->shortes->overcity="wushan";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="wushan")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_wulumuqi_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_wulumuqi->text());
        this->shortes->starcity="rongchang";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_wulumuqi->text());
        this->shortes->overcity="rongchang";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="rongchang")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_xining_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_xining->text());
        this->shortes->starcity="yongchuan";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_xining->text());
        this->shortes->overcity="yongchuan";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="yongchuan")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_huhehaote_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_huhehaote->text());
        this->shortes->starcity="kaixian";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_huhehaote->text());
        this->shortes->overcity="kaixian";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="kaixian")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_changchun_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_changchun->text());
        this->shortes->starcity="wuxi";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_changchun->text());
        this->shortes->overcity="wuxi";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="wuxi")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_beijing_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_beijing->text());
        this->shortes->starcity="wanzhou";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_beijing->text());
        this->shortes->overcity="wanzhou";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="wanzhou")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)
                                        {colors[n][m] = "red";colors[m][n] = "red";
                                        }
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_lanzhou_clicked()
{
    if(this->shortes->starcity=="")
    {
        for(int i=0;i<25;i++)
        {
            for(int j=0;j<25;j++)
            {
                colors[i][j]="lightGray";
            }
        }
        update();
        this->ui->label_start->setText(this->ui->btn_lanzhou->text());
        this->shortes->starcity="hechuan";
        this->ui->label_over->setText(""); this->ui->label_display->setText("");
    }
    else{
        this->ui->label_over->setText(this->ui->btn_lanzhou->text());
        this->shortes->overcity="hechuan";
        if(c==0)
        {
            shortes->StortPath(shortes->G,this->shortes->starcity,shortes->G.city,shortes->P,this->distance);
            int t=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]=="hechuan")
                {
                    t=i;
                    display= "两地最短距离为"+QString::number(distance[i],10)+"km";
                }
            }
            for (int n = 0; n < 25; n++)
            {
                for (int m = 0; m < 25; m++)
                {
                    for (int j = 0; j < 25; j++)
                    {
                        if (shortes->P[t][j])
                        {
                            if (j == n)
                                for (int w = 0; w < 25; w++)
                                {
                                    if (shortes->P[t][w])
                                    {
                                        if (w == m)  colors[n][m] = "red";
                                    }
                                }
                        }
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        else if(c==1)
        {
            int m=0,n=0;
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->starcity)  m=i;
            }
            for(int i=0;i<25;i++)
            {
                if(shortes->G.city[i]==this->shortes->overcity)  n=i;
            }
            display="两地最短距离为"+QString::number(distance1[m][n],10)+"km";
            for(int i=0;i<25;i++)
            {
                for(int j=0;j<25;j++)
                {
                    if(this->shortes->P1[m][i][j])
                    {
                        for(int h=0;h<25;h++)
                        {
                            if(this->shortes->P1[m][i][h])
                                colors[j][h] = "red";
                        }
                    }
                }
                sleep(100);
                update();
            }
            for(int i=0;i<25;i++)
            {
                if(this->shortes->P1[m][n][i])
                {
                    for(int j=0;j<25;j++)
                    {
                        if(this->shortes->P1[m][n][j])
                            colors[i][j]= "blue";
                    }
                }
            }
            update();
            this->ui->label_display->setText(display);
        }
        this->shortes->starcity="";
        this->shortes->overcity="";
    }
}

void MainWindow::on_btn_djstl_clicked()
{

    this->c=0;
    this->ui->btn_djstl->setStyleSheet("color: rgb(85, 170, 255);""background-color: rgb(189, 240, 255);");
    this->ui->btn_flyd->setStyleSheet("color: rgb(85, 170, 255);");
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            colors[i][j]="lightGray";
        }
    }
    this->ui->label_start->setText("");
    this->ui->label_over->setText("");
    this->ui->label_display->setText("");
    this->shortes->starcity="";
    this->shortes->overcity="";
    update();
}

void MainWindow::on_btn_flyd_clicked()
{
    this->c=1;
    this->ui->btn_flyd->setStyleSheet("color: rgb(85, 170, 255);""background-color: rgb(189, 240, 255);");
    this->ui->btn_djstl->setStyleSheet("color: rgb(85, 170, 255);");
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            colors[i][j]="lightGray";
        }
    }
    this->ui->label_start->setText("");
    this->ui->label_over->setText("");
    this->ui->label_display->setText("");
    this->shortes->starcity="";
    this->shortes->overcity="";
    update();
}

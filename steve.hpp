#ifndef steve_hpp
#define steve_hpp
#include<QWidget>
#include<QtGui>
#include<QImage>
#include<QRect>
#include<QSlider>
#include<cmath>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>
#include<QCheckBox>
#include<QRadioButton>
#include<QGridLayout>
#include<stack>
#include<QPushButton>
#include<unistd.h>
#include<QTimer>

class GlowneOkno : public QWidget{
	Q_OBJECT
public:
	GlowneOkno();
private:
	QTimer *t1,*t2;
	QPushButton *b1, *b2, *b3;
	QHBoxLayout *lH1,*lH2,*lH3;
	QGridLayout *lG1;
	QGroupBox *box1,*box2,*box3,*box4,*box5,*box6,*box7,*box8;
	QCheckBox *ch1,*ch2,*ch3,*ch4,*ch5,*ch6;
	QRadioButton *r1,*r2;
	double v,w,u,u2,v2,w2,x,y;
	int *wynik1 = new int[2];
	int *wynik2 = new int[2];
	double *vwu = new double[3];
	double *vwu2 = new double[3];
	int *punkt1 =new int[2];
	int *punkt2 =new int[2];
	int *punkt3 =new int[2];
	int *punkt4 =new int[2];
	int *punkt5 =new int[2];
	int *punkt6 =new int[2];
	int *punkt7 =new int[2];
	int *punkt8 =new int[2];
	int *p1 =new int[3];
	int *p2 =new int[3];
	int *p3 =new int[3];
	int *p4 =new int[3];
	int *p5 =new int[3];
	int *p6 =new int[3];
	int *p7 =new int[3];
	int *p8 =new int[3];
	int *rgb = new int[3];
	double a[2],b[2],c[2];
	QSlider *s,*s3;
	void rysujOdcinek(int,int,int,int,int,int,int);
	void rysujOdcinek3D_PRO(int*,int*,int,int,int);
	int szer,wys;
	QImage *img, *logo, *head1, *head2, *head3,*head4,*head5,*torso1,*torso2,*torso3,*torso4,*arm1,*arm2,*leg1,*leg2,*leg3,*leg4;
	unsigned char *ptr, *plogo, *phead1, *phead2, *phead3,*phead4,*phead5,*ptorso1,*ptorso2,*ptorso3,*ptorso4,*parm1,*parm2,*pleg1,*pleg2,*pleg3,*pleg4;
	void paintEvent(QPaintEvent*);
	void rysujKrawedzie(int*,int*,int*,int*,int*,int*,int*,int*);
	void rysujPiksel(int,int,int,int,int); 
	int* point3Dto2D(int,int,int);
	int* getKolor(int,int,unsigned char*,int);
	int* obrocOY(double,double,double,double);
	void czysc();
	int j,p1x,p1y,p1z,p2x,p2y,p2z,maxZ,id;
	double X,Y,alpha,move;
	double* obliczBarametryczne(int,int,int[2],int[2],int[2]);
    	bool wTrojkacie(double,double,double);
	void drawHead();
	void drawTorso();
	void drawLhand();
	void drawRhand();
	void drawLleg();
	void drawRleg();
	void naklejTrojkat(unsigned char*,int,int,int[2],int[2],int[2],int*,int*,int*);
	void floodFill(int,int,int,int,int,int,int,int);
	bool sprawdzKolor(int,int,int,int,int);
	void mousePressEvent(QMouseEvent *event);
	bool stan1, stan2;
private slots:
	void drawBody();
	void rotationSimulator();
	void motionSimulator();
};
#endif


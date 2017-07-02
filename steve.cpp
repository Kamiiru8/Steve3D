#include "steve.hpp"
#include "body.hpp"
#include "textures/triangles.hpp"

GlowneOkno::GlowneOkno(){
	this->setGeometry(0,0,1030,800);
	img = new QImage(800,800,QImage::Format_RGB32);
	ptr = img->bits();  
    	szer = img->width();
    	wys = img->height();

	logo = new QImage(":/textures/logo.png");
	head1 = new QImage(":/textures/head1.png");
	phead1 = head1->bits();
	head2 = new QImage(":/textures/head2.png");
	phead2 = head2->bits();
	head3 = new QImage(":/textures/head3.png");
	phead3 = head3->bits();
	head4 = new QImage(":/textures/head4.png");
	phead4 = head4->bits();
	head5 = new QImage(":/textures/head5.png");
	phead5 = head5->bits();
	torso1 = new QImage(":/textures/torso1.png");
	ptorso1 = torso1->bits();
	torso2 = new QImage(":/textures/torso2.png");
	ptorso2 = torso2->bits();
	torso3 = new QImage(":/textures/torso3.png");
	ptorso3 = torso3->bits();
	torso4 = new QImage(":/textures/torso4.png");
	ptorso4 = torso4->bits();
	arm1 = new QImage(":/textures/arm1.png");
	parm1 = arm1->bits();
	arm2 = new QImage(":/textures/arm2.png");
	parm2 = arm2->bits();
	leg1 = new QImage(":/textures/leg1.png");
	pleg1 = leg1->bits();
	leg2 = new QImage(":/textures/leg2.png");
	pleg2 = leg2->bits();
	leg3 = new QImage(":/textures/leg3.png");
	pleg3 = leg3->bits();
	leg4 = new QImage(":/textures/leg4.png");
	pleg4 = leg4->bits();


	box1 = new QGroupBox("           TEXTURES",this); 
      box1->setGeometry(800,200,230,33); 
	box1->setStyleSheet("border-radius:4px;background:white;margin:10px;margin-top:0px;margin-bottom:0px;font-weight:bold;font-size: 18px;");
	box2 = new QGroupBox(this); 
      box2->setGeometry(800,229,230,160); 
      box2->setStyleSheet("border-radius:4px;background:white;margin:10px;");
	ch1 = new QCheckBox("Head",this); ch1->setChecked(true); connect(ch1, SIGNAL(stateChanged(int)), this, SLOT(drawBody()) );
	ch2 = new QCheckBox("Torso",this); ch2->setChecked(true); connect(ch2, SIGNAL(stateChanged(int)), this, SLOT(drawBody()) );
	ch3 = new QCheckBox("L Hand",this); ch3->setChecked(true); connect(ch3, SIGNAL(stateChanged(int)), this, SLOT(drawBody()) );
	ch4 = new QCheckBox("R Hand",this); ch4->setChecked(true); connect(ch4, SIGNAL(stateChanged(int)), this, SLOT(drawBody()) );
	ch5 = new QCheckBox("L Leg",this); ch5->setChecked(true); connect(ch5, SIGNAL(stateChanged(int)), this, SLOT(drawBody()) );
	ch6 = new QCheckBox("R Leg",this); ch6->setChecked(true); connect(ch6, SIGNAL(stateChanged(int)), this, SLOT(drawBody()) );
	lG1 = new QGridLayout();
	lG1->addWidget(ch1,0,0);
	lG1->addWidget(ch2,0,1);
	lG1->addWidget(ch3,1,0);
	lG1->addWidget(ch4,1,1);
	lG1->addWidget(ch5,2,0);
	lG1->addWidget(ch6,2,1);
    	box2->setLayout(lG1);

	box3 = new QGroupBox("        SHOW EDGES",this);
	box3->setGeometry(800,390,230,33); 
	box3->setStyleSheet("border-radius:4px;background:white;margin:10px;margin-top:0px;margin-bottom:0px;font-weight:bold;font-size: 18px;");
	box4 = new QGroupBox(this); 
      box4->setGeometry(800,419,230,70); 
      box4->setStyleSheet("border-radius:4px;background:white;margin:10px;");
	r1 = new QRadioButton("On",this); r1->setChecked(false); r2 = new QRadioButton("Off",this); r2->setChecked(true); 
	connect(r1, SIGNAL(toggled(bool)), this, SLOT(drawBody()) ); connect(r2, SIGNAL(toggled(bool)), this, SLOT(drawBody()) );
	lH1 = new QHBoxLayout();
	lH1->addWidget(r1);
	lH1->addWidget(r2);
    	box4->setLayout(lH1);

	box5 = new QGroupBox("           ROTATION",this);
	box5->setGeometry(800,491,230,33); 
	box5->setStyleSheet("border-radius:4px;background:white;margin:10px;margin-top:0px;margin-bottom:0px;font-weight:bold;font-size: 18px;");
	box6 = new QGroupBox(this);
	box6->setGeometry(800,519,230,63); 
	box6->setStyleSheet("border-radius:4px;background:white;margin:10px;");
	s = new QSlider(Qt::Horizontal,this);
	connect(s, SIGNAL( valueChanged(int) ), this, SLOT(drawBody()) );  	
	s->setMaximum(315);
	s->setValue(0);
	lH2 = new QHBoxLayout();
	lH2->addWidget(s);
    	box6->setLayout(lH2);
	b1 = new QPushButton("Rotation Simulator",this);
	b1->setGeometry(810,576,210,35);
	b1->setCheckable(true);
	connect(b1, SIGNAL(clicked()), this, SLOT(rotationSimulator()) );

	box7 = new QGroupBox("          MOVEMENT",this);
	box7->setGeometry(800,622,230,33); 
	box7->setStyleSheet("border-radius:4px;background:white;margin:10px;margin-top:0px;margin-bottom:0px;font-weight:bold;font-size: 18px;");
	box8 = new QGroupBox(this);
	box8->setGeometry(800,650,230,60); 
	box8->setStyleSheet("border-radius:4px;background:white;margin:10px;");
	s3 = new QSlider(Qt::Horizontal,this);
	connect(s3, SIGNAL( valueChanged(int) ), this, SLOT(drawBody()) ); 	
	s3->setMaximum(100); 	
	s3->setValue(50);
	lH3 = new QHBoxLayout();
	lH3->addWidget(s3);
    	box8->setLayout(lH3);

	b2 = new QPushButton("Motion Simulator",this);
	b2->setGeometry(810,705,210,35);
	b2->setCheckable(true);
	connect(b2, SIGNAL(clicked()), this, SLOT(motionSimulator()) ); 

	b3 = new QPushButton("EXIT",this);
	b3->setGeometry(810,755,210,35);
	b3->setStyleSheet("font-weight:bold; font-size: 18px;");
	connect(b3,SIGNAL(clicked()),qApp,SLOT(quit()));	

	rysujOdcinek(-szer/2,wys/2,szer/2,wys/2,255,255,255);
    	rysujOdcinek(-szer/2,-wys/2,szer/2,-wys/2,255,255,255);

	t1 = new QTimer;
	connect(t1, SIGNAL(timeout()), this, SLOT(rotationSimulator()));
	stan1 = true;
	
	t2 = new QTimer;
	connect(t2, SIGNAL(timeout()), this, SLOT(motionSimulator()));
	stan2 = true;
}

void GlowneOkno::rotationSimulator(){
	t1->start(1);
	if(b1->isChecked()){
		if(stan1) s->setValue(s->value()+10);
		else s->setValue(s->value()-10);
		if(s->sliderPosition()==315) stan1=false;
		if(s->sliderPosition()==0) stan1=true;
	}	
}

void GlowneOkno::motionSimulator(){
	t2->start(1);
	if(b2->isChecked()){
		if(stan2) s3->setValue(s3->value()+10);
		else s3->setValue(s3->value()-10);
		if(s3->sliderPosition()==100) stan2=false;
		if(s3->sliderPosition()==0) stan2=true;
	}	
}

void GlowneOkno::drawBody(){
	double a = (double)s->sliderPosition();
	czysc();
	if(a<60){
		drawLleg();
		drawRleg();
		drawLhand();
		drawTorso();
		drawRhand();
		drawHead();
	}else{
		drawRleg();
		drawLleg();
		drawRhand();
		drawTorso();
		drawLhand();
		drawHead();
	}
}

void GlowneOkno::paintEvent(QPaintEvent *e) {
	QRect prostokat(0,0,800,800);
	QRect prostokat2(810,0,215,200);
	QPainter rysuj(this);
	rysuj.drawImage(prostokat,*img);  
	rysuj.drawImage(prostokat2,*logo);  
}

void GlowneOkno::rysujPiksel(int x,int y,int r,int g,int b){
	ptr[szer*4*y+4*x  ] = b;
	ptr[szer*4*y+4*x+1] = g;
	ptr[szer*4*y+4*x+2] = r;
	update();
}

int* GlowneOkno::point3Dto2D(int x,int y,int z){
	int *wynik = new int[2];
	alpha=sqrt(((double)z*(double)z)/2);	
	if(z>=0){
		X=(double)x-alpha+szer/2;
		Y=-(double)y+alpha+wys/2;
	}
	if(z<0){
		X=(double)x+alpha+szer/2;
		Y=-(double)y-alpha+wys/2;
	}
	wynik[0]=X; wynik[1]=Y;
	return wynik;
	delete[] wynik;
	wynik = 0;
}


void GlowneOkno::rysujOdcinek(int p1x,int p1y,int p2x,int p2y,int r,int g,int be){
    		
        double a  = ((double)p2y-(double)p1y)/((double)p2x-(double)p1x); 
        double b  = (double)p1y-a*(double)p1x;
	  double x1 = std::min(p1x,p2x);
	  double x2 = std::max(p1x,p2x);
	  double y1 = std::min(p1y,p2y);
	  double y2 = std::max(p1y,p2y);

          if(a>-1 && a<1){
              for(int i=x1; i<x2; i++){
                  j=a*i+b;
	          	rysujPiksel(i+400,j+400,r,g,be);
              }
          }
          else{
            a = ((double)p2x-(double)p1x)/((double)p2y-(double)p1y); 
     	      b = (double)p1x-a*(double)p1y;
     	      x1=y1; 
     	      x2=y2;
     	      
              for(int i=x1; i<x2; i++){
                  j=a*i+b;
	            rysujPiksel(j+400,i+400,r,g,be);
              }
          }  
}

void GlowneOkno::rysujOdcinek3D_PRO(int* p1,int* p2,int r,int g,int be){	  

	  p1x=p1[0]; p1y=p1[1]; p1z=p1[2];	
	  p2x=p2[0]; p2y=p2[1]; p2z=p2[2];	
	
	  wynik1=point3Dto2D(p1x,p1y,p1z);
	  p1x=wynik1[0];
	  p1y=wynik1[1];
	
	  wynik2=point3Dto2D(p2x,p2y,p2z);
	  p2x=wynik2[0];
	  p2y=wynik2[1];
		

        double a  = ((double)p2y-(double)p1y)/((double)p2x-(double)p1x); 
        double b  = (double)p1y-a*(double)p1x;
	  double x1 = std::min(p1x,p2x);
	  double x2 = std::max(p1x,p2x);
	  double y1 = std::min(p1y,p2y);
	  double y2 = std::max(p1y,p2y);

          if(a>-1 && a<1){
              for(int i=x1; i<x2; i++){
                  j=a*i+b;
	          	rysujPiksel(i,j,r,g,be);
              }
          }
          else{
            a = ((double)p2x-(double)p1x)/((double)p2y-(double)p1y); 
     	      b = (double)p1x-a*(double)p1y;
     	      x1=y1; 
     	      x2=y2;
     	      
              for(int i=x1; i<x2; i++){
                  j=a*i+b;
	            rysujPiksel(j,i,r,g,be);
              }
          }  
}

void GlowneOkno::drawHead(){
	double a = (double)s->sliderPosition()/100;
	 
	p1=obrocOY(head.p1[0],head.p1[1],head.p1[2],a);
	p2=obrocOY(head.p2[0],head.p2[1],head.p2[2],a);
	p3=obrocOY(head.p3[0],head.p3[1],head.p3[2],a);
	p4=obrocOY(head.p4[0],head.p4[1],head.p4[2],a);
	p5=obrocOY(head.p5[0],head.p5[1],head.p5[2],a);
	p6=obrocOY(head.p6[0],head.p6[1],head.p6[2],a);
	p7=obrocOY(head.p7[0],head.p7[1],head.p7[2],a);
	p8=obrocOY(head.p8[0],head.p8[1],head.p8[2],a);

	punkt1=point3Dto2D(p1[0],p1[1],p1[2]);
	punkt2=point3Dto2D(p2[0],p2[1],p2[2]);
	punkt3=point3Dto2D(p3[0],p3[1],p3[2]);
	punkt4=point3Dto2D(p4[0],p4[1],p4[2]);
	punkt5=point3Dto2D(p5[0],p5[1],p5[2]);
	punkt6=point3Dto2D(p6[0],p6[1],p6[2]);
	punkt7=point3Dto2D(p7[0],p7[1],p7[2]);
	punkt8=point3Dto2D(p8[0],p8[1],p8[2]);

	for (int i=0; i<8; i++){
		maxZ=(p1[2]+p2[2])/2; id=1;
		if( (p1[2]+p2[2])/2 > maxZ-12){id=1; maxZ=(p1[2]+p2[2])/2;}
		if( (p2[2]+p6[2])/2 > maxZ-12){id=2; maxZ=(p2[2]+p6[2])/2;}
		if( (p5[2]+p6[2])/2 > maxZ-12){id=3; maxZ=(p5[2]+p6[2])/2;}
		if( (p1[2]+p5[2])/2 > maxZ-12){id=4; maxZ=(p1[2]+p5[2])/2;}
	}
	
	if(ch1->isChecked()){
		switch(id){
			case 1:{
				naklejTrojkat(phead1,180,180,tex1.p1,tex1.p2,tex1.p3,punkt1,punkt2,punkt3);//przod
				naklejTrojkat(phead1,180,180,tex1.p1,tex1.p4,tex1.p3,punkt1,punkt4,punkt3);
				naklejTrojkat(phead3,180,180,tex1.p1,tex1.p2,tex1.p3,punkt2,punkt6,punkt7); //prawa
				naklejTrojkat(phead3,180,180,tex1.p1,tex1.p4,tex1.p3,punkt2,punkt3,punkt7);}break;
	    		case 2:{
				naklejTrojkat(phead3,180,180,tex1.p1,tex1.p2,tex1.p3,punkt2,punkt6,punkt7); //prawa
				naklejTrojkat(phead3,180,180,tex1.p1,tex1.p4,tex1.p3,punkt2,punkt3,punkt7);}break;
			case 3:{
				naklejTrojkat(phead5,180,180,tex1.p1,tex1.p2,tex1.p3,punkt5,punkt6,punkt7); //tyl
				naklejTrojkat(phead5,180,180,tex1.p1,tex1.p4,tex1.p3,punkt5,punkt8,punkt7);
				naklejTrojkat(phead4,180,180,tex1.p1,tex1.p2,tex1.p3,punkt5,punkt1,punkt4);//lewa
				naklejTrojkat(phead4,180,180,tex1.p1,tex1.p4,tex1.p3,punkt5,punkt8,punkt4);}break;
			case 4:{
				naklejTrojkat(phead5,180,180,tex1.p1,tex1.p2,tex1.p3,punkt5,punkt6,punkt7); //tyl
				naklejTrojkat(phead5,180,180,tex1.p1,tex1.p4,tex1.p3,punkt5,punkt8,punkt7);
				naklejTrojkat(phead1,180,180,tex1.p1,tex1.p2,tex1.p3,punkt1,punkt2,punkt3);//przod
				naklejTrojkat(phead1,180,180,tex1.p1,tex1.p4,tex1.p3,punkt1,punkt4,punkt3);
				naklejTrojkat(phead4,180,180,tex1.p1,tex1.p2,tex1.p3,punkt5,punkt1,punkt4);//lewa
				naklejTrojkat(phead4,180,180,tex1.p1,tex1.p4,tex1.p3,punkt5,punkt8,punkt4);}break;
		}
				naklejTrojkat(phead2,180,180,tex1.p1,tex1.p2,tex1.p3,punkt5,punkt6,punkt2);//gora
				naklejTrojkat(phead2,180,180,tex1.p1,tex1.p4,tex1.p3,punkt5,punkt1,punkt2);//gora
	}

	if(r1->isChecked() && ch1->isChecked()==false){
		rysujKrawedzie(p1,p2,p3,p4,p5,p6,p7,p8);
	}
}

void GlowneOkno::drawTorso(){
	double a = (double)s->sliderPosition()/100;

	p1=obrocOY(torso.p1[0],torso.p1[1],torso.p1[2],a);
	p2=obrocOY(torso.p2[0],torso.p2[1],torso.p2[2],a);
	p3=obrocOY(torso.p3[0],torso.p3[1],torso.p3[2],a);
	p4=obrocOY(torso.p4[0],torso.p4[1],torso.p4[2],a);
	p5=obrocOY(torso.p5[0],torso.p5[1],torso.p5[2],a);
	p6=obrocOY(torso.p6[0],torso.p6[1],torso.p6[2],a);
	p7=obrocOY(torso.p7[0],torso.p7[1],torso.p7[2],a);
	p8=obrocOY(torso.p8[0],torso.p8[1],torso.p8[2],a);

	punkt1=point3Dto2D(p1[0],p1[1],p1[2]);
	punkt2=point3Dto2D(p2[0],p2[1],p2[2]);
	punkt3=point3Dto2D(p3[0],p3[1],p3[2]);
	punkt4=point3Dto2D(p4[0],p4[1],p4[2]);
	punkt5=point3Dto2D(p5[0],p5[1],p5[2]);
	punkt6=point3Dto2D(p6[0],p6[1],p6[2]);
	punkt7=point3Dto2D(p7[0],p7[1],p7[2]);
	punkt8=point3Dto2D(p8[0],p8[1],p8[2]);

	for (int i=0; i<8; i++){
		maxZ=(p1[2]+p2[2])/2; id=1;
		if( (p1[2]+p2[2])/2 > maxZ+2){id=1; maxZ=(p1[2]+p2[2])/2;}
		if( (p2[2]+p6[2])/2 > maxZ+2){id=2; maxZ=(p2[2]+p6[2])/2;}
		if( (p5[2]+p6[2])/2 > maxZ+2){id=3; maxZ=(p5[2]+p6[2])/2;}
		if( (p1[2]+p5[2])/2 > maxZ+2){id=4; maxZ=(p1[2]+p5[2])/2;}
	}

	if(ch2->isChecked()){
			switch(id){
			case 1:{
				naklejTrojkat(ptorso1,265,380,tex2.p1,tex2.p2,tex2.p3,punkt1,punkt2,punkt3);//przod
				naklejTrojkat(ptorso1,265,380,tex2.p1,tex2.p4,tex2.p3,punkt1,punkt4,punkt3);
				naklejTrojkat(ptorso2,125,380,tex5.p1,tex5.p2,tex5.p3,punkt2,punkt6,punkt7);//prawa
				naklejTrojkat(ptorso2,125,380,tex5.p1,tex5.p4,tex5.p3,punkt2,punkt3,punkt7);}break;
	    		case 2:{
				naklejTrojkat(ptorso2,125,380,tex5.p1,tex5.p2,tex5.p3,punkt2,punkt6,punkt7);//prawa
				naklejTrojkat(ptorso2,125,380,tex5.p1,tex5.p4,tex5.p3,punkt2,punkt3,punkt7);}break;
			case 3:{
				naklejTrojkat(ptorso4,265,380,tex2.p1,tex2.p2,tex2.p3,punkt5,punkt6,punkt7);//tyl
				naklejTrojkat(ptorso4,265,380,tex2.p1,tex2.p4,tex2.p3,punkt5,punkt8,punkt7);
				naklejTrojkat(ptorso3,125,380,tex5.p1,tex5.p2,tex5.p3,punkt5,punkt1,punkt4);//lewa
				naklejTrojkat(ptorso3,125,380,tex5.p1,tex5.p4,tex5.p3,punkt5,punkt8,punkt4);}break;
			case 4:{
				naklejTrojkat(ptorso4,265,380,tex2.p1,tex2.p2,tex2.p3,punkt5,punkt6,punkt7);//tyl
				naklejTrojkat(ptorso4,265,380,tex2.p1,tex2.p4,tex2.p3,punkt5,punkt8,punkt7);
				naklejTrojkat(ptorso1,265,380,tex2.p1,tex2.p2,tex2.p3,punkt1,punkt2,punkt3);//przod
				naklejTrojkat(ptorso1,265,380,tex2.p1,tex2.p4,tex2.p3,punkt1,punkt4,punkt3);
				naklejTrojkat(ptorso3,125,380,tex5.p1,tex5.p2,tex5.p3,punkt5,punkt1,punkt4);//lewa
				naklejTrojkat(ptorso3,125,380,tex5.p1,tex5.p4,tex5.p3,punkt5,punkt8,punkt4);}break;
			}
	}
	
	if(r1->isChecked() && ch2->isChecked()==false){
		rysujKrawedzie(p1,p2,p3,p4,p5,p6,p7,p8);
	}
}

void GlowneOkno::drawLhand(){
	double a = (double)s->sliderPosition()/100;
	move = (double)s3->sliderPosition()-50;

	p1=obrocOY(lhand.p1[0],lhand.p1[1],lhand.p1[2],a);
	p2=obrocOY(lhand.p2[0],lhand.p2[1],lhand.p2[2],a);
	p3=obrocOY(lhand.p3[0],lhand.p3[1],lhand.p3[2]+move,a);
	p4=obrocOY(lhand.p4[0],lhand.p4[1],lhand.p4[2]+move,a);
	p5=obrocOY(lhand.p5[0],lhand.p5[1],lhand.p5[2],a);
	p6=obrocOY(lhand.p6[0],lhand.p6[1],lhand.p6[2],a);
	p7=obrocOY(lhand.p7[0],lhand.p7[1],lhand.p7[2]+move,a);
	p8=obrocOY(lhand.p8[0],lhand.p8[1],lhand.p8[2]+move,a);

	punkt1=point3Dto2D(p1[0],p1[1],p1[2]);
	punkt2=point3Dto2D(p2[0],p2[1],p2[2]);
	punkt3=point3Dto2D(p3[0],p3[1],p3[2]);
	punkt4=point3Dto2D(p4[0],p4[1],p4[2]);
	punkt5=point3Dto2D(p5[0],p5[1],p5[2]);
	punkt6=point3Dto2D(p6[0],p6[1],p6[2]);
	punkt7=point3Dto2D(p7[0],p7[1],p7[2]);
	punkt8=point3Dto2D(p8[0],p8[1],p8[2]); 

	for (int i=0; i<8; i++){
		maxZ=(p1[2]+p2[2])/2; id=1;
		if( (p1[2]+p2[2])/2 > maxZ-13){id=1; maxZ=(p1[2]+p2[2])/2;}
		if( (p2[2]+p6[2])/2 > maxZ-13){id=2; maxZ=(p2[2]+p6[2])/2;}
		if( (p5[2]+p6[2])/2 > maxZ-13){id=3; maxZ=(p5[2]+p6[2])/2;}
		if( (p1[2]+p5[2])/2 > maxZ-13){id=4; maxZ=(p1[2]+p5[2])/2;}
	}
	
	if(ch3->isChecked()){

		switch(id){
		case 1:{
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt1,punkt2,punkt3);//przod
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt1,punkt4,punkt3);
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt2,punkt6,punkt7);//prawa
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt2,punkt3,punkt7);}break;
    		case 2:{
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt2,punkt6,punkt7);//prawa
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt2,punkt3,punkt7);}break;
		case 3:{
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt5,punkt6,punkt7);//tyl
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt5,punkt8,punkt7);
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt5,punkt1,punkt4);//lewa
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt5,punkt8,punkt4);}break;
		case 4:{
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt5,punkt6,punkt7);//tyl
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt5,punkt8,punkt7);
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt1,punkt2,punkt3);//przod
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt1,punkt4,punkt3);
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt5,punkt1,punkt4);//lewa
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt5,punkt8,punkt4);}break;
		}
			naklejTrojkat(parm2,135,125,tex4.p1,tex4.p2,tex4.p3,punkt5,punkt6,punkt2);//gora
			naklejTrojkat(parm2,135,125,tex4.p1,tex4.p4,tex4.p3,punkt5,punkt1,punkt2);//gora
	}	

	if(r1->isChecked() && ch3->isChecked()==false){
		rysujKrawedzie(p1,p2,p3,p4,p5,p6,p7,p8);
	}
}

void GlowneOkno::drawRhand(){
	double a = (double)s->sliderPosition()/100;
	move = (double)s3->sliderPosition()-50;

	p1=obrocOY(rhand.p1[0],rhand.p1[1],rhand.p1[2],a);
	p2=obrocOY(rhand.p2[0],rhand.p2[1],rhand.p2[2],a);
	p3=obrocOY(rhand.p3[0],rhand.p3[1],rhand.p3[2]-move,a);
	p4=obrocOY(rhand.p4[0],rhand.p4[1],rhand.p4[2]-move,a);
	p5=obrocOY(rhand.p5[0],rhand.p5[1],rhand.p5[2],a);
	p6=obrocOY(rhand.p6[0],rhand.p6[1],rhand.p6[2],a);
	p7=obrocOY(rhand.p7[0],rhand.p7[1],rhand.p7[2]-move,a);
	p8=obrocOY(rhand.p8[0],rhand.p8[1],rhand.p8[2]-move,a);

	punkt1=point3Dto2D(p1[0],p1[1],p1[2]);
	punkt2=point3Dto2D(p2[0],p2[1],p2[2]);
	punkt3=point3Dto2D(p3[0],p3[1],p3[2]);
	punkt4=point3Dto2D(p4[0],p4[1],p4[2]);
	punkt5=point3Dto2D(p5[0],p5[1],p5[2]);
	punkt6=point3Dto2D(p6[0],p6[1],p6[2]);
	punkt7=point3Dto2D(p7[0],p7[1],p7[2]);
	punkt8=point3Dto2D(p8[0],p8[1],p8[2]);

	for (int i=0; i<8; i++){
		maxZ=(p1[2]+p2[2])/2; id=1;
		if( (p1[2]+p2[2])/2 > maxZ-13){id=1; maxZ=(p1[2]+p2[2])/2;}
		if( (p2[2]+p6[2])/2 > maxZ-13){id=2; maxZ=(p2[2]+p6[2])/2;}
		if( (p5[2]+p6[2])/2 > maxZ-13){id=3; maxZ=(p5[2]+p6[2])/2;}
		if( (p1[2]+p5[2])/2 > maxZ-13){id=4; maxZ=(p1[2]+p5[2])/2;}
	}

	if(ch4->isChecked()){
		switch(id){
		case 1:{
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt1,punkt2,punkt3);//przod
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt1,punkt4,punkt3);
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt2,punkt6,punkt7);//prawa
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt2,punkt3,punkt7);}break;
    		case 2:{
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt2,punkt6,punkt7);//prawa
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt2,punkt3,punkt7);}break;
		case 3:{
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt5,punkt6,punkt7);//tyl
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt5,punkt8,punkt7);
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt5,punkt1,punkt4);//lewa
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt5,punkt8,punkt4);}break;
		case 4:{
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt5,punkt6,punkt7);//tyl
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt5,punkt8,punkt7);
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt1,punkt2,punkt3);//przod
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt1,punkt4,punkt3);
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt5,punkt1,punkt4);//lewa
			naklejTrojkat(parm1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt5,punkt8,punkt4);}break;
	}
			naklejTrojkat(parm2,135,125,tex4.p1,tex4.p2,tex4.p3,punkt5,punkt6,punkt2);//gora
			naklejTrojkat(parm2,135,125,tex4.p1,tex4.p4,tex4.p3,punkt5,punkt1,punkt2);//gora
	}

	if(r1->isChecked() && ch4->isChecked()==false){
		rysujKrawedzie(p1,p2,p3,p4,p5,p6,p7,p8);
	}
}

void GlowneOkno::drawLleg(){
	double a = (double)s->sliderPosition()/100;
	move = (double)s3->sliderPosition()-50;
	
	p1=obrocOY(lleg.p1[0],lleg.p1[1],lleg.p1[2],a);
	p2=obrocOY(lleg.p2[0],lleg.p2[1],lleg.p2[2],a);
	p3=obrocOY(lleg.p3[0],lleg.p3[1],lleg.p3[2]-move,a);
	p4=obrocOY(lleg.p4[0],lleg.p4[1],lleg.p4[2]-move,a);
	p5=obrocOY(lleg.p5[0],lleg.p5[1],lleg.p5[2],a);
	p6=obrocOY(lleg.p6[0],lleg.p6[1],lleg.p6[2],a);
	p7=obrocOY(lleg.p7[0],lleg.p7[1],lleg.p7[2]-move,a);
	p8=obrocOY(lleg.p8[0],lleg.p8[1],lleg.p8[2]-move,a);

	punkt1=point3Dto2D(p1[0],p1[1],p1[2]);
	punkt2=point3Dto2D(p2[0],p2[1],p2[2]);
	punkt3=point3Dto2D(p3[0],p3[1],p3[2]);
	punkt4=point3Dto2D(p4[0],p4[1],p4[2]);
	punkt5=point3Dto2D(p5[0],p5[1],p5[2]);
	punkt6=point3Dto2D(p6[0],p6[1],p6[2]);
	punkt7=point3Dto2D(p7[0],p7[1],p7[2]);
	punkt8=point3Dto2D(p8[0],p8[1],p8[2]);

	if(ch5->isChecked()){

	for (int i=0; i<8; i++){
		maxZ=(p1[2]+p2[2])/2; id=1;
		if( (p1[2]+p2[2])/2 > maxZ-10){id=1; maxZ=(p1[2]+p2[2])/2;}
		if( (p2[2]+p6[2])/2 > maxZ-10){id=2; maxZ=(p2[2]+p6[2])/2;}
		if( (p5[2]+p6[2])/2 > maxZ-10){id=3; maxZ=(p5[2]+p6[2])/2;}
		if( (p1[2]+p5[2])/2 > maxZ-10){id=4; maxZ=(p1[2]+p5[2])/2;}
	}

	switch(id){
		case 1:{
			naklejTrojkat(pleg1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt1,punkt2,punkt3);//przod
			naklejTrojkat(pleg1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt1,punkt4,punkt3);
			naklejTrojkat(pleg2,125,380,tex3.p1,tex5.p2,tex5.p3,punkt2,punkt6,punkt7);//prawa
			naklejTrojkat(pleg2,125,380,tex3.p1,tex5.p4,tex5.p3,punkt2,punkt3,punkt7);}break;
    		case 2:{
			naklejTrojkat(pleg2,125,380,tex3.p1,tex5.p2,tex5.p3,punkt2,punkt6,punkt7);//prawa
			naklejTrojkat(pleg2,125,380,tex3.p1,tex5.p4,tex5.p3,punkt2,punkt3,punkt7);}break;
		case 3:{
			naklejTrojkat(pleg4,135,380,tex5.p1,tex5.p2,tex5.p3,punkt5,punkt6,punkt7);//tyl
			naklejTrojkat(pleg4,135,380,tex5.p1,tex5.p4,tex5.p3,punkt5,punkt8,punkt7);
			naklejTrojkat(pleg3,125,380,tex5.p1,tex5.p2,tex5.p3,punkt5,punkt1,punkt4);//lewa
			naklejTrojkat(pleg3,125,380,tex5.p1,tex5.p4,tex5.p3,punkt5,punkt8,punkt4);}break;
		case 4:{
			naklejTrojkat(pleg4,135,380,tex5.p1,tex5.p2,tex5.p3,punkt5,punkt6,punkt7);//tyl
			naklejTrojkat(pleg4,135,380,tex5.p1,tex5.p4,tex5.p3,punkt5,punkt8,punkt7);
			naklejTrojkat(pleg1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt1,punkt2,punkt3);//przod
			naklejTrojkat(pleg1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt1,punkt4,punkt3);
			naklejTrojkat(pleg3,125,380,tex5.p1,tex5.p2,tex5.p3,punkt5,punkt1,punkt4);//lewa
			naklejTrojkat(pleg3,125,380,tex5.p1,tex5.p4,tex5.p3,punkt5,punkt8,punkt4);}break;
		}
	}

	if(r1->isChecked() && ch5->isChecked()==false){
		rysujKrawedzie(p1,p2,p3,p4,p5,p6,p7,p8);
	}	
}

void GlowneOkno::drawRleg(){
	double a = (double)s->sliderPosition()/100;
	move = (double)s3->sliderPosition()-50;
	
	p1=obrocOY(rleg.p1[0],lleg.p1[1],rleg.p1[2],a);
	p2=obrocOY(rleg.p2[0],lleg.p2[1],rleg.p2[2],a);
	p3=obrocOY(rleg.p3[0],lleg.p3[1],rleg.p3[2]+move,a);
	p4=obrocOY(rleg.p4[0],lleg.p4[1],rleg.p4[2]+move,a);
	p5=obrocOY(rleg.p5[0],lleg.p5[1],rleg.p5[2],a);
	p6=obrocOY(rleg.p6[0],lleg.p6[1],rleg.p6[2],a);
	p7=obrocOY(rleg.p7[0],lleg.p7[1],rleg.p7[2]+move,a);
	p8=obrocOY(rleg.p8[0],lleg.p8[1],rleg.p8[2]+move,a);

	punkt1=point3Dto2D(p1[0],p1[1],p1[2]);
	punkt2=point3Dto2D(p2[0],p2[1],p2[2]);
	punkt3=point3Dto2D(p3[0],p3[1],p3[2]);
	punkt4=point3Dto2D(p4[0],p4[1],p4[2]);
	punkt5=point3Dto2D(p5[0],p5[1],p5[2]);
	punkt6=point3Dto2D(p6[0],p6[1],p6[2]);
	punkt7=point3Dto2D(p7[0],p7[1],p7[2]);
	punkt8=point3Dto2D(p8[0],p8[1],p8[2]);

		for (int i=0; i<8; i++){
		maxZ=(p1[2]+p2[2])/2; id=1;
		if( (p1[2]+p2[2])/2 > maxZ-10){id=1; maxZ=(p1[2]+p2[2])/2;}
		if( (p2[2]+p6[2])/2 > maxZ-10){id=2; maxZ=(p2[2]+p6[2])/2;}
		if( (p5[2]+p6[2])/2 > maxZ-10){id=3; maxZ=(p5[2]+p6[2])/2;}
		if( (p1[2]+p5[2])/2 > maxZ-10){id=4; maxZ=(p1[2]+p5[2])/2;}
	}

	if(ch6->isChecked()){
		switch(id){
			case 1:{
				naklejTrojkat(pleg1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt1,punkt2,punkt3);//przod
				naklejTrojkat(pleg1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt1,punkt4,punkt3);
				naklejTrojkat(pleg2,125,380,tex3.p1,tex5.p2,tex5.p3,punkt2,punkt6,punkt7);//prawa
				naklejTrojkat(pleg2,125,380,tex3.p1,tex5.p4,tex5.p3,punkt2,punkt3,punkt7);}break;
	    		case 2:{
				naklejTrojkat(pleg2,125,380,tex3.p1,tex5.p2,tex5.p3,punkt2,punkt6,punkt7);//prawa
				naklejTrojkat(pleg2,125,380,tex3.p1,tex5.p4,tex5.p3,punkt2,punkt3,punkt7);}break;
			case 3:{
				naklejTrojkat(pleg4,135,380,tex5.p1,tex5.p2,tex5.p3,punkt5,punkt6,punkt7);//tyl
				naklejTrojkat(pleg4,135,380,tex5.p1,tex5.p4,tex5.p3,punkt5,punkt8,punkt7);
				naklejTrojkat(pleg3,125,380,tex5.p1,tex5.p2,tex5.p3,punkt5,punkt1,punkt4);//lewa
				naklejTrojkat(pleg3,125,380,tex5.p1,tex5.p4,tex5.p3,punkt5,punkt8,punkt4);}break;
			case 4:{
				naklejTrojkat(pleg4,135,380,tex5.p1,tex5.p2,tex5.p3,punkt5,punkt6,punkt7);//tyl
				naklejTrojkat(pleg4,135,380,tex5.p1,tex5.p4,tex5.p3,punkt5,punkt8,punkt7);
				naklejTrojkat(pleg1,135,380,tex3.p1,tex3.p2,tex3.p3,punkt1,punkt2,punkt3);//przod
				naklejTrojkat(pleg1,135,380,tex3.p1,tex3.p4,tex3.p3,punkt1,punkt4,punkt3);
				naklejTrojkat(pleg3,125,380,tex5.p1,tex5.p2,tex5.p3,punkt5,punkt1,punkt4);//lewa
				naklejTrojkat(pleg3,125,380,tex5.p1,tex5.p4,tex5.p3,punkt5,punkt8,punkt4);}break;
		}
	}

	if(r1->isChecked() && ch6->isChecked()==false){
		rysujKrawedzie(p1,p2,p3,p4,p5,p6,p7,p8);
	}
}

void GlowneOkno::naklejTrojkat(unsigned char *p,int szer,int wys,int texP1[2],int texP2[2],int texP3[2],int* p1, int* p2, int* p3){
	for(int i=0; i<=szer; i++){
				for(int j=0; j<=wys; j++){
					vwu = obliczBarametryczne(i,j+1,texP1,texP2,texP3);
					v = vwu[0]; w = vwu[1]; u = vwu[2];
					if(wTrojkacie(v,w,u)){
						rgb = getKolor(i,j,p,szer);
						x = u*p1[0] + v*p2[0] + w*p3[0];
						y = u*p1[1] + v*p2[1] + w*p3[1];
						rysujPiksel(x,y,rgb[0],rgb[1],rgb[2]);
					}
				}
	}	
}

int* GlowneOkno::obrocOY(double x,double y,double z, double a){
	int *wynik3  = new int[3];
	wynik3[0] = (int)(x*cos(a)+z*sin(a));
	wynik3[1] = (int)y;
	wynik3[2] = (int)(-x*sin(a)+z*cos(a));
	return wynik3;
	delete[] wynik3;
	wynik3 = 0;
}

void GlowneOkno::czysc(){
	for(int i=1; i<szer; i++)
		for(int j=1; j<wys; j++){
			rgb=getKolor(i,j,ptr,szer);
			if(rgb[0] || rgb[1] || rgb[2] != 0) 
			rysujPiksel(i,j,0,0,0);	
		}
}

double* GlowneOkno::obliczBarametryczne(int x,int y, int A[2],int B[2],int C[2]){

	a[0]=(double)A[0]; a[1]=(double)A[1];
	b[0]=(double)B[0]; b[1]=(double)B[1];
	c[0]=(double)C[0]; c[1]=(double)C[1];

	v=((x-a[0])*(c[1]-a[1])-(y-a[1])*(c[0]-a[0]))/((b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]));
	w=((y-a[1])*(b[0]-a[0])-(x-a[0])*(b[1]-a[1]))/((b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]));
	u=1-v-w;
	
	vwu[0] = v; vwu[1] = w; vwu[2] = u;
	return vwu;
}

bool GlowneOkno::wTrojkacie(double v,double w,double u){
	if(u>=0 && u<=1 && v>=0 && v<=1 && w>=0 && w<=1) return true;
	else return false;
}

int* GlowneOkno::getKolor(int x,int y,unsigned char *p,int szer){
	int b = p[szer*4*y + 4*x  ];
      int g = p[szer*4*y + 4*x+1];
      int r = p[szer*4*y + 4*x+2];
	rgb[0]=r; rgb[1]=g; rgb[2]=b;
	return rgb;	
	delete[] rgb;
	rgb = 0;
}

void GlowneOkno::rysujKrawedzie(int* p1,int* p2,int* p3,int* p4,int* p5,int* p6,int* p7,int* p8){
	rysujOdcinek3D_PRO(p1,p2,255,255,255);
	rysujOdcinek3D_PRO(p2,p3,255,255,255);
	rysujOdcinek3D_PRO(p3,p4,255,255,255);
	rysujOdcinek3D_PRO(p4,p1,255,255,255);
	rysujOdcinek3D_PRO(p5,p6,255,255,255);   
	rysujOdcinek3D_PRO(p6,p7,255,255,255);
	rysujOdcinek3D_PRO(p7,p8,255,255,255); 
	rysujOdcinek3D_PRO(p8,p5,255,255,255);
	rysujOdcinek3D_PRO(p1,p5,255,255,255);
	rysujOdcinek3D_PRO(p2,p6,255,255,255);
	rysujOdcinek3D_PRO(p3,p7,255,255,255);
	rysujOdcinek3D_PRO(p4,p8,255,255,255);	
}

void GlowneOkno::floodFill(int x,int y,int r1,int g1,int b1,int r2,int g2,int b2){
	int w,e;
	std::stack<int>Q;
	if(!sprawdzKolor(x,y,r1,g1,b1)) return;
      Q.push(x); Q.push(y);

	while(!Q.empty()){
		y=Q.top(); Q.pop();
            x=Q.top(); Q.pop();
		if(sprawdzKolor(x,y,r1,g1,b1)){
			w=x; e=x;
			while (sprawdzKolor(w,y,r1,g1,b1)) w--;
			while (sprawdzKolor(e,y,r1,g1,b1)) e++;
 			for (int i=w+1; i<e; i++) rysujPiksel(i,y,r2,g2,b2);
			for (int i=w+1; i<e; i++){
				if (sprawdzKolor(i,y+1,r1,g1,b1)) {Q.push(i); Q.push(y+1);}
				if (sprawdzKolor(i,y-1,r1,g1,b1)) {Q.push(i); Q.push(y-1);}
			}
		}
	}
      return;
}

bool GlowneOkno::sprawdzKolor(int x,int y,int r,int g,int b){
	if(ptr[szer*4*y + 4*x  ]==r &&
         ptr[szer*4*y + 4*x+1]==g &&
         ptr[szer*4*y + 4*x+2]==b)return true;
	else return false;	
}

void GlowneOkno::mousePressEvent(QMouseEvent *event){    
	int x = event->x();
    	int y = event->y(); 
	if(x<=800 && y<=800 && r1->isChecked() && ch1->isChecked()==false && ch2->isChecked()==false && ch3->isChecked()==false
							   && ch4->isChecked()==false && ch5->isChecked()==false && ch6->isChecked()==false){
	srand(time(NULL));
      floodFill(x,y,0,0,0,std::rand(),std::rand(),std::rand()); }
}

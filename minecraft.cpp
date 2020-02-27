#include <stdio.h>
#include <graphics.h>
#include <windows.h>
#define CDEC dk[ax][bx]
#define PSG dik[ax][bx]
void Find(int aix,int bix,int pc);
void Check(int aix,int bix,int pc);
void Count(int aix,int bix,int pc);
	int dk[54][36];
	int dik[54][36];
	int flag=0;
int game(void)
{
	int x,y,tx=0,ty=0;
	int ax=0,bx=0,cx=0,dx=0,kind=1,axt,bxt;
	mouse_msg msg={0};
	PIMAGE img;
	img=newimage();
	getimage(img,"game//gm.png");
	PIMAGE other[5];
	while(cx<5)
	{
		other[cx]=newimage();
		cx++;
	}
	cx=0;
	getimage(other[0],"game//kinder.png");
	getimage(other[1],"game//pick.png");
	PIMAGE block[100];
	while(cx<100)
	{
		block[cx]=newimage();
		cx++;
	}
	getimage(block[1],"game//1.png");
	getimage(block[2],"game//2.png");
	getimage(block[3],"game//3.png");
	getimage(block[4],"game//4.png");
	getimage(block[5],"game//5.png");
	getimage(block[6],"game//6.png");
	getimage(block[7],"game//7.png");
	getimage(block[8],"game//8.png");
	getimage(block[9],"game//9.png");
	getimage(block[10],"game//10.png");
	getimage(block[11],"game//11.png");
	getimage(block[12],"game//12.png");
	getimage(block[13],"game//13.png");
	getimage(block[14],"game//14.png");
	getimage(block[25],"game//25.png");
	getimage(block[26],"game//26.png");
	getimage(block[27],"game//27.png");
	getimage(block[28],"game//28.png");
	getimage(block[29],"game//29.png");
	getimage(block[75],"game//75.png");
	getimage(block[76],"game//76.png");
	getimage(block[77],"game//77.png");
	getimage(block[78],"game//78.png");
	getimage(block[79],"game//79.png");
	getimage(block[80],"game//80.png");
	getimage(block[81],"game//81.png");
	getimage(block[82],"game//82.png");
	getimage(block[83],"game//83.png");
	putimage(0,0,img);
	while(ax<54)
	{
		while(bx<36)
		{
			dik[ax][bx]=0;
			bx++;
		}
		bx=0;
		ax++;
	}
	ax=0;bx=0;
	while(ax<54)
	{
		while(bx<36)
		{
			dk[ax][bx]=0;
			bx++;
		}
		bx=0;
		ax++;
	}
	ax=0;bx=3;cx=5;
	while(cx>0)
	{
		while(bx<54)
		{
			dk[bx][30+cx]=2;
			bx++;
		}
		bx=3;
		cx--;
	}
	bx=3;cx=0;
	while(bx<54)
	{
		dk[bx][31]=1;
		bx++;
	}
	bx=3;
	while(bx<54)
	{
		dk[bx][35]=3;
		bx++;
	}
	for(;is_run;delay_fps(30))					
	{
		putimage(tx,0,img);
		putimage_withalpha(NULL,other[0],0,0);
		if(kind>24)
		putimage_withalpha(NULL,other[1],30,ty);
		else 
		putimage_withalpha(NULL,other[1],0,ty);
		if(tx==-2159)
		tx=0;
		while(ax<54)								//确定方块种类 
		{
			while(bx<36)
			{
				if (CDEC==1)
				putimage(ax*20,bx*20,block[1]);
				else if (CDEC==2)
				putimage(ax*20,bx*20,block[2]);
				else if (CDEC==3)
				putimage(ax*20,bx*20,block[3]);
				else if (CDEC==4)
				putimage(ax*20,bx*20,block[4]);
				else if (CDEC==5)
				putimage(ax*20,bx*20,block[5]);
				else if (CDEC==6)
				putimage(ax*20,bx*20,block[6]);
				else if (CDEC==7)
				putimage(ax*20,bx*20,block[7]);
				else if (CDEC==8)
				putimage_withalpha(NULL,block[8],ax*20,bx*20);
				else if (CDEC==9)
				putimage(ax*20,bx*20,block[9]);
				else if (CDEC==10)
				putimage(ax*20,bx*20,block[10]);
				else if (CDEC==11)
				putimage(ax*20,bx*20,block[11]);
				else if (CDEC==72)
				dk[ax][bx]=12;
				else if (CDEC==12)					//沙子掉落 
				{
					putimage(ax*20,bx*20,block[12]);
					if(bx==35)
					{
						CDEC=0;
					}
					else if((dk[ax][bx+1]==0))
					{
						dk[ax][bx+1]=72;
						CDEC=0;
					}
				}
				else if (CDEC==73)
				dk[ax][bx]=13;
				else if (CDEC==13)
				{
					putimage(ax*20,bx*20,block[13]);
					if(bx==35)
					{
						CDEC=0;
					}
					else if((dk[ax][bx+1]==0))
					{
						dk[ax][bx+1]=73;
						CDEC=0;
					}
				}
				else if (CDEC==14)
				putimage_withalpha(NULL,block[14],ax*20,bx*20);
				else if (CDEC==25)					//红石粉相关特性 
				{
					if(dk[ax][bx+1]==0 || dk[ax][bx+1]==25
					|| dk[ax][bx+1]==75 || dk[ax][bx+1]==26
					|| dk[ax][bx+1]==27 || dk[ax][bx+1]==28)
					{
					 	CDEC=0;
					}
					
					if(dk[ax+1][bx-1]==25 && (dk[ax][bx-1]==0
					|| dk[ax][bx-1]==14 || dk[ax][bx-1]==27
					|| dk[ax][bx-1]==28 ||
					(dk[ax][bx-1]>=90 && dk[ax][bx-1]<117)))
					{
					 	if(PSG==1)
						putimage_withalpha(NULL,block[78],ax*20,bx*20-2);
						else
						putimage_withalpha(NULL,block[75],ax*20,bx*20-2);
					}
					
					if(dk[ax-1][bx-1]==25 && (dk[ax][bx-1]==0
					|| dk[ax][bx-1]==14 || dk[ax][bx-1]==27 || 
					dk[ax][bx-1]==28 ||
					(dk[ax][bx-1]>=90 && dk[ax][bx-1]<117)))
					{
					 	if(PSG==1)
						putimage_withalpha(NULL,block[79],ax*20,bx*20-2);
						else
						putimage_withalpha(NULL,block[76],ax*20,bx*20-2);
					}
					
					else
					{
						if(PSG==1)
						putimage_withalpha(NULL,block[77],ax*20,bx*20);
						else 
						putimage_withalpha(NULL,block[25],ax*20,bx*20);
					}
					
				}
				else if (CDEC==26)					 //红石火把相关特性 
				{
					if(dk[ax][bx+1]==0 || dk[ax][bx+1]==25
					|| dk[ax][bx+1]==75 || dk[ax][bx+1]==26
					|| dk[ax][bx+1]==27 || dk[ax][bx+1]==28
					|| dk[ax][bx+1]==96 || dk[ax][bx+1]==110)
					CDEC=0;
					else
					{
						PSG=2;
						if(dk[ax][bx-1]!=0 && dk[ax][bx-1]!=14)
						dik[ax][bx-1]=2;
					}
					if(dik[ax][bx+1]==2 || dik[ax][bx+1]==3)
					CDEC=76;
					putimage_withalpha(NULL,block[26],ax*20,bx*20);
				}
				else if (CDEC>=76 && CDEC<82)
				{
					if(dk[ax][bx+1]==0 || dk[ax][bx+1]==25
					|| dk[ax][bx+1]==75 || dk[ax][bx+1]==26
					|| dk[ax][bx+1]==27 || dk[ax][bx+1]==28
					|| dk[ax][bx+1]==96 || dk[ax][bx+1]==110)
					CDEC=0;
					else
					CDEC+=1;
					putimage_withalpha(NULL,block[26],ax*20,bx*20);
				}
				else if(CDEC==82)
				{
					if(dk[ax][bx+1]==0 || dk[ax][bx+1]==25
					|| dk[ax][bx+1]==75 || dk[ax][bx+1]==26
					|| dk[ax][bx+1]==27 || dk[ax][bx+1]==28
					|| dk[ax][bx+1]==96 || dk[ax][bx+1]==110)
					CDEC=0;
					else
					{
						PSG=0;
					}
					if(dik[ax][bx+1]==0)
					CDEC=83;
					putimage_withalpha(NULL,block[82],ax*20,bx*20);
				}
				else if (CDEC>=83 && CDEC<89)
				{
					if(dk[ax][bx+1]==0 || dk[ax][bx+1]==25
					|| dk[ax][bx+1]==75 || dk[ax][bx+1]==26
					|| dk[ax][bx+1]==27 || dk[ax][bx+1]==28
					|| dk[ax][bx+1]==96 || dk[ax][bx+1]==110)
					CDEC=0;
					else
					CDEC+=1;
					putimage_withalpha(NULL,block[82],ax*20,bx*20);
					if(CDEC==89)
					CDEC=26;
				}
				else if (CDEC==27)					 //斜红石火把相关特性 
				{
					if(dk[ax+1][bx]==0 || dk[ax+1][bx]==25
					|| dk[ax+1][bx]==75 || dk[ax+1][bx]==26
					|| dk[ax+1][bx]==27 || dk[ax+1][bx]==28
					|| dk[ax+1][bx]==96 || dk[ax+1][bx]==110)
					CDEC=0;
					else
					{
						PSG=2;
						if(dk[ax][bx-1]!=0 && dk[ax][bx-1]!=14)
						dik[ax][bx-1]=2;
					}
					if(dik[ax+1][bx]==2 || dik[ax+1][bx]==3)
					CDEC=90;
					putimage_withalpha(NULL,block[27],ax*20,bx*20);
				}
				else if (CDEC>=90 && CDEC<96)
				{
					if(dk[ax+1][bx]==0 || dk[ax+1][bx]==25
					|| dk[ax+1][bx]==75 || dk[ax+1][bx]==26
					|| dk[ax+1][bx]==27 || dk[ax+1][bx]==28
					|| dk[ax+1][bx]==96 || dk[ax+1][bx]==110)
					CDEC=0;
					else
					CDEC+=1;
					putimage_withalpha(NULL,block[27],ax*20,bx*20);
				}
				else if(CDEC==96)
				{
					if(dk[ax+1][bx]==0 || dk[ax+1][bx]==25
					|| dk[ax+1][bx]==75 || dk[ax+1][bx]==26
					|| dk[ax+1][bx]==27 || dk[ax+1][bx]==28
					|| dk[ax+1][bx]==96 || dk[ax+1][bx]==110)
					CDEC=0;
					else
					{
						PSG=0;
					}
					if(dik[ax+1][bx]==0)
					CDEC=97;
					putimage_withalpha(NULL,block[80],ax*20,bx*20);
				}
				else if (CDEC>=97 && CDEC<103)
				{
					if(dk[ax+1][bx]==0 || dk[ax+1][bx]==25
					|| dk[ax+1][bx]==75 || dk[ax+1][bx]==26
					|| dk[ax+1][bx]==27 || dk[ax+1][bx]==28
					|| dk[ax+1][bx]==96 || dk[ax+1][bx]==110)
					CDEC=0;
					else
					CDEC+=1;
					putimage_withalpha(NULL,block[80],ax*20,bx*20);
					if(CDEC==103)
					CDEC=27;
				}
				
				else if (CDEC==28)					 //斜红石火把相关特性 
				{
					if(dk[ax-1][bx]==0 || dk[ax-1][bx]==25
					|| dk[ax-1][bx]==75 || dk[ax-1][bx]==26
					|| dk[ax-1][bx]==27 || dk[ax-1][bx]==28
					|| dk[ax-1][bx]==96 || dk[ax-1][bx]==110)
					CDEC=0;
					else
					{
						PSG=2;
						if(dk[ax][bx-1]!=0 && dk[ax][bx-1]!=14)
						dik[ax][bx-1]=2;
					}
					if(dik[ax-1][bx]==2 || dik[ax-1][bx]==3)
					CDEC=104;
					putimage_withalpha(NULL,block[28],ax*20,bx*20);
				}
				else if (CDEC>=104 && CDEC<110)
				{
					if(dk[ax-1][bx]==0 || dk[ax-1][bx]==25
					|| dk[ax-1][bx]==75 || dk[ax-1][bx]==26
					|| dk[ax-1][bx]==27 || dk[ax-1][bx]==28
					|| dk[ax-1][bx]==96 || dk[ax-1][bx]==110)
					CDEC=0;
					else
					CDEC+=1;
					putimage_withalpha(NULL,block[28],ax*20,bx*20);
				}
				else if(CDEC==110)
				{
					if(dk[ax-1][bx]==0 || dk[ax-1][bx]==25
					|| dk[ax-1][bx]==75 || dk[ax-1][bx]==26
					|| dk[ax-1][bx]==27 || dk[ax-1][bx]==28
					|| dk[ax-1][bx]==96 || dk[ax-1][bx]==110)
					CDEC=0;
					else
					{
						PSG=0;
					}
					if(dik[ax-1][bx]==0)
					CDEC=111;
					putimage_withalpha(NULL,block[81],ax*20,bx*20);
				}
				else if (CDEC>=111 && CDEC<117)
				{
					if(dk[ax-1][bx]==0 || dk[ax-1][bx]==25
					|| dk[ax-1][bx]==75 || dk[ax-1][bx]==26
					|| dk[ax-1][bx]==27 || dk[ax-1][bx]==28
					|| dk[ax-1][bx]==96 || dk[ax-1][bx]==110)
					CDEC=0;
					else
					CDEC+=1;
					putimage_withalpha(NULL,block[81],ax*20,bx*20);
					if(CDEC==117)
					CDEC=28;
				}
				
				else if(CDEC==29)
				{
					if(dik[ax+1][bx]==2 || PSG==2 || PSG==3 || 
					dik[ax-1][bx]==2|| dik[ax][bx+1]==2 || (
					dik[ax][bx-1]==2 && (dk[ax][bx-1]==27 || dk[ax][bx-1]==28))
					|| dik[ax][bx+1]==2 || dik[ax+1][bx]==3 ||
					dik[ax-1][bx]==3 || dik[ax][bx+1]==3 || dik[ax][bx-1]==3)
					putimage(ax*20,bx*20,block[83]);
					else
					putimage(ax*20,bx*20,block[29]);
				}
				if(PSG==2)
				{
					Find(ax,bx,0);
					if(dk[ax][bx+1]!=26 && CDEC!=26 && CDEC!=27 && CDEC!=28)
					PSG=0;
					if(CDEC>=90 && CDEC<96)
					PSG=2;
					else if(CDEC>=76 && CDEC<82)
					PSG=2;
					else if(CDEC>=104 && CDEC<110)
					PSG=2;
				}
				if(PSG==1)
				{
					flag=0;
					Check(ax,bx,0);
					if(flag!=1)
					{
						Count(ax,bx,0);
					} 
				}
				if(PSG==3)
				{
					if((dik[ax+1][bx]!=1 && dik[ax-1][bx]!=1 
					&& dik[ax][bx-1]!=1) || CDEC==0 || CDEC==14)
					PSG=0;
				}
				bx++;
			}
			bx=0;
			ax++;
		}
		ax=0;
		
		while(mousemsg())
		{
			msg=getmouse();
			if(msg.is_left() && msg.is_up())
			{
				mousepos(&x,&y);
				dk[x/20][y/20]=0;
				dik[x/20][y/20]=0;
				if(x>30 && x<60)
				{
					kind=24+y/30+1;
					ty=y/30*30;
				}
				
				else if(x<30)
				{
					kind=y/30+1;
					ty=y/30*30;
				}
				
			}
			if(msg.is_right() && msg.is_up())
			{
				mousepos(&x,&y);
				if(x>60)
				dk[x/20][y/20]=kind;
			}
		}
		tx--;
	}
		
	getch();
}

void Find(int aix,int bix,int pc)   						//激活 
{
	int axt,bxt;
	axt=aix;bxt=bix;
	if(dk[aix+1][bix]==25 && pc!=1)
	{
		dik[aix+1][bix]=1;
		dik[aix+1][bix+1]=3;
		aix++;
		Find(aix,bix,2);
	}
	aix=axt;bix=bxt;
	if(dk[aix-1][bix]==25 && pc!=2)
	{
		dik[aix-1][bix]=1;
		dik[aix-1][bix+1]=3;
		aix--;
		Find(aix,bix,1);	
	}	
	aix=axt;bix=bxt;
	if(dk[aix][bix-1]==25 && pc!=3)
	{
		dik[aix][bix-1]=1;
		bix--;
		Find(aix,bix,4);	
	}	
	aix=axt;bix=bxt;
	if(dk[aix][bix+1]==25 && pc!=4)
	{
		dik[aix][bix+1]=1;
		bix++;
		Find(aix,bix,3);	
	}	
	aix=axt;bix=bxt;	
	if(dk[aix-1][bix-1]==25 && pc!=5 && dik[aix][bix]==1 && (dk[aix][bix-1]==0
	 || dk[aix][bix-1]==14 || dk[aix][bix-1]==27 || (dk[aix][bix-1]>=90
	 && dk[aix][bix-1]<=103)))
	{
		dik[aix-1][bix-1]=1;
		dik[aix-1][bix]=3;
		aix--;
		bix--;
		Find(aix,bix,6);	
	}	
	aix=axt;bix=bxt;	
	if(dk[aix+1][bix+1]==25 && pc!=6 && dik[aix][bix]==1 
	&& (dk[aix+1][bix]==0 || dk[aix+1][bix]==14 || dk[aix+1][bix]==27 
	|| (dk[aix+1][bix]>=90 && dk[aix+1][bix]<=103)))
	{
		dik[aix+1][bix+1]=1;
		dik[aix+1][bix+2]=3;
		aix++;
		bix++;
		Find(aix,bix,5);	
	}
		aix=axt;bix=bxt;	
	if(dk[aix+1][bix-1]==25 && pc!=7 && dik[aix][bix]==1 && (dk[aix][bix-1]==0
	 || dk[aix][bix-1]==14 || dk[aix][bix-1]==28 
	|| (dk[aix][bix-1]>=104 && dk[aix][bix-1]<=117)))
	{
		dik[aix+1][bix-1]=1;
		dik[aix+1][bix]=3;
		aix++;
		bix--;
		Find(aix,bix,8);	
	}	
	aix=axt;bix=bxt;	
	if(dk[aix-1][bix+1]==25 && pc!=8 && dik[aix][bix]==1 
	&& (dk[aix-1][bix]==0 || dk[aix-1][bix]==14 || dk[aix-1][bix]==28 
	|| (dk[aix-1][bix]>=104 && dk[aix-1][bix]<=117)))
	{
		dik[aix-1][bix+1]=1;
		dik[aix-1][bix+2]=3;
		aix--;
		bix++;
		Find(aix,bix,7);	
	}
	if(dik[aix][bix]==1 && dik[aix+1][bix]!=2 && dk[aix+1][bix]!=0 
	&& dk[aix+1][bix]!=26 && dk[aix+1][bix]!=25 && dk[aix-1][bix]!=27)
	dik[aix+1][bix]=3;	
	if(dik[aix][bix]==1 && dik[aix-1][bix]!=2 && dk[aix-1][bix]!=0 
	&& dk[aix-1][bix]!=26 && dk[aix-1][bix]!=25 && dk[aix-1][bix]!=27)
	dik[aix-1][bix]=3;
}

void Check(int aix,int bix,int pc)							//判定 
{
	int axt,bxt;
	axt=aix;bxt=bix;
	if(dk[aix+1][bix]==25 && pc!=1)
	{
		aix++;
		Check(aix,bix,2);
		
	}
	else if(dik[aix+1][bix]==2)
	flag=1;
	
	aix=axt;bix=bxt;
	if(dk[aix-1][bix]==25 && pc!=2)
	{
		aix--;
		Check(aix,bix,1);	
	}
	else if(dik[aix-1][bix]==2)
	flag=1;
	
	aix=axt;bix=bxt;
	if(dk[aix][bix-1]==25 && pc!=3)
	{
		bix--;
		Check(aix,bix,4);	
	}
	else if(dik[aix][bix-1]==2)
	flag=1;
	
	aix=axt;bix=bxt;
	if(dk[aix][bix+1]==25 && pc!=4)
	{
		bix++;
		Check(aix,bix,3);	
	}
	else if(dik[aix][bix+1]==2)
	flag=1;
	
	aix=axt;bix=bxt;	
	if(dk[aix-1][bix-1]==25 && pc!=5 && dik[aix][bix]==1 && (dk[aix][bix-1]==0
	|| dk[aix][bix-1]==14 || dk[aix][bix-1]==27
	|| (dk[aix][bix-1]>=90 && dk[aix][bix-1]<=103)))
	{
		aix--;
		bix--;
		Check(aix,bix,6);	
	}

	
	aix=axt;bix=bxt;	
	if(dk[aix+1][bix+1]==25 && pc!=6 && dik[aix][bix]==1 
	&& (dk[aix+1][bix]==0 || dk[aix+1][bix]==14 || dk[aix+1][bix]==27
	|| (dk[aix+1][bix]>=90 && dk[aix][bix+1]<=103)))
	{
		aix++;
		bix++;
		Check(aix,bix,5);	
	}
	
	
	aix=axt;bix=bxt;	
	if(dk[aix+1][bix-1]==25 && pc!=7 && dik[aix][bix]==1 && (dk[aix][bix-1]==0
	 || dk[aix][bix-1]==14 || dk[aix][bix-1]==28
	 || (dk[aix][bix-1]>=104 && dk[aix][bix-1]<=117)))
	{
		aix++;
		bix--;
		Check(aix,bix,8);	
	}

	
	aix=axt;bix=bxt;	
	if(dk[aix-1][bix+1]==25 && pc!=8 && dik[aix][bix]==1 
	&& (dk[aix-1][bix]==0 || dk[aix-1][bix]==14 || dk[aix-1][bix]==28
	|| (dk[aix-1][bix]>=104 && dk[aix-1][bix]<=117)))
	{
		aix--;
		bix++;
		Check(aix,bix,7);	
	}
	
}



void Count(int aix,int bix,int pc)							 //清零
{
	int axt,bxt;
	axt=aix;bxt=bix;
	if(dk[aix][bix]==25 && pc!=1)
	{
		dik[aix][bix]=0;
		aix++;
		Count(aix,bix,2);
	}
	
	aix=axt;bix=bxt;
	if(dk[aix][bix]==25 && pc!=2)
	{
		dik[aix][bix]=0;
		aix--;
		Count(aix,bix,1);
	}
	
	aix=axt;bix=bxt;
	if(dk[aix][bix]==25 && pc!=3)
	{
		dik[aix][bix]=0;
		bix--;
		Count(aix,bix,4);
	}	
	
	aix=axt;bix=bxt;
	if(dk[aix][bix]==25 && pc!=4)
	{
		dik[aix][bix]=0;
		bix++;
		Count(aix,bix,3);
	}
	
	aix=axt;bix=bxt;
	if(dk[aix][bix]==25 && pc!=5 && dik[aix][bix]==1 && (dk[aix][bix-1]==0
	 || dk[aix][bix-1]==14 || dk[aix][bix-1]==27 || dk[aix][bix-1]==28))
	{
		dik[aix][bix]=0;
		aix--;
		bix--;
		Count(aix,bix,6);
	}	
	
	aix=axt;bix=bxt;
	if(dk[aix][bix]==25 && pc!=6  && dik[aix][bix]==1 
	&& (dk[aix+1][bix]==0 || dk[aix+1][bix]==14 || dk[aix+1][bix]==27
	 || dk[aix+1][bix]==28))
	{
		dik[aix][bix]=0;
		aix++;
		bix++;
		Count(aix,bix,5);
	}	
	
	aix=axt;bix=bxt;
	if(dk[aix][bix]==25 && pc!=7 && dik[aix][bix]==1 && (dk[aix][bix-1]==0
	 || dk[aix][bix-1]==14))
	{
		dik[aix][bix]=0;
		aix++;
		bix--;
		Count(aix,bix,8);
	}	
	
	aix=axt;bix=bxt;
	if(dk[aix][bix]==25 && pc!=8 && dik[aix][bix]==1 
	&& (dk[aix-1][bix]==0 || dk[aix-1][bix]==14))
	{
		dik[aix][bix]=0;
		aix--;
		bix++;
		Count(aix,bix,7);
	}			
}

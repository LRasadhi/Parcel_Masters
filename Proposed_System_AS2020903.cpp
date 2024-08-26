/*----------------------------
System - Courier service System 'THE PARCEL MASTERS'
Author - B.A.L.Rasadi
Version - V.1.0.0
Description - This is the courier service for send a parcel or ducment from one location to another. This program prints bill after the calculations according to the service rules.
-----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <conio.h>
//function declaration
int distancepricecalculation(float);
int WandVpricecalculation(float, float, float, float, int [17][8] );
int DocumentPrices (float);
float discountCalculate (float);

//begins function main
int main()
{
	/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	this is the price list for according to the ITEM DETAILS and DIMENSIONS
	Rows show the amount of kilograms it starts from 1kg and end 17kg
	columns show the amount of volume it starts from 20cm^3 and end 90cm^3
	we can cange the prices by changing this array
	----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	int intWtandV_Array [17][8]=
	{
		{150,160,170,180,190,200,210,220},
		{250,260,270,280,290,300,310,320},
		{300,310,320,330,340,350,360,370},
		{350,360,370,380,390,400,410,420},
		{400,410,420,430,440,450,460,470},
		{450,460,470,480,490,500,510,520},
		{500,510,520,530,540,550,560,570},
		{550,560,570,580,590,600,610,620},
		{600,610,620,630,640,650,660,670},
		{650,660,670,680,690,700,710,720},
		{700,710,720,730,740,750,760,770},
		{750,760,770,780,790,800,810,820},
		{800,810,820,830,840,850,860,870},
		{850,860,870,880,890,900,910,920},
		{900,910,920,930,940,950,960,970},
		{950,960,970,980,990,1000,1010,1120},
		{1000,1010,1020,1030,1040,1050,1060,1070}
	};
	/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	Variables
	------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	char strSenderName , strReceiverName, strReceiverAdd, strSenderAdd, strReceiverNo, strSenderNo [20];
	float fltweight;		//this is the weight of parcel
	float fltlength;		//this is the lengthe of parcel
	float fltheight;		//this is the height of parcel
	float fltwidth;			//this is the width of parcel	
	float fltvolume;		//this is the volume of parcel volume=length x height x width
	float fltdistance;		//this is the distance between send city and received city
	char chritemtype;		//this is the item type char variable
	int intdistanceprice;	//this is the price of distance
	int intWandVprice; 		//this is the price of according to the volume and weight
	int intDocprice;		//this is the price of Document delivery
	float fltdeliveryfee;	//this is the price of Delivery fee
	float fltTotprice;		//this is the price of Payment
	float fltDiscount;		//this is the price of Discount
	
	printf("\t\t__________THE PARCEL MASTERS__________\n\n\n");
	printf("****Please Enter the weight in Kilograms****\n");
	printf("****Please Enter the package dimensions in Centimeters****\n\n");
	//this is the name of the sender
	printf("Enter the sender First Name :");
	scanf("%s",&strSenderName);
	//this is the Address of the sender
	printf("Enter the sender City :");
	scanf("%s",&strSenderAdd);
	//this is the number of the sender
	printf("Enter the sender Telephone Number :");
	scanf("%s",&strSenderNo);
	printf("\n");
	//this is the name of the receiver
	printf("Enter the Reciever First Name :");
	scanf("%s",&strReceiverName);
	//this is the Address of the reciever
	printf("Enter the Reciever City :");
	scanf("%s",&strReceiverAdd);
	//this is the number of the reciever
	printf("Enter the Reciever Telephone Number :");
	scanf("%s",&strReceiverNo);
	printf("\n");
	
	do
	{
		printf("Enter the Distance between sender city and reciever city :");
		scanf("%f",&fltdistance);
		if (fltdistance<=1)
		{
			printf("Sorry :(!! We didn't delivered within 1km.. Please enter valid distance..\n");
			printf("\n");
			continue;
		}
		else
		{
			intdistanceprice = distancepricecalculation(fltdistance);
			//printf("%d",intdistanceprice);
		}
	}while(fltdistance<=1);
	
	printf("\n");
	printf("Enter the Item Type (if ityem type is Document then Enter 'D' or if item type is Parcel Enter 'P') :");
	scanf("%s",&chritemtype);
	printf("\n");
	if (chritemtype=='P' || chritemtype=='p')
	{
		printf("Enter the Weight of parcel :");
		scanf("%f",&fltweight);
		printf("Enter the Width of parcel :");
		scanf("%f",&fltwidth);
		printf("Enter the Height of parcel :");
		scanf("%f",&fltheight);
		printf("Enter the Length of parcel :");
		scanf("%f",&fltlength);
		printf("\n\n");
		intWandVprice = WandVpricecalculation(fltlength, fltheight, fltwidth, fltweight, intWtandV_Array);
		fltdeliveryfee = ((intWandVprice+intdistanceprice)*10)/100.0;
		fltTotprice = float (fltdeliveryfee+intdistanceprice+intWandVprice);
		fltDiscount=discountCalculate(fltTotprice);
		float fltNewprice = fltTotprice-fltDiscount;
		//printf("%f\n",fltDiscount);
		//printf("%f\n",fltTotprice);
		printf("--------------------------------------------------------------------------------");
		printf("--------------------------------------------------------------------------------\n");
		printf("\t\t_________Parcel Maters_________\n\n");
		printf("\tDistance price               :   Rs.%d.00\n",intdistanceprice);
		printf("\tWeight and Volume price      :   Rs.%d.00\n",intWandVprice);
		printf("\tDelivery fee 10/100          :   Rs.%.2f\n",fltdeliveryfee);  
		printf("\t______________________________________________\n\n");
		printf("\tPrice                        :   Rs.%.2f\n",fltTotprice);
		printf("\tDiscount                     : - Rs.%.2f\n",fltDiscount);
		printf("\t______________________________________________\n\n");
		printf("\tTotal Price                  :   Rs.%.2f\n",fltNewprice);
		printf("\t______________________________________________\n");
		printf("\t______________________________________________\n\n");
		printf("\t\tThank You See You next Time!!!\n\n");
		printf("--------------------------------------------------------------------------------");	
		printf("--------------------------------------------------------------------------------\n");	


	}
	else if (chritemtype=='D' || chritemtype=='d')
	{
		printf("Enter the Weight of parcel :");
		scanf("%f",&fltweight);
		printf("\n\n");
		intDocprice = DocumentPrices (fltweight);
		intdistanceprice = distancepricecalculation(fltdistance);
		fltdeliveryfee = ((intDocprice+intdistanceprice)*10)/100.0;
		fltTotprice = float (fltdeliveryfee+intdistanceprice+intDocprice);
		printf("--------------------------------------------------------------------------------");
		printf("--------------------------------------------------------------------------------\n");
		printf("\t\t_________Parcel Maters_________\n\n");
		printf("\tDistance price      : Rs.%d.00\n",intdistanceprice);
		printf("\tDocument price      : Rs.%d.00\n",intDocprice);
		printf("\tDelivery fee 10/100 : Rs.%.2f\n",fltdeliveryfee);
		printf("\t______________________________________________\n\n");
		printf("\tTotal Price         : Rs.%.2f\n",fltTotprice);
		printf("\t______________________________________________\n");
		printf("\t______________________________________________\n\n");
		printf("\t\tThank You See You next Time!!!\n\n");
		printf("--------------------------------------------------------------------------------");
		printf("--------------------------------------------------------------------------------\n");
	}
	
    return 0;
}//end main function

	/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	begin int distancecalculation function
	this is the price list for according to the cities distance
	this is begin from 2km and we don't courier within 1km, if distance greater than 10km then charge is Rs.15/= in 1km
	we can cange the prices by changing this switch
	----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int distancepricecalculation(float fltdistance)
{
	int intdistanceprice;
	int introunddistance;
	introunddistance=ceil(fltdistance);
	switch(introunddistance)
	{
		case 2 :
			intdistanceprice=50;
			//printf("%d",intprice);
			break;
		case 3 :
			intdistanceprice=60;
			//printf("%d",intprice);
			break;
		case 4 :
			intdistanceprice=70;
			//printf("%d",intprice);
			break;
		case 5 :
			intdistanceprice=80;
			//printf("%d",intprice);
			break;
		case 6 :
			intdistanceprice=90;
			//printf("%d",intprice);
			break;
		case 7 :
			intdistanceprice=100;
			//printf("%d",intprice);
			break;
		case 8 :
			intdistanceprice=110;
			//printf("%d",intprice);
			break;
		case 9 :
			intdistanceprice=120;
			//printf("%d",intprice);
			break;
		case 10 :
			intdistanceprice=150;
			//printf("%d",intprice);
			break;	
		default :
			intdistanceprice=(introunddistance*15);
			//printf("%d",intprice);
			break;
	}
	return intdistanceprice;
}
//End int distancecalculation function

	/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	begin int WandVpricecalculation function
	this is the price calculations for according to the parcel weight and the volume
	weight is begin from 1KG to 17KG if weight is greater than 17KG then 1KG is 80/=
	volume is begin from 20cm^3 to 90cm^3 if volume is greater than 90cm^3 then price is 100/= for 1cm^3
	If weight and volume less than 1kg and 20cm^3 respectively then price is (weight*150/=)+(volume*20/=)
	we can cange the prices by changing this array and this function
	----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int WandVpricecalculation(float fltlength, float fltheight, float fltwidth, float fltweight, int intWtandV_Array [17][8])
{
	float fltvolume=fltlength*fltwidth*fltheight;
	//printf("%.2f\n",fltvolume);
	int introundvolume = ceil(fltvolume);
	int introundweight = ceil(fltweight);
	int intcolumn;
	int intWandVprice;
	//printf("%d\n",introundvolume);
	//printf("%d\n",introundweight);
		if (introundvolume==20)
		{
			intcolumn=0;
			intWandVprice = intWtandV_Array [introundweight-1][intcolumn];
			//printf("%d",intWandVprice);
		}
		else if (introundvolume==30)
		{
			intcolumn=1;
			intWandVprice = intWtandV_Array [introundweight-1][intcolumn];
			//printf("%d",intWandVprice);
		}
		else if (introundvolume==40)
		{
			intcolumn=2;
			intWandVprice = intWtandV_Array [introundweight-1][intcolumn];
			//printf("%d",intWandVprice);
		}
		else if (introundvolume==50)
		{
			intcolumn=3;
			intWandVprice = intWtandV_Array [introundweight-1][intcolumn];
			//printf("%d",intWandVprice);
		}
		else if (introundvolume==60)
		{
			intcolumn=4;
			intWandVprice = intWtandV_Array [introundweight-1][intcolumn];
			//printf("%d",intWandVprice);
		}
		else if (introundvolume==70)
		{
			intcolumn=5;
			intWandVprice = intWtandV_Array [introundweight-1][intcolumn];
			//printf("%d",intWandVprice);
		}
		else if (introundvolume==80)
		{
			intcolumn=6;
			intWandVprice = intWtandV_Array [introundweight-1][intcolumn];
			//printf("%d",intWandVprice);
		}
		else if (introundvolume==90)
		{
			intcolumn=7;
			intWandVprice = intWtandV_Array [introundweight-1][intcolumn];
			//printf("%d",intWandVprice);
		}
		else if (introundvolume>90 || introundweight>17)
		{
			intWandVprice = (introundweight*80)+(introundvolume*100);
			//printf("%d",intWandVprice);
		}
		else
		{
			intWandVprice = (introundweight*150)+(introundvolume*20);
			//printf("%d",intWandVprice);
		}
		return intWandVprice;	
}
//End int WandVpricecalculation function

	/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	begin int DocumentPrices function
	this is the price calculations for Document delivery
	this is only calculate for weight and all the doc price is weight+distance+delivery fee
	we can cange the prices by changing this function
	----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int DocumentPrices (float fltweight)
{
	int introundweight = ceil(fltweight);
	int intDocprice = (introundweight*150);
	return intDocprice;
}
//End int DocumentPrices function

	/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	begin float discountCalculate function
	this is the price calculations for Discount
	if all the bill price will greater than 5000 then customer will received 15% discount
	we can cange the prices by changing this function
	----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
float discountCalculate(float fltTotprice)
{
	float fltDiscount;
	if (fltTotprice>=5000)
	{
		fltDiscount = ((fltTotprice*15)/100.0);
	}
	return fltDiscount;
}
//End float discountCalculate function







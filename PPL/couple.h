#ifndef couple_h
#define couple_h
#include "girl.h"
#include "boy.h"
#include "gift.h"

using namespace std;

class couple{
	public:
		char *girln = (char *)malloc(13*sizeof(char));
		char *boyn = (char *)malloc(13*sizeof(char));
		double boyhap = 0;
		double girlhap = 0;
		double couplehap = 0;
		double comp = 0;
		void setc(char *g, char *b) {
			strcpy(girln,g);
			strcpy(boyn,b);
		}
		
		void get_basket(vector<boy> *vb,vector <girl> *vg, vector<gift> vgi) {
			FILE *fp = fopen("gift_det.txt","a");
			int b,g;
			double bas_price = 0.0 , bas_value = 0.0 ; 
			for(int i = 0; i < 10 ; i++) {
				if(!strcmp(girln,(*vg)[i].name)){ 
					g = i;
					break;
				}
			}	
			for(int i = 0; i < 20 ; i++) {
				if(!strcmp(boyn,(*vb)[i].name)){ 
					b = i;
					break;
				}
			}	
			fprintf(fp,"%s %s\n",(*vb)[b].name,(*vg)[g].name);
			if((*vb)[b].type == 1 ) {
				for(int i = 29 ;i >= 0;i--) {
					if( bas_price + vgi[i].price <= (*vb)[b].budget) {
						bas_price += vgi[i].price;
						if((*vg)[g].type == 0 && vgi[i].type == 1) {
							bas_value += 2*vgi[i].value;
							fprintf(fp,"%s %lf %d %d %d %d\n",vgi[i].name,vgi[i].price,2*vgi[i].value,vgi[i].type, vgi[i].rating, vgi[i].obtain);
						}
						else {
							bas_value += vgi[i].value;
							fprintf(fp,"%s %lf %d %d %d %d\n",vgi[i].name,vgi[i].price,vgi[i].value,vgi[i].type, vgi[i].rating, vgi[i].obtain);
						}
					}
				}
			}
			else {
				for( int i=0 ; i < 30 ; i++ ) {
					int l=0 ;
					if( bas_price + vgi[i].price <= (*vb)[b].budget ) {
						bas_price += vgi[i].price;
						if( (*vg)[g].type == 0 && vgi[i].type == 1 ) {
							bas_value += 2*vgi[i].value;
							fprintf(fp,"%s %lf %d %d %d %d\n",vgi[i].name,vgi[i].price,2*vgi[i].value,vgi[i].type, vgi[i].rating, vgi[i].obtain);
							l++;
						}
						else if(vgi[i].type == 1) {
							bas_value += vgi[i].value ;
							fprintf(fp,"%s %lf %d %d %d %d\n",vgi[i].name,vgi[i].price,vgi[i].value,vgi[i].type, vgi[i].rating, vgi[i].obtain);
							l++;
						}
						else {
							bas_value += vgi[i].value;
							fprintf(fp,"%s %lf %d %d %d %d\n",vgi[i].name,vgi[i].price,2*vgi[i].value,vgi[i].type, vgi[i].rating, vgi[i].obtain);
						}
					}
				}
			}
			(*vg)[g].seth( bas_price , bas_value ) ;
			(*vb)[b].seth( (*vg)[g] , bas_price , bas_value);
			fprintf(fp,"%$# %lf %d %d %d %d",0,0,0,0,0);
			fclose(fp);
		}
		void seth(vector<boy> vb , vector <girl> vg ) {
			int g,b;
			for(int i = 0;i< vg.size() ;i++) {
				if(  strcmp ( girln , vg[i].name ) == 0 ) {
					g = i;	
				}
			}
			for(int i = 0;i< vb.size() ;i++) {
				if( strcmp ( boyn , vb[i].name ) == 0 ) {
					b = i;	
				}
			}
			boyhap = vb[b].happiness;
			girlhap = vg[g].happiness;
			couplehap = boyhap + girlhap;
		}
		void setco(vector<boy> vb,vector <girl> vg) {
			int g = 0 , b = 0 ;
			for(int i = 0 ; i < vg.size() ; i++ ) {
				if( strcmp ( girln , vg[i].name ) == 0 ) {
					g = i;	
				}
			}
			for(int i = 0 ; i < vb.size() ; i++ ) {
				if( strcmp ( boyn , vb[i].name ) == 0  ) {
					b = i;	
				}
			}
			comp = ( vb[b].budget-vg[g].maintenance )+(abs( vb[b].attractiveness-vg[g].attractiveness ) ) ;
			comp += ( abs( vb[b].intelligence- vg[g].intelligence ) ) ;
		}
};
#endif

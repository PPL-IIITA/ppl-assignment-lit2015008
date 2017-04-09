#include <bits/stdc++.h> 
#include "girl.h"
#include "boy.h" 
#include "couple.h"
#include "gift.h" 
#include "input.h" 

using namespace std; 

int cmp1 ( couple a , couple b ) {
	// comparator function to sort couples according to happiness
	if ( a.couplehap < b.couplehap ) {
		return 1 ;
	}	
	return 0 ;
}

int cmp2 ( couple a , couple b ) {
	// comparator function to sort couples according to compatibility
	if ( a.comp > b.comp ) {
		return 1;
	}
	return 0 ;
}

int cmp (gift a , gift b) {
	// comparator function to sort gifts according to price
    if ( a.price < b.price ) {
    	return 1;
	}
    return 0;
}

vector<boy> vecb; // vector of boys
vector<miser> vecm; // vector of miser boys
vector<generous> vecgen; //vector of generous boys
vector<geeks> vecgee; // vector of geeks
vector<girl> vecg; // vector of girls
vector<choosy> vecch; // vector choosy girls
vector<normal> vecn; // vector of normal girls
vector<desperate> vecd; // vector of desperate girls
vector<gift> vecgi; // vector of girls
vector<utility> vecu; // vector of utility gifts
vector<luxury> vecl; // vector of luxury gifts
vector<essential> vece; // vector of essential gifts
vector<couple> vecc; // vector of couples

void pair1() {
	// Function used to pair boys and girls using algorithm 1
	FILE *fp = fopen("couple.txt","w");
	FILE *fp1 = fopen("boy.txt","r");
	char *s = (char *)malloc(13*sizeof(char));
	int a,in,r,st,t;
	double b,m;
	while(1) {
		fscanf(fp1,"%s %d %d %lf %d %d",s,&a,&in,&b,&r,&st,&t);
		while(strcmp(s,"%$#")) { // inserting boys in vectors according to their type
			boy b1;
			b1.setb(s,a,in,b,r,st,t);
			vecb.push_back(b1);
			fscanf(fp1,"%s %d %d %lf %d %d",s,&a,&in,&b,&r,&st,&t);
		}
		break;
	}
	fclose(fp1);	
	FILE *fp2 = fopen("girl.txt","r");
	while(1) { // inserting girls in vectors according to their type
		fscanf(fp2,"%s %d %d %lf %d %d",s,&a,&in,&b,&r,&st,&t);
		while(strcmp(s,"%$#")) {
			girl g1;
			g1.setg(s,a,in,b,r,st,t);
			vecg.push_back(g1);
			fscanf(fp2,"%s %d %d %lf %d %d",s,&a,&in,&b,&r,&st,&t);
		}
		break;
	}
	fclose(fp2);
	FILE *fp3 = fopen("gift.txt","r");
	while(1) { // inserting gifts in vectors according to their type
		fscanf(fp3,"%s %lf %d %d %d %d",s,&b,&in,&a, &r, &t);
		while(strcmp(s,"%$#")) {
			gift g1;
			g1.setgi(s,b,in,a,r,t);
			vecgi.push_back(g1);
			fscanf(fp3,"%s %lf %d %d %d %d",s,&b,&in,&a, &r, &t);
		}
		break;
	}
	sort(vecgi.begin(),vecgi.end(),cmp);
	fclose(fp3);
	for(int i = 0; i < 10; i++) { // making couples according to the parameters given
		if(vecg[i].status == 0) {
			int max = 0,k=-1;
			for(int j = 0;j<20;j++) {
				if(vecg[i].criteria == 0) {
					if(vecb[j].status == 0 && vecg[i].maintenance<=vecb[j].budget && vecg[i].attractiveness>=vecb[j].req && vecb[j].attractiveness>max) {
						max = vecb[j].attractiveness;
						k = j;
					}					
				}
				else if(vecg[i].criteria == 1) {
					if(vecb[j].status == 0 && vecg[i].maintenance<=vecb[j].budget && vecg[i].attractiveness>=vecb[j].req && vecb[j].intelligence>max) {
						max = vecb[j].intelligence;
						k = j;
					}					
				}
				else {
					if(vecb[j].status == 0 && vecg[i].maintenance<=vecb[j].budget && vecg[i].attractiveness>=vecb[j].req && vecb[j].budget>max) {
						max = vecb[j].budget;
						k = j;
					}					
				}
			}
			if(k!=-1) {
				couple c;
				c.setc(vecg[i].name,vecb[k].name);
				vecg[i].status = 1;
				vecb[k].status = 1;
				fprintf(fp,"%s %s\n",vecg[i].name,vecb[k].name);
				vecc.push_back(c); // inserting couples in couple vector
			} 
		}
	}	
	fclose(fp);
}
void pair2 () {
	// Function used to pair boys and girls using algorithm 2
	FILE *fp = fopen("couple.txt","w");
	FILE *fp1 = fopen("boy.txt","r");
	char *s = (char *)malloc(13*sizeof(char));
	int a,in,r,st,t;
	double b,m;
	while(1) {
		fscanf(fp1,"%s %d %d %lf %d %d %d",s,&a,&in,&b,&r,&st,&t);
		while(strcmp(s,"%$#")) { // inserting boys in vectors according to their type
			boy b1;
			b1.setb(s,a,in,b,r,st,t);
			vecb.push_back(b1);
			fscanf(fp1,"%s %d %d %lf %d %d %d",s,&a,&in,&b,&r,&st,&t);
		}
		break;
	}
	fclose(fp1);	
	FILE *fp2 = fopen("girl.txt","r");
	while(1) { // inserting girls in vectors according to their type
		fscanf(fp2,"%s %d %d %lf %d %d %d",s,&a,&in,&b,&r,&st,&t);
		while(strcmp(s,"%$#")) {
			girl g1;
			g1.setg(s,a,in,b,r,st,t);
			vecg.push_back(g1);
			fscanf(fp2,"%s %d %d %lf %d %d %d",s,&a,&in,&b,&r,&st,&t);
		}
		break;
	}
	fclose(fp2);
	FILE *fp3 = fopen("gift.txt","r");
	while(1) { // inserting gifts in vectors according to their type
		fscanf(fp3,"%s %lf %d %d %d %d",s,&b,&in,&a, &r, &t);
		while(strcmp(s,"%$#")) {
			gift g1;
			g1.setgi(s,b,in,a,r,t);
			vecgi.push_back(g1);
			fscanf(fp3,"%s %lf %d %d %d %d",s,&b,&in,&a, &r, &t);
		}
		break;
	}
	sort(vecgi.begin(),vecgi.end(),cmp);
	fclose(fp3);
	int i = 0 ;
	while ( 1 ) {
		if ( i%2 == 0 ) {
			int indg = -1 , indb = -1 ;
			for ( int j = 0 ; j < vecg.size() ; j++ ) {
				if ( vecg[j].status == 0 ) { 
					indg = j ; break ;
				}
			}
			if ( indg == -1 ) break ; int mx = -1 ;
			for ( int j = 0 ; j < vecb.size() ; j++ ) {
				if(vecg[indg].criteria == 0) {
					if(vecb[j].status == 0 && vecg[indg].maintenance<=vecb[j].budget && vecg[indg].attractiveness>=vecb[j].req && vecb[j].attractiveness > mx) {
						mx = vecb[j].attractiveness;
						indb = j;
					}					
				}
				else if(vecg[indg].criteria == 1) {
					if(vecb[j].status == 0 && vecg[indg].maintenance<=vecb[j].budget && vecg[indg].attractiveness>=vecb[j].req && vecb[j].intelligence > mx) {
						mx = vecb[j].intelligence;
						indb = j;
					}					
				}
				else {
					if(vecb[j].status == 0 && vecg[indg].maintenance<=vecb[j].budget && vecg[indg].attractiveness>=vecb[j].req && vecb[j].budget > mx) {
						mx = vecb[j].budget;
						indb = j;
					}					
				}
			}
			if ( indb == -1 ) break ;
			couple c;
			c.setc(vecg[indg].name,vecb[indb].name);
			vecg[indg].status = 1;
			vecb[indb].status = 1;
			fprintf(fp,"%s %s\n",vecg[indg].name,vecb[indb].name);
			vecc.push_back(c); // inserting couples in couple vector
		}
		else {
			int indb = -1 , indg = -1 ;
			for ( int j = 0 ; j < vecb.size() ; j++ ) {
				if ( vecb[j].status == 0 ) {
					indb = j ; break ;
				}
			}
			if ( indb == -1 ) break ; int mx = -1 ;
			for ( int j = 0 ; j < vecg.size() ; j++ ) {
				if ( vecg[j].status == 1 ) continue ;
				if ( vecg[j].attractiveness > mx ) {
					mx = vecg[j].attractiveness ;
					indg = j ;
				}
			}
			if ( indg == -1 ) break ;
			couple c;
			c.setc(vecg[indg].name,vecb[indb].name);
			vecg[indg].status = 1;
			vecb[indb].status = 1;
			fprintf(fp,"%s %s\n",vecg[indg].name,vecb[indb].name);
			vecc.push_back(c); // inserting couples in couple vector
		}
		i++ ;
	}
	fclose ( fp ) ;
}
int main() {
	input i ;
	i.create_input() ;
	int ixxx = rand()%2 ;
	if ( ixxx ) pair1() ;
	else pair2() ;
	return 0;
}

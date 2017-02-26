#include <bits/stdc++.h> 
#include "girl.h"
#include "boy.h" 
#include "couple.h"
#include "gift.h" 
#include "input.h" 

using namespace std; 

int cmp1 ( couple a , couple b ) {
	if ( a.couplehap < b.couplehap ) {
		return 1 ;
	}	
	return 0 ;
}

int cmp2 ( couple a , couple b ) {
	if ( a.comp > b.comp ) {
		return 1;
	}
	return 0 ;
}

int cmp (gift a , gift b) {
    if ( a.price < b.price ) {
    	return 1;
	}
    return 0;
}

vector<boy> vecb;
vector<girl> vecg;
vector<gift> vecgi;
vector<couple> vecc;

void pair1() {
	FILE *fp = fopen("couple.txt","w");
	FILE *fp1 = fopen("boy.txt","r");
	char *s = (char *)malloc(13*sizeof(char));
	int a,in,r,st,t;
	double b,m;
	while(1) {
		fscanf(fp1,"%s %d %d %lf %d %d",s,&a,&in,&b,&r,&st,&t);
		while(strcmp(s,"%$#")) {
			boy b1;
			b1.setb(s,a,in,b,r,st,t);
			vecb.push_back(b1);
			fscanf(fp1,"%s %d %d %lf %d %d",s,&a,&in,&b,&r,&st,&t);
		}
		break;
	}
	fclose(fp1);	
	FILE *fp2 = fopen("girl.txt","r");
	while(1) {
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
	while(1) {
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
	for(int i = 0; i < 10; i++) {
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
				vecc.push_back(c);
				cout << vecg[i].name << " " << vecb[k].name << "\n";
			} 
		}
	}	
	fclose(fp);
}

void print() {
	FILE *fp = fopen("gift_det.txt","r");
	int t = vecc.size();
	int j = 0;
	char *b = (char *)malloc(sizeof(char));
	char *g = (char *)malloc(sizeof(char));
	char *gi = (char *)malloc(sizeof(char));
	double p;
	int v,ty,r,o;
	while(j<t) {
		cout << "\n\n";
		fscanf(fp,"%s %s\n",b,g);
		cout << b << " " << g << ":\n";
		fscanf(fp,"%s %lf %d %d %d %d",gi,&p,&v,&ty,&r,&o);
		while(strcmp(gi,"%$#")) {
			cout << gi << " " << p << " " << v << " " << ty << " " << r << " " << o << "\n";
			fscanf(fp,"%s %lf %d %d %d %d",gi,&p,&v,&ty,&r,&o);
		}
		j++;
		cout << "\n";
	}
}

int main() {
	input i ;
	i.create_input();
	pair1();
	int t = vecc.size() ;
	for( int j = 0 ; j < t ; j++ ) {
		couple c = vecc[j] ;
		c.get_basket(&vecb,&vecg,vecgi);
		c.seth( vecb , vecg );
		c.setco( vecb , vecg ) ;
		vecc[j] = c;
	}
	int k ;
	cin >> k ;
	sort ( vecc.begin() , vecc.end() , cmp1 ) ;
	cout << "k Most Happy Couples:\n" ;
	for ( int i = 0 ; i < min ( k, (int)vecc.size() ) ; i++ ) {
		cout << vecc[i].girln << " " << vecc[i].boyn << endl ;
	}
	sort ( vecc.begin() , vecc.end() , cmp2 ) ;
	cout << "\nk Most Compatible Couples:\n" ;
	for ( int i = 0 ; i < min ( k, (int)vecc.size() ) ; i++ ) {
		cout << vecc[i].girln << " " << vecc[i].boyn << endl ;
	}
	cout << "\nGifts Inventory: \n" ;
	print();
	return 0;
}

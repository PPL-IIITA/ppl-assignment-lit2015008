#ifndef input_h
#define input_h
#include "girl.h"
#include "boy.h"
#include "gift.h"

using namespace std;

class input {
	public:
	int a,in,r,t;
	double b,m;
	void create_input() {
		FILE *fp1 = fopen("boy.txt","w");
		FILE *fp2 = fopen("girl.txt","w");
		FILE *fp3 = fopen("gift.txt","w");
		for(int i = 0;i < 20; i++) { // creating input file names boy.txt
			a = rand()%11;
			in = rand()%11;
			b = (double)rand() / 10;
			r = rand()%11;
			t = rand()%3;
			fprintf(fp1,"Boy%d %d %d %lf %d %d\n",i+1,a,in,b,r,t,0);
		}
		fprintf(fp1,"%$#");
		for(int i = 0;i < 10; i++) { // creating input file names girl.txt
			a = rand()%11;
			in = rand()%11;
			m = (double)rand() / 10;
			r = rand()%3;
			t = rand()%3;
			fprintf(fp2,"Girl%d %d %d %lf %d %d\n",i+1,a,in,m,r,t,0);
		}
		fprintf(fp2,"%$#");
		for(int i = 0; i < 30;i++) { // creating input file names gift.txt
			m = (double)rand() / 100;
			a = rand()%11;
			int ty = rand()%3;
			if(ty!=0) {
				in = (rand()%10)+1;
				t = (rand()%10)+1;
				fprintf(fp3,"Gift%d %lf %d %d %d %d\n",i+1,m,a,ty,in,t);
			}
			else {
				fprintf(fp3,"Gift%d %lf %d %d %d %d\n",i+1,m,a,ty,0,0);
			}
		}
		fprintf(fp3,"%$#");
		fclose(fp1);
		fclose(fp2);
		fclose(fp3);
	}
};
#endif

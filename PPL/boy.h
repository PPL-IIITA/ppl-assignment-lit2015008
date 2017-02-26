#ifndef boy_h
#define boy_h
#include "girl.h"

using namespace std;

class boy{
	public:
		char *name = (char *)malloc(13*sizeof(char));
		int attractiveness;
		int intelligence;
		double budget;
		int req;
		int status;
		int type;
		double happiness = 0;
		void setb(char *n, int a, int i, double b, int r, int t, int s) {
			strcpy(name,n);
			attractiveness = a;
			intelligence = i;
			budget = b;
			req = r;
			status = s;
			type = t;
		}
		void seth(girl g, double p, double v) {
			if(type==0) {
				happiness = budget - p;
			}
			else if(type == 1) {
				happiness = g.happiness;
			}
			else {
				happiness = g.intelligence;
			}
		}
};
#endif


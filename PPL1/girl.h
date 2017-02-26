#ifndef girl_h
#define girl_h

using namespace std;

class girl{
	public:
		char *name = (char *)malloc(13*sizeof(char));
		int attractiveness;
		int intelligence;
		double maintenance;
		int criteria;
		int status;
		int type;
		double happiness = 0;
		void setg(char *n, int a, int i, double m, int c, int t, int s) {
			strcpy(name,n);
			attractiveness = a;
			intelligence = i;
			maintenance = m;
			criteria = c;
			status = s;
			type = t;
		}
		void seth(double p, double v) {
			if(type==0) {
				double x = p + v;
				int t = 0;
				while ( x ) { 
					t++ ; 
					x /= 10 ; 
				}
                happiness = t;
			}
			else if(type == 1) {
				happiness = p + v;
			}
			else {
				happiness = p*p ;
			}
		}
};
#endif

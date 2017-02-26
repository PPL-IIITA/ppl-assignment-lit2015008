#ifndef gift_h
#define gift_h

using namespace std;

class gift{
	public:
		char *name = (char *)malloc(13*sizeof(gift));
		double price;
		int value;
		int type = 0;
		int rating = 0;
		int obtain = 0;
		void setgi(char *n,double p, int v, int t, int l, int lu) {
			strcpy(name,n);
			price = p;
			value = v;
			type = t;
			rating = l;
			obtain = lu;
		}
};
#endif

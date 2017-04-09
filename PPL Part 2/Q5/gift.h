#ifndef gift_h
#define gift_h

using namespace std;

class gift{ // parent class - gift
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

class essential : public gift { // child class - essential inheriting class gift
	public:
		char *name = (char *)malloc(13*sizeof(essential));
		double price;
		int value;
		int type;
		void setgi(char *n,double p, int v, int t) {
			strcpy(name,n);
			price = p;
			value = v;
			type = t;
		}
};

class luxury : public gift { // child class - luxury inheriting class gift
	public:
		char *name = (char *)malloc(13*sizeof(luxury));
		double price;
		int value;
		int type;
		int luxury_rating;
		int obtain;
		void setgi(char *n,double p, int v, int t, int l, int lu) {
			strcpy(name,n);
			price = p;
			value = v;
			type = t;
			rating = l;
			obtain = lu;
		}
};

class utility : public gift { // child class - utility inheriting class gift
	public:
		char *name = (char *)malloc(13*sizeof(utility));
		double price;
		int value;
		int type;
		int util_value;
		int util_class;
		void setgi(char *n,double p, int v, int t, int uv, int uc) {
			strcpy(name,n);
			price = p;
			value = v;
			type = t;
			util_value = uv;
			util_class = uc;
		}
};
#endif

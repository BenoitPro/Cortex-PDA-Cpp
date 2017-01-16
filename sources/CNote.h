#define MAX 255
class CNote  {
private :
	char _note[MAX];
public :
	CNote();
	CNote(char *);
	void setNote(char *);
	char * getNote(char *);
	friend ostream& operator<< (ostream& o,CNote c) ;
};


#define	DelayUs(x)	{ unsigned char _dcnt=x; \
			  while(_dcnt-- != 0) \
				  NOP(); }
extern void DelayMs(unsigned char);
void DelayS(unsigned char cnt);


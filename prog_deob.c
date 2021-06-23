#define L for
#include <stdio.h>
char* r;
char F[1<<21] = "~T/}3(|+G{>/zUhy;Jx+5wG<v>>u55t.?sIZrC]n.;m+:l+Hk]WjNJi/Sh+2f1>c2H`)(_2(^L\
 -]=([1/Z<2Y7/X12W:.VFFU1,T77S+;N?;M/>L..K1+JCCI<<H:(G*5F--E11C=5?.(>+(=3)Z-;*(:*.Y/5(-=)2*-U,\
/+-?5'(,+++***''EE>T,215IEUF:N`2`:?GK;+^`+?>)5?>U>_)5GxG).2K.2};}_235(]:5,S7E1(vTSS,-SSTvU(<-HG\
-2E2/2L2/EE->E:?EE,2XMMMM1Hy`)5rHK;+.T+?[n2/_2{LKN2/_|cK2+.2`;}:?{KL57?|cK:2{NrHKtMMMK2nrH;rH[n"
"CkM_E21-E,-1->E(_:mSE/LhLE/mm:2Ul;2M>,2KW-+.-u).5Lm?fM`2`2nZXjj?[n<YcK?2}yC}H[^7N7LX^7N7UN</:-\
ZWXI<^I2K?>T+?KH~-?f<;G_x2;;2XT7LXIuuVF2X(G(GVV-:-:KjJ]HKLyN7UjJ3.WXjNI2KN<l|cKt2~[IsHfI2w{[<VV"
"GIfZG>x#&#&&$#$;ZXIc###$&$$#>7[LMv{&&&&#&##L,l2TY.&$#$#&&$,(iiii,#&&&#$#$?TY2.$#$1(x###;2EE[t,\
SSEz.SW-k,T&&jC?E-.$##      &#&57+$$#      &&&W1-&$$7W  -J$#$kEN&#&      $##C^+$##W,h###n/+L2YE"
"2nJk/H;YNs#$[,:TU(#$   ,:   &&~H>&#   Y;   &&G_x&#2;   ,mT&$YE-#&   5G   $#VVF$#&zNs$$&Ej]HELy\
CN/U^Jk71<(#&:G7E+^&#  l|?1  $$Y.2$$  7lzs  WzZw>&$E    -<V-wE(2$$  G>x;  2zsW/$$#HKt&$$v>+t1(>"
"7>S7S,;TT,&$;S7S>7&#>E_::U  $$'";
/* block of memory 2^21 bytes long
 * first 956 bytes are text - font data and possibly holes
 * changing spaces that make the "2018" ASCII art changes the contents of GIF which is suspicous
 * data is not stored sequentially - changing 1st characters from '~' to '0' messes up some characters
 * 	while leaving others intact
 *  after corruption some holes are erroneous
 *  some of them seem to correspond to letters with holes but shifted and broken up
 *  some have diagonal strip-like patterns
 *  */

char* G = F;
char* I = 957+F; // pointer to contents of F after the text
int* t;
int k,  i, j;
int w, h, z, W;
int T[48<<16];

int M(int m,int nop) {
	return m % nop;
}

int f, c, Z;
int H = 11;

void E (int n) {
	for (Z=k; Z; Z/=2) {
		G[0] = (G[0] * !!f) | (n % 2 << f);		//!!f evals to 1 when f is nonzero and 0 otherwise
		f = (6 < f) ? (G++, z) : (f + 1);
		n /= 2;
	}
}

void V (int n) {		//prints Int16 as 2 bytes little endian 
	putchar(n % 256);
	putchar(n / 256);
}


void J() {
	for (j = 0; j<240; j++) {
		k = G[j/4 + (*r- 32)* *"<nopqabdeg"] % 3;
		I[6+   (h + 6 + (j/24) * 2 + (j/2) % 2) * W +M(j/4, 6)*2+w*12 + M(j, 2)] = k;
		/* "(j/24) * 2" cannot be simplifed to j/12 probably because of integer division shenanigans
		 * "*r - 32" might shift an ascii code such that 0 corresponds to the first visible character*/
	}
}


int main() {
	for (;i<21*3;i++,I++)
		for (r=G,G+=2;*G++;) *G>=13*3?*G-*r?*I++=*G:(*I++=r[1],*I++=r[2]):1;
	for(j=12,r=I;(*I=i=getchar())>-1;I++)
		i-7-3?I-=i<32||127<=i,j+=12:(H+=17+3,W=W<j?j:W,j=12);
	for (;*r>-1;r++) *r-7-3?J(),w++:(w=z,h+=17+3);
	printf("%s", "GIF89a");
	V(W); //image width
	V(H); //image height
	putchar(244);
	V(z);
	for (i=z; i<32*3 ;i++)
		putchar(i/3*255/31);
	putchar('!');
	putchar(255);
	putchar(11);
	for (G="SJYXHFUJ735";*G;)
		putchar(*G++-5);putchar(3);V(1);
	for (V(j=z);j<21*3;j++) {
		k=257;
		V(63777);
		V(k<<2);
		V(M(j,32)?11:511);
		V(z);
		putchar(22*2);
		V(i=f=z);
		V(z);
		V(W);
		V(H);
		V(1<<11);
		r = G = I + W * H;
		for (t=T;i<1<<21;i++) T[i] = (i < 256) ? i : -1;
		E(256);
		for (i=-1;++i<W*H;t=T+Z*256+256) {
			c = I[i]?I[i]*31-31:(31<
			j?j-31:31-j);
			Z=c[t[c]<z?E(Z),
			k<(1<<12)-2?t[c]=++k,T:T:t];
		}
		E(Z);
		E(257);
		for (G++;k=G-r>255?255:G-r,putchar(k),k;)
			for (; k-- ;putchar(*r++/*---#$%&04689@ABDOPQRabdegopq---*/));
	}
	putchar(59);
	return(z);
}
